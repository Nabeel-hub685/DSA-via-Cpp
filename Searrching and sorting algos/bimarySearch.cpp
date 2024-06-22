#include <iostream>
using namespace std;
void binarySearch(int Arr[], int size, int x){
    int start=0;
    int last = size-1;
    int middle= (start+last)/2;
    while(start<=last){
        
        if(Arr[middle]==x){
            cout<<"required number '"<<Arr[middle]<<"' found at index: "<<middle;
            return;
        }
        
        else if(Arr[middle]<x){
            start= middle+1;
        }
        
        else {
            last=middle-1;
        }
        middle=(start+last)/2;
    }
    cout<<"the required number is not found !"<<endl;
    
}
int main(){
int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    int Arr[size];
    cout<<"Enter the elements of array 1 by 1 in ascending order: "<<endl;
    for (int i =0;i<size;i++){
        cin>>Arr[i];
    }
    int x;
    cout<<"Enter the number you want to search: ";
    cin>>x;
    binarySearch(Arr,size,x);
    
    
}