class Solution {
private: void temp(int r1,int r2,int c1, int c2, vector<int> &spiral,vector<vector<int>>& matrix){
    for(int c=c1;c<c2;c++)
        spiral.push_back(matrix[r1][c]);
    for(int r=r1+1;r<r2&&(c1<c2);r++)
        spiral.push_back(matrix[r][c2-1]);
    for(int c=c2-2;c>=c1&&(r1+1<r2)&&(c1<c2);c--)
        spiral.push_back(matrix[r2-1][c]);
    for(int r=r2-2;r>r1&&(c2-2>=c1)&&(r1+1<r2)&&(c1<c2);r--)
        spiral.push_back(matrix[r][c1]);
}
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        bool changeCol = true;
        int r1=0;int r2=matrix.size();
        int c1=0;int c2=matrix[0].size();
        vector<int> spiral;
        int spiralsLen = min(ceil(double(r2)/2),ceil(double(c2)/2));
        for(int i=0;i<spiralsLen;i++){
            temp(r1+i,r2-i,c1+i,c2-i,spiral,matrix);
        }
        return spiral;
    }
};