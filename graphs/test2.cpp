#include<bits/stdc++.h>
using namespace std;
#define ll long long int

struct trie{
	struct trie *child[26];
	bool isend;

	trie()
	{
		memset(child,0,sizeof(child));
		isend=false;
	}
};

struct trie *root;

void insert(string str)
{
	struct trie *curr=root;
	for(char ch:str)
	{
		int i=ch-'a';
		if(curr->child[i]==NULL)
		{
			curr->child[i]= new trie;
		}
		curr=curr->child[i];
	}
	curr->isend=true;
}


bool search(string str)
{
	struct trie *curr=root;

	for(int k=0; k< str.length() ; k++)
	{
		int i=str[k]-'a';
		if(curr->child[i]==NULL)
		{
			return false;
		}
		curr=curr->child[i];
		
      
	}
  return curr->isend;

}
main()
{

    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("/home/abhishek/Downloads/Algorithms/input.txt", "r", stdin);
    freopen("/home/abhishek/Downloads/Algorithms/output.txt", "w", stdout);
    #endif  
	root=new trie;
	ll n;
	cin>>n;
	while(n--)
	{
		string str;
		cin>>str;
		insert(str);

	}
	cin>>n;
	while(n--)
	{
		string str;
		cin>>str;
		if(search(str))
		{
			cout<<str<<" present\n";

		}
		else
		{
			cout<<str<< " not present\n";

		}

	}
}




















