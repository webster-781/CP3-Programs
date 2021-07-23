//MAKER CODE

#include<bits/stdc++.h>
#define loop(x,i,n) for(int x = i; x < n; ++ x)
#define looprev(x,i,n) for(int x = i;x>=n;x--)
#define lloop(x,i,n) for(ll x = i; x < n; ++ x)
#define pb push_back
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair <int,int> pii;
typedef map<int,int> mi;

int main()
{
    long Y,P;
    cin>>Y>>P;
    vl v(P,0);
    loop(i,0,P)
        cin>>v[i];
    // Y = v.back();
    auto it = v.begin();
    int m1 = 0,m2 = 0,sz = 0;
    loop(i,0,P)
    {
        long gap = upper_bound(it,v.end(),v[i]+Y-1) - it;
        if(sz < gap)
        {
            sz = gap;
            m1 = v[i];
            m2 = v[i+gap-1];
        }
        it++;
    }
    cout<<sz<<" "<<m1<<" "<<m2<<endl;
}