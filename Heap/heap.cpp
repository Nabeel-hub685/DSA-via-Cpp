#include<iostream>
#include<stdlib.h>
using namespace std;


void heapifyMax(int arr[],int i){
    int parent= (i-1)/2;
	if(arr[parent]<arr[i]){
		int temp=arr[i];
		arr[i]=arr[parent];
		arr[parent]=temp;
		heapifyMax(arr,parent);
	}
	
}

void maxHeap(int arr[], int size){
	for(int i=1;i<size;i++){
		heapifyMax(arr,i);
	}
	cout<<"Max heap : ";
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

/*

void heapifyMin(int arr,int i){
	int parent=(i-1)/2;
	if(arr[parent]>arr[i]){
		int temp=arr[parent];
		arr[parent]=arr[i];
		arr[i]=temp;
		heapifyMin(arr,parent);
	}
}

void minHeap(int arr[],int size){
	for(int i=1;i<size;i++){
		heapifyMin(arr,i);
	}
	cout<<"Min heap : ";
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
}*/
int main(){
	int size=10;
	
	int arr[size]={11,23,55,70,63,78,230,117,99,97};
	maxHeap(arr,size);
//	minHeap(arr,size);
}
