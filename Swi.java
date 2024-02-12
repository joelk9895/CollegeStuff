import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Arrays;
import java.io.*;

public class Swi extends JFrame {
    JButton btn1 = new JButton("Clear");
    JButton btn2 = new JButton("Sort and Save");
    JTextField txt = new JTextField();
    FileWriter fw;

    public Swi() {
        setLayout(null);
        btn1.setBounds(10, 10, 100, 30);
        btn2.setBounds(120, 10, 150, 30);
        txt.setBounds(10, 50, 260, 30);
        add(btn1);
        add(btn2);
        btn1.addActionListener((ActionListener) new Clear());
        btn2.addActionListener((ActionListener) new Sort());
        add(txt);
        setVisible(true);
        setSize(300, 150);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        try {
            fw = new FileWriter("output.txt");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private class Clear implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            txt.setText("");
        }
    }

    private class Sort implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            String text = txt.getText();
            String[] arr = text.split(" ");
            Arrays.sort(arr, String.CASE_INSENSITIVE_ORDER);
            txt.setText("");
            String save = "";
            for (int i = 0; i < arr.length; i++) {
                save += i + " " + arr[i] + "\n";
            }
            try {
                fw.write(save);
                fw.close();
                System.exit(0);
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        new Swi();
    }
}
