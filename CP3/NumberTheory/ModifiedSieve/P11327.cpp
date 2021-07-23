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
const ll maxN = 2e5;

vl msep(maxN+1,1);
vl sumep(maxN+1,1);

ll gcd(ll a, ll b)
{
    return (b==0)?a:gcd(b,a%b);
}

void modifiedSieve()
{
    lloop(i,2,maxN+1)
        msep[i] = i;

    msep[1] = 2;
    sumep[0] = 0;
    sumep[1] = 2;
    lloop(i,2,maxN+1)
    {
        if(msep[i]==i)  // i is prime
            for(ll j = i; j<=maxN; j+=i)
                msep[j] -= msep[j]/i;
        sumep[i] = sumep[i-1] + msep[i];
    }
}

int main()
{
    modifiedSieve();
    ll num;
    while(cin>>num)
    {
        if(num==0)
            break;
        if(num==1)
            cout<<"0/1\n";
        else if(num==2)
            cout<<"1/1\n";
        else
        {
            int ind = lower_bound(sumep.begin(),sumep.end(),num) - sumep.begin();
            int f = num - sumep[ind-1];
            int cnt = 0;
            lloop(j,1,ind)
            {
                if(gcd(ind,j) == 1)
                    cnt++;
                if(cnt == f)
                {
                    cout<<j<<"/"<<ind<<endl;
                    break;
                }
            }
        }
    }
}