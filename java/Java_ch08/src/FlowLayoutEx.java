import java.awt.Container;
import java.awt.FlowLayout;
import javax.swing.JButton;
import javax.swing.JFrame;

public class FlowLayoutEx extends JFrame{

	public FlowLayoutEx() {
		setTitle("first flow layout");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		// 컨텐트팬 알아내기
		Container contentPane = getContentPane();
		
		// 왼쪽 정렬, 수평 30, 수직 40 FlowLayout
		contentPane.setLayout(new FlowLayout(FlowLayout.LEFT, 30, 40));
		
		contentPane.add(new JButton("add"));
		contentPane.add(new JButton("sub"));
		contentPane.add(new JButton("mul"));
		contentPane.add(new JButton("div"));
		contentPane.add(new JButton("Calculate"));
		
		setSize(300, 200);   // 프레임 크기 300 * 200 설정
		setVisible(true);    // 화면에 프레임 출력
	}
	public static void main(String[] args) {
		new FlowLayoutEx();
	}

}
