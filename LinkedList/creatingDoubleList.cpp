#include<iostream>
#include<stdlib.h>
using namespace std;

struct Record{
  int rollNo;
  float gpa;
  Record* next;
  Record* prev;  
};

Record* head=NULL;

void insertValue(){
    int set=1;
    while (set==1){
    Record* ptr=(Record*) malloc(sizeof(Record));
    cout<<"Enter roll no of the student: "<<endl;
    cin>>ptr->rollNo;
    cout<<"Enter cgpa of the student: "<<endl;
    cin>>ptr->gpa;
     ptr->next=NULL;
     ptr->prev=NULL;   
    if (head==NULL){
        head=ptr;
    }
    else{
        Record* current=head;
        
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=ptr;
        ptr->prev=current;
    }
        cout<<"Enter 1 if you want to insert further! "<<endl;
        cin>>set;
    } 
} 

    
void searchValue(){
    if (head==NULL){
        cout<<"The linked list is empty right now!"<<endl<<endl;
        return;
    }
    int tosearch;
    cout<<"Enter roll no to find the relevant gpa of that student!"<<endl;
    cin>>tosearch;
    
    Record* current=head;
    while(current!=NULL){
        if (current->rollNo==tosearch){
            cout<<"the gpa of that student is: "<<current->gpa<<endl<<endl;
            return;
        }
        current=current->next;
    }
    cout<<"given roll no was not found! probably that student didn't appear in the exam!"<<endl<<endl;
}
    /*while( current!=NULL and current->rollNo!=tosearch){
        current=current->next;
        
    }
    if (current==NULL){
        cout<<"value not found!"<<endl<<endl;
    }
    else{
        cout<<"gpa of that student is: "<<current->gpa<<endl<<endl;
    }
}*/


void printList(){
    //cout<<"print list function was called!"<<endl;
     if (head==NULL){
        cout<<"The list is empty right now!"<<endl<<endl;
        return;
    }
    Record* current=head;
    cout<<"NULL <--- ";
    while (current!=NULL){
        if(current->next==NULL){
            cout<<"Roll no: "<<current->rollNo<<" and gpa: "<<current->gpa<<" ---> ";
        }
        else{
        cout<<"Roll no: "<<current->rollNo<<" and gpa: "<<current->gpa<<" <---> ";
        }
        current=current->next;
    }
    cout<<"NULL"<<endl<<endl;
}


void deleteElement(){
    //cout<<"delete function was called!"<<endl<<endl;
    if (head==NULL){
        cout<<"the linked list is empty right now!"<<endl<<endl;
        return;
    }
    int todelete;
    cout<<"Enter roll number of the student whose record you want to delete!"<<endl;
    cin>>todelete;
    Record* current=head;
    if (head->next==NULL and head->rollNo!=todelete){
        cout<<"The given student's record is not present in the list!"<<endl<<endl;
        return;
    }
    if (head->rollNo==todelete){
         head=head->next;
        free(current);
        cout<<"The given student's record has been deleted!"<<endl<<endl;
        return;
    }
    else {
        current=current->next;
        while(current!=NULL){
            if (current->rollNo==todelete){
                current->prev->next=current->next;
                free(current);
                //cout<<"roll no :"<<current->rollNo<<" gpa :"<<current->gpa<<endl;
                cout<<"The given student's record has been deleted!"<<endl<<endl;
                return;
            }
            current=current->next;
        }
        cout<<"The given student's record is not present in the list!"<<endl<<endl;
    }
}


void deleteWholeList(){
    //cout<<"delete list function was called!"<<endl<<endl;
    if (head==NULL){
        cout<<"The list is already empty!"<<endl<<endl;
        return;
    }
    if (head->next==NULL){
        Record* current=head;
        head=head->next;
        free(current);
        // yahaan thora masla aarha he!!
       // head=NULL;
    }
    else{
        head=head->next;
        while(head->next!=NULL){
            free(head->prev);
            head=head->next;
        }
        free(head->prev);
        cout<<head->prev->rollNo<<endl;
        free(head);
        cout<<head->rollNo<<endl;
        head=NULL;
    }
    cout<<"The whole list has been deleted!"<<endl<<endl;
}


int main(){
    int choice;
    do{
        cout<<"Enter 1 to insert!"<<endl<<"Enter 2 to search "<<endl<<"Enter 3 to print the linkedList!"<<endl<<"Enter 4 to delete an element !"<<endl<<"Enter 5 to delete whole list!"<<endl<<"Enter 6 to exit the code!"<<endl;
    cin>>choice;
        //while (choice!=6){
   // while (choice!=6){
        if (choice==1){
            insertValue();
        }
        else if(choice==2){
            searchValue();
        }
        else  if(choice==3){
            printList();
        }
        else  if(choice==4){
            deleteElement();
        }
        else  if(choice==5){
            deleteWholeList();
        }  
        //else {
        else if(choice!=6){
            cout<<"Sorry ! the given option is not available!"<<endl<<endl;
        }    
           // cout<<"Enter 1 to insert!"<<endl<<"Enter 2 to search "<<endl<<"Enter 3 to print the linkedList!"<<endl<<"Enter 4 to delete an element!"<<endl<<"Enter 5 to delete whole list!"<<endl<<"Enter 6 to exit the code!"<<endl;
   // cin>>choice;
        
    }while(choice!=6);
    cout<<"We've exited the code! now!"<<endl;
}
