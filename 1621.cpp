#include<bits/stdc++.h>
using namespace std;
int N;
set<int> st;
int main(){
    cin >> N;
    for(int i = 0;i<N;i++){
        int a;
        cin >> a;
        st.insert(a);
    }
    cout << st.size() << "\n";
    return 0;
}