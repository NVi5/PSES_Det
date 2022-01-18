/**
    @file UT_Det.c
    @brief Unit tests for Default Error Tracer
*/

#include "acutest.h"
#include "fff.h"
#include "Std_Types.h"

#include "Det.c" /* This is not a mistake - static variebles are exposed for tests */

DEFINE_FFF_GLOBALS

/**
    @brief Test of Det_Init implementation
*/
void Test_Of_Det_Init(void)
{

}

/**
    @brief Test of Det_GetVersionInfo implementation
*/
void Test_Of_Det_GetVersionInfo(void)
{
    Std_VersionInfoType VersionInfo;
    Det_GetVersionInfo(&VersionInfo);
    TEST_CHECK(VersionInfo.moduleID == DET_MODULE_ID);
    TEST_CHECK(VersionInfo.vendorID == DET_VENDOR_ID);
    TEST_CHECK(VersionInfo.sw_major_version == DET_SW_MAJOR_VERSION);
    TEST_CHECK(VersionInfo.sw_minor_version == DET_SW_MINOR_VERSION);
    TEST_CHECK(VersionInfo.sw_patch_version == DET_SW_PATCH_VERSION);
}

/**
    @brief List of tests to be performed
*/
TEST_LIST = {
/*  { "Test name", Test_Of_<Function Name>         }, */
    { "Test of Test_Of_Det_Init",           Test_Of_Det_Init },
    { "Test of Test_Of_Det_GetVersionInfo", Test_Of_Det_GetVersionInfo },
    { NULL, NULL } /* Required at the end */
};
