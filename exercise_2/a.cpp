//UVA:
//g++ -std=c++14

#include <bits/stdc++.h>
using namespace std;
// E S W N

/*
3   E
2 S X N
1   W
0 1 2 3

*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    const char DIR[4] = {'N', 'W', 'S', 'E'}; 
    vector<pair<int, int>> PAIR = {make_pair(0, 1), make_pair(1, 0), make_pair(0, -1), make_pair(-1, 0)};

    int Gi, Gj; //Grid
    int Si, Sj; //Start
    char in;
    int dir; //direction
    string move;
    
    cin >> Gi >> Gj;
    while(cin >> Si >> Sj >> in >> move)
    {
        bool lost = false;
        for(int d = 0; d < 4; d++){
            if(in == DIR[d]){
                dir = d;
                break;
            }
        }
        for(auto c : move){
            if(c == 'L'){
                dir = (dir-1+4)%4;
            }
            else if(c == 'R'){
                dir = (dir+1+4)%4;
            }
            else if(c == 'F'){
                Si += PAIR[dir].first;
                Sj += PAIR[dir].second;
                if((Si < 0 || Si > Gi) || (Sj < 0 || Sj > Gj)){
                    Si -= PAIR[dir].first;
                    Sj -= PAIR[dir].second;
                    lost = true;
                    break;
                }
                for(int i = Gi; i >= 0; --i){
                    for(int j = 0; j <= Gj; ++j){
                        if(i == Si && j == Sj)
                            cout << "X ";
                        else cout << "_ ";
                    }
                    cout << '\n';
                }
                cout << '\n';
            }
        }
        cout << Si << ' ' << Sj << ' ' << DIR[dir]
             << (lost ? " LOST" : "") << '\n';
    }
    
}

/*
5   4
4   1
3   S 
2    
1
0 1 2 3

IN:
5 3
1 1 E
RFRFRFRF
3 2 N
FRRFLLFFRRFLL
0 3 W
LLFFFLFLFL

OUT:
1 1 E
3 3 N LOST
0 3 E LOST

CORRECT:
1 1 E
3 3 N LOST
2 3 S

*/