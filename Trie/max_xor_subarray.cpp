#include<bits/stdc++.h>
 using namespace std;

 class TrieNode
 {
  public:

  	TrieNode * left;
  	TrieNode * right;


 };

 void insert(TrieNode *root,int n)
  {
   TrieNode *curr=root;
   int b;

     for(int i=31;i>=0;i--)
     {
        b=(n>>i)&1;

        if(b)
        {
          if(curr->right==NULL)
             curr->right=new TrieNode();
          curr=curr->right ;  	

        }
        else
        {
          if(curr->left==NULL)
             curr->left=new TrieNode();
          curr=curr->left;   	

        }

     }

    }


 int maxor(TrieNode *root,int n)
  {
   
   TrieNode *curr=root;
   int b,sum=0;
   for(int i=31;i>=0;i--)
   {
   	b=(n>>i)&1;
    if(b)
    {
     if(curr->left!=NULL)
      {
        curr=curr->left;
        sum=sum+pow(2,i);
      }	
     else
     	curr=curr->right;
    }
    else
     {
     if(curr->right!=NULL)
      {
        curr=curr->right;
        sum=sum+pow(2,i);
      }	
     else
     	curr=curr->left;
    }



   }

  return sum;
  }


  int main()
  {

  int n;
  cin>>n;
  int *a=new int[n];
  TrieNode *root=new TrieNode();
  int i;
  int pre_xor1=0,max_xor1=INT_MIN,max_xor2=INT_MIN;
  for(int i=0;i<n;i++)
  {
  	cin>>a[i];
  }
int res=INT_MIN;

  for( i=0;i<n;i++)
  	{
  
        pre_xor1=pre_xor1^a[i];
  		insert(root,pre_xor1);
        int temp=maxor(root,pre_xor1);
         if(temp>max_xor1)
         	max_xor1=temp;
         
   int pre_xor2=0;
  for (int j = i+1; j < n; ++j)
  {

  	pre_xor2=pre_xor2^a[j];
  	insert(root,pre_xor2);
  	int temp=maxor(root,pre_xor2);
  	if(temp>max_xor2)
  		max_xor2=temp;
  

  }
  cout<<max_xor1<<" "<<max_xor2<<endl;
  res=max(res,max_xor2+max_xor1);
  
     }
  
    cout<<res;
  	return 0;
  }
