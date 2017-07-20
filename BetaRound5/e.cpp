/**
 * Tittle:	E. Bindian Signlaizing
 * Author:	Cheng-Shih, Wong
 * Date:	2016/07/15
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
int n;
vector<int> hills;
long long l[MAXN], r[MAXN], c[MAXN];

// functions
void input()
{
	int v;

	scanf( "%d", &n );
	FOR( i, 0, n-1 ) {
		scanf( "%d", &v );
		hills.PB(v);
	}
}

void solve()
{

	int maxh, maxi;

	maxi = 0;
	maxh = hills[0];
	FOR( i, 1, n-1 ) {
		if( hills[i] > maxh ) {
			maxh = hills[i];
			maxi = i;
		}
	}

	rotate( hills.begin(), hills.begin()+maxi, hills.end() );
	hills.PB(maxh);

	clr( l, 0 );
	clr( r, 0 );
	clr( c, 0 );

	for( int i=n-1; i>=0; --i ) {
		r[i] = i+1;
		while( r[i]<n && hills[r[i]]<hills[i] ) r[i] = r[r[i]];
		if( r[i]<n && hills[i]==hills[r[i]] ) {
			c[i] = c[r[i]]+1;
			r[i] = r[r[i]];
		}
	}

	for( int i=1; i<n; ++i ) {
		l[i] = i-1;
		while( l[i]>0 && hills[l[i]]<=hills[i] ) l[i] = l[l[i]];
	}

	long long ans = 0;

	FOR( i, 0, n-1 ) {
		ans += c[i];
		if( hills[i]!=hills[0] ) {
			if( l[i]==0 && r[i]==n ) ++ans;
			else ans += 2;
		}
	}

	printf( "%I64d\n", ans );
}

// main function
int main( void )
{

	input();
	solve();
	
	return 0;
}
