package ex_4;

import java.time.LocalDate;
import java.time.Year;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoField;
import java.time.temporal.ChronoUnit;

public class Persoana {

    // membri
    private String nume;
    private String cnp;

    // constructor
    public Persoana(String nume, String cnp) {
        this.nume = nume;
        this.cnp = cnp;
    }

    // getter-e
    public String getNume() {
        return nume;
    }

    public String getCnp() {
        return cnp;
    }



    // setter-e
    public void setNume(String nume) {
        this.nume = nume;
    }

    public void setCnp(String cnp) {
        this.cnp = cnp;
    }


    // metode

    public LocalDate getDataNasterii()
    {
        // an luna zi
        String an_string = cnp.substring(1, 2+1);
        String luna_string = cnp.substring(3, 4+1);
        String zi_string = cnp.substring(5, 6+1);

        String an_pref_string;

        // daca ultimele 2 cifre din anul nasterii <= ultimele 2 cifre din anul curent
        if (Integer.parseInt(an_string) <= Integer.parseInt(String.format("%ty", Year.now()))) {
            // prefixam anul cu "20"
            an_pref_string = "20" + an_string;
        }
        else {
            // prefixam anul cu "19"
            an_pref_string = "19" + an_string;
        }

        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd.MM.yyyy");
        return LocalDate.parse((zi_string+"."+luna_string+"."+an_pref_string), formatter);
    }

    public int getVarsta()
    {
        LocalDate dateNow = LocalDate.now();

        // diferenta
        return ((int) Math.abs(ChronoUnit.YEARS.between(dateNow, getDataNasterii())));
    }

}
