#include<bits/stdc++.h>
 using namespace std;



  typedef struct node
  {
   struct  node *left,*right;
   int val;
  }tree;



   tree* newnode(int val)
   {
   tree *node=new tree;
   node->left=node->right=NULL;
   node->val=val;
   return node;
   }

 tree *insert(tree *root,int val)
  {
   if(root==NULL)
   return newnode(val);

   else
   {
    tree *temp=root,*par;
    char p;
      while(temp!=NULL)
      {
      par=temp;
      cout<<" <-/->|'l'/'r'| ("<<temp->val<<"):";
      cin>>p;
      if(p=='l')temp=temp->left;
      else if(p=='r') temp=temp->right;
      }

     if(p=='l')
      par->left=newnode(val);
     else if(p=='r')
     par->right=newnode(val);

   }

   return root;


 }

   void inorder(tree *root)
   {
   if(root)
    {
     inorder(root->left);
     cout<<root->val<<" ";
     inorder(root->right);
     }
   }
   int x =100,y=100;
     void preorder(tree *root)
   {
   if(root)
    {
     cout<<root->val<<" ";
//     gotoxy(x-10,y-10);
     preorder(root->left);
     preorder(root->right);
     }
   }


int search(tree *root,int val)
 {

  if(root->left->val==val||root->right->val==val||root->val==val)
   {
    goto lb;
   }
  search(root->left,val);
  search(root->right,val);
lb:return val;

 return 0;
 }

 tree *mirror(tree *root)
 {

  if(root)
  {
   tree *temp;
   mirror(root->left);
   mirror(root->right);
   temp=root->left;
   root->left=root->right;
   root->right=temp;

  }
  else return root;



 return root;
 }





  tree  *del(tree *root,int val)
   {

    tree *temp=root,*par,*mat=root;
    while(temp!=NULL)
    {
     par=temp;
     if(temp->right!=NULL)
       temp=temp->right;
     else
      temp=temp->left;
    }

   cout<<par->val;
   return root;
    }



    void postorder(tree *root)
   {
   if(root)
    {

     postorder(root->left);
     postorder(root->right);
      cout<<root->val<<" ";

     }
   }



   int main()
   {int val,ch;

tree *root=NULL,*t=root;

    while(1)
    {
     cout<<"...BINARY TREE...\n"<<"1.Insertion\n2.Deletion\n3.Display\n4.Search\n5.Exit\n6.Mirror \n";
     cin>>ch;
     switch(ch)
     {


     case 1:cout<<"Insert->";cin>>val;root=insert(root,val);break;
     case 2:cout<<"Delete:";cin>>val;root=del(root,val);break;
     case 3:cout<<"Inorder:";inorder(root);cout<<endl;
     cout<<"Preorder:";preorder(root);cout<<endl;cout<<"Postorder:";postorder(root);cout<<endl;break;
     case 4:cout<<"search:";cin>>val;search(t,val)?cout<<"Found!":cout<<"Not found!";
     case 5:exit(0);
     case 6:root=mirror(root);
     }


    }


   return 0;
   }