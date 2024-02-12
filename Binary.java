import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JRadioButton;
import javax.swing.JTextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Binary {
    public static void main(String[] args) {
        UI ui = new UI();
    }
}

class UI extends JFrame {
    JRadioButton r1 = new JRadioButton("0");
    JRadioButton r2 = new JRadioButton("1");
    JTextField t1 = new JTextField("0");
    JButton b1 = new JButton("Convert to Decimal");

    public UI() {
        setTitle("Binary");
        setSize(500, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
        setLayout(null);
        t1.setBounds(10, 10, 100, 30);
        r1.setBounds(10, 50, 100, 30);
        r2.setBounds(10, 90, 100, 30);
        b1.setBounds(10, 130, 100, 30);
        add(t1);
        add(r1);
        add(r2);
        add(b1);
        b1.addActionListener(new Convert());
        r1.addActionListener(new Convert());
        r2.addActionListener(new Convert());
    }

    public class Convert implements ActionListener {
        public void actionPerformed(ActionEvent e) {

            int sum = 0;
            if (r1.isSelected()) {
                sum += 1;
            }
            if (r2.isSelected()) {
                sum += 2;
            }
            String text = Integer.toString(sum);
            t1.setText(text);
        }
    }
}