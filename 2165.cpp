#include<bits/stdc++.h>
using namespace std;
int N;
vector<pair<int,int>> moves;
int main(){
    cin >> N;
    moves.push_back({1,3});
    for(int i = 1;i<N;i++){
        vector<pair<int,int>> temp;
        for(pair<int,int> p : moves){
            int a = p.first;
            int b = p.second;
            if(a == 2)a = 3;
            else if(a == 3)a = 2;
            if(b == 2)b = 3;
            else if(b == 3)b = 2;
            temp.push_back({a,b});
        }
        temp.push_back({1,3});
        for(pair<int,int> p : moves){
            int a = p.first;
            int b = p.second;
            if(a == 1)a = 2;
            else if(a == 2)a = 1;
            if(b == 1)b = 2;
            else if(b == 2)b = 1;
            temp.push_back({a,b});
        }
        moves.assign(temp.begin(),temp.end());
    }
    cout << moves.size() << "\n";
    for(pair<int,int> p : moves){
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}