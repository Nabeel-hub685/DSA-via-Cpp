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

string infixToPrefix(string infix){
    string prefix;
    string revInfix;
    for(int i = infix.length()-1;i>=0;i--){
        revInfix=revInfix + infix[i];
    }
    for(int i =0;i<revInfix.length();i++){
        if(revInfix[i]=='('){
            revInfix[i]=')';
        }
       else if(revInfix[i]==')'){
            revInfix[i]='(';
        }
    }


    for(int i=0; i<revInfix.length();i++){
        char currchar=revInfix[i];
        
        // for operand 
        if (currchar>64 and currchar!=124){
        	
            prefix= prefix + currchar;

        }
        else {
        	
        	if ((top==NULL or top->value == '(' or precedenceChecker(currchar)> precedenceChecker(top->value )) and currchar!=')'){
               
			    push(currchar);
            }
            
            else {
                if(currchar==')'){
                    do{
                        prefix=prefix+pop();
                    }while(top->value!='(');
                    pop();
                }
                else{
                do{
                    if(top->value!='('){
					
					prefix=prefix+pop();
                }
                }while(top!=NULL and top->value!='(' and precedenceChecker(currchar)<=precedenceChecker(top->value));
                push(currchar);
           }
        }
    }
}

    while(top!=NULL){
                    prefix=prefix+pop();
                    }
                 string actualprefix;
                 for(int i=prefix.length()-1;i>=0;i--){
                    actualprefix=actualprefix + prefix[i];
                 }

                    return actualprefix;
}

    
int main(){
    string infix;
    cout<<"Enter any infix equation to convert it into prefix equation:"<<endl;
    cin>>infix;
    string prefix= infixToPrefix(infix);
    cout<<"The pretfix equation is: "<<prefix<<endl;

}







