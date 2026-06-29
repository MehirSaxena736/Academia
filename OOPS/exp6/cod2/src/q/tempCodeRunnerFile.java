package q;  // Package declaration

import p.A;  // Importing class A from package p

public class B extends A {  // Extending A to access protected members
    public static void main(String[] args) {
        A obj = new A();  // Creating an object of class A

        // Accessing methods based on their access modifiers
        obj.publicMethod();      // ✅ Accessible (public)
        // obj.protectedMethod(); // ❌ Not accessible directly (needs inheritance)
        // obj.defaultMethod();   // ❌ Not accessible (different package)
        // obj.privateMethod();   // ❌ Not accessible (private)

        obj.accessPrivateMethod(); // ✅ Accessing private method indirectly via public method

        // Using inheritance to access protected method
        B objB = new B();
        objB.protectedMethod();  // ✅ Accessible through inheritance
    }
}
