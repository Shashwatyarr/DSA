class Solution {
    public boolean checkOverlap(int r, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x_c=xCenter;
        if(x_c>=x1&&x_c<=x2) x_c=xCenter;
        else if(x_c<x1) x_c=x1;
        else x_c=x2;
        int y_c=yCenter;
        if(y_c>=y1&&y_c<=y2) y_c=yCenter;
        else if(y_c<y1) y_c=y1;
        else y_c=y2;
        int dist=(int)Math.pow((xCenter-x_c),2)+(int)Math.pow((yCenter-y_c),2);
        System.out.println(dist);
        if(r*r>=dist) return true;
        return false;
    }
}