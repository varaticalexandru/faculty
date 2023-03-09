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
        return (int) line.chars().filter(ch -> ch=='e'||ch=='E'||ch=='a'||ch=='A'
            ||ch=='i'||ch=='I'||ch=='o'||ch=='O'||ch=='u'||ch=='U'||ch=='y'||ch=='Y').count();
    }

}
