#include<iostream>
#include<stdlib.h>
using namespace std;


struct Node{
    char value;
    Node* next;
    Node* left;
    Node* right;
};

Node* top = NULL;

void push(Node* ptr){
    
    if(top==NULL){
        top=ptr;
    }
    else{
        ptr->next=top;
        top=ptr;

    }
}

Node* pop(){
    
    Node* current=top;
    top=top->next;
    //free(current);

    return current;
}

 void buildExpressionTree(string postfix){

    for(int i =0; i<postfix.length();i++){
        char currchar= postfix[i];
        // for operand.
        if (currchar>64 and currchar!=124){
             Node* ptr= (Node*) malloc(sizeof(Node));
             ptr->value=currchar;
             ptr->next=NULL;
             ptr->left=NULL;
             ptr->right=NULL;
             push(ptr);
           }


        // for operator
        else{
            Node* ptr= (Node*) malloc(sizeof(Node));
            ptr->value=currchar;
            ptr->next=NULL;
            ptr->right=pop();
            ptr->left=pop();
            push(ptr);
           
           }
     }
     
}

void infixTraversal(Node* top){
    if(top==NULL){
        return;
    } 
    infixTraversal(top->left);
    cout<<top->value;
    infixTraversal(top->right);

}


int main(){
    string postfix;
    cout<<"Enter postfix equation to build expression tree: "<<endl;
    cin>>postfix;
    buildExpressionTree(postfix);
    cout<<"the tree has been built!"<<endl;
    cout<<"The inorder traversal on the just built expression tree is: ";
    infixTraversal(top);
    
    

}