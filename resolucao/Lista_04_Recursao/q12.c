#include <stdio.h>

int mdc(int x, int y){
    if(x == 0 && y == 0){
        return 0;
    }
    if(y == 0){
        return x;
    }
    return mdc(y, x%y);
}

int main(){
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d\n", mdc(x, y));
}