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
typedef long double ld;

bool intersect(ld xl, ld xr, ld yl, ld yr)
{
    return max(xl,yl) <= min(xr,yr);
}
int main()
{
    int N;
    cin>>N;
    vi t(N,0);
    vector<ld> l(N,0.0),r(N,0.0);
    loop(i,0,N)
    {
        cin>>t[i]>>l[i]>>r[i];
        if(t[i] == 2 || t[i] == 4)
            r[i] = r[i] - 0.5;
        if(t[i] >= 3)
            l[i] = l[i] + 0.5;
    }
    ll cnt = 0;
    loop(i,0,N)
    {
        loop(j,i+1,N)
            if(intersect(l[i],r[i],l[j],r[j]))
                cnt ++;
    }
    cout<<cnt<<endl;
}