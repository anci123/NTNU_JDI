//UVA:
//g++ -std=c++14

#include <bits/stdc++.h>
using namespace std;

int AM[20][20];

int dijkstra(int start, int end) {
    int INF = 1e9;
    int MAX = 20;
    bool visit[20];
    int dist[20];
    for(int i = 0; i < MAX; ++i) {
        visit[i] = false;
        dist[i] = INF;
    }
    dist[start] = 0;
    for(int i = 0; i < MAX; ++i) {
        int mini_dist = INF, mini_node = -1;
        for(int j = 0; j < MAX; ++j) {
            if (!visit[j] && dist[j] < mini_dist) {
                mini_node = j;
                mini_dist = dist[j];
            }
        }
        if(mini_node == -1) break;
        visit[mini_node] = true;
        for(int j = 0; j < MAX; ++j) {
            if(!visit[j] && AM[mini_node][j] != 0 && dist[j] > dist[mini_node] + AM[mini_node][j])
                dist[j] = AM[mini_node][j] + dist[mini_node];
        }
    }
    return dist[end];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cnt = 0;
    int c;
    while(cin >> c){
        cnt++;
        if(cnt > 1) 
            cout << "\n";
        memset(AM, 0, sizeof(AM));
        for(int i = 0; i < 19; ++i){
            if(i) cin >> c;
            int tmp;
            for(int j = 0; j < c; ++j){
                cin >> tmp;
                AM[i][tmp-1] = 1;
                AM[tmp-1][i] = 1;
            }
        }

        int testcase;
        cin >> testcase;
        cout << "Test Set #" << cnt << ":\n";
        while(testcase-- && testcase >= 0){
            int start, end;
            cin >> start >> end;
            cout << setw(2) << start << " to " << setw(2) << end << ": " << dijkstra(start - 1, end - 1) << "\n";
        }
    }
}

/*

1 3
2 3 4
3 4 5 6
1 6
1 7
2 12 13
1 8
2 9 10
1 11
1 11
2 12 17
1 14
2 14 15
2 15 16
1 16
1 19
2 18 19
1 20
1 20
5
1 20
2 9
19 5
18 19
16 20

*/