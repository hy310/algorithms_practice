import java.awt.Container;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class NullContainerEx extends JFrame{
	
	public NullContainerEx() {
		setTitle("배치관리자 없이 절대 위치에 배치하는 예제");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container contentPane = getContentPane();
		//컨텐트팬의 배치관리자 제거
		contentPane.setLayout(null);
		
		JLabel la = new JLabel("Hello, Press Buttons!");
		la.setLocation(130, 50);
		la.setSize(200, 20);
		contentPane.add(la);  // la 를 컨텐트팬에 부착
		
		// 9개의 버튼 컴포넌트 생성, 동일한 크기 설정, 위치는 서로 겹치게
		for(int i=1; i<=9; i++) {
			JButton b = new JButton(Integer.toString(i)); //버튼생성
			b.setLocation(i*15, i*15);    // 버튼의 위치 설정
			b.setSize(50, 20);    // 버튼의 크기는 동일하게
			contentPane.add(b);
		}
		
		setSize(300, 200);
		setVisible(true);
	}

	public static void main(String[] args) {
		new NullContainerEx();
	}

}
