package ex_2;

public class Vers {

    // membri
    private String line;    // vers
    private Integer wordsNum;   // numar de cuvinte
    private Integer vowelsNum;  // numar de vocale


    // metode

    // constructor
    public Vers(String str) {
        line = str;
        wordsNum = getWordsNum();
        vowelsNum = getVowelsNum();
    }

    // getter
    public String getLine() {
        return line;
    }

    // numarul de cuvinte din vers
    public int getWordsNum() {
        return (line.split(" ").length);
    }

    // numarul de vocale din vers
    public int getVowelsNum() {
        int k = 0;  // contor vocale

        // iteram prin fiecare caracter din vers
        for (int i = 0; i < line.length(); i++) {
            // daca caracterul de pe pozitia i este vocala (minuscula/majuscula)
            if (line.charAt(i)=='a' || line.charAt(i)=='e' ||line.charAt(i)=='i' ||line.charAt(i)=='o' ||line.charAt(i)=='u' || line.charAt(i)=='y'
                || line.charAt(i)=='A' || line.charAt(i)=='E' || line.charAt(i)=='I' || line.charAt(i)=='O' || line.charAt(i)=='U' || line.charAt(i)=='Y') {
                // incrementam contorul
                k++;
            }
        }

        return k;
    }



}
