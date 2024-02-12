import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Division extends JFrame {
    JTextField t1, t2;
    JButton b;
    JLabel l1, l2;

    Division() {
        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize(500, 500);
        setLayout(null);
        t1 = new JTextField("Enter first number");
        t2 = new JTextField("Enter second number");
        b = new JButton("Submit");
        l1 = new JLabel("Result:");
        l2 = new JLabel("");
        t1.setBounds(100, 50, 200, 30);
        t2.setBounds(100, 100, 200, 30);
        b.setBounds(150, 150, 100, 30);
        l1.setBounds(100, 200, 200, 30);
        l2.setBounds(100, 250, 200, 30);
        add(t1);
        add(t2);
        add(b);
        add(l1);
        add(l2);
        b.addActionListener(new Calculate());
    }

    public static void main(String[] args) {
        new Division();
    }

    class Calculate implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            try {
                int num1 = Integer.parseInt(t1.getText());
                int num2 = Integer.parseInt(t2.getText());
                double num3 = num1 / num2;
                l1.setText(Double.toString(num3));
            } catch (NumberFormatException e2) {
                l2.setText("Number is not in format");
            } catch (ArithmeticException e3) {
                l2.setText("Cannot divide by zero");
            }

        }
    }
}
