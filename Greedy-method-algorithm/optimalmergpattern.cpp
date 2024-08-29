#include<bits/stdc++.h>
using namespace std;
//**************************************************
void Shift(int files[], int &n)
{
    for (int i = 1; i < n - 1; i++) files[i] = files[i + 1];
    n--;
}
//**************************************************
int optimalMerge(int files[], int n)
{
	sort(files,files+n);
	int cost = 0;
	while (n > 1)
    {
    	int effort = files[0] + files[1];
    	cost += effort;
    	cout<<"Cost of merging "<<files[0]<<" and "<<files[1]<<" is "<<cost<<endl;
    	files[0] = effort;
    	Shift(files,n);
    	sort(files,files+n);
	}
	return cost;
}
int main()
{   int n;
    cout<<"Number of Files: "; cin>>n;
	int files[n];
	cout<<"\nEnter File size";
	for(int i=0;i<=n-1;i++) cin>>files[i];
	int minCost = optimalMerge(files, n);
	cout<<"Minimum cost of merging is "<<minCost;
	return 0;
}
