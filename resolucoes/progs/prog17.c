#include <stdio.h>

typedef struct{
    int hp, atq;
} Personagem;

void fight(Personagem *, Personagem *);

int main(){
    Personagem x, y, *pX, *pY;
    pX = &x;
    pY = &y;
    scanf("%d%d%d%d", &x.hp, &x.atq, &y.hp, &y.atq);
    while(pX->hp > 0 && pY->hp >0){
        fight(pX, pY);
    }
    if(pX->hp>pY->hp){
        printf("Personagem 1\n");
    } else if(pY->hp>pX->hp){
        printf("Personagem 2\n");
    } else {
        printf("Empate\n");
    }
}

void fight(Personagem *p1, Personagem *p2){
    p1->hp -= p2->atq;
    p2->hp -= p1->atq;
}