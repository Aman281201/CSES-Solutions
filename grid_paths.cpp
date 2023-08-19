#include <iostream>
#include <bits/stdc++.h>

#define ll long long int
using namespace std;

void solution()
{
    char ch;
    ll n;
    cin>>n;
    vector<vector<ll>> table(n,vector<ll>(n,-1));
    

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            cin>>ch;
            if(ch=='*')
            table[i][j] = 0;
        }

    bool h = true,v = true;
    for(int i=0; i < n; i++)
    {

        if(table[0][i]==0)
            h = false;
        if(table[i][0]==0)
            v = false;
        
        table[0][i] = ((h)? 1:0);
        table[i][0] = ((v)? 1:0);
    }


    for(int i = 1; i < n; i++)
        for(int j = 1; j < n; j++)
        {
            if(table[i][j]!= 0)
                table[i][j] = (table[i-1][j] + table[i][j-1])%(1000000007LL);
        }

    cout<<table[n-1][n-1]<<endl;		
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