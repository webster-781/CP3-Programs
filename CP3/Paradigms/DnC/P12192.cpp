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
    int m,n;
    while(cin>>m>>n && m>0)
    {
        int A[m][n];
        loop(i,0,m)
            loop(j,0,n)
                cin>>A[i][j];
        int q;
        cin>>q;
        while(q--)
        {
            int L,U;
            cin>>L>>U;
            int bSize = 0;
            auto it1 = *A;
            auto it2 = *A;
            loop(_,0,n)
                it2++;
            loop(i,0,m)
            {
                int f = distance(it1,lower_bound(it1,it2,L));
                // cout<<i<<f<<":\n";
                loop(j,bSize,min(m-i,n-f))
                {
                    if(A[i+j][f+j] <= U)
                        bSize = j+1;
                    else
                        break;
                    // cout<<(i+j)<<(j+f)<<endl;
                }
                // cout<<bSize<<endl;
                loop(_,0,n)
                it1++;
                loop(_,0,n)
                it2++;
            }
            cout<<bSize<<endl;
        }
        cout<<"-\n";
    }
}