#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    string s;
    cin >> s;
    int ans = 1;
    int c = 1;
    for(int i = 1;i<s.length();i++){
        if(s[i] == s[i-1]) c++;
        else{
            ans = max(ans,c);
            c = 1;
        }
    }
    ans = max(c, ans);
    cout << ans << "\n";
 
    return 0;
}