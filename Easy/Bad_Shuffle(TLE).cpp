#include<iostream>
#include<unordered_map>
#define ll long long
using namespace std;
unordered_map<ll,ll> m1;
unordered_map<ll,ll>::iterator itr;
int conv(int a1[],int n){
        int i, k = 0;
        for (i = 0; i < n; i++) k = 10 * k + a1[i];
        return k;
    }
void rec(int a[],int i,int n){
    if(i==n)
    {
        m1[conv(a,n)]++;
        return;
    }
    for(long j=0;j<n;j++)
    {
        swap(a[i],a[j]);
        rec(a,i+1,n);
        swap(a[i],a[j]);
    }
}
int main()
{
        int n;
        cin>>n;
        int a[n];
        int b[n];

         for(int i=0;i<n;i++) a[i]=i+1;
         rec(a,0,n);
        for(itr=m1.begin();itr!=m1.end();itr++){
        cout<<itr->first<<" "<<itr->second<<"\n";
    }

}


