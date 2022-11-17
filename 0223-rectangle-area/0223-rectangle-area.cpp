class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
           int x1 = A >= E ? A : E;
    int x2 = C <= G ? C : G;
    int y1 = D <= H ? D : H;
    int y2 = B >= F ? B : F;
     
    int xx = x2-x1;
    if(xx < 0)
        xx = 0;
    int yy = y1-y2;
    if(yy < 0)
        yy = 0;
    return (D - B)*(C - A)+(H - F)*(G - E)- xx*yy;
    }
};