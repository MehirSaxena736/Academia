class Superclass {
    private int privateVar = 10; 

    public int getPrivateVar() {
        return privateVar; 
    }
}

class Subclass extends Superclass {
    public void display() {
        
        System.out.println("Private variable can'nt be accessed directly.");
        System.out.println("Accessing through method: " + getPrivateVar());
    }
}

public class PrivateMemberDemo {
    public static void main(String[] args) {
        Subclass obj = new Subclass();
        obj.display();
    }

}