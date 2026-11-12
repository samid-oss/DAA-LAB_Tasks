#include <stdio.h>
#include <stdlib.h>

int x[20],n;

int place(int k,int i) {
    int j;
    for(j=1;j<k;j++)
        if(x[j]==i || abs(x[j]-i)==abs(j-k))
            return 0;
    return 1;
}

void nqueen(int k) {
    int i,j;

    for(i=1;i<=n;i++) {
        if(place(k,i)) {
            x[k]=i;

            if(k==n) {
                for(j=1;j<=n;j++)
                    printf("%d ",x[j]);
                printf("\n");
            } else {
                nqueen(k+1);
            }
        }
    }
}

int main() {
    scanf("%d",&n);
    nqueen(1);
    return 0;
}
