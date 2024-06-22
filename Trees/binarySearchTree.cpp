#include<iostream>
#include<stdlib.h>
using namespace std;

struct BSTNode{
    int value;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* insertNode( BSTNode* root, int value){
     if(root==NULL){
         root=  (BSTNode*) malloc(sizeof(BSTNode));
         root->value=value;
         root->right=NULL;
         root->left=NULL;
         return root;
     }
     if(root->value>value){
        root->left=insertNode(root->left,value);
    }
    else{
        root->right=insertNode(root->right,value);
    }
}

void searchNode(BSTNode* root, int toSearch){
    if (root==NULL){
        cout<<"This value is not present in the tree!"<<endl;
        return;
    }
    if (root->value==toSearch){
        cout<<"Yes! this value is present in the tree!"<<endl;
        return;
    }
    
    if (root->value>toSearch){
        searchNode(root->left, toSearch);
    }
    else{
        searchNode(root->right, toSearch);
    }
    
}

BSTNode* findMin(BSTNode* root){
	//By recursion!!!
	
	if(root->left==NULL){
		//cout<<"Minimum value : "<<root->value;
		return root;
	}
	BSTNode* max=findMin(root->left);
    return max;
	
	//By iteration!!!
	
	/*BSTNode* current=root;
	
	while(current->left!=NULL){
		current=current->left;
	}
	//cout<<"Minimum value: "<<current->value<<endl;
    return current;*/
}

BSTNode* findMax(BSTNode* root){
	// by recursion!!!
	if(root->right==NULL){
		//cout<<"Maximum value : "<<root->value;
		return root;
	}
	BSTNode* max =findMax(root->right);
    return max;

	
	// by iteration!!!
	
	/*BSTNode* current=root;
	
	while(current->right!=NULL){
		current=current->right;
	}
	//cout<<"Maximum value: "<<current->value<<endl;
    return current;*/
	
}



BSTNode* deleteNode(BSTNode* root, int toDelete){
   // cout<<" delete function was called!"<<endl;
   if(root==NULL){
    cout<<"the given todelete value is already not present in the tree!!"<<endl;
    return root;
   }

   if(toDelete<root->value){
    root->left=deleteNode(root->left, toDelete);
   }
   else if(toDelete>root->value){
    root->right=deleteNode(root->right, toDelete);

   }

   else {
    // case of 0 child or 1 right child!
      if(root->left==NULL){
        BSTNode* temp= root->right;
        free(root);
        cout<<"The given node has been deleted!!"<<endl;
        return temp;
        }

    // case of 0 child or 1 left child    
     if(root->right==NULL){
        BSTNode* temp= root->left;
        free(root);
        cout<<"The given node has been deleted!!"<<endl;
        return temp;
     }
      // case of 2 children
     BSTNode* max= findMax(root->left);
     root->value=max->value;
     //cout<<max->left->value;
     //root->left=max->left;
     root->left=deleteNode(root->left,max->value);
     //free(max);
     //cout<<"The given node has been deleted!!"<<endl;
     return root;
  }
}
   


void InOrderTraversal(BSTNode* root){
	if(root==NULL){
		return;
	}
	InOrderTraversal(root->left);
	cout<<root->value<<" ";
	InOrderTraversal(root->right);
	
}

void preOrderTraversal(BSTNode* root){
	if(root==NULL){
		return;
	}
	cout<<root->value<<" ";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

void postOrderTraversal(BSTNode* root){
	if(root==NULL){
		return;
	}
		postOrderTraversal(root->left);
		postOrderTraversal(root->right);
		cout<<root->value<<" ";

}




int main(){
    BSTNode* root=NULL;
    cout<<"        **Menu**      "<<endl;
    cout<<"Enter 1 to insert node!"<<endl<<"Enter 2 to search Node!"<<endl<<"Enter 3 to delete a node"<<endl<<"Enter 4 for inorder tree traversal!"<<endl<<"Enter 5 for pre order tree traversal!"<<endl<<"Enter 6 for post order tree traversal!"<<endl<<"Enter 7 to find max node! "<<endl<<"Enter 8 to find min node! "<<endl<<"Enter 9 to exit the code!"<<endl<<"Enter :   ";

    int check;
    char menu='n';
    
    cin>>check;
    while(check!=9 and menu=='n'){
        if(check==1){
            int value;
            cout<<"Enter value to insert: ";
            cin>>value;
            root=insertNode(root, value);
            cout<<"The given value has been inserted in the tree!"<<endl;
        }
        
        else if(check==2){
            if(root!=NULL){
            int toSearch;
            cout<<"Enter value to search: ";
            cin>>toSearch;
            searchNode(root, toSearch);
            }
            else{
                cout<<"The Tree is empty right now!"<<endl;
            }
        }
        
        else if(check==3){
            if(root!=NULL){
                int toDelete;
                cout<<"Enter the value to delete the node: ";
                cin>>toDelete;
                root=deleteNode(root, toDelete);
               // cout<<"The given root has been deleted!"<<endl;
            }
            else{
                cout<<"The tree is already empty right now!"<<endl;
            }
        } 
        
        else if(check==4){
        	if(root!=NULL){
        		cout<<"InOrder Traversal:  ";
        		InOrderTraversal(root);
        		cout<<endl;
			}
			else{
				cout<<"The tree is empty at the moment!"<<endl;
			}
		}
		
		else if(check==5){
			if(root!=NULL){
				cout<<"Pre Order Traversal:  ";
        		preOrderTraversal(root);
        		cout<<endl;
			}
			else{
				cout<<"The tree is empty at the moment!"<<endl;
			}
		}
		
		else if(check==6){
			if(root!=NULL){
			cout<<"Post Order Traversal:  ";
        		postOrderTraversal(root);
        		cout<<endl;
				
			}
			else{
				cout<<"The tree is empty at the moment!"<<endl;
			}
		}
		
		else if(check==7){
			if(root!=NULL){
                
			BSTNode* current=	findMax(root);
            cout<<"Maximum value: "<<current->value<<endl;
				}
				
			else{
				cout<<"The tree is empty at the moment!"<<endl;
			}
		}
		
		else if(check==8){
			if(root!=NULL){
				BSTNode* current=	findMin(root);
            cout<<"Minimum value: "<<current->value<<endl;
				}
			else{
				cout<<"The tree is empty at the moment!"<<endl;
			}
			
		}
		
		
        else{
            cout<<"this operation is not available ! Enter valid operation from the menu!"<<endl;
        }
       // char menu;
        cout<<endl<<"Enter 'n' for the menu again or any other key to exit the code!"<<endl;
        cin>>menu;
        if (menu=='n'){
            
            cout<<endl<<"        **Menu**      "<<endl;
            cout<<"Enter 1 to insert node!"<<endl<<"Enter 2 to search Node!"<<endl<<"Enter 3 to delete a node"<<endl<<"Enter 4 for inorder tree traversal!"<<endl<<"Enter 5 for pre order tree traversal!"<<endl<<"Enter 6 for post order tree traversal!"<<endl<<"Enter 7 to find max node! "<<endl<<"Enter 8 to find min node! "<<endl<<"Enter 9 to exit the code!"<<endl<<"Enter :   ";

    cin>>check;
        }
             
    }
    cout<<"We've exit the code successfully!";
}
