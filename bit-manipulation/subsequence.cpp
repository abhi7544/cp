#include <iostream>
using namespace std;
//generate the all subsequence of a string
void subsequence(char str[],char out[],int i,int j)
{
    //base case
if(str[i]=='\0')
{   out[j]='\0';
     if(out[0]=='\0')
      {cout<<" NUll";}
    else cout<<out<<",";
    return;
}

// recursive case
out[j]=str[i]; //including char at str[i] in subsequence
subsequence(str,out,i+1,j+1);
out[j]='\0';//Excluding tha char at str[i] in subsequence
subsequence(str,out,i+1,j);//keeping the j pointer same and increasing i pointer

}

int main()
{

    char str[100];
    cin>>str;
    char out[100];
    subsequence(str,out,0,0);
    return 0;
}
