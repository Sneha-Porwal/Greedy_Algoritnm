#include <iostream>
#include<algorithm>
using namespace std;
struct job{
	int d,p,id;
};
void Display(job a[],int n)
{
    cout<<"\n\nJobId"<<"\tProfit"<<"\tDeadline"<<endl;
    for(int i=0;i<=n-1;i++)
    {
   	 cout<<a[i].id<<"\t\t"<<a[i].p<<"\t"<<a[i].d<<"\t"<<endl;
    }
}
//******************************
bool cmp(job x,job y)
{
    return x.p>y.p;
}
int maxSlot=0;
//********************************
void Jobseq(job a[],int n){
	int slot=0,profit=0,result[maxSlot];
	for(int i=0;i<=maxSlot-1;i++)	result[i]=-1;
	for(int i=0;i<=n-1;i++)
	{
    	for(int j=a[i].d-1;j>=0;j--)
    	{
        	if(result[j]==-1)
        	{
            	result[j]=a[i].id;
            	profit=profit+a[i].p;  break;
        	}
    	}
	if(slot++==maxSlot)   break;
	}
	for(int i=0;i<=maxSlot-1;i++)
	{
    	if(result[i]!=-1)   cout<<"Job No."<<result[i]<<"in slot"<<i<<"-"<<i+1<<endl;
	}
    
}
//*******************************
int main() {
	int n,m;
	cout<<"Enter number of jobs:";
	cin>>n;
	job a[n];
	for(int i=0;i<n;i++){
    	cin>>a[i].id>>a[i].p>>a[i].d;
    	if(maxSlot<a[i].d)  maxSlot=a[i].d;
	}
	Display(a,n);
	sort(a,a+n,cmp);
	Display(a,n);
	Jobseq(a,n);
}
