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

void solve(int n)
{
    vi arr(61,0);
    arr[0] = 1;
    for(int i = 1; i<=20; i++)
    {
        arr[i] = 1;
        arr[2*i] = 1;
        arr[3*i] = 1;
    }
    arr[50] = 1;
    ll p=0, c=0;
    loop(i,0,n+1)
    {
        loop(j,i,n+1-i)
        {
            int k = n-i-j;
            if(k>=j)
            {
                if(arr[i]*arr[j]*arr[k] == 1)
                {
                    if(i==j && j==k)
                        p++;
                    else if(i==j || j==k)
                        p+=3;
                    else
                        p+=6;
                    c++;
                }
            }
        }
    }
    if(c==0)
    {
        printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n",n);
        printf("**********************************************************************\n");
        return;
    }
    printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %lld.\n",n,c);
    printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %lld.\n",n,p);
    printf("**********************************************************************\n");
}

int main()
{
    int n;
    while(cin>>n)
    {
        if(n<=0)
            break;
        solve(n);   
    }
    printf("END OF OUTPUT\n");
}