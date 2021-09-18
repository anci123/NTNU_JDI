//UVA:
//g++ -std=c++14

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    while(cin >> n >> k && n){
        if(!n && !k) break;
        vector<int> survive;
        for(int i = 0; i < n; ++i)
            survive.push_back(true);
        int Josephus = 0; 
        int Pos = -1;
        for(int i = 0; i < n - 1; ++i){
            int deathCD = k;
            while(deathCD){
                Pos = (Pos + 1 + n) % n;
                if(survive[Pos]) --deathCD;
            }
            int DeathPos = Pos + 1;
            while(!survive[DeathPos])
                DeathPos = (DeathPos + 1 + n) % n;
            deathCD = k - 1;
            while(deathCD){
                DeathPos = (DeathPos + 1 + n) % n;
                if(survive[DeathPos]) --deathCD;
            }
            if(Pos == Josephus) Josephus = DeathPos;
            survive[DeathPos] = false;
            cout << Pos << "<=" << DeathPos << ", ";
            while(!survive[Pos])
                Pos = (Pos + 1 + n) % n;
        }
        cout << Josephus << " " << n - Josephus + 1 << "\n";
        
    }
}