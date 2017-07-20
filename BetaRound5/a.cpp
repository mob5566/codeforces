/**
 * Tittle:	A. Chat Server's Outgoing Traffic
 * Author:	Cheng-Shih, Wong
 * Date:	2016/07/06
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
char buf[128];


// functions


// main function
int main( void )
{

	int cnt = 0;
	int ans = 0;

	while( gets(buf) ) {
		if( buf[0]=='+' ) ++cnt;
		else if( buf[0]=='-' ) --cnt;
		else {
			int pos = 0;
			int len = strlen(buf);

			while( pos<len && buf[pos]!=':' ) ++pos;
			ans += cnt*(len-pos-1);
		}
	}
	cout << ans << endl;
	
	return 0;
}
