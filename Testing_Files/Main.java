import java.applet.Applet;
import java.awt.Graphics;

public class WelcomeApplet extends Applet {
  public void paint(Graphics g) {
    g.drawString("Welcome to Applet", 100, 50); // Position (100,50)
  }

  public void init() {
    setSize(300, 300); // Applet size (300x300)
  }
}
