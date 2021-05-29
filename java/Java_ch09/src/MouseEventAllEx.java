import java.awt.Color;
import java.awt.Component;
import java.awt.Container;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

import javax.swing.JFrame;
import javax.swing.JLabel;

public class MouseEventAllEx extends JFrame{
	private JLabel la = new JLabel(" Move Me");
	
	public MouseEventAllEx() {
		setTitle("MouseListener¿Í MouseMotionListener ¿¹Á¦");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		MyMouseListener listener = new MyMouseListener();
		c.addMouseListener(listener);
		c.addMouseMotionListener(listener);
		
		c.setLayout(null);
		
		la.setSize(80, 20);
		la.setLocation(100, 80);
		c.add(la);
		
		setSize(300, 200);
		setVisible(true);
	}
	
	class MyMouseListener implements MouseListener, MouseMotionListener {

		@Override
		public void mouseDragged(MouseEvent e) {
			// TODO Auto-generated method stub
			la.setLocation(e.getX(), e.getY());
			setTitle("mouseDragged("+e.getX()+","+e.getY()+")");			
		}

		@Override
		public void mouseMoved(MouseEvent e) {
			// TODO Auto-generated method stub
			la.setLocation(e.getX(), e.getY());
			setTitle("mouseMoved("+e.getX()+","+e.getY()+")");		
		}

		@Override
		public void mouseClicked(MouseEvent e) {}

		@Override
		public void mousePressed(MouseEvent e) {
			// TODO Auto-generated method stub
			la.setLocation(e.getX(), e.getY());
			setTitle("mousePressed("+e.getX()+","+e.getY()+")");
		}

		@Override
		public void mouseReleased(MouseEvent e) {
			// TODO Auto-generated method stub
			la.setLocation(e.getX(), e.getY());
			setTitle("mouseReleased("+e.getX()+","+e.getY()+")");
		}

		@Override
		public void mouseEntered(MouseEvent e) {
			// TODO Auto-generated method stub
			Component comp = (Component)e.getSource();
			comp.setBackground(Color.CYAN);			
		}

		@Override
		public void mouseExited(MouseEvent e) {
			// TODO Auto-generated method stub
			Component comp = (Component)e.getSource();
			comp.setBackground(Color.YELLOW);
			setTitle("mouseExcited("+e.getX()+","+e.getY()+")");
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new MouseEventAllEx();
	}
}
