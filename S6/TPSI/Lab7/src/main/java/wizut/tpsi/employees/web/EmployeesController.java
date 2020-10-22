package wizut.tpsi.employees.web;

import wizut.tpsi.employees.model.Employee;
import wizut.tpsi.employees.model.EmployeeList;
import java.util.List;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
public class EmployeesController {
    
    @RequestMapping("/")
    public String home(Model model) {
        List<Employee> employees = EmployeeList.getEmployees();
        
        Employee boss = employees.get(0);
        
        model.addAttribute("boss", boss);
        model.addAttribute("employees", employees);
        return "employees";
    }

}
