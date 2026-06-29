#include<stdio.h>
#include<string.h>

#define MAX_CUSTOMERS=50

struct customer{
	char name[100];
	int phoneno;
	char address[100];
	int balance;
};
struct customer customer[MAX_CUSTOMERS];
int numcustomers=0;

int main()
{
	int choice;
	do
	{
		printf("telecom system");
		printf("1: add records");
		printf("2: list of records");
		printf("3: view payments");
		printf("4: search records");
		printf("5: modify records");
		printf("6: delete records");
		printf("7: exit");
		printf("enter your choice");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				add records();
				break;
			case 2:
				list of records();
				break;
			case 3:
				view payments();
				break;
			case 4:
				search records();
				break;
			case 5:
				modify records();
				break;
			case 6:
				delete records();
				break;
			case 7:
				printf("exit\n");
				break;
			default:
				printf("invalid choice");
		}
		while(choice!=7)
		return 0;
	}
}
void add records()
{
	if(numcustomers<MAX_CUSTOMERS)
	customer new_customer
	{
		prinf("enter the name");
		scanf("%c",new_customer.name);
		prinf("enter the phoneno");
		scanf("%d",new_customer.phoneno);
		prinf("enter the address");
		scanf("%c",new_customer.address);
		newcustomer.balance=0;
		
		customer[numcustomer++]=new_customer;
		printf("\nthe customer added successfully\n");
		
		
		
	}
	else{
		printf("limit reached");
	}
}

void viewlist()
{
	int i;
	printf("the records of the customer are:")
	for(i=0;i<numcustomers;i++)
	{
		printf("%s\t,%d\t,%c\t",customer[i].name,customer[i].phoneno,customer[i].address);
	}
}

void modify()
{
	char searchname[50]
	printf("enter the name you want to modify");
	scanf("%c",&searchname);
	
	for(i=0;i<numcustomers;++i)
	{
	   if (strcmp(customers[i].name, searchName) == 0) {
            printf("Enter new address for %s: ", searchName);
            scanf("%s", customers[i].address);
            printf("Enter new phone number for %s: ", searchName);
            scanf("%s", customers[i].phoneNumber);
            printf("Customer record modified successfully.\n");
        }
        else{
        	printf("not found");
		}
	}
}

void viewpayments()
{
	char searchname[50]
	printf("enter the name whose payment we want to see")
	scanf("%c",&searchname);
	for(i=0;i<numcustomer;i++)
	{
		if(strcmp(customer[i].name,searchname==0))
		{
		
		  printf("the balance of the suctomer is ",customer[i].balance);
	    }
	    else{
	    	printf("invalind choice");
		}
	}
}

void searchrecords()
{

  char searchname[50]
	printf("enter the name whose payment we want to see")
	scanf("%c",&searchname);
	for(i=0;i<numcustomer;i++)
	{
			if(strcmp(customer[i].name,searchname==0))
			{
				printf("%c\t,%d\t,%c\t,%d\t",customer[i].name,customer[i].phoneno,customer[i].address,customer[i],balance);
			}
			else{
				printf("invalid choice not found");
	}      }
	
}
}

void delete records()
{
	char searchname[50];
	printf("enter the name to search");
	scanf("%c",searchname);
		for (int i = 0; i < numCustomers; ++i) {
        if (strcmp(customers[i].name, searchName) == 0) {
            for (int j = i; j < numCustomers - 1; ++j) {
                customers[j] = customers[j + 1];
            }
            numCustomers--;
            printf("Customer %s deleted successfully.\n", searchName);
        }
    }
    
	
}
