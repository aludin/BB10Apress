import bb.cascades 1.0

Page {
    Container{
    PersonEntry {
        employeeNumber: 100
        surname: "Smith"
        firstname: "John"
        jobTitle: "Jack of All Trades"
        picture: "asset:///johnsmith.png"
        
        onSalaryChanged: {
            salaryLabel.text = "Salary: "+newSalary;
        }
    }
    Label{
        id: salaryLabel
        
    }
    }
    
}
