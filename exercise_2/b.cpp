//UVA: 1019
//g++ -std=c++14

#include<bits/stdc++.h>
using namespace std;
int main() {
    string offset;
    int h1, h2, m1, m2;
    int n,t=0;
    while(cin >> n) {
        ++t;
        vector<pair<int, int>> p;
        pair<int,int> max(0,0);
        map<int, int> time;
        for(int i = 0; i < n; ++i) {
            scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
            getline(cin, offset);
            if(h1 >= 10 && (h2 * 60 + m2) <= 18 * 60)p.push_back({h1 * 60 + m1, h2 * 60 + m2});
        }
        sort(p.begin(), p.end());
        int pre=10*60,end=18*60,nxt=0;
        for(int i = 0; i < p.size(); ++i) {
            nxt=p[i].first;
            if((nxt-pre)>max.second){
                max.second=nxt-pre;
                max.first=pre;
            }
            pre=p[i].second;
        }
        if(pre<18*60){
            if((end-pre)>max.second){
                max.second=end-pre;
                max.first=pre;
            }
        }
        cout<<"Day #"<<t<<": the longest nap starts at "<<max.first/60<<":"<<setw(2)<<setfill('0')<<max.first%60<<" and will last for ";
        if(max.second/60) cout<<max.second/60<<" hours and "<<max.second%60<<" minutes."<<endl;
        else cout<<max.second<<" minutes."<<endl;
    }
    return 0;
}