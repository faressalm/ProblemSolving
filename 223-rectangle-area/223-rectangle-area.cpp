class Solution {
private: int recArea(int ax1, int ay1,int ax2, int ay2){
    return (ax2-ax1)*(ay2-ay1);
}
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = recArea(ax1,ay1,ax2,ay2);
        int area2 = recArea(bx1,by1,bx2,by2);
        int area = area1+area2;
        if(bx1>=ax2||ax1>=bx2||by2<=ay1||ay2<=by1)
            return area;
        int intersectArea = recArea(max(bx1,ax1),max(ay1,by1),min(ax2,bx2),min(by2,ay2));
        return area - intersectArea;    
    }
};