#include<bits/stdc++.h>
using namespace std;
#define bound 5
char puzzle[5][5];
int sx, sy;
bool A() {
    --sx;
    if(sx < 0 || sx >= bound) return false;
    else swap(puzzle[sx][sy], puzzle[sx + 1][sy]);
    return true;
}
bool B() {
    ++sx;
    if(sx < 0 || sx >= bound) return false;
    else swap(puzzle[sx][sy], puzzle[sx - 1][sy]);
    return true;
}
bool L() {
    --sy;
    if(sy < 0 || sy >= bound) return false;
    else swap(puzzle[sx][sy], puzzle[sx][sy + 1]);
    return true;
}
bool R() {
    ++sy;
    if(sy < 0 || sy >= bound) return false;
    else swap(puzzle[sx][sy], puzzle[sx][sy - 1]);
    return true;
}
int main() {
    char comment[1000] = {0};
    char start, temp;
    int time = 0;
    while(1) {
        if((start = getchar()) != EOF && start == 'Z' && (temp = getchar()) != EOF && temp == '\n') break;
        if(time) cout << endl;
        puzzle[0][0] = start;
        puzzle[0][1] = start;
        if(start == ' ') {
            sx = 0;
            sy = 0;
        }
        if(temp == ' ') {
            sx = 0;
            sy = 1;
        }
        char t;
        for(int i = 2; i < 5; ++i) {
            t = getchar();
            puzzle[0][i] = t;
            if(t == ' ') {
                sx = 0, sy = i;
            }
        }
        getchar();
        getchar();
        getchar();

        for(int i = 1; i < 5; ++i) {
            for(int j = 0; j < 5; ++j) {
                t = getchar();
                puzzle[i][j] = t;
                if(t == ' ') sx = i, sy = j;
            }
            getchar();
            getchar();
        }
        for(int i = 0; i < 5; ++i) {
            for(int j = 0; j < 5; ++j) cout << puzzle[i][j];
            cout << endl;
        }
        char cmd;
        bool OK = true;
        while((cmd = getchar()) != EOF && cmd != '0') {
            if(OK) {
                if(cmd == 'A') OK = A();
                if(cmd == 'B') OK = B();
                if(cmd == 'L') OK = L();
                if(cmd == 'R') OK = R();
            }
        }
        getchar();
        getchar();
        ++time;
        /*cout << "Puzzle #" << time << ":" << endl;
        if(!OK) cout << "This puzzle has no final configuration." << endl;
        else {
            for(int i = 0; i < 5; ++i) {
                for(int j = 0; j < 5; ++j) cout << puzzle[i][j];
                cout << endl;
            }
        }*/
    }
    return 0;
}

/*idea：yun
input整個圖的時候先把空白的位置記得
在做指令的時候"做一個指令換一次位置"並且隨時更新空白的位置
這樣就可以了
*/
