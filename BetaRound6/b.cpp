/**
 * Tittle:	B. Presidnet's Office
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
int n, m;
char targetColor[2];
char room[105][105];
bool vis[30];
int cnt;

// functions
void check( char color )
{
	if( !isalpha(color) ) return;
	if( vis[color-'A'] ) return;

	vis[color-'A'] = true;
	++cnt;
}

// main function
int main( void )
{

	scanf( "%d%d%s", &n, &m, targetColor );
	FOR( i, 1, n ) scanf( "%s", room[i]+1 );

	cnt = 0;
	clr( vis, false );
	vis[targetColor[0]-'A'] = true;

	FOR( i, 1, n ) {
		FOR( j, 1, m ) {
			if( room[i][j]==targetColor[0] ) {
				check( room[i-1][j] );
				check( room[i+1][j] );
				check( room[i][j-1] );
				check( room[i][j+1] );
			}
		}
	}

	cout << cnt << endl;
	
	return 0;
}
