#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

int main(){

    while(1){
        int64_t add=0,product=0,n=0;
        int64_t cnt=0;
        int64_t array[1000][2];

        scanf("%lld%lld",&add,&product);
        if( (add==0) && (product==0) )return 0;
        scanf("%lld",&n);
        for( int i=1 ; i<=sqrt(product) ; ++i){
            if( product%i==0 ){
                array[cnt][0]=i;
                array[cnt][1]=product/i;
                cnt++;
            }
        }
        int count=0;
        
        for( count=0 ; count<1000 ; ++count){
            if( array[count][0]+array[count][1]==add )break;
        }

        int64_t a=array[count][0],b=array[count][1];
        int64_t ans=0;

        for(int u=1 ; u<n ; ++u){
            a*=array[count][0];
            b*=array[count][1];
        }
        ans=a+b;
        printf("%lld\n",ans);
    }
    return 0;
}