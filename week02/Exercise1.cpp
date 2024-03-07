#include <iostream>
#include <cstring>

struct Book {
private:
	char title[1024];
	char** authors;
	int authorsCount;
	int published;
	float price;

	void deleteAuthors() {
		for (int i = 0; i < authorsCount; i++) {
			delete[] authors[i];
		}
		delete[] authors;
	}

public:
	Book(const char* title, char** authors, int authorsCount, int published, float price) {
		setTitle(title);
		this->authorsCount = 0;
		setAuthors(authors, authorsCount);
		setPublished(published);
		setPrice(price);
	}

	~Book() {
		deleteAuthors();
	}

	char* getTitle() {
		return title;
	}
	bool setTitle(const char* newTitle) {
		if (newTitle[0] == '\0') return false;

		strcpy(title, newTitle);
		return true;
	}

	int getAuthors() {
		return authorsCount;
	}
	bool setAuthors(char** newAuthors, int count) {
		if (count == 0) return false;

		deleteAuthors();

		authors = new char*[count];
		for (int i = 0; i < count; i++) {
			if (newAuthors[i][0] == '\0') continue;

			authors[i] = new char[strlen(newAuthors[i]) + 1];
			strcpy(authors[i], newAuthors[i]);
		}
		return true;
	}

	int getPublished() {
		return published;
	}
	bool setPublished(int newYear) {
		if (newYear < -2100 || newYear > 2024) return false;

		published = newYear;
		return true;
	}

	float getPrice() {
		return price;
	}
	bool setPrice(float newPrice) {
		if (newPrice <= 0) return false;

		price = newPrice;
		return true;
	}
};

struct Library {
private:
	Book** books;
	int* counts;
	int amountOfBooks;
	int reservedSpace;

	void resize() {
		reservedSpace *= 2;

		Book** newBooks = new Book*[reservedSpace];
		for (int i = 0; i < amountOfBooks; i++) {
			newBooks[i] = books[i];
		}
		delete[] books;
		books = newBooks;

		int* newCounts = new int[reservedSpace];
		for (int i = 0; i < amountOfBooks; i++) {
			newCounts[i] = counts[i];
		}
		delete[] counts;
		counts = newCounts;
	}

	int findBook(const char* title, int year) {
		for (int i = 0; i < amountOfBooks; i++) {
			if (books[i]->getPublished() == year && strcmp(books[i]->getTitle(), title) == 0) {
				return i;
			}
		}
		return -1;
	}

	void deleteBook(int index) {
		delete books[index];

		for (int i = index; i < amountOfBooks - 1; i++) {
			books[i] = books[i+1];
			counts[i] = counts[i+1];
		}

		amountOfBooks--;
		books[amountOfBooks] = nullptr;
	}

public:
	Library() {
		amountOfBooks = 0;
		reservedSpace = 2;
		books = new Book*[reservedSpace];
		counts = new int[reservedSpace];
	}

	~Library() {
		for (int i = 0; i < amountOfBooks; i++) {
			delete books[i];
		}
		delete[] books;
		delete[] counts;
	}

	bool AddBook(Book& book) {
		if (findBook(book.getTitle(), book.getPublished()) > -1)
			return false;

		if (amountOfBooks == reservedSpace)
			resize();

		char** authors = nullptr;
		int authorsCount = book.getAuthors(authors);
		books[amountOfBooks++] = new Book(book.getTitle(), authors, authorsCount, book.getPublished(), book.getPrice());
		return true;
	}
	bool RemoveBook(const char* title, int year) {
		int ind = findBook(title, year);
		if (ind < 0) return false;

		deleteBook(ind);
		return true;
	}

	bool StockBook(const char* title, int year, int stockWith) {
		int ind = findBook(title, year);
		if (ind < 0) return false;

		counts[ind] += stockWith;
		return true;
	}
	bool SellBook(const char* title, int year, int soldCount) {
		int ind = findBook(title, year);
		if (ind < 0) return false;

		counts[ind] -= soldCount;
		return true;
	}
};
