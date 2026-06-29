import java.awt.*;
import java.sql.*;
import javax.swing.*;

public class EmployeeDBApp extends JFrame {
    private JTextField idField, nameField, deptField, salaryField;
    private JButton insertButton, retrieveButton;
    private JTable table;
    private DefaultListModel<String> listModel;

    public EmployeeDBApp() {
        setTitle("Employee DB App");
        setSize(600, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        // Input Panel
        JPanel inputPanel = new JPanel(new GridLayout(5, 2));
        inputPanel.add(new JLabel("ID:"));
        idField = new JTextField();
        inputPanel.add(idField);

        inputPanel.add(new JLabel("Name:"));
        nameField = new JTextField();
        inputPanel.add(nameField);

        inputPanel.add(new JLabel("Department:"));
        deptField = new JTextField();
        inputPanel.add(deptField);

        inputPanel.add(new JLabel("Salary:"));
        salaryField = new JTextField();
        inputPanel.add(salaryField);

        insertButton = new JButton("Insert");
        retrieveButton = new JButton("Retrieve");
        inputPanel.add(insertButton);
        inputPanel.add(retrieveButton);
        add(inputPanel, BorderLayout.NORTH);

        // Table for displaying data
        table = new JTable();
        add(new JScrollPane(table), BorderLayout.CENTER);

        // Button Actions
        insertButton.addActionListener(e -> insertEmployee());
        retrieveButton.addActionListener(e -> retrieveEmployees());

        setVisible(true);
    }

    private void insertEmployee() {
        try {
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/dbname", "root", "yourpassword");
            String query = "INSERT INTO employees (id, name, department, salary) VALUES (?, ?, ?, ?)";
            PreparedStatement pst = con.prepareStatement(query);
            pst.setInt(1, Integer.parseInt(idField.getText()));
            pst.setString(2, nameField.getText());
            pst.setString(3, deptField.getText());
            pst.setDouble(4, Double.parseDouble(salaryField.getText()));
            pst.executeUpdate();
            JOptionPane.showMessageDialog(this, "Employee Inserted Successfully!");
            con.close();
        } catch (Exception ex) {
            JOptionPane.showMessageDialog(this, ex.getMessage());
        }
    }

    private void retrieveEmployees() {
        try {
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/yourdbname", "root", "yourpassword");
            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery("SELECT * FROM employees");

            ResultSetMetaData rsmd = rs.getMetaData();
            int columns = rsmd.getColumnCount();
            String[] columnNames = new String[columns];
            for (int i = 1; i <= columns; i++) {
                columnNames[i - 1] = rsmd.getColumnName(i);
            }

            rs.last();
            int rows = rs.getRow();
            rs.beforeFirst();

            String[][] data = new String[rows][columns];
            int row = 0;
            while (rs.next()) {
                for (int i = 1; i <= columns; i++) {
                    data[row][i - 1] = rs.getString(i);
                }
                row++;
            }

            table.setModel(new javax.swing.table.DefaultTableModel(data, columnNames));
            con.close();
        } catch (Exception ex) {
            JOptionPane.showMessageDialog(this, ex.getMessage());
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new EmployeeDBApp());
    }
}
