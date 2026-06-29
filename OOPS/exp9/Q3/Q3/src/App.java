import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class ToDoListApp extends JFrame {
    private DefaultListModel<String> listModel;
    private JList<String> taskList;
    private JTextField taskField;
    private JButton addButton, removeButton;

    public ToDoListApp() {
        setTitle("To-Do List");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        // Top Panel with input and buttons
        JPanel topPanel = new JPanel(new FlowLayout());
        taskField = new JTextField(20);
        addButton = new JButton("Add");
        removeButton = new JButton("Remove");

        topPanel.add(taskField);
        topPanel.add(addButton);
        topPanel.add(removeButton);
        add(topPanel, BorderLayout.NORTH);

        // List of tasks
        listModel = new DefaultListModel<>();
        taskList = new JList<>(listModel);
        JScrollPane scrollPane = new JScrollPane(taskList);
        add(scrollPane, BorderLayout.CENTER);

        // Add Button Listener
        addButton.addActionListener(e -> {
            String task = taskField.getText().trim();
            if (!task.isEmpty()) {
                listModel.addElement(task);
                taskField.setText("");
            }
        });

        // Remove Button Listener
        removeButton.addActionListener(e -> {
            int selected = taskList.getSelectedIndex();
            if (selected != -1) {
                listModel.remove(selected);
            }
        });

        setVisible(true);
    }

    public static void main(String[] args) {
        new ToDoListApp();
    }
}

