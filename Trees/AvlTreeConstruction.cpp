#include <iostream>
#include<stdlib.h>
using namespace std;


struct BSTNode
{
  int data;
  int heightLeft;
  int heightRight;
  BSTNode *left;
  BSTNode *right;
};

BSTNode *rightShift(BSTNode *unbalanceNode)
{
  BSTNode *tmp = unbalanceNode->left->right;
  BSTNode *retNode = unbalanceNode->left;
  retNode->right = unbalanceNode;
  unbalanceNode->left = tmp;
  
    if(unbalanceNode->right!=NULL){
	
    unbalanceNode->heightRight=unbalanceNode->right->heightRight+1;
}

  if(unbalanceNode->left==NULL and unbalanceNode->right==NULL){
  
  unbalanceNode->heightLeft=unbalanceNode->heightRight=0;
}
  if (unbalanceNode->left=NULL){
 	unbalanceNode->heightLeft=0;
 }
  if(unbalanceNode->right==NULL) {
 	unbalanceNode->heightRight=0;
 }
   
/*
	if(unbalanceNode->right->heightRight>unbalanceNode->right->heightLeft){
		unbalanceNode->heightRight= unbalanceNode->right->heightRight +1;
	}
	 if (unbalanceNode->right->heightRight<unbalanceNode->right->heightLeft){
		unbalanceNode->heightRight= unbalanceNode->right->heightLeft +1;
	}
	 if(unbalanceNode->left->heightRight>unbalanceNode->left->heightLeft){
		unbalanceNode->heightLeft= unbalanceNode->left->heightRight +1;
	}
	 if(unbalanceNode->left->heightRight<unbalanceNode->left->heightLeft){
	    unbalanceNode->heightLeft= unbalanceNode->left->heightLeft +1;

	}
	*/

  if(retNode->right->heightRight>retNode->right->heightLeft){
  
  retNode->heightRight=retNode->right->heightRight+1;
  
}
else{
 
  retNode->heightRight=retNode->right->heightLeft+1;
}

  
  return retNode;
}

BSTNode *leftShift(BSTNode *unbalanceNode)
{
  BSTNode *tmp = unbalanceNode->right->left;
  BSTNode *retNode = unbalanceNode->right;
  retNode->left = unbalanceNode;
  unbalanceNode->right = tmp;
  
  //unbalanceNode->heightLeft=unbalanceNode->heightRight=0;
  
  if(unbalanceNode->right!=NULL){
	
    unbalanceNode->heightRight=unbalanceNode->right->heightRight+1;
}
 
   if(unbalanceNode->left==NULL and unbalanceNode->right==NULL){
  
  unbalanceNode->heightLeft=unbalanceNode->heightRight=0;
}
  if (unbalanceNode->left=NULL){
 	unbalanceNode->heightLeft=0;
 }
  if(unbalanceNode->right==NULL) {
 	unbalanceNode->heightRight=0;
 }
   /*

	if(unbalanceNode->right->heightRight>unbalanceNode->right->heightLeft){
		unbalanceNode->heightRight= unbalanceNode->right->heightRight +1;
	}
	 if (unbalanceNode->right->heightRight<unbalanceNode->right->heightLeft){
		unbalanceNode->heightRight= unbalanceNode->right->heightLeft +1;
	}
	 if(unbalanceNode->left->heightRight>unbalanceNode->left->heightLeft){
		unbalanceNode->heightLeft= unbalanceNode->left->heightRight +1;
	}
	 if(unbalanceNode->left->heightRight<unbalanceNode->left->heightLeft){
	    unbalanceNode->heightLeft= unbalanceNode->left->heightLeft +1;

	}
  */
  if(retNode->left->heightRight>retNode->left->heightLeft){
  
  retNode->heightLeft=retNode->left->heightRight+1;
}
else{
	
 retNode->heightLeft=retNode->left->heightLeft+1;
}


  
  return retNode;
}

BSTNode *insert(BSTNode *root, int data)
{
  if (root == NULL)
  {
    BSTNode *node = (BSTNode *)malloc(sizeof(BSTNode));
    node->data = data;
    node->left = node->right = NULL;
    node->heightLeft = node->heightRight = 0;
    return node;
  }
  if (data < root->data)
  {
    root->left = insert(root->left, data);
   // root->heightLeft++;
   if(root->left->heightRight>root->left->heightLeft){
  
  root->heightLeft=root->left->heightRight+1;
}
else{
 
  root->heightLeft=root->left->heightLeft+1;
}
 if(root->data==150 and data==120){
 	cout<<"heightright of 150= "<<root->heightRight<<endl;
 	//root->heightRight=1;
 	//root->heightRight=1;
 }
    int balanceFactor = root->heightLeft - root->heightRight;
    if(root->data==150 ){
 	cout<<"150 wale root ka balance factor: "<<balanceFactor<<endl;
 	
 }
    
    if (balanceFactor > 1)
    {
      if (data < root->left->data)
      {
        root = rightShift(root);
      }
      else
      {
        // double shift (l, r)
        root->left = leftShift(root->left);
        root = rightShift(root);
      }
    }
    // cout << "Hello";
    return root;
  }
  else if (data > root->data)
  {
    root->right = insert(root->right, data);
    //root->heightRight++;
    if(root->right->heightRight>root->right->heightLeft){
  
  root->heightRight=root->right->heightRight +1;
}
else{
 
  root->heightRight=root->right->heightLeft +1;
}
 if (root->data==150){
 	cout<<"150 ki height right= "<<cout<<root->heightRight;
 }
    int balanceFactor = root->heightLeft - root->heightRight;
    
    if (balanceFactor < -1)
    {
      if (data > root->right->data)
      {
        cout<<"before root data: "<<root->data<<endl<<endl;

        root = leftShift(root);
        cout<<" after root-data: "<<root->data<<endl<<endl;
        
      }
      else
      {
        // double shift (r, l)
        root->right = rightShift(root->right);
        root = leftShift(root);
      }
    }
    return root;
  }
}

// Search
BSTNode *search(BSTNode *root, int toSearch)
{
  if (root == NULL)
  {
    return NULL;
  }
  if (toSearch == root->data)
  {
    return root;
  }
  if (toSearch < root->data)
  {
    search(root->left, toSearch);
  }
  else if (toSearch > root->data)
  {
    search(root->right, toSearch);
  }
}

// In Order Traversial
void inOrderTraversial(BSTNode *root)
{
  if (root == NULL)
  {
    return;
  }
  inOrderTraversial(root->left);
  cout << root->data << " ";
  inOrderTraversial(root->right);
}

// Pre Order Traversial
void preOrderTraversial(BSTNode *root)
{
  if (root == NULL)
  {
    return;
  }
  cout << root->data << " ";
  preOrderTraversial(root->left);
  preOrderTraversial(root->right);
}

// Post Order Traversial
void postOrderTraversial(BSTNode *root)
{
  if (root == NULL)
  {
    return;
  }
  postOrderTraversial(root->left);
  postOrderTraversial(root->right);
  cout << root->data << " ";
}

BSTNode *min(BSTNode *root)
{
  if (root == NULL)
  {
    return NULL;
  }
  if (root->left == NULL)
  {
    return root;
  }
  min(root->left);
}

BSTNode *max(BSTNode *root)
{
  if (root == NULL)
  {
    return NULL;
  }
  if (root->right == NULL)
  {
    return root;
  }
  max(root->right);
}

BSTNode *deleteNode(BSTNode *root, int toDelete)
{
  if (root == NULL)
  {
    cout << "Value not Found !" << endl;
    return root;
  }
  if (toDelete < root->data)
  {
    root->left = deleteNode(root->left, toDelete);
  }
  else if (toDelete > root->data)
  {
    root->right = deleteNode(root->right, toDelete);
  }
  else
  {
    if (root->left == NULL)
    {
      BSTNode *tmp = root->right;
      free(root);
      cout << "Deleted Successfully " << endl;
      return tmp;
    }
    if (root->right == NULL)
    {
      BSTNode *tmp = root->left;
      free(root);
      cout << "Deleted Successfully " << endl;
      return tmp;
    }
    BSTNode *tmp = root->right;
    BSTNode *minNode = min(tmp);
    root->data = minNode->data;
    root->right = deleteNode(root->right, minNode->data);
  }
}

int main()
{
  BSTNode *root = NULL;

  int a;
  do
  {
    cout << "Enter 1 to Insert a value" << endl
         << "Enter 2 to Search a value" << endl
         << "enter 3 to print In Order Traversial" << endl
         << "Enter 4 to print PreOrder Traversial" << endl
         << "Enter 5 to Print Post Order Traversial " << endl
         << "Enter 6 to find Minimum Node " << endl
         << "Enter 7 to Find Maximum Node" << endl
         << "Enter 8 to Delete a Node " << endl
         << "Enter 9 to Quit " << endl;
    cin >> a;
    if (a == 1)
    {
      int data;
      cout << "Enter value to Insert : ";
      cin >> data;
      root = insert(root, data);
    }
    else if (a == 2)
    {
      int toSearch;
      cout << "Enter value to Search for : ";
      cin >> toSearch;
      BSTNode *ptr = search(root, toSearch);
      if (ptr == NULL)
      {
        cout << "Not found" << endl;
      }
      else
      {
        cout << "Found" << endl;
      }
    }
    else if (a == 3)
    {
      inOrderTraversial(root);
      cout << endl;
    }
    else if (a == 4)
    {
      preOrderTraversial(root);
      cout << endl;
    }
    else if (a == 5)
    {
      postOrderTraversial(root);
      cout << endl;
    }
    else if (a == 6)
    {
      BSTNode *minNode = min(root);
      if (minNode == NULL)
      {
        cout << "Tree is Empty" << endl;
      }
      else
      {
        cout << minNode->data << endl;
      }
    }
    else if (a == 7)
    {
      BSTNode *maxNode = max(root);
      if (maxNode == NULL)
      {
        cout << "Tree is Empty" << endl;
      }
      else
      {
        cout << maxNode->data << endl;
      }
    }
    else if (a == 8)
    {
      int toDelete;
      cout << "Enter value you want to Delete : ";
      cin >> toDelete;
      root = deleteNode(root, toDelete);
    }
    else if (a == 9)
    {
      cout << "Quit Successfully!!!" << endl;
    }
    else
    {
      cout << "Invalid Number!!! " << endl;
    }
  } while (a != 9);
}
