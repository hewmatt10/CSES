#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll n;
    cin >> n;
    if(n % 4 == 1 || n % 4 == 2){
        cout << "NO\n";
        return 0;
    }
    if(n % 4 == 3){
        cout << "YES\n";
        cout << (n-3)/2 + 2 << "\n";
        cout << 1 << " " << 2 << " ";
        for(int i = 4;i <= n;i++){
            if(i % 4 == 0 || i % 4 == 3){
                cout << i << " ";
            }
        }
        cout << "\n";
        cout << (n-3)/2 + 1 << "\n";
        cout << 3 << " " ;
        for(int i = 4;i <= n;i++){
            if(i % 4 == 1 || i % 4 == 2){
                cout << i << " ";
            }
        }
    }
 
    if(n % 4 == 0){
        cout << "YES\n";
        cout << n/2 << "\n";
        cout << 1 << " " << 4 << " ";
        for(int i = 5;i <= n;i++){
            if(i % 4 == 1 || i % 4 == 0){
                cout << i << " ";
            }
        }
        cout << "\n";
        cout << n/2 << "\n";
        cout << 2 << " " << 3 << " " ;
        for(int i = 5;i <= n;i++){
            if(i % 4 == 2 || i % 4 == 3){
                cout << i << " ";
            }
        }
    }
    return 0;
}