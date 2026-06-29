public class PatternPrinter {
    public static void main(String[] args) {
        int[] rowLengths = {1, 3, 5, 7, 9}; // Length of each row
        char[] symbols = {'?', '#'}; // Alternating symbols

        for (int i = 0; i < rowLengths.length; i++) {
            char symbol = symbols[i % 2]; // Alternate between '?' and '#'
            for (int j = 0; j < rowLengths[i]; j++) {
                System.out.print(symbol + " ");
            }
            System.out.println(); // Move to the next line
        }
    }
}
