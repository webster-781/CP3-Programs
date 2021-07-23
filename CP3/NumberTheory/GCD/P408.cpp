//MAKER CODE

#include<bits/stdc++.h>
#define loop(x,i,n) for(int x = i; x < n; ++ x)
#define looprev(x,i,n) for(int x = i;x>=n;x--)
#define lloop(x,i,n) for(ll x = i; x < n; ++ x)
#define pb push_back
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair <int,int> pii;
typedef map<int,int> mi;
const long maxN = 1e8;

ll gcd(ll a, ll b)
{
    return (b==0)?a:gcd(b,a%b);
}

void solve(int x, int y)
{
    printf("%10d%10d    %s\n\n", x, y, gcd(x, y) == 1 ? "Good Choice" : "Bad Choice");
}

int main()
{
    int i,j;
    while(cin>>i>>j)
    {
        solve(i,j);
    }
}