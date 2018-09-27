#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a[4000040]={0};
ll lazy[400040]={0};

void updateRangeUtil(ll i, ll s, ll e, ll cs,ll ce) {
        if(lazy[i]!=0){
            a[i]=(e-s+1)-a[i];
            if(s!=e){
                lazy[2*i+1]++;
                lazy[2*i+2]++;
                lazy[2*i+1]%=2;
                lazy[2*i+2]%=2;
            }
            lazy[i]=0;
        }
    if (s>e||s>ce||e<cs) return;
    if (s>=cs&&e<=ce)
    {
        a[i]=(e-s+1)-a[i];
        if (s!=e)
        {
            lazy[2*i+1]++;
            lazy[2*i+2]++;
            lazy[2*i+1]%=2;
            lazy[2*i+2]%=2;
        }
        return;
    }
    ll mid=(s+((e-s)>>1));
    updateRangeUtil(2*i+1,s,mid,cs,ce);
    updateRangeUtil(2*i+2,mid + 1,e,cs,ce);
    a[i]=a[2*i+1]+a[2*i+2];
}

ll getSumUtil(ll s,ll e,ll cs,ll ce,ll i)
{
    if(lazy[i]!=0){
        a[i]=(e-s+1)-a[i];
        if(s!=e){
            lazy[2*i+1]++;
            lazy[2*i+2]++;
            lazy[2*i+1]%=2;
            lazy[2*i+2]%=2;
        }
        lazy[i]=0;
    }
    if (s>e||s>ce||e<cs) return 0;
    if (s>=cs&&e<=ce) return a[i];
    ll mid=(s+((e-s)>>1));
    return getSumUtil(s,mid,cs,ce, 2*i+1)+getSumUtil(mid + 1,e,cs,ce,2*i+2);
}

int main()
{
    ll n,q;
        ll ss,qs,qe;
        cin>>n>>q;
        while(q--){
        cin>>ss;
        if(ss==0){
            cin>>qs>>qe;
            updateRangeUtil(0,0,n,qs,qe);
            }
        else if(ss==1){
            cin>>qs>>qe;
            cout<<getSumUtil(0,n,qs,qe,0)<<endl;
            }
        }
    }
