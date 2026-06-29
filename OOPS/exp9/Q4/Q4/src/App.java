import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;

public class EmployeeDBApp extends JFrame {
    private JTextField idField, nameField, deptField, salaryField;
    private JButton insertButton, fetchButton;
    private JTable employeeTable;
    private DefaultTableModel tableModel;

    // Database Credentials
    private final String DB_URL = "jdbc:mysql://localhost:3306/company";
    private final String DB_USER = "root";
    private final String DB_PASS = "yourpassword";

    public EmployeeDBApp() {
        setTitle("Employee Management");
        setSize(600, 400);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        // Top Panel for Inputs
        JPanel inputPanel = new JPanel(new GridLayout(5, 2, 5, 5));
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
        fetchButton = new JButton("Fetch All");
        inputPanel.add(insertButton);
        inputPanel.add(fetchButton);
        add(inputPanel, BorderLayout.NORTH);

        // Table to display records
        tableModel = new DefaultTableModel(new String[]{"ID", "Name", "Department", "Salary"}, 0);
        employeeTable = new JTable(tableModel);
        add(new JScrollPane(employeeTable), BorderLayout.CENTER);

        // Insert Button
        insertButton.addActionListener(e -> insertEmployee());
        fetchButton.addActionListener(e -> fetchEmployees());

        setVisible(true);
    }

    private void insertEmployee() {
        try (Connection conn = DriverManager.getConnection(DB_URL, DB_USER, DB_PASS)) {
            String sql = "INSERT INTO employee (id, name, department, salary) VALUES (?, ?, ?, ?)";
            PreparedStatement ps = conn.prepareStatement(sql);
            ps.setInt(1, Integer.parseInt(idField.getText()));
            ps.setString(2, nameField.getText());
            ps.setString(3, deptField.getText());
            ps.setDouble(4, Double.parseDouble(salaryField.getText()));
            ps.executeUpdate();
            JOptionPane.showMessageDialog(this, "Employee inserted successfully!");
        } catch (SQLException ex) {
            JOptionPane.showMessageDialog(this, "Error: " + ex.getMessage());
        }
    }

    private void fetchEmployees() {
        tableModel.setRowCount(0); // Clear existing data
        try (Connection conn = DriverManager.getConnection(DB_URL, DB_USER, DB_PASS)) {
            Statement stmt = conn.createStatement();
            ResultSet rs = stmt.executeQuery("SELECT * FROM employee");
            while (rs.next()) {
                Object[] row = {
                        rs.getInt("id"),
                        rs.getString("name"),
                        rs.getString("department"),
                        rs.getDouble("salary")
                };
                tableModel.addRow(row);
            }
        } catch (SQLException ex) {
            JOptionPane.showMessageDialog(this, "Error: " + ex.getMessage());
        }
    }

    public static void main(String[] args) {
        new EmployeeDBApp();
    }
}

