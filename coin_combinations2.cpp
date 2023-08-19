#include <iostream>
#include <bits/stdc++.h>

#define ll long long int
using namespace std;
 

void solution()
{
 		
 		ll n,c;
 		cin>>n>>c;
 
 		vector<ll> ar(n);
 		ll i,j;
 		for(i = 0; i < n; i++)
 			cin>>ar[i];
 		
 
		ll start = ar[0];
 		vector<ll>dp(c+1,0LL);
 
 			dp[0] = 1LL;
 
 		for(i =1;i <= n; i++){
 		for(j = 0; j <= c; j++)	
 		{	
 			dp[j] = (((j>=ar[i-1])?dp[j-ar[i-1]]:0LL) + dp[j])%1000000007LL;
 			
 		}
 
 	}
 		cout<<dp[c]<<endl;
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
