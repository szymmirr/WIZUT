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
public class Student extends Person{
    public Student(String firstName, String lastName, String emailAddress, String groupId){
        super(firstName, lastName, emailAddress, groupId);
        this.groupId = groupId;
    }
    private String groupId;
    private List<Double> grades = new ArrayList<>();

    public String getGroupId() {
        return groupId;
    }

    public void setGroupId(String groupId) {
        this.groupId = groupId;
    }
    
    public List<Double> getGrades(){
        return grades;
    }
    
    public void addGrade(double grade){
        grades.add(grade);
    }
    
    public static void getGradesAverage(){
            System.out.println("oceny");
    }
}
