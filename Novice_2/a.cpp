//UVA:
//g++ -std=c++14

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, cnt = 0;
    while(cin >> N){
        if(N != 0){
            ++cnt;
            cout << "Game " << cnt << ":\n";
        }
        vector<int> ans;
        for(int i = 0; i < N; i++){
            int tmp;
            cin >> tmp;
            ans.push_back(tmp);
        }
        vector<int> ansarchive = ans;
        while(true){
            ans = ansarchive;
            vector<int> guess;
            for(int i = 0; i < N; i++){
                int tmp;
                cin >> tmp;
                guess.push_back(tmp);
            }
            bool isZero = true;
            for(auto i : guess){
                isZero = (i == 0);
                if(!isZero) break;
            }
            if(isZero) break;


            int a, b = 0;
            queue<int> q;
            for(int i = 0; i < N; ++i)
                if(guess[i] == ans[i]) q.push(i);
            a = q.size();
            for(int i = 0; i < N; ++i){
                if(q.empty())break;
                if(q.front() == i){
                    q.pop();
                    ans[i] = guess[i] = 0;
                }
            }
            

            map<int, int> gm, am;
            for(int i = 1; i <= 9; ++i){
                gm[i] = 0;
                am[i] = 0;
            }
            for(auto i : ans)
                ++am[i];
            for(auto i : guess)
                ++gm[i];
            for(int i = 1; i <= 9; ++i)
                b += min(am[i], gm[i]);

            cout << "    (" << a << "," << b << ")\n";
        }
    }
}

/*

4
1 3 5 5
1 1 2 3
4 3 3 5
6 5 5 1
6 1 3 5
1 3 5 5
0 0 0 0
10
1 2 2 2 4 5 6 6 6 9
1 2 3 4 5 6 7 8 9 1
1 1 2 2 3 3 4 4 5 5
1 2 1 3 1 5 1 6 1 9
1 2 2 5 5 5 6 6 6 7
0 0 0 0 0 0 0 0 0 0
0

*/