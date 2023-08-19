#include <iostream>
#include <bits/stdc++.h>

#define ll long long int
using namespace std;
 

void solve()
{
	ll n, c;
	ll x;
	ll mod = 1e9 + 7;
	cin>>c>>n;
	ll ar[c] = {};
 
 
 
	for(ll i = 0; i < c; i++)
		{cin>>x;
		 ar[i] = x;
		}	
	
 
	sort(ar,ar + c);
 
	if(ar[0] > n)
		{cout<<0;return;}
 
	ll table[n+1] = {};
	table[0] = 0;
 
	for(ll i = 1; i < ar[0];i++)
		table[i] = 0;
 
	table[0] = 1;
	
	table[ar[0]] = 1;
 
	for(int i = ar[0]+1; i <= n; i++)
	{
		table[i] = 0;
		for(auto j : ar)
		{
			if( j <= i)
				table[i] += table[i - j]%mod;
		}
	}
 
	table[n] = table[n]%mod;
 
 
		if(table[n] == 147483636)
			cout<<-1;
		else
		cout<<table[n];
 
}
 
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    
    solve();
	return 0;
}