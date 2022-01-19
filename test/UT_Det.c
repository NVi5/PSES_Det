/**
    @file UT_Det.c
    @brief Unit tests for Default Error Tracer
*/

#include "acutest.h"
#include "fff.h"
#include "Std_Types.h"

#include "Det.c" /* This is not a mistake - static variebles are exposed for tests */

DEFINE_FFF_GLOBALS

FAKE_VALUE_FUNC(Std_ReturnType, MyErrorHook, uint16, uint8, uint8, uint8)
FAKE_VALUE_FUNC(Std_ReturnType, MyErrorHook2, uint16, uint8, uint8, uint8)
FAKE_VALUE_FUNC(Std_ReturnType, MyRuntimeErrorCallout, uint16, uint8, uint8, uint8)
FAKE_VALUE_FUNC(Std_ReturnType, MyRuntimeErrorCallout2, uint16, uint8, uint8, uint8)
FAKE_VALUE_FUNC(Std_ReturnType, MyTransientFaultCallout, uint16, uint8, uint8, uint8)
FAKE_VALUE_FUNC(Std_ReturnType, MyTransientFaultCallout2, uint16, uint8, uint8, uint8)
FAKE_VOID_FUNC(ProgramHalt)

/**
    @brief Test of Det_Init implementation
*/
void Test_Of_Det_Init(void)
{
    const Det_ConfigType Det_Config;
    Det_Init(&Det_Config);
    TEST_CHECK(det_cfg.isInitialized == TRUE);
}

/**
    @brief Test of Det_Start implementation
*/
void Test_Of_Det_Start(void)
{
    Det_Start();
}

/**
    @brief Test of Det_ReportError implementation
*/
void Test_Of_Det_ReportError(void)
{
    Std_ReturnType returnValue = E_NOT_OK;

    returnValue = Det_ReportError(0, 0, 0, 0);
    TEST_CHECK(MyErrorHook_fake.call_count == 0);
    TEST_CHECK(MyErrorHook_fake.call_count == 0);
    TEST_CHECK(ProgramHalt_fake.call_count == 1);

    const Det_ConfigType Det_Config;
    Det_Init(&Det_Config);
    returnValue = Det_ReportError(0, 0, 0, 0);
    TEST_CHECK(MyErrorHook_fake.call_count == 1);
    TEST_CHECK(MyErrorHook_fake.call_count == 1);
    TEST_CHECK(ProgramHalt_fake.call_count == 2);
    (void)returnValue;
}

/**
    @brief Test of Det_ReportRuntimeError implementation
*/
void Test_Of_Det_ReportRuntimeError(void)
{
    Std_ReturnType returnValue = E_NOT_OK;
    returnValue = Det_ReportRuntimeError(0, 0, 0, 0);
    TEST_CHECK(returnValue == E_OK);
    TEST_CHECK(MyRuntimeErrorCallout_fake.call_count == 0);
    TEST_CHECK(MyRuntimeErrorCallout2_fake.call_count == 0);

    returnValue = E_NOT_OK;
    const Det_ConfigType Det_Config;
    Det_Init(&Det_Config);
    returnValue = Det_ReportRuntimeError(0, 0, 0, 0);
    TEST_CHECK(returnValue == E_OK);
    TEST_CHECK(MyRuntimeErrorCallout_fake.call_count == 1);
    TEST_CHECK(MyRuntimeErrorCallout2_fake.call_count == 1);
}

/**
    @brief Test of Det_ReportTransientFault implementation
*/
void Test_Of_Det_ReportTransientFault(void)
{
    Std_ReturnType returnValue = E_NOT_OK;
    returnValue = Det_ReportTransientFault(0, 0, 0, 0);
    TEST_CHECK(returnValue == E_OK);
    TEST_CHECK(MyTransientFaultCallout_fake.call_count == 0);
    TEST_CHECK(MyTransientFaultCallout2_fake.call_count == 0);

    returnValue = E_NOT_OK;
    const Det_ConfigType Det_Config;
    Det_Init(&Det_Config);
    returnValue = Det_ReportTransientFault(0, 0, 0, 0);
    TEST_CHECK(returnValue == E_OK);
    TEST_CHECK(MyTransientFaultCallout_fake.call_count == 1);
    TEST_CHECK(MyTransientFaultCallout2_fake.call_count == 1);
}

/**
    @brief Test of Det_GetVersionInfo implementation
*/
void Test_Of_Det_GetVersionInfo(void)
{
    Det_GetVersionInfo(NULL);
    TEST_CHECK(ProgramHalt_fake.call_count == 1);

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
/*  { "Test name",                  Test_Of_<Function Name>          }, */
    { "Det_Init",                   Test_Of_Det_Init                 },
    { "Det_Start",                  Test_Of_Det_Start                },
    { "Det_ReportError",            Test_Of_Det_ReportError          },
    { "Det_ReportRuntimeError",     Test_Of_Det_ReportRuntimeError   },
    { "Det_ReportTransientFault",   Test_Of_Det_ReportTransientFault },
    { "Det_GetVersionInfo",         Test_Of_Det_GetVersionInfo       },
    { NULL, NULL } /* Required at the end */
};
