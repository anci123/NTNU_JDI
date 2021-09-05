#include<bits/stdc++.h>
using namespace std;
int main() {
    int num=0;
    while(1) {
        cin>>num;
        if(!num) break;
        int low=1, high=10;
        string discrip;
        while(cin>> discrip >>discrip && discrip != "on") {
            if(discrip == "high") high = min(high, num-1);
            else if(discrip == "low") low = max(low, num+1);
            cin >> num;
        }
        if(num >= low && num <= high) cout << "Stan may be honest" << endl;
        else cout << "Stan is dishonest" << endl;
        continue;
    }
    return 0;
}