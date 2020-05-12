#include<bits/stdc++.h>
 using namespace std;

 //Ax+By=gcd(A,B)  find x ,y with gcd
//multiplicative inverse using this

 // (a*a^-1)%m=1 ,inverse exist when gcd(a,m)=1
 //a^-1=y    ay%m=1  ,(ay%m-1)=0 ,(ay%m-1)%m=0,(ay -1)=km ->ay+cm=1  similiar  to Ax+BY=Gcd(A,B)  y=x we need to find parameter a and m
 int x,y,GCD;
 void extended_gcd(int a ,int b)
 {
     if(b==0)
        {
        x=1;
        y=0;
        GCD=a;
        return;
        }


     extended_gcd(b,a%b);

     int Cx=y;
     int Cy=x-(a/b)*y;
     x=Cx;
     y=Cy;
 }
 int inverse_modulo(int a,int m)
  {
    extended_gcd(a,m);
    return (x+m)%m;
   }


int main()
{
int a,b,no,m;
/*cin>>a>>b;
if(a<b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}
extended_gcd(a,b);

cout<<a<<"x"<<x<<"+"<<b<<"x"<<y<<"="<<GCD;*/

cout<<" a =";
cin>>no;
cout<<"m=";
cin>>m;
cout<<inverse_modulo(no,m);
return 0;

}
