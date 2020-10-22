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
public class Teacher extends Person{
    public Teacher(String firstName, String lastName, String emailAddress, String groupId) {
        super(firstName, lastName, emailAddress, groupId);
        this.courseName = courseName;
    }
    private String courseName;

    public String getCourseName() {
        return courseName;
    }

    public void setCourseName(String courseName) {
        this.courseName = courseName;
    }
    
    
}
