/**
 * Tittle:	A. Shortest path of the king
 * Author:	Cheng-Shih, Wong
 * Date:	2016/06/29
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
char s[5], t[5];

// functions
void input()
{
	cin >> s >> t;
}

void solve()
{
	int dx = t[0]-s[0];
	int dy = t[1]-s[1];
	int len = max(abs(dx), abs(dy));

	printf( "%d\n", len );

	while( dx!=0 || dy!=0 ) {
		if( dx < 0 ) putchar('L'), ++dx;
		else if( dx > 0 ) putchar('R'), --dx;
		if( dy < 0 ) putchar('D'), ++dy;
		else if( dy > 0 ) putchar('U'), --dy;
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
