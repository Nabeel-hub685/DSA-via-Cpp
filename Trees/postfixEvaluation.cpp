#include<iostream>
#include<stdlib.h>
using namespace std;


struct Node{
    char value;
    Node* next;
    
};

Node* top = NULL;

void push(int operand){
    Node* ptr= (Node*) malloc(sizeof(Node));
    ptr->value=operand;
    ptr->next=NULL;
     
    if(top==NULL){
        top=ptr;
    }
    else{
        ptr->next=top;
        top=ptr;

    }
}

int pop(){
    
    Node* current=top;
    int temp= current->value;
    top=top->next;
    free(current);
    return temp;
}

int postfixEvaluation(string postfix){
    int result;
    for(int i = 0; i<postfix.length();i++){
        char currchar= postfix[i];
        if(currchar>47 and currchar<58){
            int operand= currchar;
            operand-=48;
            push(operand);
        }
        else{
            int temp;
            int right=pop();
            int left=pop();
             
            if (currchar=='|'){
                temp= left or right;
                push(temp);
            }
            else if (currchar=='&'){
                temp= left and right;
                push(temp);
            }
            else if (currchar=='>'){
                temp= left > right;
                push(temp);
            }
            else if (currchar=='<'){
                temp= left < right;
                push(temp);
            }
            else if (currchar=='='){
                temp= left == right;
                push(temp);
            }
            else if (currchar=='!'){
                temp= left != right;
                push(temp);
            }
            else if (currchar=='+'){
                temp= left + right;
                push(temp);
            }
            else if (currchar=='-'){
                temp= left - right;
                push(temp);
            }
            else if (currchar=='*'){
                temp= left * right;
                push(temp);
            }
            else if (currchar=='/'){
                temp= left / right;
                push(temp);
            }
            else if (currchar=='%'){
                temp= left % right;
                push(temp);
            }
        }

        
    }
    result=pop();
    return result;
}



int main(){
    cout<<"Enter the postfix equation for postfix evaluation as well: "<<endl;
    string infixeq1;
    string postfixeq1;
    //cin>>postfix;
    infixeq1="a+b*c/d*x-f*d";
    postfixeq1="abc*d/x*+fd*-";
    //where a=2 , b=1 , c=3 , d=1 , f=2 , x=2
   // int evaluatedValue= postfixEvaluation("213*1/2*+21*-");

    string infixeq2;
    string postfixeq2;
    //cin>>postfix;
    infixeq2="a+b*(c-d)<x&(c!y|x+y<5)";
    postfixeq2="abcd-*+x<cy!xy+5<|&";
    // let values a = 2, b= 1, c = 3, d = 1, x = 2, y = 4
    int evaluatedValue= postfixEvaluation("2131-*+2<34!24+5<|&");
    cout<<"The evaluated value is: "<<evaluatedValue;
    cout<<endl<<"Note: 0 and 1 also define false and true!!!";
}