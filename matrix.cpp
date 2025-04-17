#include <vector>
#include <iostream>
using namespace std;


vector<vector<int>> add(const vector<vector<int>>& m1, const vector<vector<int>>& m2){
    if(m1.empty() || m2.empty()){
        return {};
    }
    int rows = m1.size();
    int col = m1[0].size();
    if(rows > 0 && m1.size() == m2.size()){
        if(m1[0].size() != m2[0].size()){
            return {};
        }else{
            vector<vector<int>> result(rows, vector<int>(col));
            for(int i = 0; i<m1.size(); i++){
                for(int j = 0; j<m1[0].size(); j++){
                    result[i][j] = m1[i][j] + m2[i][j];
                }
            }
            return result;
    }
    }
    return {};
}

vector<vector<int>> scale(const vector<vector<int>>& matrix, int num){
    if(matrix.empty() || matrix[0].empty()){
        return {};
    }
    vector<vector<int>> scaled_matrix(matrix.size(), vector<int>(matrix[0].size()));
    for(int i = 0; i<matrix.size(); i++){
        for(int j = 0; j<matrix[0].size(); j++){
            scaled_matrix[i][j] = num*matrix[i][j];
        }
    }
    return scaled_matrix;

}

vector<vector<int>> transpose(const vector<vector<int>>& matrix){
    if(matrix.empty() || matrix[0].empty()){
        return {};
    }
    vector<vector<int>> transpose_matrix(matrix[0].size(), vector<int>(matrix.size()));
    for(int i = 0; i<matrix.size(); i++){
        for(int j = 0; j<matrix[0].size(); j++){
            transpose_matrix[j][i] = matrix[i][j];
        }
    }
    return transpose_matrix;
}

vector<vector<int>> multiply(const vector<vector<int>>& m1, const vector<vector<int>>& m2){
    if(m1.empty() || m2.empty()){
        return {};
    }else if(m1[0].empty() || m2[0].empty()){
        return {};
    }else if(m1[0].size() != m2.size()){
        return {};
    }
    vector<vector<int>> result(m1.size(), vector<int>(m2[0].size()));

    for(int i = 0; i< m1.size(); i++){ // Repeats procedure for each row of left matrix
        for(int j = 0; j < m1[0].size(); j++){  // Repeats for each col of left matrix
            for(int k = 0; k< m2[0].size(); k++){ // Multiplies by # of col of right matrix
                result[i][k] += m1[i][j] * m2[j][k];
            }
        }
    }
    return result;

}


void printMatrix(const vector<vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    for (int i = 0; i<row; i++) {
        for (int k = 0; k<col; k++) {
            cout << matrix[i][k] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}






int main(){
    vector<vector<int>> A = {
        {6, 4},
        {8, 3}
    };

    vector<vector<int>> B = {
        {1, 2, 3},
        {4, 5, 6}
    };
    vector<vector<int>> C = {
        {2, 4, 6},
        {1, 3, 5}
    };

    vector<vector<int>> D = {};
    D = add(A, (multiply(scale(B,3), transpose(C))));
    printMatrix(D);
    return 0;

}
