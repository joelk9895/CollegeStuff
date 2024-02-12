
/**
 * Thread
 */
import java.util.Scanner;

public class ThreadProg {
    public static void main(String[] args) {
        Inputtaking i = new Inputtaking();
        i.start();
    }
}

class Printing extends Thread {
    String txt = "Hello World";

    @Override
    synchronized public void run() {
        while (true) {
            System.out.println(txt);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class Inputtaking extends Thread {
    String txt;
    Printing p = new Printing();

    @Override
    synchronized public void run() {
        p.start();
        Scanner sc = new Scanner(System.in);
        txt = sc.nextLine();
        p.txt = txt;
        sc.close();
    }
}