package lab;

import javax.swing.plaf.nimbus.State;
import java.sql.*;
import java.util.Scanner;

public class MainApp {

    // meniu interactiv
    static void menu() {
        System.out.print(
                """
                --------- Meniu Interactiv ---------
                0) Iesire
                1) Adaugarea unei persoane
                2) Adaugarea unei excursii
                3) Afisarea persoanelor si pt. fiecare persoana excursiile
                4) Afisarea excursiilor unei persoane
                5) Afisarea persoanelor care au vizitat o destinatie
                6) Afisarea persoanelor care au facut excursii intr-un an
                7) Stergerea unei excursii
                8) Stergerea unei persoane + excursiile sale
                ------------------------------------
                Introduceti optiunea dvs: 
                        """
        );
    }

    // get id_persoana by nume
    static int getIdPersoana(Connection cnn, String nume) {

        String sql = "SELECT id FROM persoane WHERE nume=?";
        int id = -1;
        int flag = 0;

        try (PreparedStatement ps = cnn.prepareStatement(sql)) {

            ps.setString(1, nume);
            ResultSet rs = ps.executeQuery();

            while (rs.next()) {
                flag++;
                if (flag > 1) {
                    System.out.println("S-a gasit mai mult de 1 persoana cu acelasi nume.");
                    rs.close();
                    return id;
                }
                id = rs.getInt(1);
            }

            rs.close();

        } catch (SQLException e) {
            System.out.println(sql);
            e.printStackTrace();
        }

        return id;
    }

    // afisare tabela Persoane
    static void afisarePersoane(Statement statement) throws SQLException {

        String sql = "select * from persoane";

        ResultSet rs;
        rs = statement.executeQuery(sql);

        System.out.println("\nPersoane:");
        while (rs.next()) {
            System.out.println("id="+rs.getInt("id")+", nume= " + rs.getString("nume")+
                    ", varsta="+rs.getInt("varsta"));
        }

    }

    // afisare tabela Excursii
    static void afisareExcursii(Statement statement) throws SQLException {

        String sql = "select * from excursii";

        ResultSet rs;
        rs = statement.executeQuery(sql);

        System.out.println("\nExcursii:");
        while (rs.next()) {
            System.out.println("id_excursie="+rs.getInt("id_excursie")+", id_persoana= " + rs.getString("id_persoana")+
                    ", destinatia="+rs.getString("destinatia") + ", anul=" + rs.getInt("anul"));
        }

    }

    // adaugare persoana (nume, varsta)
    static void adaugaPersoana(Connection cnn) throws SQLException {

        Scanner scanner = new Scanner(System.in);

        System.out.println("\nIntroduceti date persoana noua:");

        System.out.print("nume: ");
        String nume = scanner.nextLine();

        System.out.print("varsta: ");
        int varsta = scanner.nextInt();

        String sql = "insert into persoane(nume, varsta) values(?,?)";

        try (PreparedStatement ps = cnn.prepareStatement(sql)) {

            ps.setString(1, nume);
            ps.setInt(2, varsta);

            int nr_randuri = ps.executeUpdate();
            System.out.println("\nNr. randuri afectate dupa adaugare: " + nr_randuri);

        } catch (SQLException e) {

            System.out.println(sql);
            e.printStackTrace();
        }
    }

    // adauga excursie (id_excursie, id_persoana, destinatia, anul)
    static void adaugaExcursie(Connection cnn) throws SQLException {

        Scanner scanner = new Scanner(System.in);
        Integer id_persoana = -1;

        System.out.println("\nIntroduceti date excursie noua:");

        System.out.print("nume persoana: ");
        String nume_persoana = scanner.nextLine();

        System.out.print("destinatia: ");
        String destinatia = scanner.nextLine();

        System.out.print("anul: ");
        int anul = scanner.nextInt();

        // get id_persoana from nume_persoana
        String sql_persoana = "select id from persoane where nume=?";
        try {
            PreparedStatement ps = cnn.prepareStatement(sql_persoana);
            ps.setString(1, nume_persoana);

            ResultSet rs = ps.executeQuery();
            rs.next();
            id_persoana = rs.getInt(1);
            System.out.println("\nid persoana: "  + id_persoana);
        }
        catch (SQLException e) {
            System.out.println(sql_persoana);
            e.printStackTrace();
        }

        // add excursie
        String sql_excursie = "insert into excursii (id_persoana, destinatia, anul) values (?,?,?)";
        try (PreparedStatement ps = cnn.prepareStatement(sql_excursie)) {

            ps.setInt(1, id_persoana);
            ps.setString(2, destinatia);
            ps.setInt(3, anul);

            int nr_randuri = ps.executeUpdate();
            System.out.println("\nNr. randuri afectate dupa adaugare: " + nr_randuri);

        } catch (SQLException e) {
            System.out.println(sql_excursie);
            e.printStackTrace();
        }

    }

    // afisarea persoanelor si excursiile fiecareia
    static void afisarePersoaneExcursii(Statement statement) throws SQLException {

        String sql = """
                SELECT e.id_persoana, e.id_excursie, e.destinatia, e.anul
                FROM excursii e
                INNER JOIN persoane p ON p.id = e.id_persoana;\s""";

        ResultSet rs;
        rs = statement.executeQuery(sql);

        System.out.println("\nPersoane si excursii:");

        while (rs.next()) {
            System.out.println("id_persoana=" + rs.getInt(1) +
                    ", id_excursie=" + rs.getInt(2) +
                    ", destinatia=" + rs.getString(3) +
                    ", anul=" + rs.getInt(4)
            );

        }
    }

    // afisarea excursiilor unei persoane (dupa nume)
    static void afisareExcursiiPersoana(Connection cnn, String nume) {

        int id_persoana = getIdPersoana(cnn, nume);

        String sql = """
                SELECT e.id_excursie, e.destinatia, e.anul
                FROM excursii e
                WHERE e.id_persoana=?
                """;

        try (PreparedStatement ps = cnn.prepareStatement(sql)) {

            ps.setInt(1, id_persoana);

            ResultSet rs = ps.executeQuery();

            System.out.println("\nExcursiile persoanei " + nume + ":");

            while (rs.next()) {
                System.out.println(
                        "id_excursie=" + rs.getString(1) +
                        ", destinatia=" + rs.getString(2) +
                        ", anul=" + rs.getString(3)
                );
            }

            rs.close();

        } catch (SQLException e) {
            System.out.println(sql);
            e.printStackTrace();
        }

    }

    // afisarea persoanelor care au vizitat o destinatie
    static void afisarePersoaneDestinatia(Connection cnn, String destinatia) {

        String sql = """
                SELECT p.id, p.nume, p.varsta
                FROM persoane p
                INNER JOIN excursii e ON p.id = e.id_persoana
                WHERE e.destinatia=?;
                """;

        try (PreparedStatement ps = cnn.prepareStatement(sql)) {

            ps.setString(1, destinatia);
            ResultSet rs = ps.executeQuery();

            System.out.println("\nPersoanele care au vizitat " + destinatia + ":");

            while (rs.next()) {
                System.out.println(
                        "id=" + rs.getInt(1) +
                        ", nume=" + rs.getString(2) +
                        ", varsta=" + rs.getInt(3)
                );
            }

            rs.close();

        } catch (SQLException e) {

            System.out.println(sql);
            e.printStackTrace();
        }
    }

    // afisarea persoanelor care au facut excursii intr-un an
    static void afisarePersoaneExcursiiAn(Connection cnn, int anul) {

        String sql = """
                SELECT p.id, p.nume, p.varsta
                FROM persoane p
                JOIN excursii e on p.id = e.id_persoana
                WHERE e.anul = ?;
                """;

        try (PreparedStatement ps = cnn.prepareStatement(sql)) {

            ps.setInt(1, anul);
            ResultSet rs = ps.executeQuery();

            System.out.println("\nPersoanele care au facut excursii in " + anul + ":");

            while (rs.next()) {

                System.out.println(
                        "id=" + rs.getString(1) +
                        ", nume=" + rs.getString(2) +
                        ", varsta=" + rs.getString(3)
                );
            }

            rs.close();

        } catch (SQLException e) {

            System.out.println(sql);
            e.printStackTrace();
        }
    }

    // stergere excursie
    static void stergeExcursie(Connection cnn, int id_excursie) {

        String sql = "DELETE FROM excursii WHERE id_excursie=?";

        try (PreparedStatement ps = cnn.prepareStatement(sql)) {

            ps.setInt(1, id_excursie);
            int nr_randuri = ps.executeUpdate();

            System.out.println("\nNr. randuri modificate: " + nr_randuri);

        } catch (SQLException e) {

            System.out.println(sql);
            e.printStackTrace();
        }
    }

    // stergere persoana (impreuna cu excursii, in cascada)
    static void stergePersoana(Connection cnn, String nume) {

        int id_persoana = getIdPersoana(cnn, nume);

        String sql = """
                DELETE FROM persoane WHERE id=?;
                """;

        try (PreparedStatement ps = cnn.prepareStatement(sql)) {

            ps.setInt(1, id_persoana);
            int nr_randuri = ps.executeUpdate();

            System.out.println("\nNr. randuri modificate: " + nr_randuri + "\n");

        } catch (SQLException e) {

            System.out.println(sql);
            e.printStackTrace();
        }

    }






    // functie main
    public static void main(String[] args) throws SQLException {

        String url = "jdbc:mysql://localhost:3306/pj_lab_8";

        Connection cnn = DriverManager.getConnection(url, "root", "sandu2002");
        String sql = "select * from persoane";

        Statement statement;
        statement = cnn.createStatement();

        afisarePersoane(statement);
        afisareExcursii(statement);

        // 1) adaugare persoana
        // adaugaPersoana(cnn);

        // 2) adugare excursie
        // adaugaExcursie(cnn);

        // 3) afisare persoane si excursii
        afisarePersoaneExcursii(statement);

        // 4) afisare excursii persoana (dupa nume)
        afisareExcursiiPersoana(cnn, "Dana Buda");

        // 5) afisarea persoanelor care au vizitat o destinatie
        afisarePersoaneDestinatia(cnn, "Budapesta");

        // 6) afisarea persoanelor care au facut excursii intr-un an introdus
        afisarePersoaneExcursiiAn(cnn, 2019);

        // 7) stergerea unei excursii
        // stergeExcursie(cnn, 8);

        // 8) stergerea unei persoane (impreuna cu excursiile sale)
        stergePersoana(cnn, "Oana Arapu");

    }
}
