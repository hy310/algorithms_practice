import java.awt.Color;
import java.awt.Component;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

import javax.swing.JFrame;
import javax.swing.JLabel;

public class KeyCharEx2 extends JFrame {
	
	JLabel la = new JLabel("r=red y=yellow b=blue");
	Container c = getContentPane();
	
	public KeyCharEx2() {
		super("키보드 이벤트 예제 퀴즈 문제1");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
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
		
		JLabel l = (JLabel)e.getSource();
		Component comp = (Component)e.getSource();

		switch (e.getKeyChar()) {
		case 'r':
			l.setText("붉은색입니다");				
			comp.setBackground(Color.RED);
			break;
		case 'b':
			l.setText("파란색입니다");				
			comp.setBackground(Color.BLUE);
			break;
		case 'y':
			l.setText("노란색입니다");				
			comp.setBackground(Color.YELLOW);
			break;
		case 'q':
			System.exit(0); 
		default:
			break;
		}
		
		super.keyPressed(e);
	}
}
