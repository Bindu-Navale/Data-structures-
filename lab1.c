#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int stack[SIZE],top=-1;

void push(int value){
    if(top == SIZE-1)
        printf("\nStack is Full!!! Insertion is not possible!!!");
    else{
            top++;
            stack[top] = value;
            printf("\nInsertion success");
            }
}

void pop(){
    if(top == -1)
        printf("\nStack is Empty. Deletion is not possible.");
    else{
            printf("\nDeleted : %d", stack[top]);
            top--;
            }
}

void display(){

if(top == -1)
    printf("\nStack is Empty.");
    else{
            int i;
            printf("\nStack elements are:\n");
            for(i=top; i>=0; i--)
            printf("%d\n",stack[i]);
    }
}


//int stack[SIZE], top = -1;

void main()
{

 while(1){
        int choice,value;
        printf("\n\n----MENU---\n");
        printf("1. Push\n 2. Pop\n 3. Display\n 4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the value to be insert: ");
                    scanf("%d",&value);
                    push(value);
                    break;
            case 2: pop();
            break;
            case 3: display();
            break;
            case 4: exit(0);
            default: printf("\nWrong selection!!! Try again!!!");
}
}
}

