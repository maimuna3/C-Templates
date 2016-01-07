


//  Part 3 main
//  Created by Tani Matankari on 13/05/2015.
//  mtm1g14@soton.ac.uk
// compiled online using http://cpp.sh
//

#include "Part 3.h"

int main()
{
    // expression for x + (y - 2) * (z - 3)
    typedef EXPR<ADD<X<BOUNDS<4,9>>,MULTIPLY<SUB<X<BOUNDS<2,6>>,LIT<2>>,SUB<X<BOUNDS<1,3>>,LIT<3>>>>> expr;
    
    //------------------------
    
    //OTHER EXPRESSIONS TO TEST
    
    //expression for x+(y-2)*(z-3)
    //typedef EXPR<ADD<X<BOUNDS<2,9>>,MULTIPLY<SUB<X<BOUNDS<2,9>>,LIT<2>>,SUB<X<BOUNDS<2,9>>, LIT<3>>>>>expr;
    
   
    int output[4];
    int input[3];
    try
    {
        // solve for when x = 6, y = 3, z = 1
        input[0] = 6;
        input[1] = 3;
        input[2] = 1;
        output[0] = expr::eval(input);
        
        // solve for when x = 4, y = 6, z = 2
        input[0] = 4;
        input[1] = 6;
        input[2] = 2;
        output[1] = expr::eval(input);
        
        // solve for when x = 5, y = 5, z = 3
        input[0] = 5;
        input[1] = 5;
        input[2] = 3;
        output[2] = expr::eval(input);
        
        // solve for when x = 4, y = 6, z = 3
        input[0] = 4;
        input[1] = 6;
        input[2] = 3;
        output[3] = expr::eval(input);
        
        for(int i = 0;i < 4; i++){
            printf("Output[%d]= %d\n",i,output[i]);
        }
        
        
    }
    catch(exception &e)
    {
        cout << e.what() << endl;
    }}