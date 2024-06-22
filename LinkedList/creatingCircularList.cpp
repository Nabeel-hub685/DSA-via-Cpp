#include<iostream>
using namespace std;

struct Record{
  int rollNo;
  float gpa;
  Record* next;  
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
     ptr->next=head;
    if (head==NULL){
        head=ptr;
        head->next=head;
    }
    else{
        Record* current=head;
        while(current->next!=head){
            current=current->next;
        }
        current->next=ptr;
        ptr->next=head;
        
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
    do{
        if (current->rollNo==tosearch){
            cout<<"the gpa of that student is: "<<current->gpa<<endl<<endl;
            return;
        }
        current=current->next;
    }while(current!=head);
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
    
    // agar poori cycle cricular list ki chalti hui dekhni hoto!
    /*while (current!=NULL){
        cout<<"Roll no: "<<current->rollNo<<" and gpa: "<<current->gpa<<" ---> ";
        current=current->next;
    }
    cout<<"NULL"<<endl<<endl;*/
    do{
        cout<<"Roll no: "<<current->rollNo<<" and gpa: "<<current->gpa<<" ---> ";
        current=current->next;
        
    }while(current!=head);
    cout<<"HEAD again!"<<endl<<endl;
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
    if(head==head->next and head->rollNo!=todelete){
        cout<<"the given student's record is not present in the list!"<<endl<<endl;
        return;
    }
    if (head->rollNo==todelete){
        // agar dabba hi ek hoto !
         if(head==head->next){
             free(head);
             head=NULL;
             cout<<"The given student's record has been deleted!"<<endl<<endl;
             return;
         }
        // agar dabbe ek se zyaada hon to!
        else{
            do{
                current=current->next;
            }while(current->next!=head);
            
            Record* temp=current;
            temp->next=head->next;
            free(head);
            head=temp->next;
            cout<<"the given student's record has been deleted!"<<endl<<endl;
        }
    }
    
    else {
        Record* previous=current;
        current=current->next;
        while(current!=head){
            if (current->rollNo==todelete){
                previous->next=current->next;
                free(current);
                cout<<"The given student's record has been deleted!"<<endl<<endl;
                return;
            }
            current=current->next;
            previous=previous->next;
        }
        cout<<"The given student's record is already not present!"<<endl<<endl;
    }
}


void deleteWholeList(){
    //cout<<"delete list function was called!"<<endl<<endl;
    if (head==NULL){
        cout<<"The list is already empty!"<<endl<<endl;
        return;
    }
    Record* current=head->next;
    Record* temp=head;
    head=head->next;
    while(head->next!=temp){
        head=current->next;
        free(current);
        current=head;
    }
    free(temp);
    free(head);
    head=NULL;
    
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