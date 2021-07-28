#include <bits/stdc++.h>
using namespace std;

constexpr bool DEBUG = false;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cnt;
    cin >> cnt;
    for(int c = 1; c <= cnt; ++c){
        long long v[10001];
        char Garbage, Garbage2;
        int N;
        cin >> Garbage >> Garbage2 >> N;
        bool isLegel = true;

        int Ns = N*N;
        for(int i = 0; i < Ns; ++i){
            cin >> v[i];
            if(v[i] < 0) isLegel = false;
        }

        int Mid = (Ns+1)/2;
        if(isLegel){
            for(int i = 0; i < Mid; ++i){
                if(v[i] != v[Ns-i-1]){
                    isLegel = false;
                    break;
                }
            }
        }
        cout << "Test #" << c << ": "
             << (isLegel?"Symmetric.":"Non-symmetric.") << '\n';
    }
}
