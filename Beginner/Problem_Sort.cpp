#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
using namespace std;
#define MOD  1000000007
#define p_b push_back
#define p_f push_front
#define m_p make_pair
#define po_f pop_front()
#define po_b pop_back()
#define fs first
#define sc second
typedef long long ll;
typedef long long ll;
 typedef vector<ll> vi;
typedef pair<ll, ll> ipair ;
typedef vector<ipair> vip;
vector<ll>:: iterator iv;
int main(){
ll p,s;
cin>>p>>s;
vip v1,v2;
for(int k=1;k<=p;k++){
    ll a1[s],a2[s];
    for(int i=0;i<s;i++) cin>>a1[i];
    for(int i=0;i<s;i++) cin>>a2[i];
    for(int i=0;i<s;i++) v1.p_b(m_p(a1[i],a2[i]));
    sort(v1.begin(),v1.end());
    ll c=0;
    for(int i=0;i<s-1;i++)
        if(v1[i].sc>v1[i+1].sc) c++;
    v2.p_b(m_p(c,k));
    v1.clear();
}
ll sz=v2.size();
sort(v2.begin(),v2.end());
for(int i=0;i<sz;i++) cout<<v2[i].sc<<endl;
return 0;
}

