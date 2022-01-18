/**
    @file Det_Externals.h
    @brief Headers of Default Error Tracer Externals
*/

#ifndef DET_EXTERNALS
#define DET_EXTERNALS

#define DET_NUMBER_OF_USER_ERROR_HOOKS 2
#define DET_NUMBER_OF_RUNTIME_ERROR_CALLOUTS 2
#define DET_NUMBER_OF_TRANSIENT_FAULT_CALLOUTS 2

#include "Std_Types.h"

/**
    @brief Error_Hook to be called by Det_ReportError.
    @req [SWS_Det_00181]

    @param ModuleId Module ID of calling module.
    @param InstanceId The identifier of the index based instance of a module, starting
    from 0, If the module is a single instance module it shall pass 0 as
    the InstanceId.
    @param ApiId ID of API service in which error is detected (defined in SWS of
    calling module)
    @param ErrorId ID of detected development error (defined in SWS of calling
    module).

    @returns returns always E_OK (is required for services)
*/
Std_ReturnType MyErrorHook(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);

/**
    @brief Error_Hook to be called by Det_ReportError.
    @req [SWS_Det_00181]

    @param ModuleId Module ID of calling module.
    @param InstanceId The identifier of the index based instance of a module, starting
    from 0, If the module is a single instance module it shall pass 0 as
    the InstanceId.
    @param ApiId ID of API service in which error is detected (defined in SWS of
    calling module)
    @param ErrorId ID of detected development error (defined in SWS of calling
    module).

    @returns returns always E_OK (is required for services)
*/
Std_ReturnType MyErrorHook2(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);

/**
    @brief Error_Hook to be called by Det_ReportRuntimeError.
    @req [SWS_Det_00184]

    @param ModuleId Module ID of calling module.
    @param InstanceId The identifier of the index based instance of a module, starting
    from 0, If the module is a single instance module it shall pass 0 as
    the InstanceId.
    @param ApiId ID of API service in which error is detected (defined in SWS of
    calling module)
    @param ErrorId ID of detected development error (defined in SWS of calling
    module).

    @returns returns always E_OK (is required for services)
*/
Std_ReturnType MyRuntimeErrorCallout(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);

/**
    @brief Error_Hook to be called by Det_ReportRuntimeError.
    @req [SWS_Det_00184]

    @param ModuleId Module ID of calling module.
    @param InstanceId The identifier of the index based instance of a module, starting
    from 0, If the module is a single instance module it shall pass 0 as
    the InstanceId.
    @param ApiId ID of API service in which error is detected (defined in SWS of
    calling module)
    @param ErrorId ID of detected development error (defined in SWS of calling
    module).

    @returns returns always E_OK (is required for services)
*/
Std_ReturnType MyRuntimeErrorCallout2(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);

/**
    @brief Error_Hook to be called by Det_ReportTransientFault.
    @req [SWS_Det_00187]

    @param ModuleId Module ID of calling module.
    @param InstanceId The identifier of the index based instance of a module, starting
    from 0, If the module is a single instance module it shall pass 0 as
    the InstanceId.
    @param ApiId ID of API service in which error is detected (defined in SWS of
    calling module)
    @param ErrorId ID of detected development error (defined in SWS of calling
    module).

    @returns Value is propagated to caller of Det_ReportTransientFault
*/
Std_ReturnType MyTransientFaultCallout(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);

/**
    @brief Error_Hook to be called by Det_ReportTransientFault.
    @req [SWS_Det_00187]

    @param ModuleId Module ID of calling module.
    @param InstanceId The identifier of the index based instance of a module, starting
    from 0, If the module is a single instance module it shall pass 0 as
    the InstanceId.
    @param ApiId ID of API service in which error is detected (defined in SWS of
    calling module)
    @param ErrorId ID of detected development error (defined in SWS of calling
    module).

    @returns Value is propagated to caller of Det_ReportTransientFault
*/
Std_ReturnType MyTransientFaultCallout2(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);

#endif /* DET_EXTERNALS */
