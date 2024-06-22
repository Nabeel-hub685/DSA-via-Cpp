
#include<iostream>
#include<cstdlib>
using namespace std;
struct Node{
	int value;
	Node* next;
};
Node* top=NULL;

void push(int value){
	 Node* ptr=(Node*) malloc(sizeof(Node));
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

int pop(){

//cout<<"Pop function was called"<<endl;
if(top==NULL){
    cout<<endl;
	cout<<"Error: stack underflowed!!! stack is already empty!"<<endl;
    return -1;
	}
else{
	Node* current=top;
	top=top->next;
	int temp = current->value;
	free(current);
cout<<"the popped value is :";
	return temp;
}
}

void printStack(){
    if (top==NULL){
        cout<<"The stack is already empty!"<<endl;
        return;
    }
	cout<<endl;
	Node* current=top;
	while(current!=NULL){
		cout<<current->value<<endl;
		current=current->next;
	}
    //cout<<endl;
	
}

int main(){
	cout<<"Enter 1 to push(insert) data on stack !"<<endl<<"Enter 2 to pop(delete) data from stack !"<<endl<<"Enter 3 to print the values!"<<endl<<"Enter 4 to exit the code!"<<endl<<endl;
	int choice;
	cin>>choice;
	while (choice!=4){
		if (choice==1){
			int set=1;
			while (set==1){
			
			int value;
			cout<<"Enter value to push on the stack: "<<endl;
			cin>>value;
			push(value);
			cout<<"Enter 1 if you want to push (insert) another value"<<endl;
			cin>>set;
			}
	}
		else if(choice==2){
			if( top==NULL){
				pop();
			}
			else{
			
			cout<<pop();
			cout<<endl;
		}
		}
		else{
			printStack();
		}
	    cout<<endl;
			cout<<"Enter 1 to push(insert) data on stack !"<<endl<<"Enter 2 to pop(delete) data from stack !"<<endl<<"Enter 3 to print the list !"<<endl<<"Enter 4 to exit the code!"<<endl<<endl;
			cin>>choice;
	}
	cout<<"We have exit the code now!"<<endl;
}


