/**
    @file Det.c
    @brief Implementation of Default Error Tracer
*/

#include "Det.h"
#include "Det_Externals.h"

typedef struct {
    boolean isInitialized;
    Det_ErrorHook_t errorHooks[DET_NUMBER_OF_USER_ERROR_HOOKS];
    Det_RuntimeErrorCallout_t runtimeErrorHooks[DET_NUMBER_OF_RUNTIME_ERROR_CALLOUTS];
    Det_TransientFaultCallout_t transientFaultHooks[DET_NUMBER_OF_TRANSIENT_FAULT_CALLOUTS];
} DetCfg;

DetCfg det_cfg = {
    .isInitialized = FALSE,
    .errorHooks = {MyErrorHook, MyErrorHook2},
    .runtimeErrorHooks = {MyRuntimeErrorCallout, MyRuntimeErrorCallout2},
    .transientFaultHooks = {MyTransientFaultCallout, MyTransientFaultCallout2},
};

#define Det_GetCfg() (&det_cfg)
#define ARRAY_DIM(x) (sizeof((x)) / sizeof((x)[0]))

void Det_Init(const Det_ConfigType* ConfigPtr) {

    DetCfg *cfg = Det_GetCfg();

    (void)ConfigPtr;
    cfg->isInitialized = TRUE;
}

Std_ReturnType Det_ReportError(uint16 ModuleID, uint8 InstanceID, uint8 ApiId, uint8 ErrorId) {

    DetCfg *cfg = Det_GetCfg();

    if (cfg->isInitialized) {
        for (uint8 i = 0; i < ARRAY_DIM(cfg->errorHooks); i++) {
            (void)cfg->errorHooks[i](ModuleID, InstanceID, ApiId, ErrorId);
        }
    }

    exit(-1);
    return E_OK;
}

void Det_Start (void) {

}

Std_ReturnType Det_ReportRuntimeError(uint16 ModuleID, uint8 InstanceID, uint8 ApiId, uint8 ErrorId) {

    DetCfg *cfg = Det_GetCfg();

    if (cfg->isInitialized) {
        for (uint8 i = 0; i < ARRAY_DIM(cfg->runtimeErrorHooks); i++) {
            (void)cfg->runtimeErrorHooks[i](ModuleID, InstanceID, ApiId, ErrorId);
        }
    }

    return E_OK;
}

Std_ReturnType Det_ReportTransientFault(uint16 ModuleID, uint8 InstanceID, uint8 ApiId, uint8 ErrorId) {

    DetCfg *cfg = Det_GetCfg();
    uint8 result = E_OK;

    if (cfg->isInitialized) {
        for (uint8 i = 0; i < ARRAY_DIM(cfg->transientFaultHooks); i++) {
            result += cfg->transientFaultHooks[i](ModuleID, InstanceID, ApiId, ErrorId);
        }
    }

    return result != E_OK ? E_NOT_OK : E_OK;
}

void Det_GetVersionInfo(Std_VersionInfoType* versioninfo) {

    if (NULL == versioninfo) {
        /**
         * @req [SWS_Det_00301], [SWS_Det_00052]
         * Det_GetVersionInfo called with null parameterpointer
         */
        Det_ReportError(DET_MODULE_ID, 0, 3, DET_E_PARAM_POINTER);
    }
    else {
        versioninfo->vendorID = DET_MODULE_ID;
        versioninfo->moduleID = DET_VENDOR_ID;
        versioninfo->sw_major_version = DET_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = DET_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = DET_SW_PATCH_VERSION;
    }
}
