#include <iostream>
#include <bits/stdc++.h>

#define ll long long int
using namespace std;

void solution(){
 
	ll t;
	cin>>t;
	ll n;
	vector<ll> ans(t,0);
	
	ll mx = -1;
	for(int i = 0; i < t; i++)	
	{
		cin>>ans[i];
		mx = max(ans[i],mx);
	}
 
	
	vector<pair<ll,ll>>dp(mx+1,{0LL,0LL});
 
 
	dp[0] = {1LL,0LL};dp[1] = {1LL,1LL};
 
	for(int i =2; i <= mx; i++){
		dp[i].second = ((4*dp[i-1].second)%1000000007LL + dp[i-1].first)%1000000007LL;
		dp[i].first = (dp[i-1].second + (2*dp[i-1].first)%1000000007)%1000000007LL;
	}
 
	for(auto n:ans)
	cout<<(dp[n].first + dp[n].second)%(1000000007LL)<<endl;
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