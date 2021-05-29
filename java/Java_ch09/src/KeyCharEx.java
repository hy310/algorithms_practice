import java.awt.Color;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

import javax.swing.JFrame;
import javax.swing.JLabel;

public class KeyCharEx extends JFrame {
	
	JLabel la = new JLabel("<Enter> 키로 배경색이 바뀝니다.");
	
	public KeyCharEx() {
		super("Keyboard Event Example");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		c.add(la);
		c.addKeyListener(new MyKeyListener());
		
		// keyboard 이용하기 때문에 focus 잡아주기
		// 'c 가 focus 다' 라고 해주어야함
		c.setFocusable(true);    // 컨텐트팬이 포커스를 받을 수 있도록 설정
		c.requestFocus();        // 컨텐트팬에 포커스 설정
		
		setSize(250, 150);
		setVisible(true);			
	}
	
	class MyKeyListener extends KeyAdapter {
		@Override
		public void keyPressed(KeyEvent e) {
			// TODO Auto-generated method stub
			// 색을 표현할 r,g,b 정의
			// math 사용하면 소수가 나오니 int 로. color 는 0~255 사이
			int r = (int)(Math.random()*256);     // Math 사용해서 랜덤값 받기
			int g = (int)(Math.random()*256);
			int b = (int)(Math.random()*256);
			
			switch (e.getKeyChar()) {
			case '\n':
				la.setText("r = " + r + ", g = " + g + ", b = " + b);				
				getContentPane().setBackground(new Color(r, g, b));
				
				break;
			case 'q':
				System.exit(0);    // 시스템 완전 종료
			}
			
			super.keyPressed(e);
		}
		
	}
		

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new KeyCharEx();
	}

}
