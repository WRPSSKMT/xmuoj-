#include<bits/stdc++.h>
using namespace std;

const int N9 = 9; //递归9层
const int N = 10;
int Sudu[N][N];
bool row[N][N],col[N][N],grid[N][N];
//每一行每一列扫描
bool dfs(int r,int c){
    if(r==N9) return true;  //[0-8]
    bool flag = false;  //是否找到可行解
    if(Sudu[r][c]){      //Sudu中数字不为1
        if(c==8) flag = dfs(r+1,0);  //搜索下一行
        else flag = dfs(r,c+1);
        return flag;
    }
    //每一个3*3的grid,寻找第k个grid
    int k = (r/3)*3 + c/3;
    for(int i=1;i<=9;i++){   //尝试在Sudu[r][c]摆下1-9的数字
        if(!row[r][i] && !col[c][i] && !grid[k][i]){  //如果该数字还没有被摆放
            row[r][i] = true; col[c][i] = true; grid[k][i] = true;  //每行每列每grid标志
            Sudu[r][c] = i;  //从1-9开始尝试摆下数字
            if(c==8) flag = dfs(r+1,0);  //搜索下一行
            else flag = dfs(r,c+1);
            if(flag) return true;
            //还原状态
            Sudu[r][c]=0;
            row[r][i] = false; col[c][i] = false; grid[k][i] = false;
        }
    }
    return false;
}

int main()
{
    //输入输出加速
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    memset(row,false,sizeof(row));
    memset(col,false,sizeof(col));
    memset(grid,false,sizeof(grid));
    for(int i=0;i<N9;i++)
        for(int j=0;j<N9;j++){
            char ch;
            cin>>ch;
            Sudu[i][j] = ch - '0';
            if(Sudu[i][j]){
                row[i][Sudu[i][j]] = true;  //第i行中Sudu中的数字已经被使用
                col[j][Sudu[i][j]] = true; //第j行中Sudu中的数字已经被使用
                grid[(i/3)*3 + j/3][Sudu[i][j]] = true;  //第grid方块中Sudu中的数字已经被使用
            }
        }
    dfs(0,0);
    
    for(int i=0;i<N9;i++){
        for(int j=0;j<N9;j++)
            cout<<Sudu[i][j];
        cout<<endl;
    }
}
