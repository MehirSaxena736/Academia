#include<stdio.h>
#include<math.h>

float add(float num1,float num2);
float subtract(float num1,float num2);
float multiply(float num1,float num2);
float divison(float num1,float num2);
float power(float base,float exponent);
float exponentially(float num1);
float logarithim(float num1);

int main()
{
	int choice;
	float num1,num2;
	do
	{
		printf("\n-- SCIENTIFIC CALCULATOR --\n");
		printf("1: addition\n");
		printf("2: subtraction\n");
		printf("3: multiplication\n");
		printf("4: division\n");
	    printf("5: power\n");
	    printf("6: exponentially\n");
	    printf("7: logarithim\n");
	    printf("8: exiting\n");
	    
		printf("enter your choice");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("enter the value of one number \n");
				scanf("%f",&num1);
				printf("enter the value of second number\n");
				scanf("%f",&num2);
				printf("result: %f",add(num1,num2));
				break;
			case 2:
				printf("enter the value of one number \n");
				scanf("%f",&num1);
				printf("enter the value of second number\n");
				scanf("%f",&num2);
				printf("result: %f",subtract(num1,num2));
				break;
			case 3:
				printf("enter the value of one number \n");
				scanf("%f",&num1);
				printf("enter the value of second number\n");
				scanf("%f",&num2);
				printf("result: %f",multiply(num1,num2));
				break;
		    case 4:
				printf("enter the value of one number \n");
				scanf("%f",&num1);
				printf("enter the value of second number\n");
				scanf("%f",&num2);
				if(num2==0)
				{
					printf("divisin not possible");
				}
				else
				printf("result: %f",divison(num1,num2));
				break;
			case 5:
				printf("enter the value of base number \n");
				scanf("%f",&num1);
				printf("enter the value of exponent number\n");
				scanf("%f",&num2);
				printf("result: %f",power(num1,num2));
				break;
			case 6:
				printf("enter the value of one number \n");
				scanf("%f",&num1);
				printf("result: %f",exponentially(num1));
				break;
			case 7:
				printf("enter the value of one number \n");
				scanf("%f",&num1);
				printf("result: %f",logarithim(num1));
				break;
			case 8:
				printf("exiting the program\n");
				break;
			default:
				printf("invalid");
		}
		
	}
	while(choice!=8);
	return 0;
}

float add(float num1,float num2)
{
	return  num1 +  num2;
}
float subtract(float num1, float num2)
{
	return  num1 - num2;
}
float multiply(float num1, float num2)
{
	return  num1 *  num2;
}
float divison(float num1,float num2)
{
	return  num1 / num2;
}
float power(float base,float exponent)
{
	return pow(base,exponent);
}
float exponentially(float num1)
{
	return exp(num1);
}
float logarithim(float num1)
{
	return log(num1);
}
