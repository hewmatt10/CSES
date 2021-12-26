#include<bits/stdc++.h>
using namespace std;
int cnt;
set<pair<int,int>> dead; 

void recur(int i, int colmask, int maindiamask, int otherdiamask){
    if(i == 8){
        cnt++;
        return;
    }
    for(int j = 0;j<8;j++){
        if(dead.find({i,j}) != dead.end())continue;
        if(colmask & (1 << j))continue;
        if(maindiamask & (1 << (i - j + 8)))continue;
        if(otherdiamask & (1 << (i + j)))continue;
        recur(i+1, colmask | (1 << j), maindiamask | (1 << (i - j + 8)), otherdiamask | (1 << (i + j)));
    }
}

int main(){
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            char c;
            cin >> c;
            if(c == '*'){
                dead.insert({i,j});
            }
        }
    }
    recur(0,0,0,0);
    cout << cnt << "\n";
    return 0;
}