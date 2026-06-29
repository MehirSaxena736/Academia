#include<stdio.h>

struct item{
	char name[50];
	int priceperunit;
	int quantitypurchased;
	int amount spend;
	
};
 struct item items;
void input(item)
{
	printf("enter the name of the product");
	scanf("%d",&items.name);
	printf("enter the price per unit");
	scanf("%d",&items.priceperunit);
	printf("how much quantity");
	scanf("%d",&items.quantitypurchased);
}
void display()
{
	printf("name: %c",items.name);
	printf("price per unit:%d",items.priceperunit);
	printf("quantity: %d",items.quantitypurchased);
}
 int amountspend=items.priceperunit*items.quantitypurchased;
 
 int main()
 {
 	printf("\nwelcome to our store\n");
 	printf("\ninput the details of the iten yu want to buy\n");
 	input(items);
 	
 	printf("display the details");
 	display();
 	
 	printf("the total amount spend is %d:\n",amountspend);
 }
