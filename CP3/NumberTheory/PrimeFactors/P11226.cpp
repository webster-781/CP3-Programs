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
const ll maxN = 500001;
vl primes;
vl lopf;


// int getMid(int s, int e)
// {
//     return s + (e-s)/2;
// }

void sieve()
{
    vector<bool> isp(maxN+1,true);
    lloop(i,2,maxN+1)
    {
        if(isp[i])
        {
            primes.pb(i);
            for(ll j = i*i; j<=maxN; j+= i)
                isp[j] = false;
        }
    }
}

ll eulerphi(ll n)
{
    ll x = n;
    ll ans = n;
    for(int i = 0; i<primes.size() && primes[i]<=sqrt(x); i++)
    {
        if(x%primes[i] == 0)
        {
            while(x%primes[i]==0)
                x/=primes[i];
            ans -= ans/primes[i];
        }
    }
    if(x>1)
        ans -= ans/x;
    return ans;
}

ll cntdiv(ll n)
{
    ll x = n;
    ll ans = 1;
    for(int i = 0; i<= primes.size() && primes[i] <= sqrt(x); i++)
    {
        int cnt = 0;
        while(x%primes[i]==0)
        {
            x = x/primes[i];
            cnt++;
        }
        ans *= (cnt+1);
    }
    if(x>1)
        ans *= 2;
    return ans;
}

// ll getMaxST(int st[], int ss, int se, int l, int r, int n)
// {
//     if(ss >= l && se <= r)
//         return st[n];
//     int mid = getMid(ss,se);
//     if(ss<=l && se>=l)
//         return max(getMaxST(st,ss,mid,l,r,2*n+1),getMaxST(st,mid+1,se,l,r,2*n+2));
// }

ll sumpr(ll n)
{
    ll x = n;
    ll ans = 0;
    for(int i = 0; i<= primes.size() && primes[i] <= sqrt(x); i++)
    {
        while(x%primes[i]==0)
        {
            x = x/primes[i];
            ans += primes[i];
        }
    }
    if(x>1)
        ans += x;
    return ans;
}

// int constructST(int st[], int ss, int se, int si)
// {
//     // cout<<ss<<" "<<se<<" "<<si<<endl;
//     if(ss == se)
//     {
//         st[si] = lopf[ss];
//         return lopf[ss];
//     }

//     int mid = getMid(ss,se);
//     st[si] = max(constructST(st, ss, mid, si*2 + 1),constructST(st, mid+1, se, si*2 + 2));
//     return st[si];
// }

// int getMax(int st[], int l, int r)
// {
//     return getMaxST(st,0,maxN-1,l,r,0);
// }

void call()
{
    lopf.pb(1); // 0
    lopf.pb(1); // 1
    lopf.pb(1); // 2
    loop(i,3,maxN)
    {
        ll c = sumpr(i);
        if(c==i)
            lopf.pb(1);
        else
            lopf.pb(1+lopf[c]);
    }
}
 
int main()
{
    sieve();
    call();

    // int x = (int)(ceil(log2(maxN)));
    // int max_size = 2 * (int)pow(2, x) - 1;
    // int segTree[max_size];
    // constructST(segTree,0,maxN-1,0);


    int t;
    cin>>t;
    ll m,n;
    loop(i,1,t+1)
    {
        cin>>m>>n;
        if(m>n)
            swap(m,n);
        ll ax = lopf[m];
        loop(x,m,n+1)
            ax = max(ax,lopf[x]);
        cout<<"Case #"<<i<<":\n"<<ax<<endl;
    }

    // int x;
    // while(cin>>x)
    //     cout<<sumpr(x)<<endl;

    // for(int i : lopf)
    //     cout<<i<<" ";
    // cout<<endl;
    // for(int i : segTree)
    //     cout<<i<<" ";
    // cout<<endl;
    // int l,r;
    // while(cin>>l>>r)
    //     cout<<getMax(segTree,l,r)<<endl;
}