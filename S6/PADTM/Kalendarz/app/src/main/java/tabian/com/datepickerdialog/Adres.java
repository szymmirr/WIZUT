
public class Adres { //do dostosowania jak się pojawi konwencja do GPS

    public String miasto;
    public String ulica;
    public String numer;

    public Adres(String miasto, String ulica, String numer)
    {
       this.miasto=miasto;
       this.ulica=ulica;
       this.numer=numer;
    }

    public void setMiasto(String miasto) {
        this.miasto = miasto;
    }

    public String getMiasto() {
        return miasto;
    }

    public void setNumer(String numer) {
        this.numer = numer;
    }

    public String getNumer() {
        return numer;
    }

    public void setUlica(String ulica) {
        this.ulica = ulica;
    }

    public String getUlica() {
        return ulica;
    }
}

