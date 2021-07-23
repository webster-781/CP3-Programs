//MAKER CODE

#include<bits/stdc++.h>
#define loop(x,i,n) for(int x = i; x < n; ++ x)
#define looprev(x,i,n) for(int x = i;x>=n;x--)
#define lloop(x,i,n) for(ll x = i; x < n; ++ x)
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair <int,int> pii;
typedef map<int,int> mi;
typedef pair<long,long> pll;

int main()
{
    long N,Q;
    int iter =1;
    while(cin>>N>>Q && N>0)
    {
        printf("CASE# %d:\n",iter++);
        vector<int> s(N,0);
        int t;
        loop(i,0,N)
            cin>>s[i];
        sort(s.begin(),s.end());
        loop(i,0,Q)
        {
            cin>>t;
            auto ind = lower_bound(s.begin(),s.end(),t);
            int x = distance(s.begin(),ind);
            if(s[x] == t)
            {
                printf("%d found at %d\n",t,x+1);
            }
            else
            {
                printf("%d not found\n",t);
            }
        }
    }
}