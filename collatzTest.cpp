
#include <iostream>
#include "collatz.h"
using std::cout;



int main() {

    int retval = 0;
    
    {
        long testCol=6;
        int upper=9;
       
        cout << "Testing Collatz with 6 \n";
        collatz myCol(testCol,upper);
        
        
        if (myCol.ReturnNumOfSteps() == 8) {
            cout << "1) Pass: Correctly got to the number of possible solutions\n";
        } else {
            cout << "1) Fail: Should have returned 8, but received got " << myCol.ReturnNumOfSteps() << std::endl;
            ++retval;
        }
        
        vector<pair<int,int>> ComplexVec= myCol.ReturnAllUpperBounds();
        //please continue to write code that checks all returned pairs. This code only checks the last pair of number 9
        //with 19 steps

        if(ComplexVec.size() == 9)
        {
            if((ComplexVec[ComplexVec.size()-1].first == 9) &&(ComplexVec[ComplexVec.size()-1].second == 19))
                {
                    cout<< "2) Pass: Correctly calculated steps for upper bound \n";
                    
                }
            else{
                    cout<<"2) Fail: Should have returned 19 steps for 9, but received "<<ComplexVec[ComplexVec.size()-1].second<<std::endl;
                }
        }
    }
    
    
    
    return retval;
}

