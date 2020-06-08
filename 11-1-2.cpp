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
	Book(const Book& ref) : price(ref.price)
	{
		this->title = new char[strlen(ref.title) + 1];
		this->isbn = new char[strlen(ref.isbn) + 1];
		strcpy(this->title, ref.title);
		strcpy(this->isbn, ref.isbn);
	}
	Book& operator=(Book& ref)
	{
		delete title;
		delete isbn;
		this->title = new char[strlen(ref.title) + 1];
		this->isbn = new char[strlen(ref.isbn) + 1];
		strcpy(this->title, ref.title);
		strcpy(this->isbn, ref.isbn);
		price = ref.price;
		return *this;
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
	EBook(const EBook& ref) : Book(ref)
	{
		this->DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(this->DRMKey, ref.DRMKey);
	}
	EBook& operator=(EBook& ref)
	{
		Book::operator=(ref);
		delete []DRMKey;
		this->DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(this->DRMKey, ref.DRMKey);
		return *this;
		
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
	EBook ebook1("열혈 C++", "555-12345-890-0", 20000,"gjhjhh");
	EBook ebook2 = ebook1;
	ebook2.ShowBookInfo();
	cout << endl;
	EBook ebook3("dumy", "dumy", 10000, "fdx9w0i8kiw");
	ebook3 = ebook2;
	ebook3.ShowBookInfo();
	return 0;
}