//MAKER CODE

#include<bits/stdc++.h>
#define loop(x,i,n) for(int x = i; x < n; ++ x)
#define looprev(x,i,n) for(int x = i;x>=n;x--)
#define lloop(x,i,n) for(ll x = i; x < n; ++ x)
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair <int,int> pii;
typedef map<int,int> mi;
vector<string> out;

bool stop(vi parse)
{
    int tx = -1;
    int tp  = 0;
    loop(i,0,4)
    {
        int j = (i+1)*13;
        int cntsuit = 0;
        while((tx+1<parse.size()) && parse[tx+1]<j)
        {
            tx++;
            tp += max(parse[tx] - i*13 - 8,0); // add 4,3,2,1 for A,K,Q,J respectively
            cntsuit++;
        }
        int highest = (tx>=0 && parse[tx]>=i*13)?(parse[tx]-i*13):-1;
        bool sub = (cntsuit + highest >= 13); // if A, or K and atleast one more, or Q and atleast 2 more
        if((highest >= 9) && !sub) // has >= J and sub is not satisfied.
            tp --;
        int shighest = (tx>=1 && parse[tx-1]>=i*13)?(parse[tx-1]-i*13):-1;
        if(shighest>=9)
        {
            bool sub1 =  (cntsuit + shighest >= 13);
            if(!sub1)
                tp --;
        }

        int thighest = (tx>=2 && parse[tx-2]>=i*13)?(parse[tx-2]-i*13):-1;
        if(thighest >= 9)
        {
            bool sub2 = (cntsuit + thighest >= 13);
            if(!sub2)
                tp --;
        }
        int fhighest = (tx>=3 && parse[tx-3]>=i*13)?(parse[tx-3]-i*13):-1;
        if(fhighest == 9 && cntsuit + fhighest < 13)
            tp--;
        if(highest + cntsuit < 13)
            return false;
    }
    // cout<<"STOP "<<tp<<endl;
    if(tp>=16)
        return true;
    else
        return false;
}
pii points(vi parse)
{
    int tp = 0;
    int mxcnt = 0, m = 0;
    int arr[4] = {3,2,0,1};
    for(int i: arr)
    {
        int j = (i+1)*13;
        int cntsuit = 0;
        int tx = -1;
        while((tx+1<parse.size()) && parse[tx+1]<j)
        {
            tx++;
            if(parse[tx] >= i*13)
            {
                tp += max(parse[tx] - i*13 - 8,0); // add 4,3,2,1 for A,K,Q,J respectively
                cntsuit++;
            }
        }
        int highest = (tx>=0 && parse[tx]>=i*13)?(parse[tx]-i*13):-1;
        bool sub = (cntsuit + highest >= 13); // if A, or K and atleast one more, or Q and atleast 2 more
        if((highest >= 9) && !sub) // has >= J and sub is not satisfied.
            tp --;
        int shighest = (tx>=1 && parse[tx-1]>=i*13)?(parse[tx-1]-i*13):-1;
        if(shighest>=9)
        {
            bool sub1 =  (cntsuit + shighest >= 13);
            if(!sub1)
                tp --;
        }

        int thighest = (tx>=2 && parse[tx-2]>=i*13)?(parse[tx-2]-i*13):-1;
        if(thighest >= 9)
        {
            bool sub2 = (cntsuit + thighest >= 13);
            if(!sub2)
                tp --;
        }
        int fhighest = (tx>=3 && parse[tx-3]>=i*13)?(parse[tx-3]-i*13):-1;
        if(fhighest == 9 && cntsuit + fhighest < 13)
            tp--;
        switch(cntsuit)
        {
            case 1:
                tp += 2;
                break;
            case 2:
                tp ++;
                break;
            case 0:
                tp += 2;
                break;
        }
        if(cntsuit > mxcnt)
        {
            m = i;
            mxcnt = cntsuit;
        }
    }
    return pii(tp,m);
}

void solve(char s[60])
{
    vi parse;
    for(int i=0; s[i] > 1; i+=3)
    {
        int x = 0, y =0;
        switch(s[i+1]){
            case 'D':
                x = 0;
                break;
            case 'C':
                x = 1;
                break;
            case 'H':
                x = 2;
                break;
            case 'S':
                x = 3;
                break;
        }
        switch(s[i])
        {
            case 'A':
                y = 12;
                break;
            case 'K':
                y = 11;
                break;
            case 'Q':
                y = 10;
                break;
            case 'J':
                y = 9;
                break;
            case 'T':
                y = 8;
                break;
            default:
                y = (int)s[i] - 50;
                break;
        }
        parse.push_back(x*13 + y);
    }
    sort(parse.begin(),parse.end());
    pii p = points(parse);
    // cout<<p.first<<" "<<p.second<<endl;
    if(p.first<14)
        out.push_back("PASS");
    else if(stop(parse))
        out.push_back("BID NO-TRUMP");
    else
    {
        switch(p.second)
        {
            case 0:
            out.push_back("BID D");
            break;
            case 1:
            out.push_back("BID C");
            break;
            case 2:
            out.push_back("BID H");
            break;
            case 3:
            out.push_back("BID S");
            break;
        }
    }

}

int main()
{
    char s[60];
    while(gets(s) && s[0]>1)
        solve(s);
}