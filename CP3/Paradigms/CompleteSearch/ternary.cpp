// Sample code to perform I/O:
#include <bits/stdc++.h>
using namespace std;
double t,b[3],bv[3],m[3],mv[3];
const double eps = 1e-6;

int findmin(double arr[4])
{
	int minin = 0;
	for(int i = 0; i<4;i++)
		if(arr[i]<arr[minin])
			minin = i;
	return minin;
}

double dist(double time)
{
	double sum = 0;
	for(int i=0;i<3;i++)
	{
		sum += pow(b[i] - m[i] + time*(bv[i] - mv[i]),2);
	}
	return sqrt(sum);
}

int main(){
	cin>>t;
	for(int i=0;i<3;i++)
		cin>>b[i];
	for(int i=0;i<3;i++)
		cin>>bv[i];
	for(int i=0;i<3;i++)
		cin>>m[i];
	for(int i=0;i<3;i++)
		cin>>mv[i];
	cout.precision(16);

    int iter = 1;
	double left = 0, right = t;
	while(abs(left - right)>eps)
	{
		double m1 = (2*left + right)/3;
		double m2 = (left + 2*right)/3;
		double d[4] = {dist(left),dist(m1),dist(m2),dist(right)};
		double times[4] = {left,m1,m2,right};
		
// 		cout<<"Iter: "<<iter++<<endl;
// 		for(int i = 0;i < 4;i++)
// 		{
// 		    cout<<times[i]<<" "<<dist(times[i])<<endl;
// 		}
		
		int mi1 = findmin(d);
		d[mi1] = 1e10;
		int mi2 = findmin(d);
		d[mi2] = 1e10;
		int mi3 = findmin(d);
		
// 		cout<<mi1<<" "<<mi2<<" "<<mi3<<endl;

		if(mi1 == 0)
		{
		   right = m1;
		   continue;
		}
		if(mi1 == 3)
		{
		    left = m2;
		    continue;
		}
		if(mi1>mi2)
			swap(mi1,mi2);
		
		
		left = times[mi1];
		right = times[mi2];
	}
	cout<<dist(left)<<endl;
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

// Write your code here
