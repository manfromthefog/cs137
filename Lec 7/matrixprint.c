void matrixprint(int n, int m, int mat[][m]){
    for (int i = 0; i<n ;i++) {
        for (int j = 0; j < m-1; j++){
            printf("%d ", mat[i][j]);
        }
        printf("%d\n", mat[i][m-1]);
    }
}
int main(void){
    int mat[4][5] = {
        {1,2,3,4,5}, 
        {2,3,4,5,6},
        {3,4,5,6,7}, 
        {4,5,6,7,8},
    };
    matrixprint( 4, 5, mat);
}