/**
 * Tittle:	B. Cneter Alignment
 * Author:	Cheng-Shih, Wong
 * Date:	2016/07/07
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
char buf[1005][1005];
int len[1005];
int n;
int maxl;

// functions
void input()
{
	n = 0;
	maxl = 0;

	while( gets(buf[n]) ) {
		len[n] = strlen(buf[n]);
		maxl = max( maxl, len[n] );
		++n;
	}
}

void solve()
{
	int rem;
	bool closeToLeft = false;

	FOR( i, 1, maxl+2 ) putchar('*');
	putchar('\n');
	FOR( i, 0, n-1 ) {
		rem = maxl-len[i];
		putchar('*');
		FOR( i, 1, rem/2 ) putchar(' ');
		if( (rem&1)==1 && closeToLeft ) putchar(' ');
		printf( "%s", buf[i] );
		FOR( i, 1, rem/2 ) putchar(' ');
		if( (rem&1)==1 && !closeToLeft ) putchar(' ');
		puts("*");
		if( (rem&1)==1 ) closeToLeft ^= true;
	}
	FOR( i, 1, maxl+2 ) putchar('*');
	putchar('\n');
}

// main function
int main( void )
{

	input();
	solve();
	
	return 0;
}
