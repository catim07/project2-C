#include <stdio.h>
#include <stdlib.h>
#include "datatype.h"
int main(int argc, char *argv[]){
	int choose,chooseMain,countBook=0,countCustomer=0,countAdmin=0;
	do {
		loadFromFile(&countBook);
		loadFromFileCustomer(&countCustomer);
        showMainMenu();
        scanf("%d",&chooseMain);
        getchar();
        switch(chooseMain){
            case 1:
                do {
                    showMenuBook();
                    scanf("%d",&choose);
                    getchar();
                    switch (choose){
                        case 1:
                            addBook(&countBook);
                            break;
                        case 2:
                            showBook(&countBook);
                            break;
                        case 3:
                            changeBook(countBook);
                            break;
                        case 4:
                            deleteBook(&countBook);
                            break;
                        case 5:
                            menuArrange(countBook);
                            break;
                        case 6:
                            searchBook(countBook);
                            break;
                    }
                }while(choose!=0);
                break;
            case 2:
                do{
                    showMenuCustomer();
                    scanf("%d",&choose);
                    getchar();
                    switch (choose){
                        case 1:
                            addCustomer(&countCustomer);
                            break;
                        case 2:
                            showCustomers(countCustomer);
                            break;
                        case 3:
                            changeCustomer(countCustomer);
                            break;
                        case 4:
                            changeCustomerStatus(countCustomer);
                            break;
                        case 5:
                            searchCustomer(countCustomer);
                            break;
                        case 6:
                            lendBooks(countCustomer,countBook);
                            break;
                        case 7:
                            returnBook(countCustomer,countBook);
                            break;
                    }
                }while(choose!=0);
                break;
            case 3:
            	accountAdmim(&countAdmin);
            	break;
        }
    } while(chooseMain!=0);
	return 0;
}