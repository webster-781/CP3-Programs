//MAKER CODE

#include<bits/stdc++.h>
#define loop(x,i,n) for(int x = i; x < n; ++ x)
#define looprev(x,i,n) for(int x = i;x>=n;x--)
#define lloop(x,i,n) for(ll x = i; x < n; ++ x)
#define pb push_back
using namespace std;
typedef long double ld;
typedef unsigned long long LLU;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair <int,int> pii;
typedef map<int,int> mi;

vector<LLU> vals;

void find10(int n)
{
    LLU x= 1%n;
    LLU sum = x;
    for(int i = 0; i<=n+1; i++)
    {
        vals.pb(sum);
        x = (10*x)%n;
        sum = (x + sum)%n;
    }
    return;
}

int main()
{
    int x;
    while(cin>>x)
    {
        find10(x);
        // for(int i: vals)
        //     cout<<i<<" ";
        // cout<<endl;
        loop(i,0,x+1)
            if(vals[i] == 0)
            {
                cout<<i+1<<endl;
                break;
            }
        vals.clear();
    }
}