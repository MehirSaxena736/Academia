package p;  // Package declaration

public class A {
    public void publicMethod() {
        System.out.println("Public Method: Accessible anywhere.");
    }

    protected void protectedMethod() {
        System.out.println("Protected Method: Accessible within the same package or subclass.");
    }

    void defaultMethod() {
        System.out.println("Default Method: Accessible within the same package.");
    }

    private void privateMethod() {
        System.out.println("Private Method: Accessible only within this class.");
    }

    // Public method to indirectly access privateMethod (for testing purposes)
    public void accessPrivateMethod() {
        privateMethod();
    }
}
