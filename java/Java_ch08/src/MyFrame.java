import javax.swing.JFrame;

public class MyFrame extends JFrame{
	
	public MyFrame() {   //������ ����� (main���� �ҷ����� �ٷ� ����ǰԲ�)
		setTitle("first Swing program");
		setSize(300, 300);
		setVisible(true);		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MyFrame frame = new MyFrame();
	}
}
