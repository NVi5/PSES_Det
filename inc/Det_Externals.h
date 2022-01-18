/**
    @file Det_Externals.h
    @brief Headers of Default Error Tracer Externals
*/

#ifndef DET_EXTERNALS
#define DET_EXTERNALS


#include "Std_Types.h"

/**
    @brief Service to initialize the Default Error Tracer.
    @req [SWS_Det_00008]

    @param ConfigPtr Pointer to the selected configuration set.
*/
Std_ReturnType MyErrorHook(uint16 ModuleId, uint8 InstanceId , uint8 ApiId, uint8 ErrorId);

Std_ReturnType MyErrorHook2(uint16 ModuleId, uint8 InstanceId , uint8 ApiId, uint8 ErrorId);

Std_ReturnType MyRuntimeErrorCallout(uint16 ModuleId, uint8 InstanceId , uint8 ApiId, uint8 ErrorId);

Std_ReturnType MyRuntimeErrorCallout2(uint16 ModuleId, uint8 InstanceId , uint8 ApiId, uint8 ErrorId);

Std_ReturnType MyTransientFaultCallout(uint16 ModuleId, uint8 InstanceId , uint8 ApiId, uint8 ErrorId);

Std_ReturnType MyTransientFaultCallout2(uint16 ModuleId, uint8 InstanceId , uint8 ApiId, uint8 ErrorId);

#endif /* DET_EXTERNALS */
