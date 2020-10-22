/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab2;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Student
 */

public class Lab2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        //Person p1 = new Person("Bill","Gates","bill@ms.com");
        //Person p2 = new Person("Gal","Anonim","gal@anonim.eu");
        
        //System.out.println(p1);
        //System.out.println(p2);
        
        University zut = new University("Zachoniopomorski", "zut@zut.pl");
        University wsks = new University("Wyzsza szkola", "wsks@wsks.pl");
        
        Person s1 = new Student("Jan", "Kowalski", "jan@j.pl", "32A");
        Person s2 = new Student("Helmut", "Nowak", "hn@zut.pl", "32A");
        Person t1 = new Teacher("B", "S", "bs@mail.com", "Intro");
        
        EmailRecipient[] spamList = new EmailRecipient[5];
        spamList[0] = zut;
        spamList[1] = wsks;
        spamList[2] = s1;
        spamList[3] = s2;
        spamList[4] = t1;
        
        for(EmailRecipient recipient : spamList) {
            String email = recipient.getEmailAddress();
            System.out.println(email);
        }
        
        List<String> kolory = new ArrayList<>();

        kolory.add("czerwony");
        kolory.add("niebieski");
        kolory.add("zielony");

        for(String kolor : kolory) {
            System.out.println(kolor);
        }
        
        Student.getGradesAverage();
        
    }
    
    
    
}
