public class SumDivisibleBy6And9 {

    
    public static int calculateSum(int start, int end) {
        int sum = 0;
        for (int i = start; i <= end; i++) {
            if (i % 6 == 0 && i % 9 == 0) {
                sum += i;
            }
        }
        return sum;
    }

    public static void main(String[] args) {
        int start = 10; 
        int end = 950;  

        
        int result = calculateSum(start, end);

        
        System.out.println("The sum of integers between " + start + " and " + end +
                           " that are divisible by both 6 and 9 is: " + result);
    }
}
