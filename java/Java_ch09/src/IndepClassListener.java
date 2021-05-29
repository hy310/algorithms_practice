import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;

public class IndepClassListener extends JFrame {
	
	public IndepClassListener() {
		setTitle("Action 이벤트 리스너 예제");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		
		c.setLayout(new FlowLayout());
		JButton btn = new JButton("Action");    // 버튼 만들기
		// 버튼에 액션 붙이자
		// 버튼이 눌리면 우리가 만든 액션리스너 이름 MyListener 로 가게끔
		btn.addActionListener(new MyListener());
		c.add(btn);    // 버튼 만든 것 붙여주기
		
		setSize(250, 120);
		setVisible(true);
		
	}

	public static void main(String[] args) {
		new IndepClassListener();
	}

}

// 독립된 클래스로 이벤트 리스너 작성
// 버튼 눌렀을 때 작동되게 만들 것임
class MyListener implements ActionListener{
	public void actionPerformed(ActionEvent e) {
		// ActionListener 추상클래스에 대한 메서드 아래에 작성
		JButton b = (JButton)e.getSource();  // 이벤트가 생기면 소스 받아옴
		// 방금 받은 이벤트가 유효하다면
		if(b.getText().equals("Action"))   
			// 이벤트를 받아왔더니 "액션" 이라는 글씨와 똑같다 = 즉 유효한 이벤트이다
			b.setText("액션");    // 텍스트를 한글로 바꿔라
		else
			b.setText("Action");
	}
}