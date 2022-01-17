/**
    @file Det_Externals.h
    @brief Headers of Default Error Tracer Externals
*/

#ifndef DET_EXTERNALS
#define DET_EXTERNALS


#include "Std_Types.h"

/**
    @brief Configuration data structure of the Det module.
    @req [SWS_Det_00210]
*/
typedef uint8 Det_ConfigType2;

/**
    @brief Service to initialize the Default Error Tracer.
    @req [SWS_Det_00008]

    @param ConfigPtr Pointer to the selected configuration set.
*/
void Det_Init2 (const Det_ConfigType* ConfigPtr);

/**
    @brief Service to report development errors.
    @req [SWS_Det_00009]

    @param ModuleId Module ID of calling module.
    @param InstanceId The identifier of the index based instance of a module, starting
    from 0, If the module is a single instance module it shall pass 0 as
    the InstanceId.
    @param ApiId ID of API service in which error is detected (defined in SWS of
    calling module)
    @param ErrorId ID of detected development error (defined in SWS of calling
    module).

    @returns never returns a value, but has a return type for compatibility with
    services and hooks
*/
Std_ReturnType Det_ReportError2 (uint16 ModuleID, uint8 InstanceID, uint8 ApiId, uint8 ErrorId);

/**
    @brief Service to start the Default Error Tracer.
    @req [SWS_Det_00010]
*/
void Det_Start2 (void);

/**
    @brief Service to report runtime errors. If a callout has been configured then this callout shall be
    called.
    @req [SWS_Det_01001]

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
Std_ReturnType Det_ReportRuntimeError2 (uint16 ModuleID, uint8 InstanceID, uint8 ApiId, uint8 ErrorId);

/**
    @brief Service to report transient faults. If a callout has been configured than this callout shall be
    called and the returned value of the callout shall be returned. Otherwise it returns immediately
    with E_OK.
    @req [SWS_Det_01003]

    @param ModuleId Module ID of calling module.
    @param InstanceId The identifier of the index based instance of a module, starting
    from 0, If the module is a single instance module it shall pass 0 as
    the InstanceId.
    @param ApiId ID of API service in which error is detected (defined in SWS of
    calling module)
    @param ErrorId ID of detected development error (defined in SWS of calling
    module).

    @returns If no callout exists it shall return E_OK, otherwise it shall return
    the value of the configured callout. In case several callouts are
    configured the logical or (sum) of the callout return values shall
    be returned. Rationale: since E_OK=0, E_OK will be only
    returned if all are E_OK, and for multiple error codes there is a
    good chance to detect several of them.
*/
Std_ReturnType Det_ReportTransientFault2 (uint16 ModuleID, uint8 InstanceID, uint8 ApiId, uint8 ErrorId);

/**
    @brief Returns the version information of this module.
    @req [SWS_Det_00011]

    @param versioninfo Pointer to where to store the version information of this module.
*/
void Det_GetVersionInfo2 (Std_VersionInfoType* versioninfo);

#endif /* DET_EXTERNALS */
