class Player {
    String name;
    int age;
    String position;

    public Player(String name, int age, String position) {
        this.name = name;
        this.age = age;
        this.position = position;
    }

    public void play() {
        System.out.println(name + " is playing in position: " + position);
    }

    public void train() {
        System.out.println(name + " is training.");
    }
}

class Cricket_Player extends Player {
    public Cricket_Player(String name, int age, String position) {
        super(name, age, position);
    }

    public void play() {
        System.out.println(name + " is batting or bowling.");
    }
}

class Football_Player extends Player {
    public Football_Player(String name, int age, String position) {
        super(name, age, position);
    }

    public void play() {
        System.out.println(name + " is playing football in position: " + position);
    }
}

class Hockey_Player extends Player {
    public Hockey_Player(String name, int age, String position) {
        super(name, age, position);
    }

    public void play() {
        System.out.println(name + " is playing hockey in position: " + position);
    }
}

public class PlayerDemo {
    public static void main(String[] args) {
        Cricket_Player cricketer = new Cricket_Player("Virat", 34, "Batsman");
        Football_Player footballer = new Football_Player("Messi", 37, "Forward");
        Hockey_Player hockeyPlayer = new Hockey_Player("Dhyan", 29, "Defender");

        cricketer.play();
        cricketer.train();

        footballer.play();
        footballer.train();

        hockeyPlayer.play();
        hockeyPlayer.train();
    }
}

