void showMainMenu();
void showMenuBook();
void showMenuCustomer();
void menuArrange(int countBook);
void saveToFile(int countBook);
void loadFromFile(int *countBook);
void saveToFileCustomer(int countCustomer);
void loadFromFileCustomer(int *countCustomer);
int isLeapYear(int year);
int isValidDate(int day,int month,int year);
int isIdBook(char *id,int countBook);
int isTitle(char *title,int countBook);
void addBook(int *countBook);
void showBook(int *countBook);
int checkBook(int countBook,char check[]);
void changeBook(int countBook);
void deleteBook(int *countBook);
void sortAscending(int countBook);
void sortDescending(int countBook);
void searchBook(int countBook);
int isIdCustomer(char *id,int countBook);
int isPhone(char *phone,int countBook);
void addCustomer(int *countCustomer);
void showCustomers(int countCustomer);
int findMemberIndexById(char id[],int countCustomer);
int findBookIndexById(char id[],int countBook);
void changeCustomer(int countCustomer);
void changeCustomerStatus(int countCustomer);
int checkCustomer(int countCustomer,char temp[]);
void searchCustomer(int countCustomer);
void lendBooks(int countCustomer,int countBook);
void returnBook(int countCustomer,int countBook);
void loginAdmin();
void accountAdmim(int *countAdmin);

