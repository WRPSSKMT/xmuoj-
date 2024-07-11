#include<bits/stdc++.h> 
 
using namespace std;
 
const int N = 25, INF = 0x3f3f3f3f;
int w, h, m; 
int ways[N][N][N * N];
 
int dfs(int w, int h, int m){
	if(w * h < m + 1) return INF;  //分不出那么多块 
	if(m == 0) return w * h;       //切好了 
	if(ways[w][h][m] != -1) return ways[w][h][m];  //记忆 
	
	int mincake = INF;              
	for(int i = 1; i < w; ++ i)       //第一刀是竖着切的 
	  for(int k = 0; k < m; ++ k){
	  	int m1 = dfs(i, h, k);
	  	int m2 = dfs(w - i, h, m - k - 1);
	  	mincake = min(mincake, max(m1, m2));  //m1,m2中较大值才是最大蛋糕的最小值 
	  }
	  
	for(int i = 1; i < h; ++ i)       //第一刀是横着切的 
	  for(int k = 0; k < m; ++ k){
	  	int m1 = dfs(w, i, k);
	  	int m2 = dfs(w, h - i, m - k - 1);
	  	mincake = min(mincake, max(m1, m2));
	  }
	  
	ways[w][h][m] = mincake;  
	
	return ways[w][h][m]; 
}
 
int main( )
{
    while(cin >> w >> h >> m && w != 0){
    	memset(ways, -1, sizeof ways);  //宽为w高为h的蛋糕切m-1刀最大蛋糕面积的最小值 
    	cout << dfs(w, h, m - 1) << endl;
	}
	return 0;
}