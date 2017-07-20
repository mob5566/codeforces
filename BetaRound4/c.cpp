/**
 * Tittle:	C. Registration system
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

typedef map<string,int> MSI;

// declarations
int n;
MSI reg;

// functions


// main function
int main( void )
{
	string name;

	cin >> n;

	while( n-- ) {
		cin >> name;

		if( reg.find(name) != reg.end() ) {
			printf( "%s%d\n", name.c_str(), reg[name] );
			++reg[name];
		} else {
			reg[name] = 1;
			puts("OK");
		}
	}
	
	return 0;
}
