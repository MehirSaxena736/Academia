
class MathConstants {
    // Final variable
    final double PI = 3.14159;

    
    final void displayPI() {
        System.out.println("The value of PI is: " + PI);
    }
}

class Circle extends MathConstants {

    
    void calculateArea(double radius) {
        double area = PI * radius * radius;
        System.out.println("Area of the circle with radius " + radius + " is: " + area);
    }
    // Uncommenting the below method will cause a compilation error
    // because final methods cannot be overridden.
    /*
    @Override
    void displayPI() {
        System.out.println("Trying to override final method.");
    }
    */

   
}
public class Main {
    public static void main(String[] args) {
        
        Circle myCircle = new Circle();

        
        myCircle.displayPI();

        
        myCircle.calculateArea(5.0);

        /*
        myCircle.PI = 3.14; // Error: Cannot assign a value to final variable 'PI'
        */
    }
}
