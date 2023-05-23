package org.example.ex_3;

import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.RowMapper;

import javax.sql.DataSource;
import java.time.LocalDate;
import java.util.List;

public class MasinaController {

    // members
    private DataSource dataSource;
    private JdbcTemplate jdbcTemplateObject;


    // setters
    public void setDataSource(DataSource dataSource) {
        this.dataSource = dataSource;
        this.jdbcTemplateObject = new JdbcTemplate(dataSource);
    }


    // methods

    // adauga masina
    public void insert(
        String nr_inmatriculare,
        String marca,
        int an_fabricatie,
        String culoare,
        int nr_kilometri
    ) {

        String sql = """
                INSERT INTO masina 
                (nr_inmatriculare, marca, an_fabricatie, culoare, nr_kilometri) 
                VALUES (?, ?, ?, ?, ?)
                """;

        jdbcTemplateObject.update(sql, nr_inmatriculare, marca, an_fabricatie, culoare, nr_kilometri);
    }

    // sterge masina
    public void delete(String nr_inmatriculare) {

        String sql = "DELETE FROM masina WHERE nr_inmatriculare = ?";
        jdbcTemplateObject.update(sql, nr_inmatriculare);
    }

    // cautare masina
    public Masina getMasina(String nr_inmatriculare) {

        String sql = "SELECT * FROM masina WHERE nr_inmatriculare = ?";

        Masina masina = jdbcTemplateObject.queryForObject(sql, new Object[] {nr_inmatriculare}, new MasinaMapper());

        return masina;
    }

    // afisare masini
    public List<Masina> getListaMasini() {

        String sql = "SELECT * FROM masina";
        List<Masina> masini = jdbcTemplateObject.query(sql, new MasinaMapper());

        return masini;
    }

    // cauta nr masini dupa marca
    public Integer getNrMasiniMarca(String marca) {

        String sql = "SELECT COUNT(*) as nr FROM masina WHERE marca = ?";

        Integer n = jdbcTemplateObject.queryForObject(sql, Integer.class, marca);

        return n;
    }

    // cauta masini care au sub 100.000 km
    public List<Masina> getListaMasiniNrKilometri() {

        String sql = "SELECT * FROM masina WHERE nr_kilometri < 100000";

        List<Masina> masini = jdbcTemplateObject.query(sql, new MasinaMapper());

        return masini;
    }


    // cauta masini < 5 ani
    public List<Masina> getListaMasiniVarsta() {

        int max_year = LocalDate.now().getYear() - 5;
        String sql = "SELECT * FROM masina WHERE an_fabricatie <= ?";

        List<Masina> masini = jdbcTemplateObject.query(sql,new MasinaMapper(), max_year);

        return masini;
    }

}
