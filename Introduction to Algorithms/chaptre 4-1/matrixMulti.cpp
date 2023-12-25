#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrixMultiBruteForce(vector<vector<int>> A, vector<vector<int>> B){
    vector<vector<int>> C;
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < A.size(); j++){
            int element = 0;
            for(int k = 0; k < A[j].size(); k++){
                element+= A[i][k] * B[k][j];
            }
            cout << element << endl;
        }
    }

    return C; 
}

int main(){
   vector<vector<int>> A = {
    {1, 2}, 
    {3, 4}
   }; 
   vector<vector<int>> B = {
    {5, 6}, 
    {7, 8}
   }; 

    matrixMultiBruteForce(A, B);

}