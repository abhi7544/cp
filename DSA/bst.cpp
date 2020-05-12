#include <bits/stdc++.h>
using namespace std;

 typedef struct node
 {
   int data;
   struct node *left ,*right;
  }bst;

 bst  *create_newnode(int d)
 {
 bst *newnode=new bst;
 newnode->data=d;
 newnode->left=NULL;
 newnode->right=NULL;
 return newnode;
   }


    bst* search(bst *root,int key)
   {

    while(root!=NULL && key!=root->data)
    {
      if(key < root->data)
         root = root->left;
      else
         root = root->right;
    }

    return(root);

 }

  bst *insert(bst *root,int d)
  {
   bst *t=root,*prev=NULL;
   if(root==NULL)
   return create_newnode(d);

    else
    {

      while(t!=NULL)
      {

         prev=t;

         if(d<t->data)
         t=t->left;
         else
         t=t->right;

      }
   if(d<prev->data)
     prev->left=create_newnode(d);
     else
     prev->right=create_newnode(d);

     }


return root;

  }

  void preorder(bst *root)
  {

  if(root!=NULL)
  {
  cout<<root->data<<"  ";
  preorder(root->left);
  preorder(root->right);
    }

  }
    void inorder(bst*root)
   {

   if(root)
    {
     inorder(root->left);
     cout<<root->data<<" ";
     inorder(root->right);

     }
   }

    void postorder(bst *root)
   {
     if(root)
     {

     inorder(root->left);
     inorder(root->right);
      cout<<root->data<<" ";
     }
   }




  int maxDepth(struct node* node)
{
    if (node==NULL)
        return 0;
    else
    {
         /* compute the depth of each subtree */
          int lDepth = maxDepth(node->left);
          int rDepth = maxDepth(node->right);

          /* use the larger one */
          if (lDepth > rDepth)
                return(lDepth+1);
          else
               return(rDepth+1);
   }
}


int main()
{
    bst *root=NULL,*t=root;
    int val,ch;
 while(1)
    {
     cout<<"...BINARY SEARCH TREE...\n"<<"1.Insertion\n2.Deletion\n3.Display\n4.Search\n5.Exit\n";
     cin>>ch;
     switch(ch)
     {


     case 1:cout<<"Insert->";cin>>val;root=insert(root,val);break;
    // case 2:cout<<"Delete:";cin>>val;root=delete(root,val);break;
     case 3:cout<<"Inorder:";inorder(root);cout<<endl;
     cout<<"Preorder:";preorder(root);cout<<endl;cout<<"Postorder:";postorder(root);cout<<endl;break;
     case 4:cout<<"search:";cin>>val;
     if(search(root,val)->data==val)cout<<"Found!\n";else cout<<"Not found!";
     }


    }


    cout<<" \n "<<root->right->left->data;

//cout<<temp->data;
//  preorder(root);
return 0;
}