#include<bits/stdc++.h>
using namespace std;
const int MN = 1e3+3;
int n, q;
int psa[MN][MN];


int main(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        for(int j = 0; j < n; j++){
            if(s[j] == '*'){
                psa[i][j+1]++;
            }
            psa[i][j+1] = psa[i][j+1] + psa[i][j] + psa[i-1][j+1] - psa[i-1][j];
        }
    }
    for(int i = 0;i < q; i++){
        int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
        cout << psa[y2][x2] - psa[y2][x1-1] - psa[y1-1][x2] + psa[y1-1][x1-1] << "\n";
    }
    return 0;
}