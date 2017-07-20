/**
 * Tittle:	C. Longest Regular Bracket Sequence
 * Author:	Cheng-Shih, Wong
 * Date:	2016/07/12
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
#define MAXN 1000005

// declarations
char buf[MAXN];
int len;
int cors[MAXN];
int far[MAXN];

// functions
void input()
{
	cin >> buf;
}

void solve()
{
	len = strlen(buf);
	clr( cors, -1 );
	clr( far, -1 );
	stack<int> stk;
	int pre;
	int maxl, cnt;

	FOR( i, 0, len-1 ) {
		if( buf[i]=='(' ) {
			stk.push(i);
		} else {
			if( !stk.empty() ) {
				cors[i] = stk.top(); stk.pop();

				pre = cors[i]-1;
				if( pre>0 && buf[pre]==')' && far[pre]!=-1 ) 
					far[i] = far[pre];
				else
					far[i] = cors[i];
			}
		}
	}

	maxl = 0;
	cnt = 1;

	FOR( i, 0, len-1 ) {
		if( far[i]!=-1 ) {
			if( i-far[i]+1>maxl ) {
				maxl = i-far[i]+1;
				cnt = 1;
			} else if( i-far[i]+1==maxl ) {
				++cnt;
			}
		}
	}

	printf( "%d %d\n", maxl, cnt );
}

// main function
int main( void )
{
	
	input();
	solve();
	
	return 0;
}
