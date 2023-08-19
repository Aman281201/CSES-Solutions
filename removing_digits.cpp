#include <iostream>
#include <bits/stdc++.h>

#define ll long long int
using namespace std;


void solution()
{		
 	ll n;
 	cin>>n;
 	ll c = 0;
 	ll num = n;
 	while(num>0){
 
 		ll max_dig = -1;
 		ll num2 = num;
 		while(num2>0){
 			max_dig = max(max_dig,num2%10);
 			num2 = num2/10;
 		}
 		num -= max_dig;
 		c++;
	}
	cout<<c<<endl;
}
 
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt","w", stdout);
	#endif

		solution();
	return 0;
}