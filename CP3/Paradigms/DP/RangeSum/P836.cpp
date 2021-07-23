//MAKER CODE

#include<bits/stdc++.h>
#define loop(x,i,n) for(int x = i; x < n; ++ x)
#define looprev(x,i,n) for(int x = i;x>=n;x--)
#define lloop(x,i,n) for(ll x = i; x < n; ++ x)
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef unsigned long long LLU;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair <int,int> pii;
typedef map<int,int> mi;
typedef pair<long,long> pll;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {

        string s[25];
        cin>>s[0];
        int n = s[0].length();
        loop(i,1,n)
            cin>>s[i];
        
        int A[n][n];        //  A[i][j] represents smallest index k s.t. s[k..i][j] = 1
                            //  and i+1 if s[i][j] = 0
        bool is1 = false;
        loop(j,0,n)
        {
            int last1 = -1;
            loop(i,0,n)
            {
                if(s[i][j] == '1')
                    is1 = true;
                if(s[i][j] == '0')
                {
                    A[i][j] = i+1;
                    last1 = -1;
                }
                else if(last1 == -1)
                {
                    A[i][j] = i;
                    last1 = i;
                }
                else
                    A[i][j] = last1;
                
            }
        }
        // loop(i,0,n)
        // {
        //     loop(j,0,n)
        //         cout<<A[i][j]<<" ";
        //     cout<<endl;
        // }
        if(!is1)
        {
            cout<<0<<endl;
            if(t>0)
                cout<<endl;
            continue;
        }
        ll mxA = 0;
        loop(i1,0,n)
            loop(i2,i1,n)
            {
                ll Ar = 0LL;
                loop(j,0,n)
                {
                    if(A[i2][j] <= i1)
                        Ar += (i2-i1+1);
                    else
                        Ar = 0;
                    mxA = max(mxA,Ar);
                }
            }
        cout<<mxA<<endl;
        if(t>0)
            cout<<endl;
    }
}