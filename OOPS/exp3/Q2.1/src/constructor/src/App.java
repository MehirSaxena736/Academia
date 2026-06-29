class Student{
    String name; // instance variable
    int sapid;
    int yrs;
    int batch;

public Student(String name,int sapid){
    this.name = name;
    this.sapid = sapid;
}
public void setVal(String name,int sapid){
    this.name = name;
    this.sapid = sapid;
}
public Student(){
}
public void prinInfo(){
    System.out.println(name + " : " + sapid + " : " + batch);
}
}
    public class App{
        //Constructor
        //Method overloading is and example of polymorphism.

        public static void main(String[] args) throws Exception):{
            Student s2 = new Student();
            //s2.name = 'Amit';
            //s2.sapid = 12345;
            Student s1 = new Student("Aryan",54321);
            s2.setVal("Amit", 234);
            s2.printInfo();
        }
    }
}

