#include<bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
int N,M,K;
int cnt;
int appt [MN];
int appl [MN];
int main(){
    cin >> N >> M >> K;
    for(int i = 0;i<N;i++)cin>>appt[i];
    for(int i = 0;i<M;i++)cin>>appl[i];
    sort(appt,appt+N);
    sort(appl,appl+M);
    for(int i = 0,j=0;i<N;i++){
        while(j < M && appl[j] < appt[i] - K)j++;
        if(j < M && appl[j] <= appt[i] + K){
            cnt++;
            j++;
        }
    }
    cout << cnt << "\n";
    return 0;
}