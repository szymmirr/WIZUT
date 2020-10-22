/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab3;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.TreeSet;

/**
 *
 * @author Szymek
 */
public class Lab3 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        List<String> nazwiska = new ArrayList<>();
        nazwiska.add("Kowalski");
        nazwiska.add("Nowak");
        
        for(String nazwisko : nazwiska) {
            System.out.println(nazwisko);
        }

        for(int i=0; i<nazwiska.size(); i++) {
            String nazwisko = nazwiska.get(i);
            System.out.println(nazwisko);
        }
        
        Map<String, String> dniTygodnia = new HashMap<>();
        dniTygodnia.put("pn", "poniedziałek");
        dniTygodnia.put("wt", "wtorek");
        dniTygodnia.put("śr", "środa");
        dniTygodnia.put("czw", "czwartek");
        
        String dzien = dniTygodnia.get("pn");
        System.out.println("Skrót 'pn' oznacza: " + dzien);
        
        for(String skrot : dniTygodnia.keySet()) {
            dzien = dniTygodnia.get(skrot);
            System.out.println(skrot + " - " + dzien);
        }
        
        Map<String, Person> osoby = new HashMap<>();
        osoby.put("90010112345", new Person("Jan", "Kowalski","",""));
        
        Map<Integer, List<Student>> grupy = new HashMap<>();

        List<Student> grupa32 = new ArrayList<>();
        grupa32.add(new Student("Jan", "Kowalski","",""));
        grupa32.add(new Student("Zenon", "Nowak","",""));

        grupy.put(32, grupa32);
        
        Set<String> zbiorDni = new TreeSet<>();
        zbiorDni.add("poniedziałek");
        zbiorDni.add("wtorek");

        System.out.println(zbiorDni);
        System.out.println();
        zbiorDni.add("poniedzialek");
        zbiorDni.add("wtorek");
        zbiorDni.add("sroda");
        zbiorDni.add("czwartek");
        zbiorDni.add("piatek");
        zbiorDni.add("sobota");
        zbiorDni.add("niedziela");
        System.out.println(zbiorDni);
        
        for(String dzien2 : zbiorDni) {
            System.out.println(dzien2);
        }
        
        Map<String, String> nauczyciele = new HashMap<>();
        nauczyciele.put("matematyka", "Jan Kowalski");
        nauczyciele.put("programowanie obiektowe", "Janusz Kowal");
        nauczyciele.put("programowanie strukturalne", "Janina Kowalska");
        
        String nauczyciel = nauczyciele.get("programowanie obiektowe");
        System.out.println("Programowania obiektowego uczy: " + nauczyciel);
        
        List<Student> grupa33 = new ArrayList<>();
        grupa33.add(new Student("Karol", "Karolewski","",""));
        grupa33.add(new Student("Karol", "Karolak","",""));
        grupy.put(33, grupa33);
        
        List<Student> grupa34 = new ArrayList<>();
        grupa34.add(new Student("Grzegorz", "Osinski","",""));
        grupa34.add(new Student("Kaziemierz", "Wielki","",""));
        grupy.put(34, grupa34);
        
        Map<String, List<Student>> numerListy = new HashMap<>();
        numerListy.put("32", grupa32);
        numerListy.put("33", grupa33);
        numerListy.put("34", grupa34);
        
        for(String skrot : numerListy.keySet()) {
            //String studenci = numerListy.get(skrot);
            //System.out.println(skrot + " - " + dzien);
        }
        System.out.println(new File(".").getAbsoluteFile());

        List<Product> custArr = new ArrayList<Product>();
        try(BufferedReader in = new BufferedReader(new FileReader("produkty.txt"))) {
            String s = in.readLine();
            while(s!=null) {
                
                s = in.readLine();
                System.out.println(s);
                //String linia = "10;poniedziałek";
                String[] pola = s.split(";");
                System.out.println(" ");
                System.out.println(pola[0]);   // 10
                System.out.println(pola[1]);   // poniedziałek
                System.out.println(pola[2]);   // poniedziałek
                System.out.println(pola[3]);   // poniedziałek
                double d = Double.parseDouble(pola[3]);
                custArr.add(new Product(pola[0], pola[1], d, pola[2]));
            }
        } catch (IOException ex) {
            ex.printStackTrace();
        }
        
    }
    
}
