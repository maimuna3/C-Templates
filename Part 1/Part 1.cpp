
//  Part 1 main
//  Created by Tani Matankari on 5/05/2015.
//  mtm1g14@soton.ac.uk
// compiled online using http://cpp.sh
//

#include "Part 1.h"
int main(int argc, const char * argv[]){
    
    //expression for x+(x-2)*(x-3)
    typedef ADD<X, MULTIPLY<SUB<X, LIT<2>>,SUB<X, LIT<3>>>>expr;
    //-----------------
    
    //OTHER EXPRESSIONS TO TEST
    
    //expression for  (x+3)*(x+5)
    //typedef MULTIPLY<ADD<X,LIT<3>>,ADD<X,LIT<5>>> expr;
    
    //expression for x/0
    //typedef DIVIDE<X,LIT<0>>expr;
    
    //expression for x-2
    //typedef SUB<X, LIT<2> > expr;
    
    //expression for -10/x
    //typedef DIVIDE<LIT<-10>,X>expr;
    
    
    
    expr x;
    try {
        printf("The expression equals %d\n", x.eval(3));
    }
    catch(std::invalid_argument e)
    {
        printf("%s\n", e.what());
    }
    return 0;
}




