#include <iostream>
using namespace std ;


int solve(int *a,int length) {
	int nTimes = 1 ;
	int tmp = a[0] ;
	for(int i = 1 ;i<length;i++)
	{
		if(nTimes == 0)
		{
			nTimes = 1 ;
			tmp = a[i] ;
		}
		else {
			if(tmp == a[i])
				nTimes++ ;
			else nTimes-- ;
		}
	}
	return tmp ;
}

int main() {
	int a = {1,2,1,1,2,3,1} ;
	cout<<“超过一半的数字是”<<solve(a,sizeof(a)/sizeof(int)) ;
	return 0 ;
}