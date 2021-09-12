#include <stdio.h>

int main() {
    int i, j, k, test = 0;
    int n;
    while(scanf("%d", &n) == 1) {
        int AM[21][21] = {};
        for(i = 1; i <= 19; i++) {
            if(i != 1)
                scanf("%d", &n);
            while(n--) {
                scanf("%d", &k);
                AM[i][k] = 1;
                AM[k][i] = 1;
            }
        }
        for(k = 1; k <= 20; k++) {
            for(i = 1; i <= 20; i++) {
                for(j = 1; j <= 20; j++) {
                    if(AM[i][j] == 0 || AM[i][j] > AM[i][k]+AM[k][j]) {
                        if(AM[i][k] && AM[k][j])
                            AM[i][j] = AM[i][k] + AM[k][j];
                    }
                }
            }
        }
        scanf("%d", &n);
        printf("Test Set #%d\n", ++test);
        while(n--) {
            scanf("%d %d", &i, &j);
            printf("%2d to %2d: %d\n", i, j, AM[i][j]);
        }
        puts("");
    }
    return 0;
}