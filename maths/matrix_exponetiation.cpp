#include<bits/stdc++.h>
#define ll  long long
#define mod  1000000000
 using namespace std;

 /*
 for linear recurrence
    like f(n)=c1*f(n-1)+c2*f(n-2)+c3*f(n-3)+c4*f(n-4)+...+ck*f(n-k)

    finding f(n) -one way recursion

    cool and efficient way matrix exponentitiation

    ***********************************************

 step1- make init F1 vector i.e F1{f(1),f(2),f(3),..f(k)}

 step2-make trasnformation matrix
            _1 _2 _3 _4 _5 . . .k_
          1|0   1  0  0  0 .....0
          2|0   0  1  0  0 .....0
          3|0   0  0  1  0 .....0
          4|0   0  0  0  1......0
          5|0   0  0  0  0 1....0
           .
           .
           .
          k|ck  ck-1............c1

          F2=T*F1(
           F2{f(2),f(3),..f(k),f(k+1)}
         and so F3{f(3),..f(k),f(k+1),f(k+2)} where F3=T*F2//F3=T*T*F1=T^2*F1


         Fn=((f(n),............f(k+n-1)
              so
              Fn=T^(n-1)*F1

           result- f(n)=Fn[0]

 */


ll k;
vector<ll> a,b,c;


vector<vector<ll>>multiply( vector <vector<ll>> a,vector <vector<ll>> b)
{
vector <vector<ll>> c(k+1,vector<ll>(k+1));

    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=k;j++)
        {
            for(int x=1;x<=k;x++)
            {
              c[ i][j]=(c[i][j]+(a[i][x]*b[x][j])%mod)%mod;

            }

        }
    }
    return c;
}


vector<vector<ll>> pow(vector<vector<ll>> A,ll p)
{
    if(p==1) return A;//base case
    //rec case
    if(p&1)
    {
        return multiply(A,pow(A,p-1));
    }

    else
        {
        vector<vector<ll>> x=pow(A,p/2);
        return multiply(x,x);
        }


}

ll compute(ll n)
{
    if(n==0) return n;//base case
    //case n<=k
    if(n<=k)
    return b[n-1];

    //otherwise matrix exponentiation
    vector<ll> F1 (k+1);
    for(int i=1;i<=k;i++)
        F1[i]=b[i-1];

    //Transformation matrix

    vector<vector<ll>> T(k+1,vector<ll>(k+1));

    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(i<k)
             {
               if(j==i+1)
                {
                T[i][j]=1;
                }
                else
                    T[i][j]=0;
                    continue;
             }

             T[i][j]=c[k-j];


        }
    }

   T=pow(T,n-1);

   int res=0;
   for( int i=1;i<=k;i++)
   {
       res=(res+(T[1][i]*F1[i])%mod)%mod;

   }
   return res;
}

int main()
{
  ll T,n,num;

  cin>>T;

  while(T--)
  {
     cin>>k;
     //init vector F1
       for(int i=0;i<k;i++)
       {
           cin>>num;
           b.push_back(num);
       }
       //coffecient vector
       for(int i=0;i<k;i++)
       {
           cin>>num;
           c.push_back(num);
       }

       cin>>n;
       cout<<compute(n)<<endl;
       c.clear();
       b.clear();


  }



  return 0;}

