// Interface defining media playback operations
interface Playable {
    void play();
    void pause();
    void stop();
}
// MusicPlayer class implementing Playable interface
class MusicPlayer implements Playable {

    // Overriding play method
    @Override
    public void play() {
        System.out.println("Music is playing.");
    }

    // Overriding pause method
    @Override
    public void pause() {
        System.out.println("Music is paused.");
    }

    // Overriding stop method
    @Override
    public void stop() {
        System.out.println("Music is stopped.");
    }
}
public class TestPlayer {
    public static void main(String[] args) {
        // Creating an instance of MusicPlayer
        Playable player = new MusicPlayer();

        // Testing the functionality
        player.play();
        player.pause();
        player.stop();
    }
}
