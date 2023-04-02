/*To facilitate thorough net surfing, any web browser has back and forward buttons that allow the user to move backward 
and forward through a series of web pages. To allow the user to move both forward and backward two stacks are employed.*/

//header files
#include <iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define max 100

//Here, i consider Backward Stack as my First Stack  
//And Forward Stack as my Second Stack

//variables for backward stack
char a[max][max];
int top = -1;
char x[max];

//variables for forward stack
char a1[max][max];
int top1 = -1;
char x1[max];

//functions for backward stack
int isempty() ;
int isfull() ;
void push() ;
void pushadd(char *x) ;
int pop() ;
void display();

//functions for forward stack
int isempty1() ;
int isfull1() ;
void push1(char *x1) ;
int pop1() ;
void display1();

//Main Body
int main()
{
    int ch1;
        
        //do while loop 
         do{
        cout<<"\n1) Enter into any Website!!";
        cout<<"\n2) Forward";
        cout<<"\n3) Backward";
        cout<<"\n4) Display Forward URLs";
        cout<<"\n5) Display Backward URLs";
        cout<<"\n6) Exit";
        cout<<"\nEnter Choice: ";
    cin>>ch1;

        switch (ch1) {
        case 1:
            push();
            break;
        case 2:
            pop1();
            break;
        case 3:
            pop();
            break;
        case 4:
            display1();
            break;
        case 5:
            display();
            break;
        case 6:
            break;
        default:
            printf("\nInvalid Choice!!");
            break;
        }
    }while(ch1!=6);
    return 0;
}

//isfull() for backward stack
int isfull(){
    if ( (top == max-1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//isempty() for backward stack
int isempty(){
    if((top==-1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//push() for backward stack
void push(){
    if (isfull())
    {
        cout<<"\nURL Overloaded!!";
    }
    else
    {
        cout<<"\nEnter Website URL: ";
        cin>>x;
        top++;
        strcpy(a[top],x);
        cout<<"Current Website URL: "<<a[top];
    }
}

//pop() for backward stack
int pop(){
    if(isempty())
    {
        cout<<"\nNO URL Found!!";
    }
    else{
        strcpy(x,a[top]);
        push1(x);
        top--;
        cout<<"Current Website URL: "<<a[top];
    }
}

//display() for backward stack
void display()
{
    if(isempty())
    {
        cout<<"\nNo URL Found!!";
    }
    else
    {
        int i;
        cout<<"\n URLs Available in Backward Stack-\n";
        for(i=0;i<top+1;i++)
        {
            cout<<a[i]<<"\n";
        }
    }
}

//isfull1() for forward stack
int isfull1(){
    if ( (top1 == max-1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//isempty1() for forward stack
int isempty1(){
    if((top1==-1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//push1() for forward stack
void push1(char *x1){
    if (isfull1())
    {
        cout<<"\nURL Overloaded!!";
    }
    else
    {
        top1++;
        strcpy(a1[top1],x1);
    }
}

//pop1() for forward stack
int pop1(){
    if(isempty1())
    {
        cout<<"\nNo URL Found!!";
    }
    else{
        strcpy(x1,a1[top1]);
        pushadd(x1);
        cout<<"Current Website URL: "<<x1;
        top1--;
    }
}

//pushadd() for backward stack
void pushadd(char *x){
    if (isfull())
    {
        cout<<"\nURL Overloaded!!";
    }
    else
    {
        top++;
        strcpy(a[top],x);
    }
}

//display1() for forward stack
void display1()
{
    if(isempty1())
    {
        cout<<"\nNo URL Found!!";
    }
    else
    {
        int i;
        cout<<"\n URLs Available in Forward Stack-\n";
        for(i=0;i<top1+1;i++)
        {
            cout<<a1[i]<<"\n";
        }
    }
}
