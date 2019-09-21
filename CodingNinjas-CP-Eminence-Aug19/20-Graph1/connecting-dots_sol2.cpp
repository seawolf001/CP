/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1000000007
#define DEBUG(x) cerr << #x << " is " << (x) << endl;
typedef long long ll;
typedef long double ld;
typedef std::vector<ll> vll;
typedef std::vector<int> vi;
typedef std::vector<string> vs;

const int X[] = { -1, 0, 1, 0};
const int Y[] = {0, -1, 0, 1};
int flag = 0;

void dfs(char board[][MAXN], int x, int y, int path, int px, int py, char ch, int n, int m, bool** vis) {
	if (vis[x][y] == true) {
		if (path >= 4)
			flag = 1;
		return;
	}
	vis[x][y] = true;
	for (int c = 0; c < 4; c++) {
		int nx = x + X[c];
		int ny = y + Y[c];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;
		if (nx == px && ny == py)
			continue;
		if (board[nx][ny] == ch) {
			dfs(board, nx, ny, path + 1, x, y, ch, n, m, vis);
		}
	}
}
int solve(char board[][MAXN], int n, int m) {
	char ch = '\0';
	bool ** vis = new bool * [n];
	for (int i = 0; i < n; i++) {
		vis[i] = new bool[m];
		memset(vis[i], false, m * sizeof(bool));
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!vis[i][j]) {
				ch = board[i][j];
				int path = 1;
				flag = 0;
				dfs(board, i, j, path, -1, -1, ch, n, m, vis);
				if (flag == 1)
					return 1;
			}
		}
	}
	for (int i = 0; i < n; i++) delete vis[i];
	delete[] vis;
	return 0;
}
