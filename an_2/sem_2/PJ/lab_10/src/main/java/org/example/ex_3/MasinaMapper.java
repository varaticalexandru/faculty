package org.example.ex_3;

import org.springframework.jdbc.core.RowMapper;

import java.sql.ResultSet;
import java.sql.SQLException;

public class MasinaMapper implements RowMapper<Masina> {

    // methods
    public Masina mapRow(ResultSet rs, int rowNum) throws SQLException {

        Masina masina = new Masina();
        masina.setNr_inmatriculare(rs.getString("nr_inmatriculare"));
        masina.setMarca(rs.getString("marca"));
        masina.setAn_fabricatie(rs.getInt("an_fabricatie"));
        masina.setCuloare(rs.getString("culoare"));
        masina.setNr_kilometri(rs.getInt("nr_kilometri"));

        return masina;
    }
}
