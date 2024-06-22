#include <iostream>
#include <stdlib.h>
#include "queue.h"
#include "post.h"
using namespace std;

struct Request
{
  int userID;
  Request *next;
};

struct Friend;
// User Struct
struct User
{
  int userID;
  string fullName; // optional
  string password; // optional
  Request *requestHead;
  Friend *friendHead;
  User *next;
};

// Friend Struct
struct Friend
{
  User *userAdd; // Hold user Address
  Friend *next;
};

// Actual User Application Functions started from here

// Search a user in vertical list - if found return userNode else return NULL
User *searchUser(int ID, User *userHead)
{
  if (userHead == NULL)
  {
    return NULL;
  }
  User *curr = userHead;
  while (curr != NULL)
  {
    if (curr->userID == ID)
    {
      return curr;
    }
    curr = curr->next;
  }
  return NULL;
}

// Add user in a vertical list
int addUser(string name, string password, User **userHead)
{
  int count = 1;
  User *ptr = new User();
  ptr->fullName = name;
  ptr->password = password;
  ptr->requestHead = NULL;
  ptr->friendHead = NULL;
  ptr->next = NULL;
  if (*userHead == NULL) // for 1st user
  {
    ptr->userID = count;
    *userHead = ptr;
    cout << "Account created Successfully... " << endl;
    return count;
  }
  User *currUser = *userHead;
  while (currUser->next != NULL)
  {
    count++;
    currUser = currUser->next;
  }
  count++;
  ptr->userID = count;
  currUser->next = ptr;
  cout << "Account created Successfully... " << endl;
  return count;
}

void allUsers(User *userHead)
{
  User *currUser = userHead;
  cout << "All users in friends circle " << endl;
  int count = 0;
  while (currUser != NULL)
  {
    count++;
    cout << "User ID : " << currUser->userID << " - Name : " << currUser->fullName << endl;
    currUser = currUser->next;
  }
  cout << endl;
  cout << "Total users in friends circle are " << count << endl;
}

// Search for a friend in your friend list - if found return friend else return null
User *isFriend(User *myNode, User *userNode)
{
  Friend *currFriend = myNode->friendHead;
  while (currFriend != NULL)
  {
    if (currFriend->userAdd == userNode)
    {
      return userNode; // return friend node
    }
    currFriend = currFriend->next;
  }
  return NULL; // if not found
}

// Search a friend request in user request list
bool isInRequestList(User *userNode, int myID)
{
  Request *currRequest = userNode->requestHead;
  while (currRequest != NULL)
  {
    if (currRequest->userID == myID)
    {
      return true; // return true
    }
    currRequest = currRequest->next;
  }
  return false; // if not in the request list
}

void sendRequest(User *userNode, int myID)
{
  Request *ptr = (Request *)malloc(sizeof(Request));
  ptr->userID = myID;
  ptr->next = NULL;
  if (userNode->requestHead == NULL)
  {
    userNode->requestHead = ptr;
    cout << "Request sent to " << userNode->fullName << endl;
    return;
  }
  Request *currRequest = userNode->requestHead;
  while (currRequest->next != NULL)
  {
    currRequest = currRequest->next;
  }
  currRequest->next = ptr;
  cout << "Request sent to " << userNode->fullName << endl;
}

void deleteFromRequestList(User *myNode, int userID)
{
  Request *currRequest = myNode->requestHead;
  if (currRequest->userID == userID)
  {
    myNode->requestHead = myNode->requestHead->next;
    free(currRequest);
    return;
  }
  Request *prevRequest = myNode->requestHead;
  currRequest = prevRequest->next;
  while (currRequest != NULL)
  {
    if (currRequest->userID == userID)
    {
      prevRequest->next = currRequest->next;
      free(currRequest);
      return;
    }
    prevRequest = currRequest;
    currRequest = currRequest->next;
  }
}

// Add user in your friend list
void addFriend(User *myNode, User *userNode)
{
  Friend *ptr1 = (Friend *)malloc(sizeof(Friend));
  ptr1->userAdd = userNode;
  ptr1->next = NULL;
  if (myNode->friendHead == NULL) // for 1st friend
  {
    myNode->friendHead = ptr1;
  }
  else
  {
    Friend *currFriend = myNode->friendHead;
    while (currFriend->next != NULL)
    {
      currFriend = currFriend->next;
    }
    currFriend->next = ptr1;
  }

  Friend *ptr2 = (Friend *)malloc(sizeof(Friend));
  ptr2->userAdd = myNode;
  ptr2->next = NULL;
  if (userNode->friendHead == NULL)
  {
    userNode->friendHead = ptr2;
  }
  else
  {
    Friend *currFriend = userNode->friendHead;
    while (currFriend->next != NULL)
    {
      currFriend = currFriend->next;
    }
    currFriend->next = ptr2;
  }
  cout << userNode->fullName << " is added in your friendlist..." << endl;
}

void showAllRequests(User *myNode, User **userHead)
{
  Request *currRequest = myNode->requestHead;
  int count = 0;
  cout << "All Requests in your Request List..." << endl;
  while (currRequest != NULL)
  {
    count++;
    User *userNode = searchUser(currRequest->userID, *userHead);
    cout << "User ID : " << currRequest->userID << " - Name : " << userNode->fullName << endl;
    currRequest = currRequest->next;
  }
  cout << endl;
  cout << "Total Requests : " << count << endl;
  int userID;
  do
  {
    cout << "Enter user id to accept/delete request " << endl
         << "Enter negative value to go back " << endl;
    cin >> userID;

    if (userID > 0)
    {
      if (isInRequestList(myNode, userID))
      {
        int a;
        cout << "Enter 1 to accept request " << endl
             << "Enter 2 to Delete Request " << endl;
        cin >> a;
        User *userNode = searchUser(userID, *userHead);
        if (a == 1)
        {
          cout << "you accept the request of " << userNode->fullName << endl;
          addFriend(myNode, userNode);
        }
        else if (a == 2)
        {
          cout << "you delete the request of " << userNode->fullName << endl;
        }
        // delete from rquest list
        deleteFromRequestList(myNode, userID);
      }
      else
      {
        cout << "This userID is not in requestlist..." << endl;
      }
    }
    else
    {
      return;
    }
  } while (myNode->requestHead != NULL);
}

void findMutualFriends(User *myNode, User *userNode)
{
  QNode *front = NULL; // for deque
  QNode *rear = NULL;  // for enqueue

  Friend *currFriend = myNode->friendHead;
  while (currFriend != NULL)
  {
    // Enqueue all friends
    enQueue(currFriend->userAdd, &front, &rear);
    currFriend = currFriend->next;
  }
  int count = 0;
  do
  {
    // Deque friends one by one
    User *currFriendNode = deQueue(&front, &rear);
    if (!currFriendNode)
    {
      cout << "You don't have any friends in friendlist..." << endl;
      return;
    }
    currFriend = currFriendNode->friendHead;

    while (currFriend != NULL)
    {
      if (currFriend->userAdd == userNode)
      {
        count++;
        cout << "User ID : " << currFriendNode->userID << " - Name : " << currFriendNode->fullName << endl;
      }
      currFriend = currFriend->next;
    }
  } while (!isEmpty(front));
  cout << count << " mutual friends... " << endl;
}

void unfriend(User *myNode, User *friendNode)
{
  // Delete friend from my friendlist
  Friend *currFriend = myNode->friendHead;
  if (myNode->friendHead->userAdd == friendNode) // if friend is on 1
  {
    myNode->friendHead = myNode->friendHead->next;
    free(currFriend);
  }
  else
  {
    Friend *prevFriend = myNode->friendHead;
    currFriend = prevFriend->next;
    while (currFriend != NULL)
    {
      if (currFriend->userAdd == friendNode)
      {
        prevFriend->next = currFriend->next;
        free(currFriend);
        break;
      }
      prevFriend = currFriend;
      currFriend = currFriend->next;
    }
  }
  // Delete mynode from friend friendlist
  currFriend = friendNode->friendHead;
  if (friendNode->friendHead->userAdd == myNode) // if friend is on 1
  {
    friendNode->friendHead = friendNode->friendHead->next;
    free(currFriend);
  }
  else
  {
    Friend *prevFriend = friendNode->friendHead;
    currFriend = prevFriend->next;
    while (currFriend != NULL)
    {
      if (currFriend->userAdd == myNode)
      {
        prevFriend->next = currFriend->next;
        free(currFriend);
        break;
      }
      prevFriend = currFriend;
      currFriend = currFriend->next;
    }
  }
}

void showAllFriends(User *myNode)
{
  Friend *currFriend = myNode->friendHead;
  int count = 0;
  cout << "All friends in your friendlist..." << endl;
  while (currFriend != NULL)
  {
    count++;
    cout << "User ID : " << currFriend->userAdd->userID
         << " - Name : " << currFriend->userAdd->fullName << endl;
    currFriend = currFriend->next;
  }
  cout << endl;
  cout << "Total Friends : " << count << endl;
}

void friendsPage(User *myNode, User **userHead)
{
  string text = "Friends Page";
  int width = 50; // Width of the terminal line

  int padding_left = (width - text.length()) / 2;
  int padding_right = width - text.length() - padding_left;

  string border_line(width, '*');
  string empty_line = "" + string(width - 2, ' ') + "";
  string text_line = "" + string(padding_left - 1, ' ') + text + string(padding_right - 1, ' ') + "";

  cout << border_line << endl;
  cout << empty_line << endl;
  cout << text_line << endl;
  cout << empty_line << endl;
  cout << border_line << endl;

  int a;
  do
  {
    cout << "Enter 1 to send a request " << endl
         << "Enter 2 to show all pending requests " << endl
         << "Enter 3 to find mutual friends " << endl
         << "Enter 4 to unfriend any friend " << endl
         << "Enter 5 to Show all friends " << endl
         << "Enter 6 to Search a friend " << endl
         << "Enter 7 to go back to homepage " << endl;
    cin >> a;
    if (a == 1)
    {
      int userID;
      cout << "Enter user ID : ";
      cin >> userID;
      if (userID == myNode->userID)
      {
        cout << "Idiot! You can't send request to yourself... " << endl;
        continue;
      }
      User *userNode = searchUser(userID, *userHead);
      if (userNode)
      {
        if (isFriend(myNode, userNode))
        {
          cout << userNode->fullName << " is already in your friendlist..." << endl;
        }
        else if (isInRequestList(userNode, myNode->userID))
        {
          cout << "You've already send request to " << userNode->fullName << endl;
        }
        else if (isInRequestList(myNode, userID))
        {
          cout << userNode->fullName << " already send you a request!!! please check your requestlist and simply accept the request..." << endl;
        }
        else
        {
          sendRequest(userNode, myNode->userID);
        }
      }
      else
      {
        cout << "User not found with this ID " << endl;
      }
    }
    else if (a == 2)
    {
      showAllRequests(myNode, userHead);
    }
    else if (a == 3)
    {
      int userID;
      cout << "Enter User ID : ";
      cin >> userID;
      User *userNode = searchUser(userID, *userHead);
      findMutualFriends(myNode, userNode);
    }
    else if (a == 4)
    {
      int friendID;
      cout << "Enter friend ID : ";
      cin >> friendID;
      User *UserNode = searchUser(friendID, *userHead);
      if (UserNode)
      {
        User *friendNode = isFriend(myNode, UserNode);
        if (friendNode)
        {
          unfriend(myNode, friendNode);
          cout << "Unfriend Successfully... " << endl;
        }
        else
        {
          cout << UserNode->fullName << " is not your friend " << endl;
        }
      }
      else
      {
        cout << "User ID : " << friendID << " is not in friends circle " << endl;
      }
    }
    else if (a == 5)
    {
      showAllFriends(myNode);
    }
    else if (a == 6)
    {
      int friendID;
      cout << "Enter friend ID : ";
      cin >> friendID;
      User *userNode = searchUser(friendID, *userHead);
      if (userNode)
      {
        User *friendNode = isFriend(myNode, userNode);
        if (friendNode)
        {
          cout << friendNode->fullName << " is in your friendlist..." << endl;
        }
        else
        {
          cout << userNode->fullName << " is not your friend..." << endl;
        }
      }
      else
      {
        cout << "User not found with this ID..." << endl;
      }
    }
    else if (a == 7)
    {
      cout << "Go back..." << endl;
    }
    else
    {
      cout << "Please enter between 1 & 7 !!!" << endl;
    }
  } while (a != 7);
}

void viewPost(Post *postNode, User *userNode)
{
  int a;
  do
  {
    cout << "Enter 1 to like this post " << endl
         << "Enter 2 to comment on post " << endl
         << "Enter 3 to show likes of this post " << endl
         << "Enter 4 to show comments on post " << endl
         << "Enter 5 to go back to post page " << endl;
    cin >> a;
    if (a == 1)
    {
      if (isLike(userNode->userID, postNode))
      {
        cout << "You already like this post..." << endl;
      }
      else
      {
        likePost(postNode, userNode->userID);
      }
    }
    else if (a == 2)
    {
      string comment;
      cout << "Enter Comment : ";
      cin.ignore();
      getline(cin, comment);
      commentOnPost(postNode, userNode->userID, comment);
    }
    else if (a == 3)
    {
      showLikes(postNode);
    }
    else if (a == 4)
    {
      showComments(postNode);
    }
    else if (a == 5)
    {
      cout << "Back to Post Page... " << endl;
    }
    else
    {
      cout << "Please Enter between 1 & 5 !!!" << endl;
    }
  } while (a != 5);
}

void postOptions(User *myNode, Post **postHead)
{
  int postID;
  cout << "Enter post ID of the post to like or comments on post " << endl
       << "Enter negative value to go back" << endl;
  cin >> postID;
  if (postID > 0)
  {
    Post *postNode = searchPost(postID, *postHead);
    if (postNode)
    {
      viewPost(postNode, myNode);
    }
    else
    {
      cout << "Post ID not found in Posts !!!" << endl;
    }
  }
}

void postPage(User *myNode, Post **postHead, User **userHead)
{
  string text = "Post Page";
  int width = 50; // Width of the terminal line

  int padding_left = (width - text.length()) / 2;
  int padding_right = width - text.length() - padding_left;

  string border_line(width, '*');
  string empty_line = "" + string(width - 2, ' ') + "";
  string text_line = "" + string(padding_left - 1, ' ') + text + string(padding_right - 1, ' ') + "";

  cout << border_line << endl;
  cout << empty_line << endl;
  cout << text_line << endl;
  cout << empty_line << endl;
  cout << border_line << endl;

  int a;
  do
  {
    cout << "Enter 1 to Create a post " << endl
         << "Enter 2 to search a post " << endl
         << "Enter 3 to delete a Post " << endl
         << "Enter 4 to update a post " << endl
         << "Enter 5 to show your posts " << endl
         << "Enter 6 to show all posts " << endl
         << "Enter 7 to show post of specific user " << endl
         << "Enter 8 to go back to homepage " << endl;
    cin >> a;
    if (a == 1)
    {
      string postDescription;
      cout << "Enter post description " << endl;
      cin.ignore();
      getline(cin, postDescription);
      createPost(myNode->userID, postDescription, postHead);
    }
    else if (a == 2)
    {
      int postID;
      cout << "Enter post ID : ";
      cin >> postID;
      Post *postNode = searchPost(postID, *postHead);
      if (!postNode)
      {
        cout << "Post not found with this Post ID !!!" << endl;
      }
      else
      {
        User *userNode = searchUser(postNode->userID, *userHead);
        cout << userNode->fullName << " posted this... " << endl
             << "Post Description " << endl
             << postNode->postdescription << endl;
        viewPost(postNode, myNode);
      }
    }
    else if (a == 3)
    {
      int postID;
      cout << "Enter post ID : ";
      cin >> postID;
      if (!searchPost(postID, *postHead))
      {
        cout << "Post not found with this Post ID !!!" << endl;
      }
      else
      {
        deletePost(myNode->userID, postID, postHead);
      }
    }
    else if (a == 4)
    {
      int postID;
      cout << "Enter post ID : ";
      cin >> postID;
      cin.ignore();
      if (!searchPost(postID, *postHead))
      {
        cout << "Post not found with this Post ID !!!" << endl;
      }
      else
      {
        string postDesc;
        cout << "Update post description : " << endl;
        // cin.ignore();
        getline(cin, postDesc);
        updatePost(myNode->userID, postID, postDesc, postHead);
      }
    }
    else if (a == 5)
    {
      showUserPosts(myNode->userID, *postHead, userHead);
      postOptions(myNode, postHead);
    }
    else if (a == 6)
    {
      showAllPosts(*postHead);
      postOptions(myNode, postHead);
    }
    else if (a == 7)
    {
      int userID;
      cout << "Enter User ID : ";
      cin >> userID;
      showUserPosts(userID, *postHead, userHead);
      postOptions(myNode, postHead);
    }
    else if (a == 8)
    {
      cout << "Loading..." << endl;
      cout << "Back to Homepage" << endl;
    }
    else
    {
      cout << "Please enter between 1 & 8 !!!" << endl;
    }
  } while (a != 8);
}

void homepage(User *myNode, User **userHead, Post **postHead)
{
  string text = "Home Page";
  int width = 50; // Width of the terminal line

  int padding_left = (width - text.length()) / 2;
  int padding_right = width - text.length() - padding_left;

  string border_line(width, '*');
  string empty_line = "" + string(width - 2, ' ') + "";
  string text_line = "" + string(padding_left - 1, ' ') + text + string(padding_right - 1, ' ') + "";

  cout << border_line << endl;
  cout << empty_line << endl;
  cout << text_line << endl;
  cout << empty_line << endl;
  cout << border_line << endl;

  cout << "Welcome " << myNode->fullName << " in friends circle..." << endl;
  cout << "Your ID is " << myNode->userID << ". please remember it and use this to login again..." << endl;
  int a;
  do
  {
    cout << "Enter 1 to go to friends page " << endl
         << "Enter 2 to go to Post page " << endl
         << "Enter 3 to Search user " << endl
         << "Enter 4 to Show all users " << endl
         << "Enter 5 to logout to your account " << endl;
    cin >> a;
    if (a == 1)
    {
      friendsPage(myNode, userHead);
    }
    else if (a == 2)
    {
      postPage(myNode, postHead, userHead);
    }
    else if (a == 3)
    {
      int userID;
      cout << "Enter user ID : ";
      cin >> userID;
      User *userNode = searchUser(userID, *userHead);
      if (userNode)
      {
        cout << userNode->fullName << " is in friends circle..." << endl;
      }
      else
      {
        cout << "User not found with this ID..." << endl;
      }
    }
    else if (a == 4)
    {
      allUsers(*userHead);
    }
    else if (a == 5)
    {
      cout << "Logout Successfully..." << endl;
    }
    else
    {
      cout << "Enter number betweeen 1 & 5 " << endl;
    }
  } while (a != 5);
}

int main()
{
  string text = "Friends circle";
  int width = 50; // Width of the terminal line

  int padding_left = (width - text.length()) / 2;
  int padding_right = width - text.length() - padding_left;

  string border_line(width, '*');
  string empty_line = "" + string(width - 2, ' ') + "";
  string text_line = "" + string(padding_left - 1, ' ') + text + string(padding_right - 1, ' ') + "";

  cout << border_line << endl;
  cout << empty_line << endl;
  cout << text_line << endl;
  cout << empty_line << endl;
  cout << border_line << endl;

  User *userHead = NULL;
  Post *postHead = NULL;

  // Test Case
  // addUser("Aliyan", "123", &userHead);
  // addUser("Bilal", "456", &userHead);
  // addUser("Daniyal", "789", &userHead);
  // addUser("Fahad", "123", &userHead);
  // addUser("Hamza", "456", &userHead);
  // addUser("Usama", "789", &userHead);
  // addUser("Saim", "123", &userHead);
  // addUser("Muzzamil", "456", &userHead);
  // User *user1Node = searchUser(1, userHead);
  // User *user2Node = searchUser(2, userHead);
  // User *user3Node = searchUser(3, userHead);
  // User *user4Node = searchUser(4, userHead);
  // User *user5Node = searchUser(5, userHead);
  // User *user6Node = searchUser(6, userHead);
  // User *user7Node = searchUser(7, userHead);
  // User *user8Node = searchUser(8, userHead);
  // sendRequest(user2Node, 1);
  // sendRequest(user8Node, 1);

  int a;
  do
  {
    cout << "Enter 1 to Create an Account " << endl
         << "Enter 2 to Login " << endl
         << "Enter 3 to Exit " << endl;
    cout << endl;
    cin >> a;
    if (a == 1)
    {
      string fullName;
      cout << "Enter your Full Name : ";
      cin.ignore();
      getline(cin, fullName);
      string password;
      cout << "Enter password : ";
      getline(cin, password);
      int ID = addUser(fullName, password, &userHead);
      User *myNode = searchUser(ID, userHead);
      homepage(myNode, &userHead, &postHead);
    }

    else if (a == 2)
    {
      int ID;
      cout << "Enter ID to Login : ";
      cin >> ID;
      User *myNode = searchUser(ID, userHead);
      if (!myNode)
      {
        cout << "User not found with this ID " << "Select option 1 to create an account " << endl;
      }
      else
      {
        string password;
        cout << "Enter Password : ";
        cin.ignore();
        getline(cin, password);
        if (myNode->password == password)
        {
          cout << "Login Successfully " << endl;
          homepage(myNode, &userHead, &postHead);
        }
        else
        {
          cout << "Wrong password try again to login!!! " << endl;
        }
      }
    }
  } while (a != 3);
}