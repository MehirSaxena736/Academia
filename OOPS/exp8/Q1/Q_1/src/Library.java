class Library {
    static class Book {
        String title;
        String author;
        String ISBN;

        Book(String title, String author, String ISBN) {
            this.title = title;
            this.author = author;
            this.ISBN = ISBN;
        }

        void displayDetails() {
            System.out.println("Title: " + title);
            System.out.println("Author: " + author);
            System.out.println("ISBN: " + ISBN);
        }
    }

    public static void main(String[] args) {
        Book book = new Book("Java Programming", "John Doe", "1234567890");
        book.displayDetails();
    }
}
