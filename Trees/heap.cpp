#include<iostream>
using namespace std;
struct Node{
    int value;
    Node* left;
    Node* right;
};
 
 Node* root=NULL;
 
int main(){
    int size;
    cout<<"Enter how many numbers you want to Enter: "<<endl;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++){
        arr[i]=-1;
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }



     
}