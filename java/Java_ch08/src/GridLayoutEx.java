import java.awt.Container;
import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;

public class GridLayoutEx extends JFrame{
	
	public GridLayoutEx() {
		setTitle("First Grid Layout Example");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container contentPane = getContentPane();
		
		contentPane.setLayout(new GridLayout(1, 10));
		
		//버튼 10개 만들기
		for(int i=0; i<10; i++) {
			String text = Integer.toString(i);
			JButton button = new JButton(text);
			contentPane.add(button);
		}
		
		setSize(500, 200);
		setVisible(true);
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new GridLayoutEx();

	}

}
