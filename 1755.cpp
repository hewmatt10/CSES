#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
int freq[26];
int main(){
    string s;
    cin >> s;
    for(int i = 0;i<s.length();i++){
        freq[s[i]-'A']++;
    }
    int oddcnt = 0;
    for(int i = 0;i<26;i++){
        if(freq[i] % 2 == 1)oddcnt++;
    }
    string ans = "";
    if(oddcnt > 1){
        cout << "NO SOLUTION";
        return 0;
    }
    else if(oddcnt == 1){
        for(int i = 0;i<26;i++){
            if(freq[i]%2){
                for(int j = 0;j<freq[i];j++){
                    ans += (char)(i+'A');
                }
                freq[i] = 0;
                break;
            }
        }
    }
    for(int i = 0;i<26;i++){
        string temp = "";
        for(int j = 0;j<freq[i]/2;j++){
            temp += (char)(i+'A');
        }
        ans = temp + ans + temp;
    }
    cout << ans;
    return 0;
}