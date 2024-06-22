#include <iostream>
using namespace std;

int main()
{
  int vertices;
  cout << "How many vertices are there in a graph? " << endl;
  cin >> vertices;
  int verticesArray[vertices];
  int arr[vertices][vertices];

  // Asking for vertices representation
  cout << "Enter vertex representations : ";
  for (int i = 0; i < vertices; i++)
  {
    cin >> verticesArray[i];
  }
  for (int i = 0; i < vertices; i++)
  {
    for (int j = 0; j < vertices; j++)
    {
      arr[i][j] = 0;
    }
  }
  // Asking for connections/edges
  for (int i = 0; i < vertices; i++)
  {
    int n;

    do
    {
      cout << verticesArray[i] << " is adjacent to? " << endl
           << "Enter -1, if not adjacent to : ";
      cin >> n;
      if (n == -1)
        break;
      for (int j = 0; j < vertices; j++)
      {
        if (n == verticesArray[j])
        {
          arr[i][j] = 1;
        }
      }
    } while (n != -1);
  }

  // print 2d array
  for (int i = 0; i < vertices; i++)
  {
    for (int j = 0; j < vertices; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}