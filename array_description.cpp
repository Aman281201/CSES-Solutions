#include <iostream>
#include <bits/stdc++.h>

#define ll long long int
using namespace std;

void solution(){
 
	ll n,m;
	cin>>n>>m;
 
	vector<ll> ar(n);
	for(int i = 0; i < n; i++)
	{
		cin>>ar[i];
	} 
 
	vector<vector<ll>> dp(m+2, vector<ll>(n+1,0));
 
	if(ar[0]==0)
		for(int i = 1; i <= m; i++)
			dp[i][0] = 1;
	else dp[ar[0]][0] = 1;
 
	for(int i= 1; i < n; i++){
		if(ar[i]==0){
			for(int j = 1; j <= m; j++){
				dp[j-1][i] =(dp[j-1][i] + dp[j][i-1] )%1000000007LL;
				dp[j][i] = (dp[j][i] + dp[j][i-1] )%1000000007LL;
				dp[j+1][i] =(dp[j+1][i] + dp[j][i-1] )%1000000007LL;
			}
		}
		else{
			dp[ar[i]][i] += (dp[ar[i]][i-1] + ((ar[i]+1 <= m)?dp[ar[i]+1][i-1]:0) + ((ar[i]-1 >= 1)?dp[ar[i]-1][i-1]:0) )%1000000007LL;
		}
	}
	ll ans=0;
	for(int i = 1; i <= m; i++)
		ans += dp[i][n-1];
 
	cout<<ans%1000000007LL<<endl;

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