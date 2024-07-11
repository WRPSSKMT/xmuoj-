#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
 
#define x first
#define y second
 
typedef pair<char, int> PII;
vector<PII> res;
const int N = 30;
bool st[N][N];
int p, q, cnt = 1;
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2}, dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
 
bool dfs(int x, int y, int u){
	
	res.push_back({x + 65, y + 1});   //顺序 
	
	if(u >= p * q){
		for(auto a: res) cout << a.x << a.y;
		cout << endl; 
		return true;
	}
	
	st[x][y] = true;
	
	
	for(int i = 0; i < 8; ++ i){
		int nx = x + dx[i], ny = y + dy[i];
		//if(u <= 4)cout << u << ' ' << nx << ' '<< ny << endl;
		if(nx >= q || nx < 0 || ny >= p || ny < 0) continue;  //x是行 y是列 
		
		if(!st[nx][ny]){
			if(dfs(nx, ny, u + 1) ) return true;  //是这一步阻断了后续的搜索			
		} 
	}
	st[x][y] = false;   //出循环说明无路可走
	res.pop_back();     //弹出‘错误’的点
    return false;       //返回false
}
 
int main(){
	  int t;
	  cin >> t;
	  while(t--){
	  	cin >> p >> q;
	  	cout << '#' << cnt << ':' << endl;
	    if(!dfs(0, 0, 1)) cout << "none" << endl;
	  	memset(st, 0, sizeof st);
	  	res.clear();
	  	++ cnt;
	  }
	
     return 0;
}