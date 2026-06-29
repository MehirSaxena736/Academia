// Declaring a final class
final class Logger {
    // Method to log messages
    void logMessage(String message) {
        System.out.println("Log: " + message);
    }
}
public class Main {
    public static void main(String[] args) {
        // Creating an instance of Logger
        Logger logger = new Logger();

        // Calling the logMessage method
        logger.logMessage("This is a log message.");
    }
}
/* 
// Attempting to inherit a final class (This will cause an error)
class ExtendedLogger extends Logger {
    // This class will not compile because Logger is final.
    }
*/