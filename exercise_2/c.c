//UVA:686
//g++ -std=c++14

#include <stdio.h>

int isprime(int i){
    for(int cnt=2 ; cnt<=i/2 ; ++cnt){
        if(i%cnt==0)return 0;
    }
    return 1;
}

int main(){
    int testcase=0;
    int prime[20000]={0};
    int a=0;
    int ans=0;

    for(int m=2 ; m<32768 ; ++m){
            if( isprime(m) ){
                prime[a]=m;
                ++a;
            }
        } 

    while( (scanf("%d",&testcase) != EOF) && (testcase!=0) ){
        ans=0;
        for(int m=0 ; prime[m]<=testcase/2 ; ++m){
             if(isprime(testcase-prime[m]))ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}