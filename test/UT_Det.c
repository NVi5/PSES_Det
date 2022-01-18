/**
    @file UT_Det.c
    @brief Unit tests for Default Error Tracer
*/

#include "acutest.h"
#include "Std_Types.h"

#include "Det.c" /* This is not a mistake - static variebles are exposed for tests */

/**
    @brief Test of Det_Init implementation
*/
void Test_Of_Det_Init(void)
{

}

/**
    @brief List of tests to be performed
*/
TEST_LIST = {
/*  { "Test name", Test_Of_<Function Name>         }, */
    { "Test of Test_Of_Det_Init", Test_Of_Det_Init },
    { NULL, NULL } /* Required at the end */
};
