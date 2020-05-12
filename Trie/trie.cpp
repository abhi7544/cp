#include<bits/stdc++.h>
 using namespace std;
/* smallest unique prefix
input -zebra dog dove duck
output- z    dog dov du

input -zebra dog dove duck zebras dogs
output-  -1  -1  dov du   zebras dogs
input -zebra dog dove dovel  duck zebras dogs
output-  -1  -1   -1   dovel    du   zebras dogs
*/
class Node
{
public:

	char data;
	bool isleaf;
	int visit;
	unordered_map<char,Node*> children;
	 Node(char data)
	 {
	 	this->data=data;
	 	this->isleaf=false;
	 	this->visit=0;
	 }
	
	
};

class trie
{
public:
	Node *root;

	trie()
	{

		this->root=new Node('\0');

	}
	
	void addWord(string str)
	 {
	 	Node *temp=root;
	 	for(char ch:str)
	 	{
	 		if(temp->children.count(ch))
	 		{
	 		
	 			temp=temp->children[ch];
	 			temp->visit++;
	 		}
	 		else
	 		{
	 			Node *n=new Node(ch);
	 			temp->children[ch]=n;
	 			temp=n;
	 			temp->visit++;
	 		}
	 	}
	 	temp->isleaf=true;
	 }
	
	string lcp()
	{
		string res="";
		char ch;
       
		Node *temp=root;
     
       while(!temp->isleaf && temp->children.size()==1 )
           {

 
           	for(auto t:temp->children)
            ch=t.first;
         
           	res=res+ch;
           	
           	temp=temp->children[ch];
           }

           return res;

     }

	bool search(string str)
	{
	

		Node *temp=root;
     	for(char ch:str)
	 	{
	 		if(temp->children.count(ch))
	 		{
	 			temp=temp->children[ch];
	 		}
	 		else
	 		{
	 			return false;
	 		}
	 	}
	 	 return (temp->isleaf);

	}

	void unique_prefix(vector<string> s,int n)
	 {
              
         vector<string> m(n); 
       for(int i=0;i<n;i++)
       {
       
         string str=s[i];
         Node *temp=root;
         int j=0;
         for(char ch:str)
	 	 {
            
	 		 if(temp->children.count(ch))
	 		 {
	 	       temp=temp->children[ch];
	 	       if(temp->visit!=1)
	 	        j++;
	 	       else if(temp->visit==1)
	 	       {  
	 	          m[i]=str.substr(0,j+1);
	 	       }

	 		 }
           

	 	  }
	 	  if(j==str.size())
	 	  	m[i]="-1";



        }

        
  for(int i=0;i<n;i++)
  	cout<<m[i]<<" ";  

     }   

};


 int main()
 {

  trie T;
  int n;
  cout<<"#Words\n";
  cin>>n;
  string s;
  int size=n;
  vector<string> str(n);
  vector<string> res(n);
   for(int i=0;i<n;i++)
   {
    cin>>str[i];
  	T.addWord(str[i]);
    }

    cout<<"#Search-query\n";
    cin>>n;
    while(n--)
    {
    cout<<"str:	";
    cin>>s;
    T.search(s)?cout<<"present":cout<<"Not present";
    cout<<"\n";
    }
     cout<<"longest common prefix is"<<T.lcp()<<endl;

     T.unique_prefix(str,size);




 return 0;}