class Solution {
public:    

    
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        
        // possible cases where we can capture queen in 1 move 

        
        if(a==e){ // rook is in same row as queen
            if(a!=c) return 1; //bishop is not in same row
            if(!(b<d && d<f) && !(f<d && d<b)) return 1; // bishop is in same row but not in between rook and queen
        }

        if(b==f){// rook is in same col as queen
            if(b!=d) return 1;  //bishop is not in same column
            if(!(a<c && c<e) && !(e<c && c<a)) return 1; //bishop is in same column but not in between rook and queen
        }

        if(c+d==e+f){ // bishop is in same main-diagonal as queen
            if(c+d!=a+b) return 1; //rook is not in same main-diagonal
            if(!(c<a && a<e) && !(e<a && a<c)) return 1; //rook is in same main-diagonal but not in between bishop and queen
        }

        if(c-d==e-f){ // // bishop is in same anti-diagonal as queen
            if(c-d!=a-b) return 1; //rook is not in same anti-diagonal
            if(!(c<a && a<e) && !(e<a && a<c)) return 1;//rook is in same anti-diagonal but not in between bishop and queen
        }

        // Edge Case 1 = if bishop is in between rook and queen we can remove bishop in
        // one step and capture queen using rook in 2nd step
        // Edge Case 2 = if rook is in same diagonal as of queen and bishop 
        // we can remove rook in one step and capture queen using bishop in 2nd step
        
        // rest in all cases we need 2 moves
        return 2;
        
    }
};