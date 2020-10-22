package wizut.tpsi.calculator;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
public class CalculatorController {
    
    @Autowired
    private CalculatorService calculatorService;
    
    @PostMapping("/")
    public String home() {
        return "index";
    }
    
    @PostMapping("/add")
    public String addNumbers(Model model, CalculatorForm form) {
        int result = calculatorService.add(form.getX(), form.getY());
        
        form.setOperation("+");
        model.addAttribute("result", result);
        return "result";
    }

    @PostMapping("/multiply")
    public String multiplyNumbers(Model model, CalculatorForm form) {
        int result = calculatorService.multiply(form.getX(), form.getY());
        
        form.setOperation("*");
        model.addAttribute("result", result);
        return "result";
    }

    @PostMapping("/calculate")
    public String doCalculations(Model model, CalculatorForm form) {
        int result = 0;
        switch(form.getOperation()) {
            case "+":
                result = calculatorService.add(form.getX(), form.getY());
                break;
            case "-":
                result = calculatorService.subtract(form.getX(), form.getY());
                break;
            case "*":
                result = calculatorService.multiply(form.getX(), form.getY());
                break;
        }
        
        model.addAttribute("result", result);
        
        return "result";
    }
    
    @GetMapping("/add")
    public String addForm(CalculatorForm form) {
        return "add";
    }

    @GetMapping("/multiply")
    public String multiplyForm(CalculatorForm form) {
        return "multiply";
    }

    @GetMapping("/calculate")
    public String calculateForm(CalculatorForm form) {
        return "calculate";
}
}
