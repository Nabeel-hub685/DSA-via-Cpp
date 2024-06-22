#include<iostream>
#include<cstdlib>
using namespace std;

struct Queue{
	int value;
	Queue* next;
};

Queue* front;
Queue* rare;

void NQueue(int value){
	//cout<<"N queue method was called"<<endl;
	Queue* ptr=(Queue*) malloc(sizeof(Queue));
	 ptr->value=value;
	 ptr->next=NULL;
	 
	if (front==NULL and rare==NULL){
		front=ptr;
		rare=ptr;
	}
	 
	else {
		rare->next=ptr;
		rare=rare->next;
		}
}

int DeQueue(){
	
	if (front==NULL or rare==NULL){
		cout<<"The Queue is empty now!"<<endl<<endl;
 return -1;
	}
	else{
	
	Queue* current=front;
	int temp=current->value;
	front=front->next;
	free(current);
	cout<<"The value DeQueued is : ";
	return temp;
}
	
}



void printQueue(){
	//cout<<"print queue function was called"<<endl;
	if (front==NULL and rare==NULL){
		cout<<"The list is empty right now!"<<endl<<endl;
	}
	else{
		cout<<endl;
	    Queue* current=front;
	    while (current!=NULL){
	    	cout<<current->value<<endl;
	    	current=current->next;
	}
	cout<<endl;
}
}



int main(){
	cout<<"Enter 1 to N-Queue(insert) data in queue !"<<endl<<"Enter 2 to DeQueue(delete) data from queue !"<<endl<<"Enter 3 to print the values!"<<endl<<"Enter 4 to exit the code!"<<endl;
	int choice;
	cin>>choice;
	while (choice!=4){
		if (choice==1){
			int set=1;
			while (set==1){
			
			int value;
			cout<<"Enter value to N-Queue(insert) in the queue: "<<endl;
			cin>>value;
			NQueue(value);
			cout<<"Enter 1 if you want to N-Queue (insert) another value"<<endl;
			cin>>set;
			}
	}
		else if(choice==2){
			if(front==NULL or rare==NULL){
				DeQueue();
			}
			else{
			
			cout<<DeQueue();
			cout<<endl<<endl;
		}
		}
		else{
			
			printQueue();
		}
		cout<<"Enter 1 to N-Queue(insert) data in queue !"<<endl<<"Enter 2 to DeQueue(delete) data from queue !"<<endl<<"Enter 3 to print the values!"<<endl<<"Enter 4 to exit the code!"<<endl;
			cin>>choice;
	}
	cout<<"We have exit the code now!"<<endl;
}