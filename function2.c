#include<stdio.h>
#include<string.h>
#include "datatype.h"
#include<windows.h>
#include<ctype.h>
void showMainMenu(){
	printf("\n|=========== MENU ===========|\n");
	printf("|============================|\n");
	printf("| [1]. Book Management       |\n");
	printf("| [2]. Customer Management   |\n");
	printf("| [3]. Admin                 |\n");
	printf("| [0]. Exit The Program      |\n");
	printf("|============================|\n");
	printf(" Enter The Choice: ");
}
void showMenuBook(){
	printf("\n|======== Book Management =========|\n");
	printf("|==================================|\n");
	printf("|   [1]. Add a new book            |\n");
	printf("|   [2]. Show Book                 |\n");
	printf("|   [3]. Change Book               |\n");
	printf("|   [4]. Delete Book               |\n");
	printf("|   [5]. Sort By Price             |\n");
	printf("|   [6]. Search Book               |\n");
	printf("|   [0]. Exit The Program          |\n");
	printf("|==================================|\n");
	printf(" Enter The Choice: ");
}
void showMenuCustomer(){
	printf("\n|======== Customer Management ========|\n");
	printf("|=====================================|\n");
	printf("|  [1]. Add Customers                 |\n");
	printf("|  [2]. Show All Customers            |\n");
	printf("|  [3]. Edit Customer Information     |\n");
	printf("|  [4]. Lock (Unlock) The Customer    |\n");
	printf("|  [5]. Search Customer               |\n");
	printf("|  [6]. Lend Books                    |\n");
	printf("|  [7]. Return Book                   |\n");
	printf("|  [0]. Exit The Program              |\n");
	printf("|=====================================|\n");
	printf(" Enter The Choice: ");
}
void saveToFile(int countBook){
    FILE *file=fopen("book2.dat","wb");
    if(file==NULL){
        printf("Khong the mo file de ghi\n");
        return;
    }
    fwrite(book,sizeof(struct Book),countBook,file);
    fclose(file);
}
void loadFromFile(int *countBook){
    FILE *file=fopen("book2.dat","rb");
    if(file==NULL){
        printf("Khong the doc file\n");
        *countBook=0;
        return;
    }
    int numRead=fread(book,sizeof(struct Book),100,file);
    if(numRead==0){
        printf("File rong hoac loi khi doc du lieu\n");
    }
    *countBook=numRead;
    fclose(file);
}
void saveToFileCustomer(int countCustomer){
    FILE *file=fopen("Customer2.dat","wb");
    if(file==NULL){
        printf("Khong the mo file de ghi\n");
        return;
    }
    fwrite(member,sizeof(struct Member),countCustomer,file);
    fclose(file);
}
void loadFromFileCustomer(int *countCustomer){
    FILE *file=fopen("customer2.dat","rb");
    if(file==NULL){
        printf("Khong the doc file\n");
        *countCustomer=0;
        return;
    }
    int numRead=fread(member,sizeof(struct Member),100,file);
    if(numRead==0){
        printf("File rong hoac loi khi doc du lieu\n");
    }
    *countCustomer=numRead;
    fclose(file);
}
int isLeapYear(int year){
    if((year%4==0&&year%100!=0)||(year%400==0)){
    	return 1;
	}
    return 0;
}
int isValidDate(int day,int month,int year){
    if(year<1){
    	return 0;
	}
    if(month<1||month>12){
    	return 0;
	}
    int dayInMonth[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(month==2&&isLeapYear(year)){
        dayInMonth[2]=29;
    }
    if(day<1||day>dayInMonth[month]){
    	return 0;
	}
    return 1;
}
int isIdBook(char *id,int countBook){
    for(int i=0;i<countBook;i++){
        if(strcmp(book[i].bookId,id)==0){
            printf("ID da ton tai\n");
            return 1;
        }
    }
    return 0;
}
int isTitle(char *title,int countBook){
    for(int i=0;i<countBook;i++){
        if(strcmp(book[i].title,title)==0){
            printf("tieu de da ton tai\n");
            return 1;
        }
    }
    return 0;
}
void addBook(int *countBook){
	do{
		do{
        	printf("moi ban nhap ID: ");
        	fgets(book[*countBook].bookId,sizeof(book[*countBook].bookId),stdin);
        	book[*countBook].bookId[strcspn(book[*countBook].bookId,"\n")]='\0';
        	if(strlen(book[*countBook].bookId)==0){
            	printf("ID khong duoc de trong!\n");
        	}else if(strlen(book[*countBook].bookId)>9){
            	printf("ID qua dai toi da 9 ky tu\n");
        	}
    	}while(strlen(book[*countBook].bookId)==0||strlen(book[*countBook].bookId)>10);
    }while(isIdBook(book[*countBook].bookId,*countBook));
    do{
    	do{
        	printf("moi ban nhap tieu de: ");
        	fgets(book[*countBook].title,sizeof(book[*countBook].title),stdin);
        	book[*countBook].title[strcspn(book[*countBook].title,"\n")] ='\0';
        	if(strlen(book[*countBook].title)==0){
            	printf("khong duoc de trong\n");
        	}else if(strlen(book[*countBook].title)>29){
            	printf("tieu de qua dai toi da 29 ky tu\n");
        	}
    	}while(strlen(book[*countBook].title)==0||strlen(book[*countBook].title)>30);
    }while(isTitle(book[*countBook].title,*countBook));
    do{
        printf("moi ban nhap tac gia: ");
        fgets(book[*countBook].author,sizeof(book[*countBook].author),stdin);
        book[*countBook].author[strcspn(book[*countBook].author,"\n")]='\0';
        if(strlen(book[*countBook].author)==0){
            printf("tac gia khong duoc de trong\n");
        }else if (strlen(book[*countBook].author)>20){
            printf("ten tac gia qua dai toi da 19 ky tu\n");
        }
    }while(strlen(book[*countBook].author)==0||strlen(book[*countBook].author)>20);
    do{
        printf("moi ban nhap so luong: ");
        if(scanf("%d",&book[*countBook].quantity)!=1||book[*countBook].quantity<=0){
        	getchar();
            printf("so luong la so nguyen duong\n");
            while(getchar()!='\n');
        }else{
            break;
        }
    }while(1);
	do{
        printf("Moi ban nhap gia: ");
        if(scanf("%d",&book[*countBook].price)!=1||book[*countBook].price<=0){
        	getchar();
            printf("So luong la so nguyen duong\n");
            while(getchar()!='\n');
        }else{
            break;
        }
    }while(1);
	do{
		printf("Moi ban nhap ngay xuat ban(dd mm yyyy): ");
        scanf("%d %d %d",&book[*countBook].publication.day,&book[*countBook].publication.month,&book[*countBook].publication.year);
        getchar();
        if (!isValidDate(book[*countBook].publication.day,book[*countBook].publication.month,book[*countBook].publication.year)){
        	printf("Ngay khong hop le\n");
        	}   	
    }while(!isValidDate(book[*countBook].publication.day,book[*countBook].publication.month,book[*countBook].publication.year));
	(*countBook)++;
	saveToFile(*countBook);
	printf("them sach thanh cong\n");
}
void showBook(int *countBook){
	if(*countBook==0){
		printf("khong co sach de hien thi");
		return;
	}
	printf("\n=============================== All Book ==============================\n\n");
	printf("|======|==============|===============|========|==========|===============|\n");
	printf("|%-6s|%-14s|%-15s|%-6s|%-10s|%-15s|\n","ID","TIEU DE","TAC GIA","SO LUONG","GIA","ngay xuat ban");
	printf("|======|==============|===============|========|==========|===============|\n");
	for(int i=0;i<*countBook;i++){
		printf("|%-6s|%-14s|%-15s|%-8d|%-10d|%02d/%02d/%04d%-5s|\n",book[i].bookId,book[i].title,book[i].author,book[i].quantity,book[i].price,book[i].publication.day,book[i].publication.month,book[i].publication.year,"     ");
		printf("|======|==============|===============|========|==========|===============|\n");
	}
}
int checkBook(int countBook,char check[]){
	for(int i=0;i<countBook;i++){
		if(strcmp(book[i].bookId,check)==0){
			return i;
		}
	}
	return -1;
}
void changeBook(int countBook){
	if(countBook==0){
		printf("chua co sach de sua\n");
	}else{
	char temp[10];
	printf("moi ban nhap id: ");
	fgets(temp,sizeof(temp),stdin);
	temp[strcspn(temp,"\n")]='\0';
	int index=checkBook(countBook,temp);
	if(index==-1){
		printf("Id khong ton tai\n\n");
		return;
	}
	printf("\n========================= Current information ===========================\n");
	printf("|======|==============|===============|========|==========|===============|\n");
	printf("|%-6s|%-14s|%-15s|%-8d|%-10d|%02d/%02d/%04d%-5s|\n",book[index].bookId,book[index].title,book[index].author,book[index].quantity,book[index].price,book[index].publication.day,book[index].publication.month,book[index].publication.year,"     ");
	printf("|======|==============|===============|========|==========|===============|\n");
	printf("moi ban nhap tieu de: ");
	fgets(book[index].title,sizeof(book[index].title),stdin);
	book[index].title[strcspn(book[index].title,"\n")]='\0';
	printf("moi ban nhap tac gia: ");
	fgets(book[index].author,sizeof(book[index].author),stdin);
	book[index].author[strcspn(book[index].author,"\n")]='\0';
	printf("moi ban nhap so luong: ");
	scanf("%d",&book[index].quantity);
	getchar();
	printf("moi ban nhap gia: ");
	scanf("%d",&book[index].price);
	getchar();
	do{
		printf("Moi ban nhap ngay xuat ban(dd mm yyyy): ");
        scanf("%d %d %d",&book[index].publication.day,&book[index].publication.month,&book[index].publication.year);
        getchar();
        if (!isValidDate(book[index].publication.day,book[index].publication.month,book[index].publication.year)){
        	printf("Ngay khong hop le\n\n");
        	}   	
    }while(!isValidDate(book[index].publication.day,book[index].publication.month,book[index].publication.year));
    saveToFile(countBook);
	printf("sua thong tin thanh cong\n\n");
	}
}
void deleteBook(int *countBook){
	if(*countBook==0){
		printf("chua co sach de sua\n");
	}else{
	int check=0;
	char temp[10];
	printf("moi ban nhap id: ");
	fgets(temp,sizeof(temp),stdin);
	temp[strcspn(temp,"\n")]='\0';
	int index=checkBook(*countBook,temp);
	if(index==-1){
		printf("Id khong ton tai\n\n");
		return;
	}
	do{
	printf("\n========================= Current information ===========================\n");
	printf("|======|==============|===============|========|==========|===============|\n");
	printf("|%-6s|%-14s|%-15s|%-8d|%-10d|%02d/%02d/%04d%-5s|\n",book[index].bookId,book[index].title,book[index].author,book[index].quantity,book[index].price,book[index].publication.day,book[index].publication.month,book[index].publication.year,"     ");
	printf("|======|==============|===============|========|==========|===============|\n");
	printf("moi ban xac nhan thong tin\n");
	printf("[1]. xac nhan xoa\n");
	printf("[2]. xac nhan khong xoa\n");
	printf("Lua chon cua ban: ");
	scanf("%d",&check);
	}while(check!=1&&check!=2);
	if(check==2){
		printf("da xac nhan khong xoa\n\n");
		return;
	}
	for(int i=index;i<*countBook-1;i++){
        book[i]=book[i+1];
    }
    (*countBook)--;
    saveToFile(*countBook);
	printf("xoa thong tin thanh cong\n\n");
	}
}
void sortAscending(int countBook){
	for(int i=0;i<countBook-1;i++){
        for(int j=0;j<countBook-i-1;j++){
            if(book[j].price>book[j+1].price){
                struct Book temp=book[j];
                book[j]=book[j+1];
                book[j+1]=temp;
            }
        }
    }
    saveToFile(countBook);
    printf("sap xep tang dan theo gia thanh cong");
}
void sortDescending(int countBook){
	for(int i=0;i<countBook-1;i++){
        for(int j=0;j<countBook-i-1;j++){
            if(book[j].price<book[j+1].price){
                struct Book temp=book[j];
                book[j]=book[j+1];
                book[j+1]=temp;
            }
        }
    }
    saveToFile(countBook);
    printf("sap xep giam dan theo gia thanh cong");
}
void menuArrange(int countBook){
	if(countBook==0){
		printf("chua co sach");
		return;
	}
	int choose;
	printf("\n|======== Sort By Price ========|\n");
	printf("| [1]. Sap xep tang dan         |\n");
	printf("| [2]. Sap xep giam dan         |\n");
	printf("| [3]. Thoat                    |\n");
	printf("Lua chon cua ban: ");
	scanf("%d",&choose);
	getchar();
	switch(choose){
		case 1:
			sortAscending(countBook);
			break;
		case 2:
			sortDescending(countBook);
			break;
	}
}
void searchBook(int countBook){
    char temp[30];
    int check=1;
    printf("Nhap ten sach muon tim: ");
    fgets(temp,sizeof(temp),stdin);
    temp[strcspn(temp,"\n")]='\0';
    printf("============================== Search Results =============================\n");
    printf("|======|==============|===============|========|==========|===============|\n");
    printf("|%-6s|%-14s|%-15s|%-6s|%-10s|%-15s|\n","ID","TIEU DE","TAC GIA","SO LUONG","GIA","ngay xuat ban");
    printf("|======|==============|===============|========|==========|===============|\n");
    for(int i=0;i<countBook;i++){
        if(strstr(book[i].title,temp)!=NULL){
            printf("|%-6s|%-14s|%-15s|%-8d|%-10d|%02d/%02d/%04d%-5s|\n",book[i].bookId,book[i].title,book[i].author,book[i].quantity,book[i].price,book[i].publication.day,book[i].publication.month,book[i].publication.year,"     ");
            printf("|======|==============|===============|========|==========|===============|\n");
            check=0;
        	}
    }
	if(check){
        printf("Khong tim thay sach\n");
    }
    return;
}
int isIdCustomer(char *id,int countBook){
    for(int i=0;i<countBook;i++){
        if(strcmp(book[i].bookId,id)==0){
            printf("ID da ton tai\n");
            return 1;
        }
    }
    return 0;
}
int isPhone(char *phone){
    for(int i=0;phone[i]!='\0';i++){
        if(isalpha(phone[i])){
            printf("so dien thoai khong co chu cai\n");
            return 1;
        }
    }
    return 0;
}
void addCustomer(int *countCustomer){
	do{
		do{
        	printf("moi ban nhap ID: ");
        	fgets(member[*countCustomer].memberId,sizeof(member[*countCustomer].memberId),stdin);
        	member[*countCustomer].memberId[strcspn(member[*countCustomer].memberId,"\n")]='\0';
        	if(strlen(member[*countCustomer].memberId)==0){
            	printf("ID khong duoc de trong\n");
        	}else if(strlen(member[*countCustomer].memberId)>10){
            	printf("ID qua dai toi da 9 ky tu\n");
        	}
    	}while(strlen(member[*countCustomer].memberId)==0||strlen(member[*countCustomer].memberId)>10);
    }while(isIdCustomer(member[*countCustomer].memberId,*countCustomer));
    printf("Moi ban nhap ten: ");
    fgets(member[*countCustomer].name,sizeof(member[*countCustomer].name),stdin);
    member[*countCustomer].name[strcspn(member[*countCustomer].name,"\n")]='\0';
    do{
		do{
        	printf("Moi ban nhap so dien thoai co 10 so: ");
        	fgets(member[*countCustomer].phone,sizeof(member[*countCustomer].phone),stdin);
        	member[*countCustomer].phone[strcspn(member[*countCustomer].phone,"\n")]='\0';
        	if(strlen(member[*countCustomer].phone)==0){
            	printf("so dien thoai khong duoc de trong\n");
        	}else if(strlen(member[*countCustomer].phone)==10){
            	printf("\n");
        	}
    	}while(strlen(member[*countCustomer].phone)!=10);
    }while(isPhone(member[*countCustomer].phone));
    
    do{
        printf("Moi ban nhap trang thai(khoa/mo khoa): ");
        fgets(member[*countCustomer].status,sizeof(member[*countCustomer].status),stdin);
        member[*countCustomer].status[strcspn(member[*countCustomer].status,"\n")]='\0';
    }while(strcmp(member[*countCustomer].status,"khoa")!=0&&strcmp(member[*countCustomer].status,"mo khoa")!=0);
    member[*countCustomer].borrowedCount=0;
    (*countCustomer)++;
    saveToFileCustomer(*countCustomer);
    printf("Added customer information successfully\n");
}
void showCustomers(int countCustomer){
    if(countCustomer==0){
        printf("Khong co khach hang\n");
        return;
    }
    printf("\n------------------------------- All Customer --------------------------------\n");
    printf("|------|--------------------|---------------|---------------|---------------|\n");
    printf("|%-6s|%-20s|%-15s|%-15s|%-15s|\n","ID","TEN","SO DIEN THOAI","TRANG THAI","sach da muon");
    printf("|------|--------------------|---------------|---------------|---------------|\n");
    for(int i=0;i<countCustomer;i++){
        printf("|%-6s|%-20s|%-15s|%-15s|%-15d|\n", member[i].memberId,member[i].name,member[i].phone,member[i].status,member[i].borrowedCount);
        printf("|------|--------------------|---------------|---------------|---------------|\n");
    }
}
int findMemberIndexById(char id[],int countCustomer){
    for(int i=0;i<countCustomer;i++){
        if(strcmp(id,member[i].memberId)==0){
            return i;
        }
    }
    return -1;
}
int findBookIndexById(char id[],int countBook){
    for(int i=0;i<countBook;i++){
        if(strcmp(id,book[i].bookId)==0){
            return i;
        }
    }
    return -1;
}
void changeCustomer(int countCustomer){
	if(countCustomer==0){
		printf("chua co khach hang\n");
	}
    char id[10];
    printf("Moi ban nhap id: ");
    fgets(id,sizeof(id),stdin);
    id[strcspn(id,"\n")]='\0';
    int index=findMemberIndexById(id,countCustomer);
    if(index==-1){
        printf("Id khong ton tai\n");
        return;
    }
	printf("Moi ban nhap id: ");
    fgets(member[index].memberId,sizeof(member[index].memberId),stdin);
    member[index].memberId[strcspn(member[index].memberId,"\n")]='\0';
    printf("Moi ban nhap ten: ");
    fgets(member[index].name,sizeof(member[index].name),stdin);
    member[index].name[strcspn(member[index].name,"\n")]='\0';
    printf("Moi ban nhap so dien thoai: ");
    fgets(member[index].phone,sizeof(member[index].phone),stdin);
    member[index].phone[strcspn(member[index].phone,"\n")]='\0';
    saveToFileCustomer(countCustomer);
    printf("sua thong tin thanh cong\n");
}
void changeCustomerStatus(int countCustomer){
	if(countCustomer==0){
		printf("chua co khach hang\n");
		return;
	}
    char id[10];
    printf("moi ban nhap id: ");
    fgets(id,sizeof(id),stdin);
    id[strcspn(id,"\n")]='\0';
    int index=findMemberIndexById(id,countCustomer);
    if(index==-1){
        printf("ID khach hang da ton tai\n");
        return;
    }
    if(strcmp(member[index].status,"khoa")==0){
        printf("xac nhan mo khoa (Y la xac nhan)/(N la huy): ");
    }else{
        printf("xac nhan khoa khach hang (Y la xac nhan)/(N la huy): ");
    }
    char confirm;
    scanf("%c",&confirm);
    getchar();
    if(confirm=='Y'||confirm=='y'){
        if(strcmp(member[index].status,"khoa")==0){
            strcpy(member[index].status,"mo khoa");
            printf("Khach hang da mo khoa thanh cong\n");
        }else{
            strcpy(member[index].status,"khoa");
            printf("Khach hang da khoa thanh cong\n");
        }
        saveToFileCustomer(countCustomer);
    }else{
        printf("khong hop le\n");
    }
}
int checkCustomer(int countCustomer,char temp[]){
	for(int i=0;i<countCustomer;i++){
		if(strcmp(member[i].name,temp)==0){
			return i;
		}
	}
	return -1;
}
void searchCustomer(int countCustomer){
	char temp[30];
	printf("Moi ban nhap ten: ");
    fgets(temp,sizeof(temp),stdin);
    temp[strcspn(temp,"\n")]='\0';
	int check=checkCustomer(countCustomer,temp);
	if(check==-1){
		printf("ten khong ton tai");
		return;
	}
	printf("|------|--------------------|---------------|---------------|---------------|\n");
    printf("|%-6s|%-20s|%-15s|%-15s|%-15s|\n","ID","TEN","SO DIEN THOAI","TRANG THAI","sach da muon");
    printf("|------|--------------------|---------------|---------------|---------------|\n");
	for(int i=0;i<countCustomer;i++){
        if(strstr(book[i].title,temp)!=NULL){
            printf("|%-6s|%-20s|%-15s|%-15s|%-15d|\n", member[check].memberId,member[check].name,member[check].phone,member[check].status,member[check].borrowedCount);
            printf("|------|--------------------|---------------|---------------|---------------|\n");
        	}
    }
}
void lendBooks(int countCustomer,int countBook){
	if(countCustomer==0){
		printf("chua co khach hang\n");
		return;
	}
    char idCustomer[10];
    char idBook[10];
    printf("Moi ban nhap id hhhhhh khach hang: ");
    fgets(idCustomer,sizeof(idCustomer),stdin);
    idCustomer[strcspn(idCustomer,"\n")]='\0';
    int indexCustomer=findMemberIndexById(idCustomer,countCustomer);
    if(indexCustomer==-1){
        printf("Id khong ton tai\n");
        return;
    }
    if(strcmp("khoa",member[indexCustomer].status)==0){
    	printf("khach hang dang bi khoa");
    	return;
	}
	printf("Moi ban nhap id sach: ");
	fgets(idBook,sizeof(idBook),stdin);
    idBook[strcspn(idBook,"\n")]='\0';
    int indexBook=findBookIndexById(idBook,countBook);
    if(indexBook==-1){
    	printf("khong co ma sach ban nhap\n");
    	return;
	}
    int numberOfBooks;
    do{
    	printf("moi ban nhap so hhhhhhhhh luong sach: ");
    	scanf("%d",&numberOfBooks);
    	getchar();
    	if(numberOfBooks<1||numberOfBooks>6){
    		printf("so sach lon hon 1 va nho hon 6\n");
		}
		if(book[indexBook].quantity<numberOfBooks){
			printf("sach khong du, hien tai chi co %d sach\n",book[indexBook].quantity);
		}
	}while(numberOfBooks<1||numberOfBooks>6||book[indexBook].quantity<numberOfBooks);
	printf("Hello 1\n");
    int borrowedIdx=member[indexCustomer].borrowedCount;
    member[indexCustomer].brrowedBooks[borrowedIdx]=book[indexBook];
	book[indexBook].quantity-=numberOfBooks;
	printf("so luong %d\n",book[indexBook].quantity);
	member[indexCustomer].borrowedCount+=numberOfBooks;
	saveToFile(countCustomer);
	printf("cho muon sach thanh cong\n");
}
void returnBook(int countCustomer,int countBook){
    if(countCustomer==0){
        printf("chua co khach hang\n");
        return;
    }
    char idCustomer[10];
    char idBook[10];
    printf("moi ban nhap ID khach hang: ");
    fgets(idCustomer,sizeof(idCustomer),stdin);
    idCustomer[strcspn(idCustomer,"\n")]='\0';
    int indexCustomer=findMemberIndexById(idCustomer,countCustomer);
    if(indexCustomer==-1){
        printf("khach hang khong ton tai\n");
        return;
    }
    if(member[indexCustomer].borrowedCount==0){
        printf("khach hang chua muon sach\n");
        return;
    }
    printf("moi ban nhap ID sach muon tra: ");
    fgets(idBook,sizeof(idBook),stdin);
    idBook[strcspn(idBook,"\n")]='\0';
    int found=-1;
    for(int i=0;i<member[indexCustomer].borrowedCount;i++){
        if(strcmp(member[indexCustomer].brrowedBooks[i].bookId,idBook)==0){
            found=i;
            break;
        }
    }
    if(found==-1){
        printf("khach hang khong muon sach\n");
        return;
    }
    int indexBook=findBookIndexById(idBook,countBook);
    if(indexBook!=-1){
        book[indexBook].quantity++;
    }
    for(int i=found;i<member[indexCustomer].borrowedCount-1;i++){
        member[indexCustomer].brrowedBooks[i]=member[indexCustomer].brrowedBooks[i+1];
    }
    member[indexCustomer].borrowedCount--;
    printf("tra sach thanh cong\n");
}
void loginAdmin(){
    FILE *file=fopen("admin.dat","wb");
    if(file==NULL){
        printf("loi mo file de ghi\n");
        return;
    }
    struct Admin admin;
	strcpy(admin.username,"admin@gmail.com");
	strcpy(admin.password,"123456");
    fwrite(&admin,sizeof(struct Admin),1,file);
    fclose(file);
}
void accountAdmim(int *countAdmin){
	if(*countAdmin==0){
	loginAdmin();
	(*countAdmin)++;
	}
	struct Admin admin;
    FILE *file=fopen("admin.dat","rb");
    if(file==NULL){
        printf("khong the mo file de doc\n");
        return;
    }
    fread(&admin,sizeof(struct Admin),1,file);
    fclose(file);
    char username[20];
	char password[20];
    do{
        printf("moi ban nhap ten tai khoang: ");
        fgets(username,sizeof(username),stdin);
        username[strcspn(username,"\n")]='\0';
        if(strcmp(username,admin.username)!=0){
            printf("sai tai khoan\n");
        }
    }while(strcmp(username,admin.username)!=0);
    do{
        printf("moi ban nhap mat khau: ");
        fgets(password,sizeof(password),stdin);
        password[strcspn(password,"\n")]='\0';
        if(strcmp(password,admin.password)!=0){
            printf("sai mat khau\n");
        }
    }while(strcmp(password,admin.password)!=0);
    printf("dang nhap admin thanh cong");
}
