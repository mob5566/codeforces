/**
 * Tittle:	D. Mysterious Present
 * Author:	Cheng-Shih, Wong
 * Date:	2016/07/04
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

typedef pair<int,int> PII;
typedef pair<PII,int> PIII;

// declarations
int n, w, h;
PIII env[5005];
int dp[5005];
int pre[5005];

// functions
void input()
{
	cin >> n >> w >> h;
	FOR( i, 1, n ) {
		cin >> env[i].F.F >> env[i].F.S;
		env[i].S = i;
	}
	sort( env+1, env+n+1 );
}

inline bool strickGreater( const PII &a, const PII &b )
{
	return (a.F<b.F && a.S<b.S);
}

void solve()
{
	clr( dp, 0 );
	clr( pre, 0 );
	int start = 1;
	PII card = make_pair(w,h);
	
	while( start<=n && !strickGreater(card, env[start].F) )
		++start;
	
	if( start>n ) puts("0");
	else {
		--start;
		env[start].F = card;

		for( int i=n; i>=start; --i ) {
			for( int j=i+1; j<=n; ++j ) {
				if( strickGreater(env[i].F, env[j].F) && dp[i]<dp[j]+1 ) {
					dp[i] = dp[j]+1;
					pre[i] = j;
				}
			}
		}

		printf( "%d\n", dp[start] );
		bool space = false;
		for( int cur=pre[start]; cur; cur=pre[cur] ) {
			if( space ) putchar(' ');
			else space = true;
			printf( "%d", env[cur].S );
		}
		putchar('\n');
	}
}

// main function
int main( void )
{
	
	input();
	solve();
	
	return 0;
}
