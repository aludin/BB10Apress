import bb.cascades 1.0
Container {
    id: root
    property int    employeeNumber
    property string surname
    property string firstname
    property string jobTitle
    property alias  picture: employeeImage.imageSource 
    
    signal salaryChanged(double newSalary)
    
    
    function getLogin(){
        return root.firstname.charAt(0).toLowerCase() + root.surname.toLowerCase();
    }
    
    function getEmail(){
        return root.firstname.toLowerCase() +"."+root.surname.toLowerCase()+"@mycompany.com";
    }
    
    onCreationCompleted: {
        switch (jobTitle) {
            case "Software Engineer":
                jobs.selectedIndex = 1;
                break;
            case "Manager":
                jobs.selectedIndex = 2;
                break;
            case "Director":
                jobs.selectedIndex = 3;
                break;
            case "Technician":
                jobs.selectedIndex = 4;
                break;
            default:
                jobs.selectedIndex = 0;
        }
    }
    
    ImageView {
        id: employeeImage
        horizontalAlignment: HorizontalAlignment.Center
    }
    
    Label{
        text: "MyCompany Employee Details"
        textStyle.base: SystemDefaults.TextStyles.TitleText
        horizontalAlignment: HorizontalAlignment.Center
    }

    Label {
        text: "Employee number: " + employeeNumber;
    }

    Label {
        text: "Last name: " + surname;
    }

    Label {
        text: "First name:" + firstname;
    }

    Label {
        text: "Login: " + root.getLogin();
    }
    Label {
        text: "Email: " + root.getEmail();
    }
    DropDown {
        id: jobs
        title: "Job Title"
        enabled: true

        onSelectedIndexChanged: {
            console.debug("SelectedIndex was changed to " + selectedIndex);
            console.debug("Selected option is: "+selectedOption.text);
            root.jobTitle = selectedOption.text;
            switch (selectedOption.text){
                case "Software Engineer":
                    root.salaryChanged(90000);
                    break;
                case "Manager":
                    root.salaryChanged(100000);
                    break;
                case "Director":
                    root.salaryChanged(150000);
                    break;
                case "Technician":
                    // yes technician should be rewarded
                    root.salaryChanged(160000);
                    break;
                default:
                    root.salaryChanged(0.0);    
            }
        }
        
        Option{
            text: "Unknown"
        }

        Option {
            text: "Software Engineer"
        }
        
        Option {
            text: "Manager"
        }
        
        Option {
            text: "Director"
        }
        
        Option {
            text: "Technician"
        }

    }

}











