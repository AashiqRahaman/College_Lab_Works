package theoryException;

import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.Graphics;

class WelcomePanel extends JPanel {
    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.drawString("Welcome to Java Swing", 100, 50);
    }
}

public class ThreadAppleat {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Welcome App");
        frame.setSize(300, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        WelcomePanel panel = new WelcomePanel();
        frame.add(panel);

        frame.setVisible(true);
    }
}

