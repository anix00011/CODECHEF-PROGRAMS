#include<iostream>
using namespace std;
#define ll long long
ll f1(ll n)
{
	if(n==1) return 1;
	if(n&1) return(2*f1(n/2)+1);
	else return(2*f1(n/2)-1);
}
ll f2(ll n)
{
	if(n==2) return 2;
	if(n==3) return 1;
	if(n&1) return(2*f2(n/2)+1);
	else return(2*f2(n/2)-1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=0;
	cin>>t;
	while(t-->0)
	{
		ll n;
		cin>>n;
		cout<<f1(n)<<" "<<f2(n)<<"\n";
	}
}
