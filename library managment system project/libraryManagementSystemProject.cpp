#include<iostream>
#include<stdlib.h>

using namespace std;
int count=0;
int counted=0;

struct BookNode{
    int bookID;
    string bookTitle;
    string bookAuthor;
    string bookGenre;
    int noOfCopies;
    int heightLeft;
    int heightRight;
    BookNode* left;
    BookNode* right;
};

struct UserNode{
	int userID;
	string userName;
    string userEmail;
    string userAddress;
    string userNumber;
	int bookHold;
	UserNode* next;
};

int checkAdmin(string password){
	string code="!@#$%^&*()";
	if(code==password){
		return 1;
	}
	return -1;
}

//BookNode* root= NULL;
int maxHeight(int a , int b){
	if(a>b){
		return a;
	}
	else {
		return b;
	}
}

BookNode *rightShift(BookNode *unbalanceNode){

  BookNode *tmp = unbalanceNode->left->right;
  BookNode *retNode = unbalanceNode->left;
  retNode->right = unbalanceNode;
  unbalanceNode->left = tmp;
  
if(unbalanceNode->right!=NULL){
	
    unbalanceNode->heightRight= maxHeight(unbalanceNode->right->heightRight,unbalanceNode->right->heightLeft) +1;
}
if(unbalanceNode->left!=NULL){
	
   unbalanceNode->heightLeft= maxHeight(unbalanceNode->left->heightRight,unbalanceNode->left->heightLeft) +1;
}

  if (unbalanceNode->left==NULL){
 	unbalanceNode->heightLeft=0;
 }
  if(unbalanceNode->right==NULL) {
 	unbalanceNode->heightRight=0;
 }
 
retNode->heightRight= maxHeight(retNode->right->heightRight,retNode->right->heightLeft) +1;
  
  return retNode;
}


BookNode *leftShift(BookNode *unbalanceNode){


  BookNode *tmp = unbalanceNode->right->left;
  BookNode *retNode = unbalanceNode->right;
  retNode->left = unbalanceNode;
  unbalanceNode->right = tmp;
  
  //unbalanceNode->heightLeft=unbalanceNode->heightRight=0;
  
  if(unbalanceNode->right!=NULL){
	
    unbalanceNode->heightRight= maxHeight(unbalanceNode->right->heightRight,unbalanceNode->right->heightLeft) +1;
}
if(unbalanceNode->left!=NULL){
	
   unbalanceNode->heightLeft= maxHeight(unbalanceNode->left->heightRight,unbalanceNode->left->heightLeft) +1;
}
 
   
  if (unbalanceNode->left==NULL){
 	unbalanceNode->heightLeft=0;
 }
  if(unbalanceNode->right==NULL) {
 	unbalanceNode->heightRight=0;
 }
 
retNode->heightLeft= maxHeight(retNode->left->heightRight,retNode->left->heightLeft) +1;

return retNode;
}


BookNode* addBooks(BookNode* root, int bookID, string bookTitle,  string bookAuthor, string bookGenre, int noOfCopies){
   //BookNode* addBooks(BookNode* root, int bookID){
  // cout<<"Nabeel"<<endl;
    if (root == NULL)
  {
   // BookNode* node = (BookNode *)malloc(sizeof(BookNode));
   BookNode* node= new BookNode();
    node->bookID = bookID;
    node->bookTitle= bookTitle;
    node->bookAuthor= bookAuthor;
    node->bookGenre= bookGenre;
    node->noOfCopies=noOfCopies;
    node->left = node->right = NULL;
    node->heightLeft = node->heightRight = 0;
    
    return node;
  }
 // cout<<"Nabeel2"<<endl;
  if (bookID < root->bookID)

  {
    root->left = addBooks(root->left,  bookID , bookTitle, bookAuthor, bookGenre, noOfCopies);
    //root->left = addBooks(root->left, bookID );
   // root->heightLeft++;

root->heightLeft= maxHeight(root->left->heightLeft,root->left->heightRight) +1;

int balanceFactor = root->heightLeft - root->heightRight;
if (balanceFactor > 1)
    {
      if (bookID < root->left->bookID)
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
  else if (bookID > root->bookID)
  {
    root->right = addBooks(root->right, bookID , bookTitle, bookAuthor, bookGenre, noOfCopies);
    //root->right = addBooks (root->right, bookID);
    //root->heightRight++;
   root->heightRight= maxHeight(root->right->heightLeft, root->right->heightRight) +1;
   
int balanceFactor = root->heightLeft - root->heightRight;
    
    if (balanceFactor < -1)
    {
      if (bookID > root->right->bookID)
      {
        root = leftShift(root);
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



BookNode* findmin(BookNode* root){
  if (root->left==NULL){
    return root;
  }
  BookNode* min= findmin(root->left);
  return min;
}

BookNode* removeBooks(BookNode* root, int toremove){
  
  if (root == NULL)
  {
    cout << "This book is already not present in the library!" << endl;
    return root;
  }
  if (toremove < root->bookID)
  {
    root->left = removeBooks(root->left, toremove);
    if (root->left == NULL)
    {
      root->heightLeft = 0;
    }
    else
    {
      root->heightLeft = maxHeight(root->left->heightLeft, root->left->heightRight) + 1;
    }
  }
  else if (toremove > root->bookID)
  {
    root->right = removeBooks(root->right, toremove);
    if (root->right == NULL)
    {
      root->heightRight = 0;
    }
    else
    {
      root->heightRight = maxHeight(root->right->heightLeft, root->right->heightRight) + 1;
    }
  }
  else
  {
    if (root->left == NULL)
    {
      BookNode *tmp = root->right;
      free(root);
      cout << "The given ID book  has been removed from the library Successfully " << endl;
      return tmp;
    }
    if (root->right == NULL)
    {
      BookNode *tmp = root->left;
      free(root);
      cout << "The given ID book  has been removed from the library Successfully " << endl;
      return tmp;
    }
    BookNode *tmp = root->right;
    BookNode *minNode = findmin(tmp);
    root->bookID = minNode->bookID;
    root->right = removeBooks(root->right, minNode->bookID);
    root->heightRight = maxHeight(root->right->heightLeft, root->right->heightRight) + 1;
  }
}



void listAllBooks(BookNode* root ){

    if (root == NULL)
  {
    return;
  }
  listAllBooks(root->left);
  cout << "Book ID: "<<root->bookID << "   Book Title : "<<root->bookTitle << "   "<< "By Author:  " << root->bookAuthor<<endl;
  listAllBooks(root->right);
    
}

void listAvailableBooks(BookNode* root){
    //cout<<"only available books will be listed !"<<endl;
    if (root == NULL)
  {
    return;
  }
  listAvailableBooks(root->left);
  if(root->noOfCopies>0){
  	if(root->noOfCopies==1){
  	 cout << "Book ID: "<<root->bookID << "   Book Title : "<<root->bookTitle << "   "<< "By Author:  " << root->bookAuthor<< "   (1 copy available! )"<<endl;
	
  		
	  }
	  else {
	  
 cout << "Book ID: "<<root->bookID << "   Book Title : "<<root->bookTitle << "   "<< "By Author:  " << root->bookAuthor<< "   ("<<root->noOfCopies<<" copies available! )"<<endl;
  }
}
  listAvailableBooks(root->right);

}

int  registerYourself(string userName, string userEmail, string userAddress , string userNumber, UserNode* arr[], int size){
	
	count++;
	UserNode* ptr = new (UserNode);
	ptr->userName= userName;
	ptr->userEmail= userEmail;
	ptr->userAddress= userAddress;
	ptr->userNumber= userNumber;
	ptr->userID=count;
	ptr->bookHold=-1;
	ptr->next=NULL;
	
	int key = count%size;
	
	if (arr[key] == NULL)
  {
    arr[key] = ptr;
     return count;
  }
  UserNode* curr = arr[key];
  while (curr->next != NULL)
  {
    curr = curr->next;
  }
  curr->next = ptr;
  return count;
  
}

int searchBookToCheck(BookNode* root, int bookID){
	if (root==NULL){
		return -1;
	}
	if (root->bookID==bookID){
        
       return 1;
    }
    
    if (root->bookID>bookID){
        searchBookToCheck(root->left, bookID);
    }
    else{
        searchBookToCheck(root->right, bookID);
    }
	
}

void searchBookToAdd(BookNode* root, int bookID, int noOfCopies){
	
	if (root->bookID==bookID){
		root->noOfCopies= root->noOfCopies + noOfCopies;
        return ;
    }
    
    if (root->bookID>bookID){
        searchBookToAdd(root->left, bookID, noOfCopies);
    }
    else{
        searchBookToAdd(root->right, bookID, noOfCopies);
    }
	
}

int searchBookToIssue(BookNode* root, int bookID){
	
if (root==NULL){
        //cout<<"This book is not present in the library"<<endl;
        return -2;
    }
    if (root->bookID==bookID){
        //cout<<"Yes! this value is present in the tree!"<<endl;
        if(root->noOfCopies==0){
        	return -1;
		}
		root->noOfCopies= root->noOfCopies -1;
        
        return 1;
    }
    
    if (root->bookID>bookID){
        searchBookToIssue(root->left, bookID);
    }
    else{
        searchBookToIssue(root->right, bookID);
    }
    
}
	
	

void issueBook( int userid, int bookid, UserNode* arr[], int size){
	
    //cout<<"book will be issued!"<<endl;
    int key = userid % size;
  UserNode* curr = arr[key];
  while (curr != NULL)
  {
    if (curr->userID == userid)
    {
      curr->bookHold= bookid;
      cout<<"you have been issued that book! take it from the library , thank you!"<<endl<<endl;
      return ;
    }
    curr = curr->next;
  }
  
}

void searchBookToReturn(BookNode* root, int bookID){
	

    if (root->bookID==bookID){
       
        root->noOfCopies= root->noOfCopies +1;
        
        return ;
    }
    
    if (root->bookID>bookID){
        searchBookToReturn(root->left, bookID);
    }
    else{
        searchBookToReturn(root->right, bookID);
    }
    
}  
  
    
int returnBook(int userid, UserNode* arr[], int size){
	int key = userid % size;
  UserNode* curr = arr[key];
  while (curr != NULL)
  {
    if (curr->userID == userid)
    {
      /*curr->bookHold= bookid;
      return 1;*/
      if(curr->bookHold==-1){
      	return -2;
	  }
      int temp= curr->bookHold;
      curr->bookHold=-1;
      return temp;
    }
    curr = curr->next;
  }
  if (curr == NULL)
  {
    return -1;
  }
   
}


void printUsersList(UserNode* arr[], int size){
	cout<<"Here, below is the list of all the registered users in the library so far!  "<<endl<<endl;
	int counter=0;
	UserNode* key;
	while(counter <= 9){
		 key= arr[counter];
		 if(key==NULL){
		 	counter++;
		 }
		 else{
		 	while(key!=NULL){
		
		 		cout<<"User ID : "<<key->userID<< "   User Name:  "<<key->userName << "   User Email: "<<key->userEmail<< "     User Phone Number: "<< key->userNumber<<endl;
		 		key=key->next;
			 }
			 counter++;
		 }
		
	}
	
		cout<<endl;
	}



int ifUser(UserNode* arr[], int size){
	int counter=0;
	int counting=0;
	
	UserNode* key;
	while(counter <= 9){
		 key= arr[counter];
		 if(key==NULL){
		 	counter++;
		 }
		 else{
		 	while(key!=NULL){
		 		counting++;
		 		key=key->next;
			 }
			 counter++;
		 }
		
	}
	if(counting==0){
		return -1;
	}
	else{
		return 1;
	}

}



int checkBookOfUser(int userid, UserNode* arr[], int size){
		int key = userid % size;
  UserNode* curr = arr[key];
  while (curr != NULL)
  {
    if (curr->userID == userid)
    {
       return curr->bookHold;
      }
      
    curr = curr->next;
  }
  if (curr == NULL)
  {
    return -2;
  }
   
}

int ifBookUser(UserNode* arr[], int size){
    int counter=0;
//	int counting=0;
	int countBooks=0;
	
	UserNode* key;
	while(counter <= 9){
		 key= arr[counter];
		 if(key==NULL){
		 	counter++;
		 }
		 else{
		 	while(key!=NULL){
		 		//counting++;
		 		if(key->bookHold!=-1){
		 			countBooks++;
		 		//	cout<<"User ID : "<<key->userID<< "   User Name:  "<<key->userName <<  "     User Phone Number: "<< key->userNumber<< "    Book Hold: "<< key->bookHold<<endl;
	
			}
		 		key=key->next;
		 	
			 }
			 counter++;
		 }
		
	}
	 if(countBooks==0){
            return -1;
	}
	else{
		return 1;
	}

}

void printBookIssuedUsers(UserNode* arr[], int size){
	//cout<<"all book issued users will be printed: "<<endl;
	cout<<"Here, below is the list of all the  users who issued books !  "<<endl<<endl;
	int counter=0;
//	int counting=0;
//	int countBooks=0;
	
	UserNode* key;
	while(counter <= 9){
		 key= arr[counter];
		 if(key==NULL){
		 	counter++;
		 }
		 else{
		 	while(key!=NULL){
		 		//counting++;
		 		if(key->bookHold!=-1){
		 		//	countBooks++;
		 			cout<<"User ID : "<<key->userID<< "   User Name:  "<<key->userName <<  "     User Phone Number: "<< key->userNumber<< "    Book Hold: ID-"<< key->bookHold<<endl;
	
			}
		 		key=key->next;
		 	
			 }
			 counter++;
		 }
		
	}
	 
		cout<<endl;
	}



int removeUser(int userid , UserNode* arr[], int size){
	int key = userid % size;
	UserNode* head= arr[key];
	UserNode* current= arr[key];
	if (head==NULL){
		return -1;
	}
	if (head->userID==userid){
		if(head->next==NULL){
			free(head);
			//head=NUll;
			arr[key]=NULL;
			return 1;
		}
		
			head=head->next;
			free(current);
			arr[key]=head;
			return 1;
			
	}
	else{
		UserNode* previous=head;
		current= head->next;
		while(current->next!=NULL){
			if(current->userID==userid){
				previous->next=current->next;
				free(current);
				return 1;
			}
			previous=previous->next;
			current=current->next;
		}
		return -1;
	}
}

void booksByAuthor(BookNode* root, string author){
	//cout<<"all books of any specific author"<<endl;
	if (root == NULL)
  {
    return;
  }
  booksByAuthor(root->left, author);
  if(root->bookAuthor==author){
       counted++;
  cout << "Book ID: "<<root->bookID << "   Book Title : "<<root->bookTitle <<endl;
}
  booksByAuthor(root->right, author);
    
}
	


void booksByCategory(BookNode* root, string genre){
	
//	cout<<"All books of any specific category: "<<endl;
if (root == NULL)
  {
    return ;
  }
  booksByCategory(root->left, genre);
  if(root->bookGenre==genre){
      counted++;
  cout << "Book ID: "<<root->bookID << "   Book Title : "<<root->bookTitle <<endl;
}
 booksByCategory(root->right, genre);
    
}


int main(){
    BookNode* root= NULL;
    
    UserNode* userTable[10];
    for (int i = 0; i < 10; i++)
  {
    userTable[i] = NULL;
  }
    
    
    cout<<"                                     ****** Libraray Management System ******                             "<<endl<<endl;
 
string check;
cout << "                                                 **** MENU ****                                                      "<<endl<<endl;
cout <<" Enter 1 to add books in the library (For admin section only): "<<endl;
cout <<" Enter 2 to remove books from the library (For admin section only): "<<endl;
cout <<" Enter 3 to show the list of all the books in the library: "<<endl;
cout <<" Enter 4 to show the list of currently available books only: "<<endl;
cout <<" Enter 5 to register yourself in the system as a valid user: "<<endl;
cout <<" Enter 6 to issue a book from the library : "<<endl;
cout <<" Enter 7 to return the book back : "<<endl;
cout <<" Enter 8 to print the list of all the registered users of LMS( For admin section only):  "<<endl;
cout <<" Enter 9 to print to check the bookID issued by any specific user(For admin section only):  "<<endl;
cout <<" Enter 10 to print the list of all those users who issued books( For admin section only):   "<<endl;
cout <<" Enter 11 to remove any user from the system( For admin section only):  "<<endl;
cout <<" Enter 12 to search the books by any specific author:  "<<endl;
cout <<" Enter 13 to search the books of any specific category:  "<<endl;
cout <<" Enter 14 to exit the library management system: "<<endl;
cin>>check;

while( check!="14"){
	
    if (check=="1"){
    	string password;
	    cout<<"This section is for admin use only, Enter password to access this option if you're an admin: "<<endl;
	    cin.ignore();
	    getline(cin,password);
	    int checkpassword= checkAdmin(password);
	    if(checkpassword==1){
		
        int bookID;
        int noOfCopies;
        cout<<"Enter book id: "<<endl;
        cin>>bookID;
        int ifBook= searchBookToCheck(root, bookID);
        if(ifBook==1){
        	cout<<"The given id book is already present in any shelf of library , now you just need to enter the no of its copies you want to add further!"<<endl<<"Enter its no of copies you want to add: "<<endl;
		    cin>>noOfCopies;
		    searchBookToAdd(root, bookID, noOfCopies);
		    if(noOfCopies==1){
		    	cout<<"The given copy of this book has been added in the library!!! , Thank you!"<<endl<<endl;
			}
			else{
				cout<<"The given "<<noOfCopies<<" copies of this book have been added in the library!!! , Thank you!"<<endl<<endl;
			}
		}
		else{
		
        //cin>>bookID;
        string bookTitle;
        string bookAuthor;
        string bookGenre;
        cin.ignore(); // it clears the input buffer
        cout<<"Enter book title: "<<endl;
        //cin>>bookTitle; 
        getline(cin, bookTitle);

        cout<<"Enter book author name in lowercase: "<<endl;
       // cin>>bookAuthor;
       getline(cin, bookAuthor);
        cout<<"Enter the book genre or category in lowercase: "<<endl;
       // cin>>bookGenre;
       getline(cin,bookGenre);
        cout<<" how many copies of this book you want to add: "<<endl;
        cin>>noOfCopies;

        root =addBooks(root, bookID , bookTitle, bookAuthor, bookGenre, noOfCopies);
        if(noOfCopies==1){
    	cout<<"The given book has been added in the library , Thank you!!!"<<endl<<endl;
	}
	else {
		cout<<"The given "<<noOfCopies<<" books have been added in the library , Thank you!!!"<<endl<<endl;
	}
        //root= addBooks(root, bookID);
    }
} 
else{
	cout<<"Wrong password !! you're not an admin ! , try other sections of the system, this is for admin purpose only! , Thank you!"<<endl<<endl;
}
}
    else if ( check=="2"){
    	string password;
	    cout<<"This section is for admin use only, Enter password to access this option if you're an admin: "<<endl;
	    cin.ignore();
	    getline(cin,password);
	    int checkpassword= checkAdmin(password);
	    if(checkpassword==1){
             if(root!=NULL){
             cout<<"Enter the book ID to remove from library: "<<endl;
              int toremove;
             cin>>toremove;

        root=removeBooks(root, toremove);
      }
      else{
        cout<<"The library is empty at the moment!"<<endl;
      }
  }
  else{
  		cout<<"Wrong password !! you're not an admin ! , try other sections of the system, this is for admin purpose only! , Thank you!"<<endl<<endl;

  }
    }
    else if (check=="3"){
        if(root!=NULL){
            cout<<"Following is the list of all the books in the library!"<<endl;
         listAllBooks(root);
        }
        else {
            cout<<"There is no book in the library right now!"<<endl;
        }
    }
    else if ( check=="4"){
      if(root!=NULL){
            cout<<"Following is the list of currently available books in the library!"<<endl;
        listAvailableBooks(root);
      }
      else {
        cout<<"There is no book in the library right now!"<<endl;
        }
      }
    
    else if ( check=="5"){
    	string userName;
    	string userEmail;
    	string userAddress;
    	string userNumber;
    	cin.ignore();
    	cout<<"Enter your name: "<<endl;
    	getline(cin, userName);
    	cout<<"Enter your email address: "<<endl;
    	getline(cin,userEmail);
    	cout<<"Enter your home Address: "<<endl;
    	getline(cin,userAddress);
    	cout<<"Enter your phone number: "<<endl;
    	getline (cin, userNumber);
    	
        int ID=registerYourself(userName, userEmail, userAddress, userNumber, userTable, 10);
        cout<<"You have been registered in the LMS and your userID is: "<<ID<<endl<<endl;
        
    }
    else if (check =="6"){
    	if (root!=NULL){
    		int checkUser= ifUser(userTable, 10);

    			if (checkUser==-1){
    				cout<<"Currently there is no registered user in the system right now! , First register yourself in the system , then you can issue the book! Thank you!!"<<endl<<endl;
				}
				else{
				
			int userid;
    		int bookid;
    		/*cout<<"Enter your user ID : "<<endl;
    		cin>>userid;*/
    		cout<<"Enter the book ID you want to issue: "<<endl;
    		cin>>bookid;
    		int hasBook= searchBookToIssue(root, bookid);
    		if(hasBook==-1){
    			cout<<"Sorry ! the given book is currently not available in the library ... You can search for any other book.., Thank you!"<<endl<<endl;
			}
			else if(hasBook==-2){
				cout<<"sorry! the library management didn't add that ID book in the library so far, try searching for any other book, Thank you"<<endl<<endl;
			}
			else{
				cout<<"Enter your user ID : "<<endl;
    		cin>>userid;
    		int ifbook= checkBookOfUser(userid, userTable, 10);
    		if(ifbook==-2){
    			cout<<"Sorry! you're not the registered user of the system, register yourself first to issue the book, Thank you! "<<endl<<endl;
			}
			else if(ifbook!=-1){
				cout<<"sorry! you already have issued the book 'ID-"<<ifbook<<"' , you cannot issue more than one book at a time! "<<endl<<endl;
			}
			else{
			
			 issueBook( userid, bookid, userTable, 10);
			
    	}
    }
}
          }
        else {
    	cout<<"There is no book in the library right now!!"<<endl<<endl;
    	 }

    }
    else if (check =="7"){
        int checkUser= ifUser(userTable, 10);

    			if (checkUser==-1){
    				cout<<"Currently there is no registered user in the system right now! ,We don't receive any book from non registered users, Thank you!!"<<endl<<endl;
				}
				else{
    	
    	    int userid;
    	    cout<<"Enter your user ID: "<<endl;
    	    cin>>userid;
    		int retbook = returnBook(userid, userTable, 10);
    		if(retbook==-1){
    			cout<<"You are not even the registered user of our system, try to contact any other system for returning the book, Thank you!!"<<endl<<endl;
			}
			else if(retbook==-2){
				cout<<" you did not issue any book recently according to our information, try to contact any other library to return the book!"<<endl<<endl; 
			}
			else {
				searchBookToReturn(root, retbook);
				cout<<"Thank you so much for returning the book with ID "<<retbook<<" , Enjoy your time in the library , Thank you!!"<<endl<<endl;
			}
		}
    }

    
    
    else if(check=="8"){
    	string password;
	    cout<<"This section is for admin use only, Enter password to access this option if you're an admin: "<<endl;
	    cin.ignore();
	    getline(cin,password);
	    int checkpassword= checkAdmin(password);
	    if(checkpassword==1){
	    	int checkUser= ifUser(userTable, 10);

    			if (checkUser==-1){
    				cout<<"Currently there is no registered user in the system right now! , Thank you!!"<<endl<<endl;
				}
				else{
    	
    	printUsersList(userTable,10);
         }
    }
    else{
    	cout<<"Wrong password !! you're not an admin ! , try other sections of the system, this is for admin purpose only! , Thank you!"<<endl<<endl;

    	}
	}
	
	else if(check=="9"){
		string password;
	    cout<<"This section is for admin use only, Enter password to access this option if you're an admin: "<<endl;
	    cin.ignore();
	    getline(cin,password);
	    int checkpassword= checkAdmin(password);
	    if(checkpassword==1){
	    	int checkUser= ifUser(userTable, 10);

    			if (checkUser==-1){
    				cout<<"Currently there is no registered user in the system right now! , Thank you!!"<<endl<<endl;
				}
				else{
		int userid;
		cout<<"Enter the user ID to check the book he issued: "<<endl;
		cin>>userid;
		int checkBook= checkBookOfUser(userid,userTable, 10);
		if(checkBook==-1){
			cout<<"This user didn't issue any of the books so far , he doesn't have any book right now! , Thank you!!"<<endl;
		}
		else if( checkBook==-2){
			cout<<"Sorry sir! this user has not been registered in the system so far, try searching for any registered user, Thank you!!"<<endl;
		}
		else{
			cout<<"The given user has issued the book with book ID : "<<checkBook <<endl<<endl;
		}
	}
}
	else{
		cout<<"Wrong password !! you're not an admin ! , try other sections of the system, this is for admin purpose only! , Thank you!"<<endl<<endl;

	  }
	}
	
	else if(check=="10"){
		string password;
	    cout<<"This section is for admin use only, Enter password to access this option if you're an admin: "<<endl;
	    cin.ignore();
	    getline(cin,password);
	    int checkpassword= checkAdmin(password);
	    if(checkpassword==1){
	    	int checkUser= ifUser(userTable, 10);

    			if (checkUser==-1){
    				cout<<"Currently there is no registered user in the system right now! , Thank you!!"<<endl<<endl;
				}
				else{
					int checkBookUser= ifBookUser(userTable, 10);

    			if (checkBookUser==-1){
    				cout<<"Currently no registered user of the system issue any book so far, Thank you!!"<<endl<<endl;
				}
				else{
	    	
		printBookIssuedUsers(userTable, 10);
	      }
       }
	}
	else{
		cout<<"Wrong password !! you're not an admin ! , try other sections of the system, this is for admin purpose only! , Thank you!"<<endl<<endl;
       }

	}
	
	else if( check=="11"){
		string password;
	    cout<<"This section is for admin use only, Enter password to access this option if you're an admin: "<<endl;
	    cin.ignore();
	    getline(cin,password);
	    int checkpassword= checkAdmin(password);
	    if(checkpassword==1){
	    	int checkUser= ifUser(userTable, 10);

    			if (checkUser==-1){
    				cout<<"Currently there is already no registered user in the system right now! ,  Thank you!!"<<endl<<endl;
				}
				else{
	    	int userid;
	    	cout<<"Enter user id you want to remove from the system"<<endl;
	    	cin>>userid;
		int ifremove=removeUser(userid, userTable,10);
		if(ifremove==1){
			cout<<"The given user has been removed from the system, Thank you!!"<<endl;
		}
		else{
			cout<<"This user is already not present in the system , Thank you!!"<<endl;
		}
		
	}
}
	else{
		cout<<"Wrong password !! you're not an admin ! , try other sections of the system, this is for admin purpose only! , Thank you!"<<endl<<endl;
       }
	}
	
	
	else if(check=="12"){
		if(root!=NULL){
		
		string author;
		cout<<"Enter any author name in lowercase to search his all books in the library: "<<endl;
		cin.ignore();
		getline(cin,author);
		cout<<"Here is the list of all the books written by author  '"<<author<<"' present in the library: "<<endl;
		booksByAuthor(root, author);
		if(counted==0){
        	cout<<"Sorry ! there is no such book in the library written by '"<<author<<"' !! , Thank you!! "<<endl<<endl;
		}
		counted=0;
		
	}
	else{
		cout<<"Sorry! there is no book in the library right now!!"<<endl;
	}
	}
	else if(check=="13"){
		if(root!=NULL){	
		string category;
		cout<<"Enter any specific category in lowercase to check all the books lying in that category in the library: "<<endl;
		cin.ignore();
		getline(cin, category);
		cout<<"Here is the list of all the books lying in the cateogy '"<<category<<"' present in the library: "<<endl;
        booksByCategory(root, category);

        if(counted==0){
        	cout<<"Sorry ! there is no such book in the library lying in the category of '"<<category<<"' !! , Thank you!! "<<endl<<endl;
		}
		counted=0;
	}
	else{
		cout<<"Sorry! there is no book in the library right now!!"<<endl;
	}
	}
    else {
        cout<<"This option is not available at the moment!! Try other operations! "<<endl;
    }
    string x ;
    cout <<"Enter '#' to get the menu again or press any other key to exit the system: "<<endl;
    cin>>x;
    //getline(cin, x);
    if (x=="#"){
        cout << "                                                 **** MENU ****                                                      "<<endl<<endl;
cout <<" Enter 1 to add books in the library (For admin section only): "<<endl;
cout <<" Enter 2 to remove books from the library (For admin section only): "<<endl;
cout <<" Enter 3 to show the list of all the books in the library: "<<endl;
cout <<" Enter 4 to show the list of currently available books only: "<<endl;
cout <<" Enter 5 to register yourself in the system as a valid user: "<<endl;
cout <<" Enter 6 to issue a book from the library : "<<endl;
cout <<" Enter 7 to return the book back : "<<endl;
cout <<" Enter 8 to print the list of all the registered users of LMS( For admin section only):  "<<endl;
cout <<" Enter 9 to print to check the bookID issued by any specific user(For admin section only):  "<<endl;
cout <<" Enter 10 to print the list of all those users who issued books( For admin section only):   "<<endl;
cout <<" Enter 11 to remove any user from the system( For admin section only):  "<<endl;
cout <<" Enter 12 to search the books by any specific author:  "<<endl;
cout <<" Enter 13 to search the books of any specific category:  "<<endl;
cout <<" Enter 14 to exit the library management system: "<<endl;
cin>>check;

    }
    else {
        break;
    }
}

cout<<"We have exit the library management system now ! " <<endl;
}

