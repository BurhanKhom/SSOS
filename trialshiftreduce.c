#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char stack[50], input[50], action[50], temp[20];
int top=0, ip=0;
void check();
int main()
{
	printf("Enter input string(terminated by $): ");
	scanf("%s", input); // id+id*id$
	printf("STACK\t\tINPUT\t\tACTION\n");
	while(input[ip] != '$')
	{
		strcpy(action, "Shift ");
		if(input[ip] == 'i' && input[ip+1] == 'd')
		{
			stack[top] = 'i';
			stack[top+1] = 'd';
			stack[top+2] = '\0';
			top++;
			ip += 2;
			temp[0] = 'i';
			temp[1] = 'd';
			temp[2] = '\0';
		}
		else
		{
			stack[top] = input[ip];
			stack[top+1] = '\0';
			temp[0] = input[ip];
			temp[1] = '\0';
			ip++;
		}
		strcat(action, temp);
		printf("%s\t\t%s\t\t%s\n", stack, (input+ip), action);
		check();
		top++;
	}
	check();
}
void check()
{
	int flag=0;
	while(1)
	{
		if(stack[top] == 'd' && stack[top-1] == 'i')
		{
			stack[--top] = 'F';
			stack[top+1] = '\0';
			printf("%s\t\t%s\t\tReduce F->id\n", stack, (input+ip));
			flag=1;
		}
		if(stack[top] == ')' && stack[top-1] == 'E' && stack[top-2] == '(')
		{
			stack[top-2] = 'F';
			top -= 2;
			stack[top+1] = '\0';
			printf("%s\t\t%s\t\tReduce F->(E)\n", stack, (input+ip));
			flag=1;
		}
		if(stack[top] == 'F' && stack[top-1] == '*' && stack[top-2] == 'T')
		{
			stack[top-2] = 'T';
			top -= 2;
			stack[top+1] = '\0';
			printf("%s\t\t%s\t\tReduce T->T*F\n", stack, (input+ip));
			flag=1;
		}
		if(stack[top] == 'F')
		{
			stack[top] = 'T';
			stack[top+1] = '\0';
			printf("%s\t\t%s\t\tReduce T->F\n", stack, (input+ip));
			flag=1;
		}
		if(stack[top] == 'T' && stack[top-1] == '+' && stack[top-2] == 'E' && input[ip]!='*')
		{
			stack[top-2] = 'E';
			top -= 2;
			stack[top+1] = '\0';
			printf("%s\t\t%s\t\tReduce E->E+T\n", stack, (input+ip));
			flag=1;
		}
		if(stack[top] == 'T' && (top==0 || input[ip]!='*'))
		{
			stack[top] = 'E';
			stack[top+1] = '\0';
			printf("%s\t\t%s\t\tReduce E->T\n", stack, (input+ip));
			flag=1;
		}
		else
			flag = 2;

		if(stack[top] == 'E' && input[ip] == '$')
		{
			printf("%s\t\t%s\t\tAccepted\n", stack, (input+ip));	
			exit(0);
		}
		if(flag == 2)
			return;
	}
}