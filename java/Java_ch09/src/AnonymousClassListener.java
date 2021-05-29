import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;

public class AnonymousClassListener extends JFrame{
	public AnonymousClassListener() {
		setTitle("�͸�Ŭ������ Action �̺�Ʈ ������ �����");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		JButton btn = new JButton("Action");
//		btn.addActionListener(new MyActionListener());
		btn.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				JButton b = (JButton)e.getSource();
				if(b.getText().equals("Action"))
					b.setText("�׼�");
				else
					b.setText("Action");
				setTitle(b.getText());
			}
		});
		
		c.add(btn);
		
		setSize(350, 150);
		setVisible(true);
	}
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new AnonymousClassListener();

	}

}
