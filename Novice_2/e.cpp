//UVA:
//g++ -std=c++14

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cnt;
    cin >> cnt;
    while(cnt--){
        int N;
        cin >> N;
        vector<int> SS, FF;
        for(int i = 0; i < N; ++i){
            int tmp, tmp2;
            cin >> tmp >> tmp2;
            SS.push_back(tmp);
            FF.push_back(tmp2);
        }
        sort(SS.begin(), SS.end());
        sort(FF.begin(), FF.end());
        queue<int> S, F;
        for(int i = 0; i < N; ++i){
            S.push(SS[i]);
            F.push(FF[i]);
        }
        int workcnt = 0, ans = 0;
        while(!S.empty() && !F.empty()){
            //cout << "(" << S.front() << "," << F.front() << ")\n";
            if(S.front() > F.front()){
                F.pop();
                --workcnt;
            }
            if(S.front() < F.front()){
                S.pop();
                ++workcnt;
            }
            if(S.front() == F.front()){
                S.pop();
                F.pop();
            ans = max(ans, workcnt+1);
            }
            ans = max(ans, workcnt);
            if(workcnt < 0) cout << "ERROR WORK < 0\n";
        }
        cout << ans << "\n";
    }
}

/*
2
8
1 2
3 4
5 6
7 8
9 10
11 12
13 14
15 16
6
1 2
2 3
3 4
4 5
5 6
6 7
*/