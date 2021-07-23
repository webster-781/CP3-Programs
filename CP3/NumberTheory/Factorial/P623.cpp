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
const int maxN = 1000;
const int digmax = 3000;
int f [maxN+1][digmax];

void mult(int i)    // set the fact[i] value to fact[i-1]*i
{
    loop(j,0,digmax-1)
    {
        f[i][j] += (f[i-1][j])*i;
        if(j<digmax-1)
            f[i][j+1] += (f[i][j]/10);
        f[i][j] = f[i][j]%10;
    }
}

void call()
{
    loop(i,0,maxN+1)
    {
        loop(j,0,digmax)
        {
            f[i][j] = 0;
        }
    }
    f[0][0] = 1;
    loop(i,1,maxN+1)
        mult(i);
}

int main()
{
    call();
    int n;
    while(cin>>n)
    {
        cout<<n<<"!\n";
        bool t = false;
        looprev(x,digmax-1,0)
            if(t || f[n][x])
            {
                cout<<f[n][x];
                t = true;
            }
        cout<<endl;
    }
}