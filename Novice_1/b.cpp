#include<bits/stdc++.h>
using namespace std;

int main(){
    string table = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    char array[100]={0};
    char ans[100]={0};

    int lenth=0;
    fgets(array,99,stdin);
    array[strlen(array)-1]=0;
    lenth=strlen(array);
 
    for(int i=0 ; i<lenth ; ++i){
        if( array[i]>='A' && array[i]<='Z' ) array[i]+=32;
    }

    for(int i=0 ; i<lenth ; ++i){
        if(array[i]==' ')printf(" ");
        else {
                char tmp=array[i];
                int here=table.find(tmp);
                ans[i]=table[here-2];
                printf("%c",ans[i]);
        }
    }
    printf("\n");
    return 0;
}