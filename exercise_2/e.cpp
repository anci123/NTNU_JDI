//UVA:
//g++ -std=c++14

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        int N, B, ans = 0;
        cin >> N >> B;
        while(B--){
            int K, in;
            cin >> K;
            int Pi = 1;
            while(K--){
                cin >> in;
                Pi = (Pi * in) % N;
            }
            ans = (ans + Pi) % N;
        }
        cout << ans << '\n';
    }

}

/*

2
5 2
3 2 3 4
4 5 2 3 1
6 1
4 5 6 7 8

*/