#include <iostream>

using namespace std;

int maxSum(int* a, int n)
{
	int sum=0;
	int b=0;
	int i;

	for(i=0; i<n; i++)
	{
		if(b<=0) //此处修正下，把b<0改为b<=0
			b=a[i];
		else
			b+=a[i];
		if(sum<b)
			sum=b;
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	int a[10] = {1,-8,6,3,-1,5,7,-2,0,1};
	
	cout<<maxSum(a,10)<<endl;
	
	return 0;
}
