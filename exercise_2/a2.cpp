//UVA:
//g++ -std=c++14
//Ahhhhhhh ZA WALUDOOO!!!!!!!!!!!

#include <bits/stdc++.h>
using namespace std;
/*
j
3   N
2 W X E
1   S
0 1 2 3 i

*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    const char DIR[4] = {'N', 'E', 'S', 'W'}; 
    vector<pair<int, int>> PAIR = {make_pair(0, 1), make_pair(1, 0), make_pair(0, -1), make_pair(-1, 0)};

    int Gi, Gj; //Grid
    int Si, Sj; //Start
    char in;
    int dir; //direction
    string move;
    bool B[51][51];//Barrier
    memset(B, 0, sizeof(B));
    
    
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
                    if(!B[Si][Sj]){
                        B[Si][Sj] = true;
                        lost = true;
                        break;
                    }
                }
                /*
                for(int j = Gj; j >= 0; --j){
                    for(int i = 0; i <= Gi; ++i){
                        cout << ((i == Si && j == Sj)?"X ":"_ ");
                    }
                    cout << '\n';
                }
                cout << '\n';
                */
            }
        }
        cout << Si << ' ' << Sj << ' ' << DIR[dir]
             << (lost ? " LOST" : "") << '\n';
    }
    
}

/*
3   
2    
1  
0 1 2 3 4 5

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