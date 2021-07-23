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
const long maxN = 366;
const int digmax = 800;
int f [maxN+1][digmax];

void mult(int i)    // set the fact[i] value to fact[i-1]*i
{
    // cout<<i<<endl;
    loop(j,0,digmax-1)
    {
        f[i][j] += (f[i-1][j])*(i);
        f[i][j+1] += (f[i][j]/10);
        f[i][j] = f[i][j]%10;
        // cout<<f[i][j];
    }
    // cout<<endl;
}

void count(int i)
{
    vi cnt(10,0);
    int lnz = 1;
    loop(j,0,digmax)
    {
        cnt[f[i][j]]++;
        if(f[i][j] > 0)
            lnz = j;
    }
    cnt[0] = cnt[0] - (digmax - lnz - 1);
    cout<<i<<"! --"<<endl;
    loop(j,0,5)
    {
        cout<<setw(7)<<right<<"("<<j<<")";
        cout<<setw(7)<<right<<cnt[j];
    }
    cout<<endl;
    loop(j,5,10)
    {
        cout<<setw(7)<<right<<"("<<j<<")";
        cout<<setw(7)<<right<<cnt[j];
    }
    cout<<endl;
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
        if(n==0)
            break;
        count(n);
    }
}