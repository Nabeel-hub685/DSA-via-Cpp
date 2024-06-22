#include<iostream>
using namespace std;
void bubbleSort(int arr[],int size){
    for (int j=0;j<size-1;j++){
        for (int i=0;i<size-1-j;i++){
        if(arr[i]>arr[i+1]){
            int temp=arr[i+1];
            arr[i+1]=arr[i];
            arr[i]=temp;
        }
        }
    }
}
    

void selectionSort(int arr[],int size){
    for(int j =0;j<size-1;j++){
       int smallest=j;
        for(int i=j+1;i<size;i++){
        if(arr[smallest]>arr[i]){
            smallest=i;
        }
    }
        int temp =arr[j];
        arr[j]=arr[smallest];
        arr[smallest]=temp;
    }
}

void insertionSort(int arr[],int size){
    for (int i=1; i<size;i++){
        int hold =arr[i];
        while (i>0 and hold<arr[i-1]){
            arr[i]=arr[i-1];
            i--;
        }
        arr[i]=hold;
            
    }
}
int main(){
    cout<<"Enter the size of array: "<<endl;
    int size;
    cin>>size;
    int arr[size];
    cout<<"Now enter the elements of the array 1 by 1: "<<endl;
    for(int i =0;i<size;i++){
        cin>>arr[i];
    }
    
        
    cout<<"Enter which sorting algorithm you would like to use ?"<<endl;
    cout<<"Enter 1 for bubble sort!"<<endl<<"Enter 2 for selection sort!"<<endl<<"Enter 3 for insertion sort!"<<endl;
    int choice;
    cin>>choice;
    if (choice==1){
        bubbleSort(arr,size);
        cout<<"the sorted array by applying bubble sort is :"<<endl;
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
    }
    else if(choice==2){
        selectionSort(arr,size);
        cout<<"the sorted array by applying selection sort is :"<<endl;
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
    }
    else {
        
        cout<<"the sorted array by applying insertion sort is:"<<endl;
        insertionSort(arr,size);
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
            
        }
      
    }
    // just checking k fumction me array k first index ka address ho paass hota he? joke base address kehlaata he!
    cout<<endl;
    cout<<arr<<endl;
    cout<<&(arr[0])<<endl;
   
}
