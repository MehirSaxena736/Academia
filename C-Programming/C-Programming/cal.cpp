#include<stdio.h>

float add(float a,float b)
{
	return a+b;
}
float sub(float a,float b)
{
	return a-b;
}
float  mul(float a,float b)
{
	return a*b;
}
float div(float a,float b)
{
	if(b==0)
	{
		printf("error");
	}
	else
	{ 
	  return a/b;
	}
}

int main()
{
	float num1,num2,result;
	char oper;
	
	printf("enter thr first number");
	scanf("%f",&num1);
	printf("enter thr second number");
	scanf("%f",&num2);
	
	printf("enter the operator:(+,-,*,/)");
	scanf("%c",&oper);
	
    switch(oper);
	{
	    case '+':
            result=add(num1,num2);
		    break;
		case '-':
            result=sub(num1,num2);
			break;
		case '*':
	        result=mul(num1,num2);
			break;
		case '/':
	        result=div(num1,num2);
			break;
		default
			printf("invalid operator");
			return 1;
	}
	printf("the result of the calculation is %.2f\n",result);
	return 0;
}
