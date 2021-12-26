#include<bits/stdc++.h>
using namespace std;
int N;
string s;
set<string> st;

void recur(string cur, int mask){
    if(mask == ((1 << N) - 1)){
        st.insert(cur);
    }
    for(int i = 0;i<N;i++){
        if(!(mask & (1 << i))){
            recur(cur + s[i], (mask | (1 << i)));
        }
    }
}


int main(){
    cin >> s;
    N = s.length();
    recur("",0);
    cout << st.size() << "\n";
    for(string s : st){
        cout << s << "\n";
    }
    return 0;
}