


//  Part 2 main
//  Created by Tani Matankari on 10/05/2015.
//  mtm1g14@soton.ac.uk
// compiled online using http://cpp.sh
//

#include "Part 2.h"

int main() {


    //expression for (x+3)*(x+5)
    typedef MULTIPLY<ADD<X <BOUNDS<0, 5>>, LIT<3> >, ADD<X<BOUNDS<0, 5>>, LIT<5>>>expr;
    
    //-----------------
    
    //OTHER EXPRESSIONS TO TEST

    //expression for x+(x-2)*(x-3)
    //typedef ADD<X<BOUNDS<2,9>>, MULTIPLY<SUB<X<BOUNDS<2,9>>, LIT<2>>,SUB<X<BOUNDS<2,9>>, LIT<3>>>>expr;
    
    //expression for x+2
   //typedef ADD<X<BOUNDS<0,5>>,LIT<2>>expr;
    
    //expression for x*(-3) --the multiplication of negative values cause the lower bound to be higher but the bounds are then swaped.
     //typedef MULTIPLY<X<BOUNDS<-2,5>>,LIT<-3>>expr;
    
    //expression for -10/x
    //typedef DIVIDE<LIT<-10>,X<BOUNDS<3,5>>>expr;
    
    //expression for x/0 ---for division by zero
    //typedef DIVIDE<X<BOUNDS<3,5>>,LIT<0>>expr;
    
    //expression for x+(x-5)/(x-3)
    //typedef ADD<X<BOUNDS<-4,0>>,DIVIDE<SUB<X<BOUNDS<-4,0>>, LIT<8>>,SUB<X<BOUNDS<-4,0>>, LIT<3>>>>expr;

    expr res;
    
    
    
    try{
        //print the value of the expression
        printf("The result of the expression is %d\n", res.eval(4));
        
        //print the lower bound of the expression
        printf("The lower bound of the expression is %d\n", res.LOWER);
        
        //print the upper bound of the expression
        printf("The upper bound of the expression is %d\n", res.UPPER);
        
    }
    catch (std::invalid_argument e)
    {
        printf("%s\n", e.what());
    }
    return 0;
};

