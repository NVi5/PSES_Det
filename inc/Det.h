/** 
    @file Det.h
    The Default Error Tracer provides functionality to support error detection and tracing of
    errors during the development and runtime of Software Components and other Basic
    Software Modules. For this purpose the Default Error Tracer receives and evaluates
    error messages from these components and modules.
*/

#ifndef STD_TYPES_H
#define STD_TYPES_H

#include "Std_Types.h"

/**
    @brief Configuration data structure of the Det module.
    @req [SWS_Det_00210] 
*/
typedef uint8t Det_ConfigType;

/* [SWS_Det_00008] */
void Det_Init (const Det_ConfigType* ConfigPtr);

/* [SWS_Det_00009] */
Std_ReturnType Det_ReportError (uint16 ModuleID, uint8 InstanceID, uint8 ApiId, uint8 ErrorId);

/* [SWS_Det_00010]  */
void Det_Start (void);

/* [SWS_Det_01001] */
Std_ReturnType Det_ReportRuntimeError (uint16 ModuleID, uint8 InstanceID, uint8 ApiId, uint8 ErrorId);

/* [SWS_Det_01003] */
Std_ReturnType Det_ReportTransientFault (uint16 ModuleID, uint8 InstanceID, uint8 ApiId, uint8 ErrorId);

/* [SWS_Det_00011] */
void Det_GetVersionInfo (Std_VersionInfoType* versioninfo);

#endif // STD_TYPES_H
