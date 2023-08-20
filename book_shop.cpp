#include <iostream>
#include <bits/stdc++.h>

#define ll long long int
using namespace std;

void solution(){
 
	ll n,x;
	cin>>n>>x;
	ll sum_p = 0;
	vector<ll> price(n);
	for(int i = 0; i < n; i++)
	{
		cin>>price[i];
	} 
 
	vector<ll> pages(n);
	
	for(int i = 0; i < n; i++)
	{
		cin>>pages[i];
	}
	vector<ll> dp(x+1,0LL);
	vector<ll> dp_new(x+1,0LL);
	for(int j = 0; j < n; j++){

	for(int i = 1;i < dp.size(); i++)
	{
		if(i-price[j]>=0 && pages[j] + dp[i - price[j]] > dp[i])
		{
			dp_new[i] = pages[j] + dp[i - price[j]];
		}
		else {
			dp_new[i] = dp[i];
		}
	}
			for(int i =0; i < dp_new.size(); i++){
			dp[i] = dp_new[i];
			
		}
}
	cout<<dp[x];
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
