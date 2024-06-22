#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node{
    char value;
    Node* next;
};
Node* top=NULL;

void push(char value){
    Node* ptr= (Node*) malloc(sizeof(Node));
    ptr->value=value;
    ptr->next=NULL;
    if(top==NULL){
        top=ptr;
    }
    else{
        ptr->next=top;
        top=ptr;

    }
}

char pop(){
    int temp=top->value;
    Node* current=top;
    top=top->next;
    free(current);
    return temp;
}

int precedenceChecker(char value){

    if (value=='|'){
        return 1;
    }
    if(value=='&'){
        return 2;
    }
    if( value=='=' or value=='!'){
        return 3;
    }
    if(value=='>' or value=='<'){
        return 4;
    }
    if(value=='+' or value=='-'){
        return 5;
    }
    if(value=='*' or value=='/' or value=='%'){
        return 6;
    }

}

string infixToPostfix(string infix){
    string postfix;
    for(int i=0; i<infix.length();i++){
        char currchar=infix[i];
        
        // for operand 
        if (currchar>64 and currchar!=124){
        	
            postfix= postfix + currchar;

        }
        else {
        	
        	if ((top==NULL or top->value == '(' or precedenceChecker(currchar)> precedenceChecker(top->value )) and currchar!=')'){
               
			    push(currchar);
            }
            
            else {
                if(currchar==')'){
                    do{
                        postfix=postfix+pop();
                    }while(top->value!='(');
                    pop();
                }
                else{
                do{
                    if(top->value!='('){
					
					postfix=postfix+pop();
                }
                if(top->value=='('){
                	pop();
				}
                }while(top!=NULL and top->value!='(' and precedenceChecker(currchar)<=precedenceChecker(top->value));
                push(currchar);
           }
        }
    }
}

    while(top!=NULL){
                    postfix=postfix+pop();
                    }
                    return postfix;
}
    
int main(){
    string infix;
    cout<<"Enter any infix equation to convert it into postfix equation:"<<endl;
    cin>>infix;
    string postfix= infixToPostfix(infix);
    cout<<"The postfix equation is: "<<postfix<<endl;

}







