//UVA: 10813

#include<bits/stdc++.h>
using namespace std;
//#define debug
bool anal(bool mark[][5]) {
    bool bingo;
    for(int i = 0; i < 5; ++i) { //row
        bingo = true;
        for(int j = 0; j < 5; ++j) {
            if(!mark[i][j]) {
                bingo = false;
                break;
            }
        }
        if(bingo) break;
    }
    if(!bingo) {//col
        for(int i = 0; i < 5; ++i) {
            bingo = true;
            for(int j = 0; j < 5; ++j) {
                if(!mark[j][i]) {
                    bingo = false;
                    break;
                }
            }
            if(bingo) break;
        }
    }
    if(!bingo) {
        bingo = true;
        for(int i = 0; i < 5; ++i) if(!mark[i][i]) bingo = false;
    }
    if(!bingo){
        bingo=true;
        for(int i = 0; i < 5; ++i) if(!mark[i][5 - i - 1]) bingo = false;
    }
#ifdef debug
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5; ++j) cout << mark[i][j] << " ";
        cout << endl;
    }
    cout << endl;
#endif
    if(bingo) return true;
    else return false;
}
int main() {
    int n;
    cin >> n;
    while(n--) {
        vector<vector<int>> table;
        bool mark[5][5];
        memset(mark, 0, sizeof(mark));
        for(int i = 0; i < 5; ++i) {
            vector<int> line(5);
            if(i != 2)for(int j = 0; j < 5; ++j) cin >> line[j];
            else {
                for(int j = 0; j < 2; ++j) cin >> line[j];
                for(int j = 3; j < 5; ++j) cin >> line[j];
                line[2] = 0;
            }
            table.push_back(line);
        }
        int num[75];
        bool bingo = false;
        for(int i = 0; i < 75; ++i) cin >> num[i];
        int i;
        mark[2][2] = true;
        for(i = 1; i <= 75; ++i) {
            int y = 0, x = 0;
            for(y = 0; y < 5; ++y) {
                for(x = 0; x < 5; ++x)
                    if(num[i - 1] == table[y][x]) goto bingo;

            }
bingo:
            if(x < 5 && y < 5) mark[y][x] = true;
            bingo = anal(mark);
            if(bingo) break;
        }
        while(i < 5) ++i;
        cout << "BINGO after " << i << " numbers announced" << endl;
    }
    return 0;
}
