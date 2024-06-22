#include<iostream>
#include<stdlib.h>
using namespace std;
struct TreeNode{
	int value;
	TreeNode* s1;
	TreeNode* s2;
	TreeNode* s3;
	TreeNode* s4;
};

TreeNode* root=NULL;

 int findMedian(int arr[],int size){
    if(size%2!=0){
 	int medIndex= (size + 1)/2 -1;
 	return arr[medIndex];
    }
    else{
        int median1index= (size )/2-1;
        int median2Index= (size +1)/2;
        int medianIndex=  (arr[median1index]+ arr[median2Index])/2 ;
        return medianIndex;
        
    }
 	
 }
 
TreeNode* insertion( int value){
	//if(root==NULL){
	
	

	TreeNode* ptr = (TreeNode*) malloc(sizeof(TreeNode));
	ptr->value= value;
	ptr->s1=NULL;
	ptr->s2=NULL;
	ptr->s3=NULL;
	ptr->s4=NULL;
    if(root==NULL){
    root=ptr;
	return root;
	
	
    }

/*if (root->s1==NULL){
    

}
if (root->s2==NULL){
   

}
if (root->s3==NULL){

}
if (root->s4==NULL){

}*/
 return root;
}
int main(){
	int size=11;
	int s[size]= {22,44,75,90,92,99,110,112,125,130,131};
    int s1[3]={22,44,75};
    int s2[2]={90,92};
    int s3[3]={110,112,125};
    int s4[2]={130,131};

	//TreeNode* root=NULL;
	
	int median = findMedian(s,size);
	cout<<"Median Value: "<<median<<endl;

	root = insertion(median);
	cout<<"root value : "<<root->value<<endl<<endl;

    int medianS1=findMedian(s1,3);
    cout<<"medianS1 :"<<medianS1;
    cout<<endl;
    int medianS2=findMedian(s2,2);
    cout<<"medianS2 :"<<medianS2;
    cout<<endl;
    int medianS3=findMedian(s3,3);
    cout<<"medianS3 :"<<medianS3;
    cout<<endl;
    int medianS4=findMedian(s4,2);
    //cout<<endl;
    cout<<"medianS4 :"<<medianS4;

    root= insertion(medianS1);





    
	
	
}