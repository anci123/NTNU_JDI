//UVA:
//g++ -std=c++14

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int simulate[6][6] = {{1, 2, 3, 5, 4, 6}, 
                     {2, 6, 3, 1, 4, 5}, 
                     {3, 6, 5, 1, 2, 4}, 
                     {4, 6, 2, 1, 5, 3}, 
                     {5, 6, 4, 1, 3, 2}, 
                     {6, 2, 4, 5, 3, 1}};

    int twist[4][6] = {{1, 2, 3, 4, 5, 6}, 
                       {1, 3, 4, 5, 2, 6}, 
                       {1, 4, 5, 2, 3, 6}, 
                       {1, 5, 2, 3, 4, 6}};

    char original[6] = {};
    char simulated[6] = {};
    char twisted[6] = {};
    char ans[6] = {};
    string in;
    while(cin >> in){
        bool isSame = true;
        for(int i = 0; i < 12; ++i){
            if(i < 6) original[i] = in[i];
            else ans[i - 6] = in[i];
        }
        swap(ans[4], ans[3]);
        for(int s = 0; s < 6; ++s){
            for(int x = 0; x < 6; ++x)
                simulated[x] = original[simulate[s][x] - 1];
            for(int t = 0; t < 4; ++t){
                for(int x = 0; x < 6; ++x){
                    twisted[x] = simulated[twist[t][x] - 1];
                }
                /*for(auto a : original)
                    cout << a;
                cout << " => ";
                for(auto a : simulated)
                    cout << a;
                cout << " => ";
                for(auto a : twisted)
                    cout << a;
                cout << " <=> ";
                for(auto a : ans)
                    cout << a;
                cout << "\n";*/
                isSame = true;
                for(int x = 0; x < 6; ++x)
                    if(twisted[x] != ans[x]) isSame = false;
                if(isSame) break;
            }
            if(isSame) break;
        }
        cout << (isSame?"TRUE":"FALSE") << "\n";
    }

}

/*

rbgggrrggbgr
rrrbbbrrbbbr
rbgrbgrrrrrg

*/