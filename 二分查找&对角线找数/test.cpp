#include <cstdio>
using namespace std ;

const int length = 10000 ;
const int COL = 5 ;
const int ROW = 5 ;
int a[length] ;

int solve(int a[],int left,int right,int key)
{
	if(left > right)
        return -1 ;
	int middle = left+((right-left)/2) ;
	if(a[middle] == key)
	{
		return middle ;
	}
	else if(a[middle] > key)
	{
		return solve(a,left,middle-1,key) ;
	}
	else return solve(a,middle+1,right,key) ;
}


bool youngSolve()
{
	int key = 61 ;
	int a[ROW][COL] = {{1,2,3,4,5},
	{2,3,4,5,6},
	{3,4,5,6,7},
	{4,5,6,7,8},
	{5,6,7,8,9}
    } ;
	int i = 0 ;
	int j = COL-1 ;
	int var = a[i][j] ;
	while(true)
	{
		if(key == var)
			return true ;
		else if(key>var && i<ROW-1)
			var = a[++i][j] ;
		else if(key < var && j>0)
			var = a[i][--j] ;
		else return false ;
	}
}

int main()
{

	for(int i=0 ;i<length ;i++)
    {
        a[i] = i ;
    }
   if(youngSolve())
   {
   	printf("查找成功");
   }
   else printf("查找失败") ;
}
