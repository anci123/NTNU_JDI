//UVA:
//g++ -std=c++14

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long cnt;
    cin >> cnt;
    while(cnt--){
        long long N, M;
        cin >> N >> M;
        if(M < N){
            cout << M << "\n";
            continue;
        }
        M = M - N + 1;
        long long max = N - 1;

        long long up = N - 1;
        long long down = 0;
        long long sacrifice;
        while(true){
            sacrifice = (up + down)/2;
            if(sacrifice * (sacrifice - 1) / 2 >= M)
                up = sacrifice;
            else
                down = sacrifice;
            if(down == up - 1){
                sacrifice = up;
                break;
            }
        }

        /*while(true){
            if(sacrifice * (sacrifice - 1) / 2 >= M) break; 
            if(sacrifice < 1) sacrifice = 1;
            sacrifice++;
        }*/

        cout << max - sacrifice << "\n";
    }
}