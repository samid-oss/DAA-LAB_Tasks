#include <stdio.h>

int Knapsack(int W, int weights[], int values[], int n) {
    int i, w;
    int k[n + 1][W + 1];

    for(i=0;i<=n;i++){
        for(w=0;w<=W;w++){
            if(i==0 || w==0)
                k[i][w] = 0;
            else if(weights[i-1]<=w)
            k[i][w]= (values[i-1]+k[i-1][w-weights[i-1]]>k[i-1][w])?(values[i-1]+k[i-1][w-weights[i-1]]):k[i-1][w];
            else
                k[i][w]=k[i-1][w];

        }
    }

    return k[n][W];
}

int main(){
    int n, w, i;
    printf("Enter number of items:");
    scanf("%d",&n);
    int weights [n], values[n];
    printf("Enter weights and values:");
    for(i=0;i<n;i++){
        scanf("%d %d",&weights[i],&values[i]);
    }
    printf("Enter maximum weight:");
    scanf("%d",&w);
    printf("Maximum value: %d",Knapsack(w, weights, values, n));
    return 0;
}
