//UVA: 11541
#include <stdio.h>
#include <string.h>

int main(){
	int T=0;
	int cnt=0;
	char alpha=0;
	char buffer[1024]={0};
	scanf("%d",&T);
	fgets(buffer,1023,stdin);
	for(int i=1 ; i<=T ; ++i){
		cnt=0;
		fgets(buffer,1023,stdin);
		printf("Case %d: ",i);
		for(int y=0 ; y<strlen(buffer) ; ++y){
			if(buffer[y]>='A' && buffer[y]<='Z'){
				while(cnt--){
					printf("%c",alpha);
				}
				alpha=buffer[y];
				cnt=0;
			}
			else if(buffer[y]>='0' && buffer[y]<='9'){
				cnt=cnt*10+(buffer[y]-'0');
			}
		}
//		printf("%c\n",alpha);
//		printf("%d\n",cnt);
		while(cnt--){
					printf("%c",alpha);
		}
		printf("\n");
	}
	return 0;
}