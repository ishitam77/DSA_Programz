#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *rnode;
    Node *lnode;
};

typedef struct Node n;

Node* create(int ele){
    Node* n1=new Node;
    n1->data=ele;
    n1->lnode=NULL;
    n1->rnode=NULL;
    return n1;
}

void inorder(Node *root){
    if(root==NULL)
        return;
    inorder(root->lnode);
    cout<<root->data<<" ";
    inorder(root->rnode);
}

Node* min(Node* curr){
    while(curr->lnode!=NULL){
        curr=curr->lnode;
    }
    return curr;
}

Node* max(Node* curr){
    while(curr->rnode!=NULL){
        curr=curr->rnode;
    }
    return curr;
}

Node* inst(Node* root,int ele){
    if(root==NULL)
        return create(ele);
    if(ele<root->data)
        root->lnode=inst(root->lnode,ele);
    else
        root->rnode=inst(root->rnode,ele);
    return root;
}

Node* del(Node* root,int ele){
    if(root==NULL) return root;
    
    if(ele<root->data)
        root->lnode=del(root->lnode,ele);
    else if(ele>root->data)
        root->rnode=del(root->rnode,ele);
    else{
        //If the node have only one child or no child
        if(root->lnode==NULL){
            n * temp=root->rnode;
            free(root);
            return temp;
        }
        else if(root->rnode==NULL){
            n* temp=root->lnode;
            free(root);
            return temp;
        }
        //If the node have 2 child
        n* temp=min(root->rnode);
        root->data=temp->data;
        root->rnode=del(root->rnode,temp->data);
    }
    return root;
}

int main(){
    Node* root=NULL;
    int ele,ch;
    while(true)
    {
        cout<<"1) Insert\n2) Delete\n3) Display\n4) Maximun\n5) Exit"<<endl;
        cout<<"Enter Your Choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1: cout<<"Insert the value in BST: ";
                    cin>>ele;
                    root=inst(root,ele);
                    break;
            case 2: cout<<"Delete the value in BST: ";
                    cin>>ele;
                    root=del(root,ele);
                    break;
            case 3: cout<<"BST Values in Inorder"<<endl;
                    cout<<endl<<"Root: "<<root->data<<endl;
                    inorder(root);
                    break;
            case 4: cout<<endl<<"Maximum Value: "<<max(root)->data<<endl;
                    break;
            case 5: exit(0);
                    break;
            default: cout<<"Wrong Choice!!"<<endl;
                      break;
        }
    }

    return 0;
}