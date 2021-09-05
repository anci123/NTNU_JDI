// Sky

#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, p;
    int cnt = 0;
    while(cin >> N >> p){
        if(cnt) cout << "\n";
        cnt++;
        int ansAC, ansP, time;
        vector<int> T;
        for(int i = 0; i < N; ++i){
            int tmp;
            cin >> tmp;
            T.push_back(tmp);
        }
        if(T[p] > 300){
            cout << "0 0";
            continue;
        }
        time = T[p];
        ansP = time;
        ansAC = 1;
        T[p] = 999;
        sort(T.begin(), T.end());
        for(auto i : T){
            if(time + i > 300) break;
            time += i;
            ansP += time;
            ++ansAC;
        }
        cout << ansAC << " " << ansP;
    }
}


/*
7 0
30 270 995 996 997 998 999
7 1
30 270 995 996 997 998 999
7 2
30 270 995 996 997 998 999
3 0
1 300 299


*/

/*
idea:Sky

先把第一個題目匯入
若超時變輸出0 0
否則用貪心法把簡單的題目加入即可
*/