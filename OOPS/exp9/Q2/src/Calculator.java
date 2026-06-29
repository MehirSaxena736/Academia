import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Calculator {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Calculator");
        JTextField field = new JTextField();
        field.setBounds(30, 40, 280, 30);

        String[] buttons = {
            "1","2","3","+",
            "4","5","6","-",
            "7","8","9","*",
            "0","C","=","/"
        };

        JButton[] btns = new JButton[16];
        StringBuilder current = new StringBuilder();

        for (int i = 0; i < 16; i++) {
            btns[i] = new JButton(buttons[i]);
            btns[i].setBounds(30 + (i % 4) * 70, 80 + (i / 4) * 50, 60, 40);
            frame.add(btns[i]);

            btns[i].addActionListener(e -> {
                String txt = ((JButton)e.getSource()).getText();
                if (txt.equals("=")) {
                    try {
                        field.setText(String.valueOf(eval(current.toString())));
                        current.setLength(0);
                    } catch (Exception ex) {
                        field.setText("Error");
                    }
                } else if (txt.equals("C")) {
                    current.setLength(0);
                    field.setText("");
                } else {
                    current.append(txt);
                    field.setText(current.toString());
                }
            });
        }

        frame.add(field);
        frame.setSize(340, 350);
        frame.setLayout(null);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public static double eval(String expression) {
        try {
            Object result = new javax.script.ScriptEngineManager()
                    .getEngineByName("JavaScript")
                    .eval(expression);
            return ((Number) result).doubleValue();  // Ensure correct conversion to double
        } catch (Exception e) {
            throw new RuntimeException("Invalid Expression");
        }
    }
}
