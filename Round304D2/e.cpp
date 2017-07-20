/**
 * Tittle:	E. Soldier and Traveling
 * Author:	Cheng-Shih, Wong
 * Date:	2016/06/30
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
#define MAXN 205
#define INF 1e5

// declarations
int N, M;
int S, T;
int ttlp;
int ttlq;

// functions

/** Ford-Fulkerson Maximum Flow **/
int f[MAXN][MAXN];
int c[MAXN][MAXN];
int pre[MAXN], que[MAXN], d[MAXN], mk[MAXN];

int maxFlow( int n, int s, int t )
{
	int head, tail;
	int i, u, v, flow = 0;
	clr( f, 0 );

	do {
		clr( mk, 0 ); clr( d, 0 );
		que[0] = s; mk[s] = 1; d[s] = INF;

		for( pre[s]=head=tail=0; head<=tail && !mk[t]; ++head ) {
			for( u=que[head], v=1; v<=n; ++v ) if( !mk[v]&&f[u][v]<c[u][v] ) {
				mk[v] = 1; que[++tail] = v; pre[v] = u;

				if( d[u] < c[u][v]-f[u][v] ) d[v] = d[u];
				else d[v] = c[u][v]-f[u][v];
			}
		}
		if( !mk[t] ) break; flow += d[t];

		for( u=t; u!=s; ) { v = u; u = pre[v]; f[u][v] += d[t]; f[v][u] = -f[u][v]; }
	} while( d[t] > 0 ); 

	return flow;
}

void input()
{
	// input data and initialzie variables
	cin >> N >> M;
	S = 2*N+1; T = 2*N+2;

	clr( c, 0 );
	int u, v;

	FOR( i, 1, N ) 
		cin >> c[S][i];
	FOR( i, 1, N )
		cin >> c[i+N][T];
	
	ttlp = 0;
	FOR( i, 1, N )
		ttlp += c[S][i];
	ttlq = 0;
	FOR( i, 1, N )
		ttlq += c[i+N][T];
	
	// edge construction
	FOR( i, 1, N )
		c[i][i+N] = INF;
	
	FOR( i, 1, M ) {
		cin >> u >> v;
		c[u][v+N] = c[v][u+N] = INF;
	}
}

void solve()
{
	int maxf = maxFlow( 2*N+2, S, T );

	if( ttlp!=ttlq || maxf!=ttlp ) puts("NO");
	else {
		puts("YES");
		FOR( i, 1, N ) {
			printf( "%d", f[i][N+1] );

			FOR( j, 2, N )
				printf( " %d", f[i][N+j] );
			putchar('\n');
		}
	}
}


// main function
int main( void )
{

	input();
	solve();
	
	return 0;
}
