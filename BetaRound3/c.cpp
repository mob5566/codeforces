/**
 * Tittle:	C. Tic-tac-toe
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

// declarations
char board[5][5];

// functions
void input()
{
	cin >> board[0] >> board[1] >> board[2];
}

void solve()
{
	bool xwin = false;
	bool owin = false;
	int xcnt = 0;
	int ocnt = 0;
	
	FOR( i, 0, 2 ) FOR( j, 0, 2 ) {
		switch( board[i][j] ) {
		case 'X':
			++xcnt;
			break;
		case '0':
			++ocnt;
			break;
		}
	}

	if( xcnt!=ocnt && xcnt!=ocnt+1 ) {
		puts("illegal");
		return;
	}

	FOR( i, 0, 2 ) {
		if( board[i][0]==board[i][1] && board[i][1]==board[i][2] ) {
			if( board[i][0]=='X' ) xwin = true;
			else if( board[i][0]=='0' ) owin = true;
		}
		if( board[0][i]==board[1][i] && board[1][i]==board[2][i] ) {
			if( board[0][i]=='X' ) xwin = true;
			else if( board[0][i]=='0' ) owin = true;
		}
	}

	if( board[0][0]==board[1][1] && board[1][1]==board[2][2] ) {
		if( board[0][0]=='X' ) xwin = true;
		else if( board[0][0]=='0' ) owin = true;
	}
	if( board[0][2]==board[1][1] && board[1][1]==board[2][0] ) {
		if( board[0][2]=='X' ) xwin = true;
		else if( board[0][2]=='0' ) owin = true;
	}

	if( xwin && owin ) {
		puts("illegal");
		return;
	}

	if( (owin&&xcnt>ocnt) || (xwin&&xcnt==ocnt) ) {
		puts("illegal");
		return;
	}

	if( xwin ) puts("the first player won");
	else if( owin ) puts("the second player won");
	else if( xcnt+ocnt == 9 ) puts("draw");
	else if( xcnt==ocnt ) puts("first");
	else puts("second");
}

// main function
int main( void )
{

	input();
	solve();
	
	return 0;
}
