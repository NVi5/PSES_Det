/**
    @file Det.c
    @brief Implementation of Default Error Tracer
*/

#include "Det.h"
#include "Det_Externals.h"

void Det_Init (const Det_ConfigType* ConfigPtr) {
    
}

Std_ReturnType Det_ReportError (uint16 ModuleID, uint8 InstanceID, uint8 ApiId, uint8 ErrorId) {
    exit(-1);
}

void Det_Start (void) {

}

Std_ReturnType Det_ReportRuntimeError (uint16 ModuleID, uint8 InstanceID, uint8 ApiId, uint8 ErrorId) {

}

Std_ReturnType Det_ReportTransientFault (uint16 ModuleID, uint8 InstanceID, uint8 ApiId, uint8 ErrorId) {

}

void Det_GetVersionInfo (Std_VersionInfoType* versioninfo) {
    if (NULL == versioninfo) {
        /**
         * @req [SWS_Det_00301]
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
