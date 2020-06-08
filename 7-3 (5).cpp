#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Book
{
	char * title;
	char *isbn;
	int price;
public:
	Book(const char * title, const char * isbn, const int price) :price(price)
	{
		this->title = new char[strlen(title) + 1];
		this->isbn = new char[strlen(isbn) + 1];
		strcpy(this->title, title);
		strcpy(this->isbn, isbn);
	}
	void ShowBookInfo()
	{
		cout << "제목: " << title << endl;
		cout << "ISbN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}
	~Book()
	{
		delete[]title;
		delete[]isbn;
	}
};

class EBook : public Book
{
	char *DRMKey;
public:
	EBook(const char * title, const char * isbn, const int price, const char * DRMKey) :Book(title, isbn, price)
	{
		this->DRMKey = new char[strlen(DRMKey) + 1];
		strcpy(this->DRMKey, DRMKey);
	}
	void ShowBookInfo()
	{
		Book::ShowBookInfo();
		cout << "인증키: " << DRMKey << endl;
	}
	~EBook()
	{
		delete[]DRMKey;
	}
};

int main()
{
	Book book("열혈 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	EBook ebook("열혈 C++ ebook", "55-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowBookInfo();
	return 0;
}