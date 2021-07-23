#include<bits/stdc++.h>
#define loop(x,i,n) for(int x = i; x < n; ++ x)
#define looprev(x,i,n) for(int x = i;x>=n;x--)
#define lloop(x,i,n) for(ll x = i; x < n; ++ x)
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair <int,int> pii;
typedef map<int,int> mi;
vi out;
int main()
{
    int a = 1,b = 1,c = 1,d = 1;
    while(true)
    {
        int ans = 120;
        cin>>a>>b>>c>>d;
        if(a+b+c+d == 0)
            break;
        ans += (a-b+40)%40;
        ans += (c-b+40)%40;
        ans += (c-d+40)%40;
        out.push_back(ans*9);
    }
    for(auto u: out)
        cout<<u<<endl;
}