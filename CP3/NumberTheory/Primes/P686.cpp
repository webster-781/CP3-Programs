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

vl primes;
vector<bool> isPrime;
map<long,long>m;
long maxN = 1e7;

long power10(long n,long val)
{
    if(n==0)
        return val;
    else{
        return power10(n/10,val*10);
    }
}

bool check(int c1, int c3, int c7, int c9, int tot, long val)
{
    if(tot == 0)
    {
        // if(isPrime[val])
        //     cout<<val<<" is Prime"<<endl;
        // else
        //     cout<<val<<" is not Prime"<<endl;
        return isPrime[val];
    }
    else
    {
        int i = 1;
        int arr[4] = {c1,c3,c7,c9};
        for(int c: arr)
        {
            if(c>0)
            {
                bool x;
                if(i==1)
                    x = check(c1-1,c3,c7,c9,tot-1,val*10 + 1);
                if(i==3)
                    x = check(c1,c3-1,c7,c9,tot-1,val*10 + 3);
                if(i==7)
                    x = check(c1,c3,c7-1,c9,tot-1,val*10 + 7);
                if(i==9)
                    x = check(c1,c3,c7,c9-1,tot-1,val*10 + 9);
                if(x == false)
                    return false;
            }
            if(i!=3)
                i+=2;
            else 
                i+=4;
        }
    }
    return true;
}
bool permuteCheck(long n)
{
    int c1 = 0, c3 = 0,c7 = 0,c9 = 0;
    long x= n;
    int tot = 0;
    while(x>0)
    {   
        int dig = x%10;
        if(dig%2==0 || dig==5)
            return false;
        if(dig==1)
            c1++;
        if(dig==3)
            c3++;
        if(dig==7)
            c7++;
        if(dig==9)
            c9++;
        x = x/10;
        tot ++;
    }
    bool o = check(c1,c3,c7,c9,tot,0);
    // if(!o)
    //     cout<<n<<"is not anagrammic"<<endl;
    // else
    //     cout<<n<<"is anagrammic"<<endl;
    return o;
}

pair<vector<bool>,vl> sieve()
{
    vector<bool> isp(maxN,true);
    vl ans;
    int x = 0;
    for(long i=2; i<maxN; i++)
    {
        if(isp[i])
        {
            for(long j = i*i; j< maxN; j+=i)
                isp[j] =false;
            ans.pb(i);
            m[i] = x;
            x++;
        }
    }
    return make_pair(isp,ans);
}
void solve(long n)
{
    long t = n+1;
    long p10 = power10(n,1);
    if(p10 == 10)
    {
        if(n<2)
            cout<<2<<endl;
        else if(n<3)
            cout<<3<<endl;
        else if(n<5)
            cout<<5<<endl;
        else if(n<7)
            cout<<7<<endl;
        else
            cout<<0<<endl;
        return;
    }
    while(!isPrime[t])
        t++;
    if(!isPrime[t])
        cout<<0<<endl;
    else
    {
        int i = m[t];
        while(primes[i]<p10)
        {
            if(permuteCheck(primes[i]))
            {
                cout<<primes[i]<<endl;
                return;
            }
            i++;
        }
        cout<<0<<endl;
    }
}

int main()
{
    auto x = sieve();
    primes = x.second;
    isPrime = x.first;
    long n;
    while((cin>>n))
    {
        if(n==0)
            break;
        solve(n); 
    }
    // cout<<permuteCheck(173)<<endl;
}