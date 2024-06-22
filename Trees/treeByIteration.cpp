#include<iostream>
#include<stdlib.h>
using namespace std;


struct BSTNode{
	int value;
	BSTNode* left;
	BSTNode* right;
	};
	
BSTNode* insertNode(BSTNode* root,int value){
    
        BSTNode* ptr= (BSTNode*) malloc(sizeof(BSTNode)) ;
        ptr->value=value;
        ptr->left=NULL;
        ptr->right=NULL;
    if (root==NULL){
        root=ptr;
        return root;
    }
    else{
        BSTNode* current= root;
        BSTNode* previous=NULL;
        while (current!=NULL){
            if(value<current->value){
                previous=current;
                current=current->left;
            }
            else{
                previous=current;
                current=current->right;
            }
        }
        if(value<previous->value){
            previous->left=ptr;
        }
        else{
            previous->right=ptr;
        }
    }
    return root;
}



void searchNode( BSTNode* root, int toSearch){
 	//cout<<"Search node was called!"<<endl;.
    BSTNode* current=root;
    while(  current!=NULL and current->value!=toSearch){
        if(toSearch<current->value){
            current=current->left;
        }
        else{
            current=current->right;
        }
    }
    if(current==NULL){
        cout<<"This value is not present in the tree!"<<endl<<endl;
    }
    else{
        cout<<"yes the given value is present in the tree!"<<endl<<endl;
    }
    
}

void deleteNode( int value){
 	cout<<"DeleteNode function was called!"<<endl;
 }	



int main(){
	BSTNode* root=NULL;
		
	int check;
	cout<<"                                             ***MENU****                                                  "<<endl;
	cout<<"Enter 1 to insert a value in BST: "<<endl<<"Enter 2 to search a value in BST"<<endl<<"Enter 3 to delete a value from BST"<<endl<<"Enter 4 for the tree traversal and printing data"<<endl<<"Enter 5 to exit the code"<<endl<<"Enter: ";
	cin>>check;
	while(check!=5){
		if(check==1){
			int value;
			cout<<"Enter the value you want to insert in the tree!"<<endl;
			cin>>value;
	//		root=insertNode(root , value);
		    root=insertNode(root, value);
		}
		else if(check==2){
			if(root!=NULL){
			
			int toSearch;
			cout<<"Enter the value to search in the tree! "<<endl;
			cin>>toSearch;
			searchNode( root, toSearch);
		}
		else {
			cout<<"The tree is empty at the moment!"<<endl;
		}
		}
		else if(check ==3){
			int toDelete;
			cout<<"Enter the value to delete from the tree! "<<endl;
			cin>>toDelete;
			deleteNode(toDelete);
			
		}
		else if(check==4){
			cout<<" will do tree traversal in the next class!"<<endl<<endl;
		}
		else {
			cout<<"invalid operation ! please select from the given operations! or enter 5 to exit the code!"<<endl<<endl;
			
		}
		cout<<endl;
		cout<<"Enter 1 to insert a vlaue in BST: "<<endl<<"Enter 2 to search a value in BST"<<endl<<"Enter 3 to delete a value from BST"<<endl<<"Enter 4 for the tree traversal and printing data"<<endl<<"Enter 5 to exit the code"<<endl<<"Enter: ";
	cin>>check;
		
	}
    cout<<"We have exit the code now!";
	
}