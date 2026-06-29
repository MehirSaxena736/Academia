// Define the EventHandler interface
interface EventHandler {
    void handleEvent();
}

// Create a class that demonstrates the use of EventHandler
public class EventDemo {
    // Method to register events
    void registerEvent() {
        // Local Inner Class
        class LocalEventHandler implements EventHandler {
            public void handleEvent() {
                System.out.println("Event handled by local inner class");
            }
        }
        
        LocalEventHandler localHandler = new LocalEventHandler();
        localHandler.handleEvent();
        
        // Anonymous Inner Class
        EventHandler anonymousHandler = new EventHandler() {
            public void handleEvent() {
                System.out.println("Event handled by anonymous inner class");
            }
        };
        
        anonymousHandler.handleEvent();
    }

    // Main method to run the program
    public static void main(String[] args) {
        EventDemo demo = new EventDemo();
        demo.registerEvent();
    }
}
