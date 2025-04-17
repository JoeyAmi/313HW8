#include <stdio.h>
#include <stdlib.h>


void add(int rows, int cols, const int m1[rows][cols], const int m2[rows][cols], int result[rows][cols]){    
    if(rows != cols){
    }else{
        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                result[i][j] = m1[i][j] + m2[i][j];
            }
        }
    }

}

void scale(int rows, int cols, int scaler, int matrix[rows][cols], int result[rows][cols]){
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            result[i][j] = scaler * matrix[i][j];
        }
    }
}

void transpose(int rows, int cols, int original[rows][cols], int result[cols][rows]){
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            result[j][i] = original[i][j];
        }
    }    
}

void mulitply(int row1, int col1, int col2, int m1[row1][col1], int m2[col1][col2], int result[row1][col2]){
    for(int i = 0; i<row1; i++){ // Repeats procedure for each row of left matrix
        for(int j = 0; j < col1; j++){  // Repeats for each col of left matrix
            for(int k = 0; k<col2; k++){ // Multiplies by # of col of right matrix
                result[i][k] += m1[i][j] * m2[j][k];
            }
        }
    }
}




void printMatrix(int rows, int cols, int matrix[rows][cols]){
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n"); 
    }
}


int main(){
    // A + (3*B) * C_transpose
    int A[2][2]= { 
        {6, 4},
        {8, 3}
    };
    int B[2][3]= { 
        {1, 2, 3},
        {4, 5, 6}
    };
    int C[2][3] = {
        {2, 4, 6},
        {1, 3, 5}
    };
    int scaleB[2][3] = {0};
    int transpose_C[3][2] = {0};
    int multiBC[2][2] = {0};
    int D[2][2];
    scale(2,3,3, B, scaleB);
    transpose(2,3,C,transpose_C);
    mulitply(2,3,2,scaleB,transpose_C,multiBC);
    add(2,2,A,(multiBC),D);
    printMatrix(2,2,D);


    return 0;
}