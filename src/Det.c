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

/**
 * @req [SWS_Det_00018]
 * The Default Error Tracer shall execute the corresponding list of
 * configured DetErrorHook.
 */
static DetCfg det_cfg = {
    .isInitialized = FALSE,
    .errorHooks = {MyErrorHook, MyErrorHook2},
    .runtimeErrorHooks = {MyRuntimeErrorCallout, MyRuntimeErrorCallout2},
    .transientFaultHooks = {MyTransientFaultCallout, MyTransientFaultCallout2},
};

extern void ProgramHalt(void);

#define Det_GetCfg() (&det_cfg)
#define ARRAY_DIM(x) (sizeof((x)) / sizeof((x)[0]))

void Det_Init(const Det_ConfigType* ConfigPtr) {

    DetCfg *cfg = Det_GetCfg();
    (void)ConfigPtr;

    /**
     * @req [SWS_Det_00020]
     * Det_Init set the DefaultError Tracer to a defined initial status.
     */
    cfg->isInitialized = TRUE;
}

Std_ReturnType Det_ReportError(uint16 ModuleID, uint8 InstanceID, uint8 ApiId, uint8 ErrorId) {

    DetCfg *cfg = Det_GetCfg();

    /**
     * @req [SWS_Det_00208]
     * If the Default Error Tracer has not been initialized before Det_ReportError
     * is called, the execution shall stop.
     */
    if (cfg->isInitialized) {
        /**
         * @req [SWS_Det_00207], [SWS_Det_00014], [SWS_Det_00501]
         * If at least one error hook has been configured, the Default Error Tracer
         * will notify each received error report by calling the configured error hook(s).
         */
        for (uint8 i = 0; i < ARRAY_DIM(cfg->errorHooks); i++) {
            (void)cfg->errorHooks[i](ModuleID, InstanceID, ApiId, ErrorId);
        }
    }

    //exit(1);
    ProgramHalt();
    return E_OK;
}

void Det_Start (void) {

}

Std_ReturnType Det_ReportRuntimeError(uint16 ModuleID, uint8 InstanceID, uint8 ApiId, uint8 ErrorId) {

    DetCfg *cfg = Det_GetCfg();

    /**
     * @req [SWS_Det_00024]
     * If the Default Error Tracer has not been initialized before Det_ReportTransientFault
     * or Det_ReportRuntimeError reporting functions are called, these
     * functions shall return immediately without any other action.
     */
    if (cfg->isInitialized) {
        /**
         * @req [SWS_Det_00207], [SWS_Det_00014], [SWS_Det_00503]
         * If at least one error hook has been configured, the Default Error Tracer
         * will notify each received error report by calling the configured error hook(s).
         */
        for (uint8 i = 0; i < ARRAY_DIM(cfg->runtimeErrorHooks); i++) {
            (void)cfg->runtimeErrorHooks[i](ModuleID, InstanceID, ApiId, ErrorId);
        }
    }

    return E_OK;
}

Std_ReturnType Det_ReportTransientFault(uint16 ModuleID, uint8 InstanceID, uint8 ApiId, uint8 ErrorId) {

    DetCfg *cfg = Det_GetCfg();
    uint8 result = E_OK;

    /**
     * @req [SWS_Det_00024]
     * If the Default Error Tracer has not been initialized before Det_ReportTransientFault
     * or Det_ReportRuntimeError reporting functions are called, these
     * functions shall return immediately without any other action.
     */
    if (cfg->isInitialized) {
        /**
         * @req [SWS_Det_00207], [SWS_Det_00014], [SWS_Det_00502]
         * If at least one error hook has been configured, the Default Error Tracer
         * will notify each received error report by calling the configured error hook(s).
         */
        for (uint8 i = 0; i < ARRAY_DIM(cfg->transientFaultHooks); i++) {
            result += cfg->transientFaultHooks[i](ModuleID, InstanceID, ApiId, ErrorId);
        }
    }

    return result != E_OK ? E_NOT_OK : E_OK;
}

#if (DET_VERSIONINFO_API == STD_ON)
void Det_GetVersionInfo(Std_VersionInfoType* versioninfo) {

    if (NULL == versioninfo) {
        /**
         * @req [SWS_Det_00301], [SWS_Det_00052]
         * Det_GetVersionInfo called with null parameter pointer.
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
#endif
