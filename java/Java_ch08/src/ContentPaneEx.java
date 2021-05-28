import java.awt.Color;
import java.awt.Container;
import java.awt.FlowLayout;
import javax.swing.JButton;
import javax.swing.JFrame;

public class ContentPaneEx extends JFrame {
	
	public ContentPaneEx() {     // 생성자
		setTitle("3 buttons example");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		// 창을 닫으면 (스윙) 도 종료. 창닫으면서 프로그램도 종료시켜라
		
		// 바닥판 오렌지 색깔로 만들기
		Container contentPane = getContentPane();
		contentPane.setBackground(Color.ORANGE);
		
		//배치관리자
		contentPane.setLayout(new FlowLayout()); // 일렬로
		
		// 버튼 만들기
		// 버튼도 결국 contentPane 위에 넣는 것임
		// Jbutton 의 외부 클래스를 선언해서 사용할 것임
		// 그럴려면 ~~~ = new ~~ 이런식으로 해야하는데 아까처럼 축약해서 사용해도 됨
		contentPane.add(new JButton("OK"));
		contentPane.add(new JButton("Cancel"));
		contentPane.add(new JButton("Ignore"));
		
		setSize(300, 150);
		setVisible(true);
	}
	
	public static void main(String[] args) {
		//ContentPaneEx content = new ContentPaneEx();
		// 위를 더 축약할 수 있음. 어차피 content 라는 이름 쓰지 않음
		
		new ContentPaneEx();
		
	}

}
