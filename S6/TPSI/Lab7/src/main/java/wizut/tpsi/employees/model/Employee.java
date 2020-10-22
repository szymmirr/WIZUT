package wizut.tpsi.employees.model;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class Employee {
    
    private String firstName;
    private String lastName;
    private String photoUrl;
    
    private Date dateOfEmployment;
    private Date dateOfTermination;
    
    private String jobTitle;
    
    private double salary;
    
    private List<Skill> skills = new ArrayList<>();
    private List<String> comments = new ArrayList<>();

    public Employee() {
    }

    public Employee(String firstName, String lastName, String photoUrl, Date dateOfEmployment, Date dateOfTermination, String jobTitle, double salary) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.photoUrl = photoUrl;
        this.dateOfEmployment = dateOfEmployment;
        this.dateOfTermination = dateOfTermination;
        this.jobTitle = jobTitle;
        this.salary = salary;
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public String getPhotoUrl() {
        return photoUrl;
    }

    public void setPhotoUrl(String photoUrl) {
        this.photoUrl = photoUrl;
    }

    public Date getDateOfEmployment() {
        return dateOfEmployment;
    }

    public void setDateOfEmployment(Date dateOfEmployment) {
        this.dateOfEmployment = dateOfEmployment;
    }

    public Date getDateOfTermination() {
        return dateOfTermination;
    }

    public void setDateOfTermination(Date dateOfTermination) {
        this.dateOfTermination = dateOfTermination;
    }

    public String getJobTitle() {
        return jobTitle;
    }

    public void setJobTitle(String jobTitle) {
        this.jobTitle = jobTitle;
    }

    public double getSalary() {
        return salary;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    public List<Skill> getSkills() {
        return skills;
    }

    public List<String> getComments() {
        return comments;
    }
    
    public void addComment(String comment) {
        comments.add(comment);
    }
    
    public void addSkill(String name, String proficiency) {
        skills.add(new Skill(name, proficiency));
    }
}
