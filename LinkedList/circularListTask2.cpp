#include<iostream>
using namespace std;

struct Node{
  int rollNo;
  float gpa;
  int index=0;
  Node* next;  
};

Node* head=NULL;
int counter=0;

void insertValue(){
    int set=1;
    while (set==1){
    Node* ptr=(Node*) malloc(sizeof(Node));
    cout<<"Enter roll no of the student: "<<endl;
    cin>>ptr->rollNo;
    cout<<"Enter cgpa of the student: "<<endl;
    cin>>ptr->gpa;
     ptr->next=NULL;
        ptr->index=++counter;
        
    if (head==NULL){
        head=ptr;
        ptr->index=0;
        ptr->next=head;
    }
    else if (head->next==head){
        if(head->rollNo<ptr->rollNo){
            head->next=ptr;
            ptr->index=1;
            ptr->next=head;
        }
        
        else{
            Node* current=head;
            head=ptr;
            ptr->next=current;
            head->index=0;
            current->index=1;
            current->next=head;
        }
    }
     else{
         Node* previous=NULL;
         Node* current=head;
         do{
             if(current->rollNo>ptr->rollNo){
                 break;
             }
             previous=current;
             current=current->next;
         }while(current!=head and current->rollNo<ptr->rollNo);
         
         int index;
         if(previous==NULL){
             ptr->next=current;
             head=ptr;
             ptr->index=0;
              index=1;
             Node* temp=current;
             while(current->next!=temp){
                 current->index=index;
                 current=current->next;
                 index++;
             }
             current->next=head;
             current->index=index;
         }
         else{
         previous->next=ptr;
         ptr->next=current;
         ptr->index=previous->index+1;
          index=ptr->index+1;
         
             if(current!=head){
         
                 while(current->next!=head){
                      current->index=index;
                      current=current->next;
                      index++;
                  }
                 current->index=index;
                 current->next=head;
              }
        }
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
    
    Node* current=head;
    do{
        if (current->rollNo==tosearch){
            cout<<"the gpa of that student is: "<<current->gpa<<endl<<endl;
            return;
        }
        current=current->next;
    }while(current!=head);
    cout<<"given roll no was not found! probably that student didn't appear in the exam!"<<endl<<endl;
}
    


void printList(){
    //cout<<"print list function was called!"<<endl;
    if (head==NULL){
        cout<<"The list is empty right now!"<<endl<<endl;
        return;
    }
    Node* current=head;
    do{
        cout<<"index: "<<current->index<<" ,Roll no: "<<current->rollNo<<" and gpa: "<<current->gpa<<" ---> ";
        current=current->next;
    }while(current!=head);
    cout<<"HEAD again"<<endl<<endl;
}


void deleteElement(){
    if (head==NULL){
        cout<<"the linked list is empty right now!"<<endl<<endl;
        return;
    }
    int todelete;
    cout<<"Enter roll number of the student whose record you want to delete!"<<endl;
    cin>>todelete;
    Node* current=head;
    if(head==head->next and head->rollNo!=todelete){
        cout<<"the given student's record is not present in the list!"<<endl<<endl;
        return;
    }
    int index=0;
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
                current->index=index;
                index++;
            }while(current->next!=head);
            
            Node* temp=current;
            temp->next=head->next;
            free(head);
            head=temp->next;
            cout<<"the given student's record has been deleted!"<<endl<<endl;
        }
    }
    
    else {
        Node* previous=current;
        current=current->next;
        while(current!=head){
            if (current->rollNo==todelete){
                previous->next=current->next;
                index=previous->index+1;
                
                while(previous->next!=head){
                    previous->next->index=index;
                    previous=previous->next;
                    index++;
                }
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
    counter=0;
    if (head==NULL){
        cout<<"The list is already empty!"<<endl<<endl;
        return;
    }
    Node* current=head->next;
    Node* temp=head;
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

void getTotalCount(){
    /* int count=0;
     Node* current=head;
     while(current!=NULL){
         current=current->next;
         count++;
     }
     */
    cout<<"The total count of the list right now : "<<counter<<" Nodes"<<endl<<endl;
     
 }

int main(){
    int choice;
    do{
        cout<<"Enter 1 to insert!"<<endl<<"Enter 2 to search "<<endl<<"Enter 3 to print the linkedList!"<<endl<<"Enter 4 to delete an element !"<<endl<<"Enter 5 to delete whole list!"<<endl<<"Enter 6 to get the total count!"<<endl<<"Enter 7 to exit the code!"<<endl;
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
        else if (choice==6){
            getTotalCount();
        }
        //else {
        else if(choice!=7){
            cout<<"Sorry ! the given option is not available!"<<endl<<endl;
        }    
           // cout<<"Enter 1 to insert!"<<endl<<"Enter 2 to search "<<endl<<"Enter 3 to print the linkedList!"<<endl<<"Enter 4 to delete an element!"<<endl<<"Enter 5 to delete whole list!"<<endl<<"Enter 6 to exit the code!"<<endl;
   // cin>>choice;
        
    }while(choice!=7);
    cout<<"We've exited the code! now!"<<endl;
}