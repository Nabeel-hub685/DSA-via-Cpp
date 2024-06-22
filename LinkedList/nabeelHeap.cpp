#include <iostream>
using namespace std;
int heapify(int array[] , int i)
{
    int p=(i-1) / 2;
    if (array[p]>array[i])
        {
            int temp = array[p];
            array[p]=array[i];
            array[i]=temp;
            heapify(array , p );
        }
        return 0;
    
}

void MinHeap(int array[] , int lim)
{
    for (int i = 1; i < lim; i++)
    {
        heapify(array , i);     
    }
    for (int i = 0; i < lim; i++)
    {
        cout<<array[i]<< "  ";
    }
    cout<<endl;
}
int heapifymax(int array[] , int i)
{
    int p=(i-1) / 2;
    if (array[p]<array[i])
        {
            int temp = array[p];
            array[p]=array[i];
            array[i]=temp;
            heapifymax(array , p );
        }
        return 0;
    
}
void MaxHeap(int array[], int lim)
{
    for (int i = 1; i < lim; i++)
    {
        heapifymax(array , i);     
    }
    for (int i = 0; i < lim; i++)
    {
        cout<<array[i]<< "  ";
    }
    cout<<endl;
}

void deleteroot(int array[])
{
    int temp=array[0];
    array[0]=array[9];
    array[9]=-1;
    MinHeap(array , 9);
}


void maxheapsort(int array[] , int n)
{ 
    
    
    for (int i = n ; i > 0; i--)
    {
        MaxHeap(array ,i );
        int temp=array[0];
        array[0]=array[i-1];
        array[i-1]=temp;
    }
    for (int i = 0; i < 10; i++)
    {
        cout<<array[i]<< "  ";
    }
    
    
}
int main()
{
    int arr[10]={11,23,55,70,63,78,230,117,99,97};
    //MinHeap(arr , 10 );
    //deleteroot(arr);
    //MaxHeap(arr, 10);
    maxheapsort(arr ,10);

    return 0;
}