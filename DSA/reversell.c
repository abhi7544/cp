#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
int data;
struct list* next;

}node;
node* head=NULL;
void insert(int d)
{
node* newnode=(node*)malloc(sizeof(node));
newnode->data=d;
newnode->next=NULL;
if(head==NULL)
  head=newnode;

 else
 {
node* temp=head;
while(temp->next!=NULL)
 {
 temp=temp->next;
 }
temp->next=newnode;

  }



}

void disp()
{
if(head!=NULL)
{
 node* temp=head;
  while(temp->next!=NULL)
   {
   printf("%d->",temp->data);
   temp=temp->next;
   }
    printf("%d",temp->data);
 }

}


void rev()
{
node* prev=NULL,*adv,*cur=head;
 while(cur!=NULL)
 {
  adv=cur->next;
  cur->next=prev;
  prev=cur;
  cur=adv;
  }
  head=prev;

}

void Delete()
{

if(head!=NULL)
{
 rev();

 node* cur=head,*temp,*max=head;

 while((cur->next)!=NULL)
 {

  if(cur->next->data <max->data)
  {
   temp=cur->next;
   cur->next=temp->next;
   free(temp);

   }

   else
    {
    cur=cur->next;
    max=cur;
   }

 }
 rev();

}


}

void seg()
{
node* t1=head,*t2=head->next,*h=head->next;
while(t2!=NULL &&t2->next!=NULL)
{
 t1->next=t2->next;
 t1=t1->next;
 t2->next=t1->next;
 t2=t2->next;

     }
     t1->next=h;
 }



 int main()
  {
   int ch,d;
   while(1)
   {
    printf("\n1.insert\n2.display\n3.exit\n4.Reverse\n5.Delete(grtRi8)\n6.seg\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:printf("Enter a data:");
         scanf("%d",&d);
         insert(d);break;
    case 2:disp();break;
    case 4:rev();break;
    case 5:Delete();break;
    case 6:seg();break;
    case 3:exit(0);
    }


   }


return 0;
  }