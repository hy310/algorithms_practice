
public class Book02 {
	String title;
	String author;
	void show() {
		System.out.println(title + " " + author);
	}
	
	public Book02() {
		this("", "");
		System.out.println("������ ȣ���");
	}
	
	public Book02(String title) {
		this(title, "���� �̻�");
	}
	
	public Book02(String title, String author) {
		this.title = title; this.author = author;
	}

	public static void main(String[] args) {
		Book02 littlePrince = new Book02("�����", "�������丮");
		Book02 loveStory = new Book02("������");
		Book02 emptyBook = new Book02();
		loveStory.show();
	}
}
