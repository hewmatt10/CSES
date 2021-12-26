#include<bits/stdc++.h>
using namespace std;
string s;
int cnt;
bool vis [7][7];
 
bool go(int i, int j){
    return (i >= 0 && j >= 0 && i < 7 && j < 7 && !vis[i][j]);
}
 
void dfs(int i, int j, int cur = 0){
    if(i == 6 && j == 0){
        if(cur == 48){
            cnt++;
        }
        return;
    }
    vis[i][j] = 1;
    if(s[cur] == '?' || s[cur] == 'L'){
        if(j && !vis[i][j-1]){
            if(!(!go(i,j-2) && go(i+1,j-1) && go(i-1,j-1))) dfs(i,j-1,cur+1);
        }
    }
    if(s[cur] == '?' || s[cur] == 'R'){
        if(j<6 && !vis[i][j+1]){
            if(!(!go(i,j+2) && go(i+1,j+1) && go(i-1,j+1))) dfs(i,j+1,cur+1);
        }
    }
    if(s[cur] == '?' || s[cur] == 'U'){
        if(i && !vis[i-1][j]){
            if(!(!go(i-2,j) && go(i-1,j+1) && go(i-1,j-1))) dfs(i-1,j,cur+1);
        }
    }
    if(s[cur] == '?' || s[cur] == 'D'){
        if(i < 6&& !vis[i+1][j]){
            if(!(!go(i+2,j) && go(i+1,j+1) && go(i+1,j-1))) dfs(i+1,j,cur+1);
        }
    }
    vis[i][j] = 0;
}
 
int main(){
    cin >> s;
    dfs(0,0);
    cout << cnt << "\n";
    return 0;
}