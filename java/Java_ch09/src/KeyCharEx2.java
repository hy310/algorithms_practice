import java.awt.Color;
import java.awt.Component;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.text.JTextComponent;

public class KeyCharEx2 extends JFrame {
	
	JLabel la = new JLabel("r=red y=yellow b=blue");
	Container c = getContentPane();
	
	public KeyCharEx2() {
		super("키보드 이벤트 예제 퀴즈 문제1");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
//		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		c.add(la);
		c.addKeyListener(new MyKeyListener());
		
		c.setFocusable(true);
		c.requestFocus();
		
		setSize(250, 150);
		setVisible(true);			
	}
		
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new KeyCharEx2();
	}
}

class MyKeyListener extends KeyAdapter {
	@Override
	public void keyPressed(KeyEvent e) {
		// TODO Auto-generated method stub
		
		Component c = (Component)e.getSource();
		JLabel la2 = new JLabel();

		switch (e.getKeyChar()) {
		case 'r':
			la2.setText(la2.getText() + e.getKeyChar());		
			c.setBackground(Color.RED);
			break;
		case 'b':
//			la2.setText("파란색입니다");				
			c.setBackground(Color.BLUE);
			break;
		case 'y':
//			la2.setText("노란색입니다");				
			c.setBackground(Color.YELLOW);
			break;
		case 'q':
			System.exit(0); 
		default:
			break;
		}
		
		super.keyPressed(e);
	}

	private void JTextComponent() {
		// TODO Auto-generated method stub
		
	}
}
