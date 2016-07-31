#include <cstdio>
using namespace std ;

int fun(int n, int a[]) {
	int b = a[0] ;
	int maxN = 0 ;
	for(int i = 1 ;i<n ;i++)
	{
		if(b >= 0)
		{
			b+=a[i] ;
		}
		else b = a[i] ;
		if(b > maxN)
		{
			maxN = b ;
		}
	}
	return maxN ;
}

int main()
{
	int a[] = {1,2,3,-2,1} ;
	printf("%d\n",fun(5,a)) ;
	return 0 ;
}