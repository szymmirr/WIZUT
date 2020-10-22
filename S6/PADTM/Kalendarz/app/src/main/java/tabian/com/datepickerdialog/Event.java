import java.util.Date;

public class Event {

    public enum TypZadania {
    POJEDYNCZE,
    CYKLICZNE,
    NIESTANDARDOWE
    }

    public enum Priorytet{
    BARDZO_WAZNE,
    WAZNE,
    NORMALNE,
    MALO_WAZNE
    }

    public String nazwa;
    TypZadania typZadania;
    Priorytet priorytet;
    Boolean powiadomienie;
    Date poczatek_wydarzenia;
    Date koniec_wydarzenia;
    Adres adres;


    public Event (String nazwa, TypZadania typZadania, Priorytet priorytet, Date poczatek_wydarzenia, Date koniec_wydarzenia) {
        this.nazwa=nazwa;
        this.typZadania=typZadania;
        this.priorytet=priorytet;

        this.poczatek_wydarzenia=poczatek_wydarzenia;
        this.koniec_wydarzenia=koniec_wydarzenia;
    }

    public Event (String nazwa, TypZadania typZadania, Priorytet priorytet, Date poczatek_wydarzenia, Date koniec_wydarzenia, Adres adres) {
        this.nazwa=nazwa;
        this.typZadania=typZadania;
        this.priorytet=priorytet;

        this.adres=adres;
        this.poczatek_wydarzenia=poczatek_wydarzenia;
        this.koniec_wydarzenia=koniec_wydarzenia;
    }

    public void setNazwa(String nazwa) {
        this.nazwa = nazwa;
    }

    public String getNazwa() {
        return nazwa;
    }

    public void setPriorytet(Priorytet priorytet) {
        this.priorytet = priorytet;
    }

    public Priorytet getPriorytet() {
        return priorytet;
    }

    public void setTypZadania(TypZadania typZadania) {
        this.typZadania = typZadania;
    }

    public TypZadania getTypZadania() {
        return typZadania;
    }
}