#include <iostream>
#include <cstring>
using namespace std;
const int N =9;
const int M=3;
int a[N][N],b[N][N];
bool st[N+1];
string memory[N]={{"530070000"},{"600195000"},{"098000060"},{"800060003"},{"400803001"},{"700020006"},{"060000280"},{"000419005"},{"000080079"}};
 
const int n = 9;
 
bool check_input(){
	string line;
	for(int i=0;i<N;i++)
	{
		cin >> line;
		if(line.size()!=N) return false; //长度不对
		for(int j=0;j<N;j++) {
			int t = line[j]-'0'; //字符转整数
			if(t<1 || t>N) { //出现不是1到9的数字 
				return false; 
			}
			if(a[i][j]!=0 && a[i][j]!=t) return false; //输入的值与初始值不匹配 
			b[i][j]=t; 
		}
	}
	return true;
}
 
bool check_row(){
	for(int i=0;i<N;i++){
		memset(st,false,sizeof(st));
		for(int j=0;j<N;j++)
		{
			int t = b[i][j];
			if(t<0 || t>N) return false;
			if(st[t]) return false;
			st[t]=true;
		}
	}
	return true;
}
 
bool check_col()
{
	for(int i=0;i<N;i++){
		memset(st,false,sizeof(st));
		for(int j=0;j<N;j++)
		{
			int t=b[j][i];
			if(t<0 || t>N) return false;
			if(st[t]) return false;
			st[t]=true;
		}
	}
	return true;
}
 
bool check_block(){
	for(int x=0;x<N;x += M)
		for(int y=0;y<N; y += M)
		{
			memset(st,false,sizeof(st));
			for(int dx=0;dx<M;dx++)
				for(int dy=0;dy<M;dy++) 
				{
					int t = b[x+dx][y+dy];
					if(t<0 || t>N) return false;
					if(st[t]) return false;
					st[t]=true;
				}
		}
	return true;
}
 
int main()
{
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++) 
		{
			a[i][j]=memory[i][j]-'0';
		}
	if(check_input() && check_row() && check_col() && check_block())
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
 
}