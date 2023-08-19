#include <iostream>
#include <bits/stdc++.h>

#define ll long long int
using namespace std;
 
void solve()
{
	ll n;
	cin>>n;
	ll div = 1e9 + 7;
	ll ar[n] = {};
	ar[0] = 0;
	ar[1] = 1;
	ar[2] = 2;
	for(ll i = 3; i <=n; i++)
	{
		ar[i] = 0;
		if(i <= 6)
		{  
			for(ll j = 0; j < i; j++)
			ar[i] += ar[j];
 
			ar[i]++;
		}
		else{
			ar[i] = ar[i-1]%(div) + ar[i-2]%(div) + ar[i-3]%div + ar[i-4]%div + ar[i-5]%div + ar[i-6]%div;
			ar[i] = ar[i]%div;
		}
	}
	ll ans = ar[n]%div;
	cout<<ans;
}
 
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
 
    solve();
 
	return 0;
}