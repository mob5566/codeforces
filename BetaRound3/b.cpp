/*
 * Tittle:	B. Lorry
 * Author:	Cheng-Shih, Wong
 * Date:	2016/07/01
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

typedef vector< pair<int,int> > VPII;
typedef pair<int,int> PII;

// declarations
long long n, v;
VPII veh[2];

// functions
void input()
{
	cin >> n >> v;
	
	int a, b;
	veh[0].clear();
	veh[1].clear();
	FOR( i, 1, n ) {
		cin >> a >> b;
		if( a==1 ) veh[0].PB(make_pair(b,i));
		else veh[1].PB(make_pair(b,i));
	}
}

void solve()
{
	sort( veh[0].begin(), veh[0].end() );
	sort( veh[1].begin(), veh[1].end() );
	vector<int> list;

	long long ans = 0;
	int p = veh[0].size()-1;
	int q = veh[1].size()-1;

	if( v&1==1 && p>=0 ) {
		--v;
		list.PB(veh[0][p].S);
		ans += veh[0][p].F;
		--p;
	}

	while( (p>=0 || q>=0) && v>0 ) {
		if( v>=2 && q>=0 ) {
			v -= 2;

			if( p==0 && veh[1][q].F < veh[0][p].F ) {
				ans += veh[0][p].F;
				list.PB( veh[0][p].S );
				--p;
				++v;
			} else if( p<1 || veh[1][q].F >= veh[0][p].F+veh[0][p-1].F ) {
				ans += veh[1][q].F;
				list.PB( veh[1][q].S );
				--q;
			} else {
				ans += veh[0][p].F+veh[0][p-1].F;
				list.PB( veh[0][p].S );
				list.PB( veh[0][p-1].S );
				p -= 2;
			}
		} else if( p>=0 ){
			--v;
			list.PB(veh[0][p].S);
			ans += veh[0][p].F;
			--p;
		} else {
			break;
		}
	}

	printf( "%d\n", ans );
	bool space = false;
	for( int a : list ) {
		if( space ) putchar(' ');
		else space = true;
		printf( "%d", a );
	}
	putchar('\n');
}


// main function
int main( void )
{

	input();
	solve();
	
	return 0;
}
