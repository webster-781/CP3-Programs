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
const ll maxN = 100;
int arr[8] = {9,8,7,6,5,4,3,2};

pair<vi,int> divide(vi n, int d)
{
    vi q;
    int rem = 0;
    int i = 0;
    while(i<n.size())
    {
        rem = rem*10 + n[i];
        q.pb(rem/d);
        rem = rem%d;
        i++;
    }
    if(q[0]==0)
        q.erase(q.begin());
    return make_pair(q,rem);
}

void solve(vi n)
{
    // cout<<n.size()<<endl;
    if(n.size()==1)
    {
        cout<<1<<n[0]<<endl;
        return;
    }
    vi temp = n;
    map<int,int> m;
    int totcnt = 0;
    for(int i : arr)
    {
        auto div = divide(temp,i);
        int cnt = 0;
        while(div.second == 0)
        {
            temp = div.first;
            div = divide(temp,i);
            cnt++;
        }
        m[i] = cnt;
        // cout<<i<<" "<<cnt<<endl;
        // for(int i: temp)
        //     cout<<i;
        //     cout<<endl;
        totcnt += cnt;
    }
    if(temp.size()>1)   // if another prime greater than 10 divides n
    {
        cout<<"There is no such number.\n";
        return;
    }
    else
    {
        loop(i,2,10)
            loop(_,0,m[i])
                cout<<i;
        cout<<endl;
    }
}

int main()
{
    vi x;
    string s;
    while(cin>>s)
    {
        if(s == "-1")
            break;
        for(char c: s)
            x.pb((int)(c-48));
        solve(x);
        x.clear();
    }
}