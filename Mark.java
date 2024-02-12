import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileReader;

public class Mark extends JFrame {
    JButton btn1 = new JButton("Import Data");
    JButton btn2 = new JButton("Calculate");
    JTextArea txt1 = new JTextArea();
    JLabel lbl = new JLabel("Enter Marks");
    JTextArea txt2 = new JTextArea();

    public static void main(String[] args) {
        Mark s = new Mark();
    }

    public Mark() {
        setTitle("Mark");
        setSize(500, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
        setLayout(null);
        txt1.setBounds(10, 10, 150, 70);
        lbl.setBounds(10, 50, 100, 30);
        btn1.setBounds(10, 90, 100, 30);
        btn2.setBounds(10, 130, 100, 30);
        txt2.setBounds(10, 170, 150, 70);
        add(txt1);
        add(lbl);
        add(btn1);
        add(btn2);
        add(txt2);
        btn1.addActionListener(new Import());
        btn2.addActionListener(new Calculate());
    }

    public class Import implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            try {
                FileReader fr = new FileReader("Marl.txt");
                int i;
                String text = "";
                while ((i = fr.read()) != -1) {
                    text += (char) i;
                }
                String[] lines = text.split("\n");
                int count = 0;
                String text2 = "";
                System.out.println(lines[0]);
                for (count = 3; count < lines.length; count++) {
                    text2 += lines[count] + "\n";
                }
                txt1.setText(text2);
                fr.close();
            } catch (Exception ex) {
                ex.printStackTrace();
            }
        }
    }

    public class Calculate implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            String text = txt1.getText();
            String[] arr = text.split("\n");
            String text2 = "";
            int sum = 0;
            for (String i : arr) {
                String[] marks = i.split(" ");
                for (int j = 2; j < marks.length; j++) {
                    sum += Integer.parseInt(marks[j]);
                }
                text2 += marks[0] + " " + marks[1] + " " + sum + "\n";
                sum = 0;
            }
            txt2.setText(text2);
        }
    }
}
