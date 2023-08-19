#include <iostream>
#include <bits/stdc++.h>

#define ll long long int
using namespace std;
 

void solve()
{
	ll n, c;
	ll x;
	ll mod = 1e9 + 7LL;
	cin>>c>>n;
	ll ar[c] = {};
 
	for(ll i = 0; i < c; i++)
		{cin>>x;
		 ar[i] = x;
		}	
	
 
	sort(ar,ar + c);
 
	if(ar[0] > n)
		{cout<<-1;return;}
	ll table[n+1] = {};
	table[0] = 0;
 
	for(ll i = 1; i < ar[0];i++)
		table[i] = INT_MAX;
 
	
	table[ar[0]] = 1;
 
	for(ll i = table[0]+1; i <= n; i++)
		{	
			table[i] = 0;
			ll min = INT_MAX;
			for(ll j = 0; j < c; j++)
				{
					if(i - (ar[j]) >= 0 )
						{if( min > table[i - ar[j]])
							min = table[i - ar[j]];}
						else break;
 
				}
				table[i] = (min)%mod +1;
				table[i] = table[i]%mod;
		}
 
 
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