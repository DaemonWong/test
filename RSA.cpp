#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std ;


int rsa(int a,int b,int c) {
	int r = 1 ;
	b = b+1 ;
	while(b != 1) {
		r = r*a ;
		r = r%c ;
		b-- ;
	}
	return r ;
}




int main() {
	cout<< "请输入基础数字p,q" ;
	int p,q ;
	cin>>p>>q ;
	int n = p*q ;       //n
	int t = (p-1)*(q-1) ;   //t
	cout<<"p*q="<<n<<endl ;
	cout<<"(p-1)*(q-1)="<<t<<endl;
	cout<<"请输入e"<<endl ;
	int e ;
	cin>>e ;
	if(e < 1 || e>=t)
	{
		cout<<"e的范围输入错误"<<endl ;
		//continue ;
	}
	int d = 1 ;
	while((e*d)%t != 1) {
		d++ ;
	}
	cout<<"算出来的d的数值是"<<d<<endl ;
	cout<<"加密输入数字1，解密输入数字2"<<endl ;
	int choice ;
	cin>>choice ;
	if(choice == 1)
	{
		int m ;
		cout<<"请输入要加密的数字m" ;
		cin>>m ;
		int res = rsa(m,e,n) ;
		cout<<"加密后的数字是:"<<res<<endl ;
	}
	else if(choice == 2)
	{
		int c ;
		cout<<"请输入要解密的数字c"<<endl ;
		cin>>c ;
		int res = rsa(c,d,n) ;  
		cout<<"解密后的数字是:"<<res<<endl ;
	}
	return 0 ;


}