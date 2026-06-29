public class PrimeNumbers {
    public static void main(String[] args) {
        int count = 0; 

        System.out.println("Prime numbers between 1 and 1000 are:");

    
        for (int i = 2; i <= 1000; i++) {
            if (isPrime(i)) {
                System.out.print(i + " "); 
                count++;
            }
        }

        
        System.out.println("\n\nTotal number of prime numbers between 1 and 1000: " + count);
    }

    
    public static boolean isPrime(int num) {
        if (num <= 1) {
            return false; 
        }
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) {
                return false; 
            }
        }
        return true; 
    }
}
