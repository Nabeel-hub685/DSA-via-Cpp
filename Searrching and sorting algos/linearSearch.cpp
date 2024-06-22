#include <iostream>
using namespace std;
void linearSearch(int Arr[], int size, int x){
    for(int i=0;i<size;i++){
        if (x==Arr[i]){
            cout<<"the number found at index "<<i<<endl;
            break;
        }
            else if (i==size-1){
                cout<<"the required number was not found!";
            
            }
        }
    }

int main() {
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    int Arr[size];
    cout<<"Enter the elements of array 1 by 1:"<<endl;
    for (int i =0;i<size;i++){
        cin>>Arr[i];
    }
    int x;
    cout<<"Enter the number you want to search: ";
    cin>>x;
    linearSearch(Arr,size,x);
    
    
        
    }
    
