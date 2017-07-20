/**
 * Tittle:	A. Watermelon
 * Author:	Cheng-Shih, Wong
 * Date:	2016/07/03
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
int w;

// functions


// main function
int main( void )
{
	cin >> w;

	if( w>2 && (w&1)==0 ) puts("YES");
	else puts("NO");
	
	return 0;
}
