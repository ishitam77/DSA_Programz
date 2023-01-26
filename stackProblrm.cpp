@-  Students of a Programming class arrive to submit assignments. 
Their register numbers are stored in a LIFO list in the order in which 
the assignments are submitted. Write a program using an array to display 
the registered number of the ten students who submitted first. 
Register number of the ten students who submitted first will be at the bottom of the LIFO list. 
Hence pop out the required number of elements from the top so as to retrieve and display the first 10 students. 


#include <iostream>
using namespace std;
int top=-1,stack[20];
bool isFull(){
    if(top==19){
        return true;
    }
    else{
        return false;
    }
}
bool isEmpty(){
    if(top==-1){
        return true;
    }
    else{
        return false;
    }
}
void push(int val){
    if(isFull()==true){
        cout<<"Stack overflow!!"<<endl;
    }
    else{
        top++;
        stack[top]=val;
    }
}
void pop(){
    if(isEmpty()==true){
        cout<<"Stack underflow!!"<<endl;
    }
    else{
        top--;
    }
}
void display(){
    cout<<"Stack elements are-"<<endl;
    for(int i=top;i>=0;i--){
        cout<<stack[i]<<" ";
    }
    cout<<endl;
}
int main() {
int ch,val;
do{
    cout<<"1)Enter Reg No.s \n2)Display First 10 Reg N0.  \n3)Exit"<<endl;
    cout<<"Enter the Choice: ";
    cin>>ch;
    cout<<endl;
    switch(ch){
        case 1:{
            for(int i=0;i<20;i++){
            cout<<"Enter "<<i+1<<" Reg No.- ";
            cin>>val;
            push(val);}
            break;
        }
        case 2:{
            int i=19;
            while(i>=10){
            pop();
            i--;
            }
            cout<<"First 10 Reg No. are- "<<endl;
            for(int i=top;i>=0;i--){
                cout<<stack[i]<<" ";
            }
            break;
        }
        case 3:{
            cout<<"\nExit!!";
            break;
        }
        default:{
            cout<<"\nInvalid Option";
        }
    }
    
}while(ch!=3);
    return 0;
}