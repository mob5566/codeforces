/**
 * Tittle:	C. Alice, Bob and Chocolate
 * Author:	Cheng-Shih, Wong
 * Date:	2016/07/19
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

// declarations
int n;
int cho[100005];
int acc[100005];

// functions
void input()
{
	scanf( "%d", &n );
	FOR( i, 1, n ) scanf( "%d", &cho[i] );
}

void solve()
{
	acc[1] = cho[1];
	FOR( i, 2, n )
		acc[i] = cho[i]+acc[i-1];

	int halfCho = acc[n]>>1;
	int idx;

	for( idx=1; idx<=n && acc[idx]<=halfCho; ++idx );

	if( acc[idx-1]>acc[n]-acc[idx] ) --idx;

	printf( "%d %d\n", idx, n-idx );
}

// main function
int main( void )
{
	input();
	solve();
	
	return 0;
}
