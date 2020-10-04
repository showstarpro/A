#include<stdio.h>

int main(){
    int a;
    float b;
    int C[5];
    scanf("%d", &a);
    scanf("%f", &b);
    for (int i = 0; i < 2;++i){
        if(i==0){
            C[i] = a;
        }
        else
            C[i] = b;
    }
    printf("%d %d", C[0], C[1]);
}