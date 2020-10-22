package wizut.tpsi.employees.model;

import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class EmployeeList {
    
    private static List<Employee> employees = new ArrayList<>();
    
    static {
        DateFormat df = new SimpleDateFormat("dd.MM.yyyy");

        try {           
            Employee e1 = new Employee("Eustachy", "Czartoryski", "https://image.shutterstock.com/z/stock-vector-happy-bald-cartoon-businessman-boss-standing-under-rain-of-money-isolated-314941748.jpg", df.parse("01.10.2007"), null, "prezes", 125000);
            e1.addSkill("praca", "początkujący");
            e1.addSkill("liczenie pieniędzy", "ekspert");
            e1.addSkill("golf", "zaawansowany");
            
            Employee e2 = new Employee("Jan", "Kowalski", "https://pbs.twimg.com/profile_images/547153953289281536/AT2rLPo6.jpeg", df.parse("01.08.2011"), null, "programista", 9000);
            e2.addSkill("Java", "ekspert");
            e2.addSkill("SQL", "zaawansowany");
            e2.addSkill("Spring", "zaawansowany");
            e2.addComment("Wymaga 2kg bananów dziennie");
            e2.addComment("Uwaga! Lubi iskać koleżanki z pracy");
            
            Employee e3 = new Employee("Janina", "Liczykrupa", "https://previews.123rf.com/images/lenm/lenm1011/lenm101100301/8268716-Illustration-Featuring-a-Female-Accountant-Computing-Stock-Illustration.jpg", df.parse("01.10.2007"), null, "księgowa", 6000);
            e3.addSkill("księgowość", "ekspert");
            e3.addSkill("podatki", "ekspert");
            e3.addSkill("humor", "początkujący");
            e3.addComment("Nie drażnić pod koniec miesiąca");
            
            Employee e4 = new Employee("Mariola", "Nowak", "http://orig00.deviantart.net/902a/f/2012/180/d/9/d9c7c5de8f360247cec970c3d33be681-d55bvvy.png", df.parse("06.12.2016"), null, "asystentka prezesa", 27500);
            e4.addSkill("parzenie kawy", "zaawansowany");
            e4.addSkill("odbieranie telefonów", "początkujący");
            e4.addSkill("malowanie paznokci", "ekspert");
            e4.addComment("Miss Opolszczyzny 2016");
            e4.addComment("Nie zwalniać pod żadnym pozorem!!!");
            
            Employee e5 = new Employee("Maurice", "Moss", "http://vignette2.wikia.nocookie.net/theitcrowd/images/a/a9/Moss_with_big_glasses.png/revision/latest?cb=20100903162250", df.parse("01.10.2008"), null, "administrator", 5300);
            e5.addSkill("komputery", "ekspert");
            e5.addSkill("komunikacja interpersonalna", "początkujący");
            
            Employee e6 = new Employee("Zenon", "Webowy", "http://abetteruserexperience.com/wp-content/uploads/2011/11/nerd-619x346.jpg", df.parse("01.03.2008"), df.parse("30.10.2011"), "programista", 7600);
            e6.addSkill("PHP", "ekspert");
            e6.addSkill("JavaScript", "zaawansowany");
            e6.addComment("Zdolny, ale leniwy");
            e6.addComment("Zadrapał samochód prezesa - zwolnić");
            
            Employee e7 = new Employee("Jasio", "Wędrowniczek", "https://s-media-cache-ak0.pinimg.com/originals/7c/84/5f/7c845fb5d113642fdf9ee5ce973ed1e5.jpg", df.parse("01.10.2009"), df.parse("30.12.2012"), "programista", 8200);
            e7.addComment("Nic nie umie - zwolnić");
            
            employees.addAll(Arrays.asList(e1, e2, e3, e4, e5, e6, e7));
            
        } catch (ParseException ex) {
            ex.printStackTrace();
        }
        
    }

    public static List<Employee> getEmployees() {
        return employees;
    }
    
}
