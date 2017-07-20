/**
 * Tittle:	D. Least cost Bracket Sequence
 * Author:	Cheng-Shih, Wong
 * Date:	2016/07/02
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

typedef pair<int,int> PII;
typedef priority_queue<PII> PQPII;

// declarations
char bkt[50005];
int len;

// functions
void input()
{
	cin >> bkt;
	len = strlen(bkt);
}

void solve()
{
	int obcnt = 0;
	long long cost = 0;
	int a, b;
	PII nd;
	PQPII pq;

	FOR( i, 0, len-1 ) {
		if( bkt[i]=='(' ) {
			++obcnt;
		} else if( bkt[i]==')' ) {
			--obcnt;
		} else {
			cin >> a >> b;
			pq.push( make_pair(b-a,i) );
			cost += b;
			--obcnt;
			bkt[i] = ')';
		}

		if( obcnt<0 ) {
			if( pq.empty() ) break;

			nd = pq.top();
			pq.pop();

			cost -= nd.F;
			bkt[nd.S] = '(';
			obcnt += 2;
		}
	}

	if( obcnt!=0 ) puts("-1");
	else {
		cout << cost << endl;
		cout << bkt << endl;
	}
}

// main function
int main( void )
{

	input();
	solve();
	
	return 0;
}
