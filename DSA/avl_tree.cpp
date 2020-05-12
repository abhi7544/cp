// Node is defined as
#include<bits/stdc++.h>
using namespace std;
 struct avl
{
    int val;
    struct avl* left;
    struct avl* right;
    int ht;
};
typedef struct avl node;
int max(int a,int b)
{
 return (a>b)?a:b;
 }

int height(node *n)
 {
  if(n==NULL)
   return 0;
    else
       return n->ht;
 }

int getbf(node *n)
  {
    if(n==NULL)return 0;
     else
         return height(n->left)-height(n->right);

  }

node *newnode(int val)
 {
    node *newnode=new node;
    newnode->left=newnode->right=NULL;
    newnode->ht=-1;
    newnode->val=val;



    return newnode;
 }
node *rightrotate( node *y)
{
    node *x = y->left;
    node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->ht = max(height(y->left), height(y->right))+1;
    x->ht = max(height(x->left), height(x->right))+1;

    // Return new root
    return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
node *leftrotate(node *x)
{
    node *y = x->right;
    node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    //  Update heights
    x->ht = max(height(x->left), height(x->right))+1;
    y->ht = max(height(y->left), height(y->right))+1;

    // Return new root
    return y;
}


node * insert(node *root,int val)
{

    if(root==NULL)
       return newnode(val);

    if(root->val>val)
    root->left=insert(root->left,val);

    else if(root->val<val)
    root->right=insert(root->right,val);

    else
        return root;
    root->ht=1+max(height(root->left),height(root->right));
    int bf=getbf(root);


    if(bf>1)
    {  //LL case
         if(val<(root->left)->val)
          return   rightrotate(root);
      //LR case
        else
         {
             root->left=leftrotate(root->left);
             return  rightrotate(root);
         }
    }

    if(bf<-1)
    { //RR case
        if(val>(root->left)->val)
          return   leftrotate(root);
      //RL case
        else
         {
             root->right=rightrotate(root->right);
             return  leftrotate(root);
         }
    }


    return root;

 }


void inorder(node *root)
{
    if(root!=NULL)
    {   inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }

}


 int main()
  {
     node* root =NULL;
     int val;
     while(1)
     {
         cout<<"\n1.Insert\n2.Display\n3.Exit\n4.Default\n";
         int ch;
         cin>>ch;
         switch(ch)
         {
             case 1:cout<<"Insert:";cin>>val;root=insert(root,val); break;
             case 2: inorder(root); break;
             case 3:exit(0);
             default:cout<<"Invalid Entry\n";
         }


     }

     return 0;
  }


