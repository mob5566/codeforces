/**
 * Tittle:	D. Palindrome Degree
 * Author:	Cheng-Shih, Wong
 * Date:	2016/08/22
 */

// include files
#include <bits/stdc++.h>

using namespace std;

// definitions
#define FOR(i,a,b) for( int i=(a),_n=(b); i<=_n; ++i )
#define clr(x,v) memset( x, v, sizeof(x) )
#define F first
#define S second
#define PB push_back

typedef long long LL;

// declarations
char s[5000005];
LL ans;
const LL MOD = 1e9+7;
int dp[5000005];

// functions
void input()
{
	scanf( "%s", s );
}

void solve()
{
	LL p, q;
	LL hash = 1LL;
	int sl = strlen(s);
	p = q = s[0];
	clr( dp, 0 );
	dp[0] = 1;
	ans = 1LL;

	FOR( i, 1, sl-1 ) {
		p = (p*131+s[i])%MOD;
		hash = (hash*131)%MOD;
		q = (s[i]*hash+q)%MOD;

		if( p==q ) {
			dp[i] = dp[((i-1)>>1)]+1;
			ans += dp[i];
		}
	}

	cout << ans << endl;
}

// main function
int main( void )
{
	input();
	solve();
	
	return 0;
}
