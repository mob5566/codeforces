/**
 * Tittle:	A. Triangle
 * Author:	Cheng-Shih, Wong
 * Date:	2016/07/17
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
int a, b, c, d;

// functions
int check( int A, int B, int C )
{
	if( C > B ) swap(B,C);
	if( B > A ) swap(A,B);

	if( A > B+C ) return 0;
	if( A == B+C ) return 1;
	if( A < B+C ) return 2;
}

// main function
int main( void )
{

	cin >> a >> b >> c >> d;

	int val = check( a, b, c ) |
			  check( a, b, d ) |
			  check( a, c, d ) |
			  check( b, c, d );

	if( (val&2)==2 ) puts("TRIANGLE");
	else if( (val&1)==1 ) puts("SEGMENT");
	else puts("IMPOSSIBLE");
	
	return 0;
}
