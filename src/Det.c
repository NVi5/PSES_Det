/**
    @file Det.c
    @brief Implementation of Default Error Tracer
*/

#include "Det.h"
#include "Det_Externals.h"

void Det_Init (const Det_ConfigType* ConfigPtr) {

}

Std_ReturnType Det_ReportError (uint16 ModuleID, uint8 InstanceID, uint8 ApiId, uint8 ErrorId) {

}

void Det_Start (void) {

}

Std_ReturnType Det_ReportRuntimeError (uint16 ModuleID, uint8 InstanceID, uint8 ApiId, uint8 ErrorId) {

}

Std_ReturnType Det_ReportTransientFault (uint16 ModuleID, uint8 InstanceID, uint8 ApiId, uint8 ErrorId) {

}

void Det_GetVersionInfo (Std_VersionInfoType* versioninfo) {
    if (NULL == versioninfo) {
        versioninfo->vendorID = DET_MODULE_ID;
        versioninfo->moduleID = DET_VENDOR_ID;
        versioninfo->sw_major_version = DET_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = DET_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = DET_SW_PATCH_VERSION;
    }
    else {
        // TODO: handle null pointer error
    }
}
