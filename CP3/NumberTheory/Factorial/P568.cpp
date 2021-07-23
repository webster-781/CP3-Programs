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
const int maxN = 10000;
const int digmax = 10;
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
    int j = 0;
    while(f[i][j]==0)j++;
    // cout<<i<<" "<<j<<endl;
    int temp[digmax];
    for(int k = 0; k+j<digmax; k++)
        temp[k] = f[i][j+k];
    loop(t,digmax-j,digmax)
        temp[t] = 0;
    swap(temp,f[i]);
    // cout<<i<<": ";
    // looprev(x,9,0)
    //     cout<<f[i][x];
    // cout<<endl;
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
        cout<<setw(5)<<right<<n<<" -> "<<f[n][0]<<endl;
    }
}