#define DATATYPE_H
struct Date{
	int month,day,year;
};
struct Date date[100];

struct Book{
	char bookId[10];
	char title[30];
	char author[20];
	int quantity;
	int price;
	struct Date publication;
};
struct Book book[100];

struct Member{
	char memberId[10];
	char name[20];
	char phone[12];
	char status[10];
	struct Book brrowedBooks[5];
	int borrowedCount;
};
struct Member member[100];

struct Admin{
    char username[20];
    char password[20];
};
struct Admin admin[100];