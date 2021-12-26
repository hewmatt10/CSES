#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll n;
    cin >> n;
    ll x, y;
    while(n--){
        cin >> y >> x;
        if(y > x){
            if(y % 2 == 0){
                cout << y * y - y + 1 + y - x << "\n";
            }
            else{
                cout << y * y - y + 1 - y + x << "\n";
            }
        }
        else{
            if(x % 2 == 0){
                cout << x * x - x + 1 + y - x << "\n";
            }
            else{
                cout << x * x - x + 1 - y + x << "\n";
            }
        }
    }
    return 0;
}