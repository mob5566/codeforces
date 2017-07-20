/**
 * Tittle:	E. Exposition
 * Author:	Cheng-Shih, Wong
 * Date:	2016/08/11
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

#define MAXN 100005
typedef pair<int,int> PII;

// declarations
int n, k;
int M;
int h[MAXN];
unsigned int maxv[300000];
unsigned int minv[300000];

// functions
void input()
{
	scanf( "%d%d", &n, &k );
	FOR( i, 1, n ) scanf( "%d", &h[i] );
}

int queryMax( int l, int r )
{
	if( l > r ) return 0;

	unsigned int ret = maxv[l+M];

	int s, t;
	for( s=l+M-1, t=r+M+1; s^t^1; s>>=1, t>>=1 ) {
		if( ~s&1 ) ret = max( ret, maxv[s^1] );
		if(  t&1 ) ret = max( ret, maxv[t^1] );
	}

	return ret;
}

int queryMin( int l, int r )
{
	if( l > r ) return 0;

	unsigned int ret = minv[l+M];

	int s, t;
	for( s=l+M-1, t=r+M+1; s^t^1; s>>=1, t>>=1 ) {
		if( ~s&1 ) ret = min( ret, minv[s^1] );
		if(  t&1 ) ret = min( ret, minv[t^1] );
	}

	return ret;
}

bool valid( int len )
{
	for( int l=1, r=len; r<=n; ++l, ++r ) {
		if( queryMax(l,r)-queryMin(l,r) <= k ) return true;
	}

	return false;
}

void solve()
{
	clr( maxv, 0 );
	clr( minv, -1 );

	for( M=1; M-2<n; M<<=1 );

	FOR( i, 1, n ) 
		maxv[i+M] = minv[i+M] = h[i];
	
	for( int i=M-1; i>0; --i ) {
		maxv[i] = max( maxv[i+i], maxv[i+i+1] );
		minv[i] = min( minv[i+i], minv[i+i+1] );
	}
	
	int l = 1, r = n;
	int mid;

	while( l<=r ) {
		mid = (l+r)>>1;

		if( valid(mid) ) l = mid+1;
		else r = mid-1;
	}

	vector<int> ans;

	for( int i=1, j=r; j<=n; ++i, ++j )
		if( queryMax(i,j)-queryMin(i,j) <= k )
			ans.PB(i);

	printf( "%d %d\n", r, ans.size() );
	for( int v:ans )
		printf( "%d %d\n", v, v+r-1 );
}

// main function
int main( void )
{
	input();
	solve();
	
	return 0;
}
