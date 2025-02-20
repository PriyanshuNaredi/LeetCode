class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int col0 = 1;


        // mark the presence of 0 in the matrix
        // using row[0] and col[0] as the tracked
        for(int i =0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0; // mark the ith row
                    // mark the jth col
                    if(j!=0)
                        matrix[0][j] = 0;
                    else
                        col0 = 0;
                }
            }
        }


        for(int i=1; i<n; i++){
            for(int j = 1; j<m; j++){
                if(matrix[i][j] != 0){
                    // check in row or col of tracked 
                    if( matrix[0][j] == 0 || matrix[i][0] == 0 ){
                        matrix[i][j] = 0;
                    }
                }
            }
        }


        if( matrix[0][0] == 0 ){
            for(int j=0; j<m; j++){
                matrix[0][j] = 0;
            }
        }

        if(col0 == 0){
            for(int i=0; i<n; i++){
                matrix[i][0] = 0;
            }
        }


        // return matrix;

    }
};