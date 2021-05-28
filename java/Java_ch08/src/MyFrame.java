import javax.swing.JFrame;

public class MyFrame extends JFrame{
	
	public MyFrame() {   //생성자 만들기 (main에서 불러오면 바로 실행되게끔)
		setTitle("first Swing program");
		setSize(300, 300);
		setVisible(true);		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MyFrame frame = new MyFrame();
	}
}
