#include<bits/stdc++.h>
using namespace std;



	struct Node
	{
		int data;
		struct Node* left;
		struct Node* right;
		
		
	};

struct Node* insert(int data,struct Node * root)
{
	struct Node *t ;
	struct Node  *p ;


	t=(struct Node*)malloc(sizeof(struct Node));
	t->data=data;
	t->left=NULL;
	t->right=NULL;
	p=root;


	if(root==NULL)
	{
		
		return t;
	}

	else
	{
		struct Node *curr;
		curr=root;

		while(curr)
		{
			p=curr;
			if(t->data>curr->data)
			{
				curr=curr->right;
			}
			else
				curr=curr->left;
		}

		if(t->data>p->data)
		{
			p->right=t;
		}
		else
			p->left=t;
	}

	return root;
}
void printInorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
   
    printInorder(node->left); 
  
   
    cout << node->data << " "; 
  
   
    printInorder(node->right); 
}
main()
{
 
	struct Node* root=NULL;
    int n;
    cin>>n;
    int data;
    for(int i=0;i<n;i++)
	{
	cin>>data;
	root=insert(data,root); 
	

   }
 
  printInorder(root);
	
}

