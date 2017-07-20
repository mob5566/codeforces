/**
 * Tittle:	A. Kalevitch and Chess
 * Author:	Cheng-Shih, Wong
 * Date:	2016/08/14
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
char bd[10][10];

// functions
void input()
{
	FOR( i, 1, 8 )
		scanf( "%s", bd[i]+1 );
}

bool allB( int l )
{
	if( 1<=l && l<=8 ) {
		FOR( i, 1, 8 )
			if( bd[l][i]=='W' ) return false;
		return true;
	} else if( 8<l && l<=16 ) {
		l-=8;
		FOR( i, 1, 8 )
			if( bd[i][l]=='W' ) return false;
		return true;
	}

	return false;
}

void solve()
{
	bool hasW = false;
	
	FOR( i, 1, 8 ) {
		FOR( j, 1, 8 ) {
			if( bd[i][j]=='W' ) {
				hasW = true;
				break;
			}
		}

		if( hasW ) break;
	}

	if( !hasW ) puts("8");
	else {
		int cnt = 0;

		FOR( i, 1, 16 )
			if( allB(i) ) ++cnt;

		printf( "%d\n", cnt );
	}
}

// main function
int main( void )
{
	input();
	solve();
	
	return 0;
}
