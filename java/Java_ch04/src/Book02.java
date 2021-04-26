
public class Book02 {
	String title;
	String author;
	void show() {
		System.out.println(title + " " + author);
	}
	
	public Book02() {
		this("", "");
		System.out.println("생성자 호출됨");
	}
	
	public Book02(String title) {
		this(title, "작자 미상");
	}
	
	public Book02(String title, String author) {
		this.title = title; this.author = author;
	}

	public static void main(String[] args) {
		Book02 littlePrince = new Book02("어린왕자", "생텍쥐페리");
		Book02 loveStory = new Book02("춘향전");
		Book02 emptyBook = new Book02();
		loveStory.show();
	}
}
