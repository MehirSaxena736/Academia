import javax.swing.*;

public class LoginForm {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Login Form");

        JLabel userLabel = new JLabel("Username:");
        userLabel.setBounds(50, 50, 100, 30);
        JTextField userField = new JTextField();
        userField.setBounds(150, 50, 150, 30);

        JLabel passLabel = new JLabel("Password:");
        passLabel.setBounds(50, 100, 100, 30);
        JPasswordField passField = new JPasswordField();
        passField.setBounds(150, 100, 150, 30);

        JButton loginBtn = new JButton("Login");
        loginBtn.setBounds(150, 150, 100, 30);

        JLabel result = new JLabel("");
        result.setBounds(150, 190, 200, 30);

        loginBtn.addActionListener(e -> {
            String username = userField.getText();
            String password = new String(passField.getPassword());
            if (username.equals("admin") && password.equals("password")) {
                result.setText("Login successful!");
            } else {
                result.setText("Invalid credentials.");
            }
        });

        frame.add(userLabel);
        frame.add(userField);
        frame.add(passLabel);
        frame.add(passField);
        frame.add(loginBtn);
        frame.add(result);

        frame.setSize(400, 300);
        frame.setLayout(null);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
