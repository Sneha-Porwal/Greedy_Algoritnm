 #include<iostream>
#include<algorithm>
using namespace std;
struct Item{
	double p,w,pDivw;
};
//*****************************
void Display(Item a[],int n)
{
	cout<<"\n\nItem No"<<"\tProfit"<<"\tWeight"<<"\tP/W ratio"<<endl;
	for(int i=0;i<=n-1;i++)
	{
		cout<<"Item"<<i+1<<"\t"<<a[i].p<<"\t"<<a[i].w<<"\t"<<a[i].pDivw<<endl;
	}
}
//*******************************
double knapsack(Item a[],int n,int m)
{
	int i;
	double x[n]={0.0},remainingW=m,totalProfit=0.0;
	for(int i=0;i<=n-1;i++)
	{
		if(a[i].w>remainingW)  break;
		x[i]=1; 
		totalProfit+=a[i].p;
		remainingW=remainingW-a[i].w;
	}
	if(remainingW!=0)
	{
		x[i]=remainingW/a[i].w;
		totalProfit+=x[i]*a[i].p;	
	}
		return totalProfit;
}
bool cmp(Item x,Item y)
{
	return x.pDivw>y.pDivw;
}
//*****************************
int main()
{
	int n,m;
    cout<<"Enter No. of elements"; cin>>n;
    Item a[n];
    cout<<"\nEnter item wise profits and weights\n";
    for(int i=0;i<n;i++)
    {
	    cout<<"\nItem "<<i+1<<"\t"; cin>>a[i].p>>a[i].w;    a[i].pDivw=double(a[i].p/a[i].w);
	}
	cout<<"Enter capacity of knapsack:";   cin>>m;
	sort(a,a+n,cmp);
	Display(a,n);
	cout<<"Max Profit :"<<knapsack(a,n,m);
}
