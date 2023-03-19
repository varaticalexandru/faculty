package ex_1;

/**
 * Copiatorul este un subtip de echipament electronic.
 * @author Admin
 * @version 1
 * @since 2023
 */
public class Copiator extends EchipamentElectronic {

    // membri
    Integer p_ton;
    FormatCopiere format_copiere;

    // constructori


    /**
     * Constructorul clasei Copiator.
     * {@inheritDoc}
     * @param p_ton Nr. pagini / toner
     * @param format_copiere Format de copiere (A3 / A4)
     */
    public Copiator(String nume, String nr_inventar, Float pret, ZonaMagazie zona_magazie, Situatie situatie, Integer p_ton, FormatCopiere format_copiere) {
        super(nume, nr_inventar, pret, zona_magazie, situatie);
        this.p_ton = p_ton;
        this.format_copiere = format_copiere;
    }

    // getters & setters

    public Integer getP_ton() {
        return p_ton;
    }

    public void setP_ton(Integer p_ton) {
        this.p_ton = p_ton;
    }

    public FormatCopiere getFormat_copiere() {
        return format_copiere;
    }

    public void setFormat_copiere(FormatCopiere format_copiere) {
        this.format_copiere = format_copiere;
    }


    // metode
    @Override
    public String toString() {
        return
            super.toString() +
            "Pagini / toner: " + this.p_ton + "\n" +
            "Format copiere: " + this.format_copiere.toString() + "\n" +
            "\n"
        ;
    }
}
