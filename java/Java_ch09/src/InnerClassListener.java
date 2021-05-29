import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;

public class InnerClassListener extends JFrame{
	
	public InnerClassListener() {
		setTitle("내부 클래스를 쓰는 이벤트");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		JButton btn = new JButton("Action");
		btn.addActionListener(new MyActionListener());
		c.add(btn);    // 컨텐트팬 c판에 방금 만든 버튼 붙이기
		
		setSize(200, 120);
		setVisible(true);
		
		}

	// 밖이 아니라 이 안에 쓴다고 해서 내부 클래쓰임
	class MyActionListener implements ActionListener{

		public void actionPerformed(ActionEvent e) {
			JButton b = (JButton)e.getSource();
			if(b.getText().equals("Action"))
				b.setText("액션");
			else
				b.setText("Action");
			
			// 버튼 이름 가져와 title 이름도 바꾸기기
			InnerClassListener.this.setTitle(b.getText());
			
		}
	
	}
	
	public static void main(String[] args) {
		
		new InnerClassListener();

	}

}
