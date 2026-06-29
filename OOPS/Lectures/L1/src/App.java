class Human{
public String name;
private int age;
private int phonum;

public void setAge(int age){ // provides access to the privately variables i.e restricted variables
    this.age=age;
}
public int getAge(){
    return age;
}

public void info(){
    System.out.println(name + ":" +age + ":" + phonum);
}
}
public class App{
    public static void main(String[] args) {
        Human h1=new Human();
        h1.name ="Aman";
        h1.setAge( 20);
        int age = h1.getAge();
        System.out.println("Age is " + age );

        
    }// memory allocation of object gives references = memory provided in heap using new
}
// Method Area 
//class Employee{
// instance variable associated with objects
    //private String name;
    //public int id;
    //private int salary;

    //static String companyname="TCS"; // class variable associated with class

    //public Employee(){} //default constructor
    //public Emplyee(String n) {//parameterized constructor
       // Companyname=n;
    //}
    //static{  //static block- one time act karega 
        //companyname="TCS";
   // }
   //public void info(){ method 
   // System.out.println(id+"" +companyname);
   //}
   //public  static void info(){   //public  static void info(Employee obj)
   // System.out.println(id+"" +companyname);// here id is redline because memory is not allocated to id as its object isnot initialized
   //}
//}

