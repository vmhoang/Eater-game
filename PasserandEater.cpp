/*********** Declaration******* I hereby certify that no part of this assignment has been copied from any other student’s work or from any other source. 
 *  No part of the code has been written/produced for me by another person or copied from any other source. 
 * I hold a copy of this assignment that I can produce if the original is lost or damaged. **************************/ 
#include <stdio.h>      
#include <stdlib.h>     
#include <iomanip>
#include <iostream>
#include <string>
#include <time.h>
using namespace std;
#include "Task3_4.h"
//#include "Task5.h"

int main(){
    Board d;
    srand(time (0));
    d.play();
    d.~Board();
}