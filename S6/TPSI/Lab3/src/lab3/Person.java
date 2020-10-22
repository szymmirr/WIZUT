/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab3;

/**
 *
 * @author Student
 */
public class Person{
    private String firstName;
    private String lastName;
    private String emailAddress;
    private String groupId;
    //, String emailAddress, String groupId
    public Person(String firstName, String lastName, String emailAddress, String groupId) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.emailAddress = emailAddress;
        this.groupId = groupId;
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }
    
    @Override
    public String toString()
    {
        return firstName + " " + lastName;
    }

    /*@Override
    public String getEmailAddress() {
        return emailAddress;
    }*/
    
    
}
