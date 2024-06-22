#include<iostream>
using namespace std;

void insertionViaLinear(int hashTable[], int size, int insert){
   // cout<<"method insertionVia linear called!"<<endl;
    int index=insert%size;
    int count=0;
    while(count<size){
    if(hashTable[index]==-1){
        hashTable[index]=insert;
        cout<<"this value has been inserted in the hashTable"<<endl<<endl;
        return;
    }
    index=(index+1)%size;
    count++;    
    }
    cout<<"hash Table has been filled fully ! sorry no space!"<<endl<<endl;
}


void searchingViaLinear(int hashTable[],int size, int toSearch){
    //cout<<"method searchingVia linear called!"<<endl;
    int index=toSearch%size;
    int count=0;
    while(count<size){
    if(hashTable[index]==toSearch){
        cout<<"value found at index: "<<index<<endl<<endl;
        return;
    }
    index=(index+1)%size;
    count++;    
    }
    cout<<" sorry! the given value is not present in the hash table!"<<endl<<endl;
}

void insertionViaQuadratic(int hashTable[], int size, int insert){
    //cout<<"method insertionVia Quadratic called!"<<endl;
    int index=insert%size;
    int count=0;
    
    while(count<size){
    if(hashTable[index]==-1){
        hashTable[index]=insert;
        cout<<"this value has been inserted in the hashTable"<<endl<<endl;
        return;
    }
    count++;
    index=((index)+ count*count)%size;
       
    }
    cout<<"hash Table has been filled fully ! sorry no space!"<<endl<<endl;
}


void searchingViaQuadratic(int hashTable[],int size, int toSearch){
    //cout<<"method searchingVia Quadratic called!"<<endl;
    int index=toSearch%size;
    int count=0;
    while((count)<(1*size)){
    if(hashTable[index]==toSearch){
        cout<<"value found at index: "<<index<<endl<<endl;
        return;
    }
    count++; 
    index=((index) + (count*count))%size;
       
    }
    cout<<" sorry! the given value is not present in the hash table!"<<endl<<endl;
}



int main(){
    
 cout<<"     Pre requisite of menu!   "<<endl;   
int size;
cout<<"Enter the size of array in which you want data will be stored!"<<endl;
cin>>size;
int hashTable[size];
for(int i =0;i<size;i++){
    hashTable[i]=-1;
    
}
    
/*for(int i=0;i<size;i++){
    cout<<hashTable[i]<<endl;
}*/
    
int hashCheck;
cout<<"Which method you would like for hashing?"<<endl<<"Enter 1 for via linear probing"<<endl<<"Enter 2 for via quadratic probing"<<endl<<"Enter : ";
cin>>hashCheck;
int check;
cout<<endl<<"          ***MENU***          "<<endl<<"Enter 1 for insertion!"<<endl<<"Enter 2 for searching!"<<endl<<"Enter 3 to print the list! "<<endl<<"Enter 4 to exit the code!"<<endl<<"Enter: ";
cin>>check;
while (check!=4){
    if(check==1){
            int insert;
            cout<<"Enter the value to insert: ";
            cin>>insert;
            cout<<endl;
        if(hashCheck==1){
            insertionViaLinear(hashTable,size,insert);
        }
        else{
            insertionViaQuadratic(hashTable,size,insert);
        }
    }
    else if(check==2){
        int toSearch;
        cout<<"Enter the value to search: ";
        cin>>toSearch;
        cout<<endl;
        if(hashCheck==1){
            searchingViaLinear(hashTable,size,toSearch);
        }
        else{
            searchingViaQuadratic(hashTable,size,toSearch);
        }
    }
    else if(check==3){
        cout<<endl;
        for(int i=0;i<size;i++){
            cout<<"ind: "<<i<<"  "<<hashTable[i]<<endl;
        }
        cout<<endl;
        
    }
    else{
        cout<<"please choose any number for the given options only!"<<endl<<"Try again! "<<endl;
    }
        string x;
      cout<<"Enter 'n' to get the menu again! or any other key to exit the code!"<<endl;
      cin>>x ;
      if(x=="n"){  
      cout<<endl<<"          ***MENU***          "<<endl<<"Enter 1 for insertion!"<<endl<<"Enter 2 for searching!"<<endl<<"Enter 3 to print the list! "<<endl<<"Enter 4 to exit the code!"<<endl<<"Enter: ";
      cin>>check;    

      }
      else{
          break;
      }  
    }

    
cout<<"We have exit the code now!"<<endl;     
}
