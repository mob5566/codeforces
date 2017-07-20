/**
 * Tittle:	D. Soldier and Number Game
 * Author:	Cheng-Shih, Wong
 * Date:	2016/04/17
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
#define N 5000001

typedef vector<int> VI;
typedef long long LL;

// declarations
int t, a, b;
bool isp[N];
int d[N];
int acc[N];

// functions


// main function
int main( void )
{
	
	// init
	clr( isp, true );

	FOR( i, 2, N-1 ) if( isp[i] ) {
		for( LL j = (LL)i*i; j<N; j+=i ) isp[j] = false, d[j] = i;
	}
	
	clr( acc, 0 );

	int val;
	FOR( i, 2, N-1 ) {
		if( isp[i] ) acc[i] = 1;
		else acc[i] = acc[i/d[i]]+1;
	}

	FOR( i, 2, N-1 )
		acc[i] += acc[i-1];

	// solve
	scanf( "%d", &t );

	while( t-- ) {
		scanf( "%d%d", &a, &b );
		printf( "%d\n", acc[a]-acc[b] );
	}

	
	return 0;
}
