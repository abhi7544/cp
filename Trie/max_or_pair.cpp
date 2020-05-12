#include<bits/stdc++.h>
using namespace std;

class trieNode
{
public:
	trieNode *left;
	trieNode *right;



	
};


void insert(trieNode *head ,int n)
{
	trieNode *curr=head;
	for(int i=31;i>=0;i--)
	{
		int bit=(n>>i)&1;
		if(bit)
		{
			if(curr->right==NULL)
				curr->right=new trieNode();
			curr=curr->right;
		}

		else
		{
			if(curr->left==NULL)
				curr->left=new trieNode();
			curr=curr->left;
		
		}
	}

 }

int MaxXorPair(trieNode *head,int *arr,int n,int el)
 {
 	int max_xor=INT_MIN;
 	trieNode *cur=head;
 	int val=el;
 	int cur_xor=0;
 	for(int i=31;i>=0;i--)
 	{
     int b=(val>>i)&1;
      if(b==0)
      {
      	if(cur->right!=NULL)
      		{
      		cur=cur->right;
      	 	cur_xor+=pow(2,i);
      	}
      	else
      	 	cur=cur->left; 
       }

        else
        {
      	if(cur->left!=NULL)
      	 	{   cur=cur->left;
      	 		cur_xor+=pow(2,i);
      	 	}
      	 else
        	 cur=cur->right; 
        }

 	  }
  
  max_xor=max(max_xor,cur_xor);
  return max_xor;
   }


 int main()
 {
    int n;
    cin>>n;
    int *arr =new int[n];
    for(int i=0;i<n;i++)
     cin>>arr[i];

int res=INT_MIN;


 trieNode *head=new trieNode();

 for(int i=0;i<n;i++)
 {
  

 	insert(head,arr[i]);
 	
 	int x=MaxXorPair(head,arr,n,arr[i]);
 	res=(res<x)?x:res;
 }




   cout<<res;

  	return 0;}