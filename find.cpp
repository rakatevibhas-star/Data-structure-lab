#include<iostream>
using namespace std;
int main()
{
int a[10];
int b,c;
cout<<"Enter array Elements"<<endl;
for(int i=0;i<10;i++)
{
cin>>a[i];
}
cout<<"Array elements are:"<<endl;
for(int i=0;i<10;i++)
{
cout<<a[i]<<" ";
}
cout<<"Enter searching element:"<<endl;
cin>>b;
for(int i=0;i<10;i++)
{
if(a[i]==b)
{
c=1;
}
else
{
c=0;
}
}
if(c==1)
{
cout<<"Element found";
}
else
{
cout<<"Element not found";
}
}
