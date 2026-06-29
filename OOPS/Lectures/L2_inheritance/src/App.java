class Parent {     
    int i = 10;     

    public Parent(String n) {         
        System.out.println("Parent constructor is called: " + n);     
    }     

    public void info() {         
        System.out.println("Hello, World! from Parent");     
    }  
} 

class Child extends Parent {     
    int j = 20;     

    public Child() {          
        super("Amit"); // Calls Parent's constructor with a string argument       
        System.out.println("Child constructor is called");
    }         

    @Override
    public void info() {             
        System.out.println("Hello, World! from Child");         
    }         

    public Child callme() {             
       super.info(); // Calls the overridden method in Child class
        return this; // Returning the current instance
    } 
} 

public class App {     
    public static void main(String[] args) {         
        System.out.println("Hello, World!");          

        Child ch = new Child(); // Creating an object of Child class        
        ch.callme();  // Corrected method call

        Parent p = new Child(); // Parent reference holding Child object         
        p.info(); // Calls the overridden method in Child class

        // Child ch1 = new Parent(); // This is NOT allowed as a child cannot reference a parent object directly      
    } 
}
