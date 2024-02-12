public class Office {
    public static void main(String[] args) {
        Officer officer = new Officer();
        officer.Employee("John", 50000, 30, 1234567890, "IT");
        officer.printSalary();

        Manager manager = new Manager();
        manager.Employee("Mary", 100000, 40, 1234567890, "IT");
        manager.printSalary();
    }
}

class Employee {
    String name;
    long Salary;
    int age;
    long phoneNumber;

    void printSalary() {
        System.out.println("Salary: $" + Salary);
    }
}

class Officer extends Employee {
    String specialization;

    void Employee(String name, long Salary, int age, long phoneNumber, String specialization) {
        this.name = name;
        this.Salary = Salary;
        this.age = age;
        this.phoneNumber = phoneNumber;
        this.specialization = specialization;
    }
}

class Manager extends Employee {
    String department;

    void Employee(String name, long Salary, int age, long phoneNumber, String department) {
        this.name = name;
        this.Salary = Salary;
        this.age = age;
        this.phoneNumber = phoneNumber;
        this.department = department;
    }
}
