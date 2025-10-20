#include "fogo.h"

void tocar_fogo(int rows, int columns, char mat[rows][columns], int l, int c) {
    if(l < 0 || l >= rows || c < 0 || c >= columns){
        return;
    }
    if(mat[l][c] == '#'){
        mat[l][c] = 'o';
        tocar_fogo(rows, columns, mat, l-1, c);
        tocar_fogo(rows, columns, mat, l+1, c);
        tocar_fogo(rows, columns, mat, l, c-1);
        tocar_fogo(rows, columns, mat, l, c+1);
    }
}