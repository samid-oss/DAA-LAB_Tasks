#include<stdio.h>
//Method 1: Using Recursion
// int GeoSum(int a, int r, int n) {
//     if (n == 1) {
//         return a;
//     }
//     return a + GeoSum(a * r, r, n - 1);
// }

//Method 2: Using Formula
// int GeoSum(int a, int r, int n) {
//     return a * (1 - pow(r, n)) / (1 - r);
// }

//Method 3: Using Loop
// int GeoSum(int a,int r,int n){
//     int sum=0;
//     for(int i=0;i<n;i++){
//         sum+=a*pow(r,i);
//     }
//     return sum;
// }

//Method 4: Using Loop (Optimized)
long long GeoSum(long long a,long long r,int n){
    long long sum=0;
    for(int i=0;i<n;i++){
        sum+=a;
        a*=r;
    }
    return sum;
}

int main() {
    long long a, r;
    int n;
    printf("Enter the first term: ");
    scanf("%lld", &a);
    printf("Enter the common ratio: ");
    scanf("%lld", &r);
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    long long sum = GeoSum(a, r, n);
    printf("The sum of the geometric series is: %lld\n", sum);

    return 0;
}

