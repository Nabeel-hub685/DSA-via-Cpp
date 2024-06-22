#include <iostream>
#include<stdlib.h>
using namespace std;

struct HashNode
{
  int data;
  HashNode *next;
};

void insert(int value, HashNode* arr[], int size)
{

  HashNode* ptr = (HashNode *)malloc(sizeof(HashNode));
  ptr->data = value;
  ptr->next = NULL;
  
    int key = value % size;

  if (arr[key] == NULL)
  {
    arr[key] = ptr;
    return;
  }
  HashNode *curr = arr[key];
  while (curr->next != NULL)
  {
    curr = curr->next;
  }
  curr->next = ptr;
  
}

void search(int toSearch, HashNode *arr[], int size)
{
  int key = toSearch % size;
  HashNode *curr = arr[key];
  while (curr != NULL)
  {
    if (curr->data == toSearch)
    {
      cout << "found" << endl;
      return;
    }
    curr = curr->next;
  }
  if (curr == NULL)
  {
    cout << "Not found " << endl;
  }
}

int main()
{
  int size;
  cout << "Enter size of Hash Table : ";
  cin >> size;
  HashNode* hashTable[size];
  // initialize table values with NULL
  for (int i = 0; i < size; i++)
  {
    hashTable[i] = NULL;
  }
  int n;
  do
  {
    cout << "Enter 1 to Insert a Value " << endl
         << "Enter 2 to Search a value" << endl
         << "Enter 3 to Exit " << endl;
    cin >> n;
    if (n == 1)
    {
      int value;
      cout << "Enter Value : ";
      cin >> value;
      insert(value, hashTable, size);
    }
    else if (n == 2)
    {
      int toSearch;
      cout << "Enter value to Search : ";
      cin >> toSearch;
      search(toSearch, hashTable, size);
    }
    else if (n == 3)
    {
      cout << "Exit " << endl;
    }
    else
    {
      cout << "Invalid Number !!!" << endl;
    }
  } while (n != 3);
}
