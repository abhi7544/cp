#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    char c;
    struct node *left ,*right;
}et;

bool isop(char c)
{

    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
     return true;
     else
     return false;

}
void inorder(et *root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->c;
        inorder(root->right);
    }
}

et* create_newnode(char c)
{
  et *newnode=new et;
  newnode->c=c;
  newnode->left=newnode->right=NULL;
return newnode;
}
