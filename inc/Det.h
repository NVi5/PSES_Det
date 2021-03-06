/**
    @file Det.h
    @req [SWS_Det_00037]
    @brief The Default Error Tracer provides functionality to support error detection and
    tracing of errors during the development and runtime of Software Components and other
    Basic Software Modules. For this purpose the Default Error Tracer receives and evaluates
    error messages from these components and modules.
*/

#ifndef DET
#define DET

/**
    @req [SWS_BSW_00024]
    Include AUTOSAR Standard Types Header to Implementation header
*/
#include "Std_Types.h"

/**
    @defgroup PublishedInformationElements Published information elements
    @req [SWS_BSW_00059]
    Define Published information elements
*/
/**@{*/
/**
    @brief Vendor ID (vendorId) of the dedicated
    implementation of this module according to the
    AUTOSAR vendor list.
*/
#define DET_MODULE_ID            1
/**
    @brief Module ID of this module, as defined in the BSW
    Module List.
*/
#define DET_VENDOR_ID            1
/**
    @brief Major version number of the vendor specific
    implementation of the module.
*/
#define DET_SW_MAJOR_VERSION     4
/**
    @brief Minor version number of the vendor specific
    implementation of the module.
*/
#define DET_SW_MINOR_VERSION     7
/**
    @brief Patch level version number of the vendor specific
    implementation of the module.
*/
#define DET_SW_PATCH_VERSION     0
/**@}*/

/**
    @defgroup ImplementationSpecificErrors Implementation specific errors
    @req [SWS_BSW_00059]
*/
/**@{*/
/**
    @brief Function called with null parameter pointer.
*/
#define DET_E_PARAM_POINTER     0x01
/**@}*/

/**
    @defgroup CalloutFunctions Callout Functions
    @req [SWS_Det_00180]
    If callout functions are configured, they should have the same signatures as the corresponding functions. If several callouts are defined for the same
    service they should have the same ID.
*/
/**@{*/
/**
    @brief Type used as User_Error_Hooks.
    @req [SWS_Det_00181], [SWS_Det_00035], [SWS_Det_00180]
*/
typedef Std_ReturnType (*Det_ErrorHook_t)(uint16 ModuleId, uint8 InstanceId , uint8 ApiId, uint8 ErrorId);

/**
    @brief Type used as DetReportRuntimeErrorCallout.
    @req [SWS_Det_00184], [SWS_Det_00035], [SWS_Det_00180]
*/
typedef Det_ErrorHook_t Det_RuntimeErrorCallout_t;

/**
    @brief Type used as DetReportTransientFaultCallout.
    @req [SWS_Det_00187], [SWS_Det_00035], [SWS_Det_00180]
*/
typedef Det_ErrorHook_t Det_TransientFaultCallout_t;
/**@}*/

/**
    @brief Configuration data structure of the Det module.
    @req [SWS_Det_00210]
*/
typedef uint8 Det_ConfigType;

/**
    @defgroup APIFunctions API Functions
*/
/**@{*/
/**
    @brief Service to initialize the Default Error Tracer.
    @req [SWS_Det_00008], [SWS_Det_00019]

    @param ConfigPtr Pointer to the selected configuration set.
*/
void Det_Init (const Det_ConfigType* ConfigPtr);

/**
    @brief Service to report development errors.
    @req [SWS_Det_00009], [SWS_Det_00039], [SWS_Det_00026]

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
Std_ReturnType Det_ReportError (uint16 ModuleID, uint8 InstanceID, uint8 ApiId, uint8 ErrorId);

/**
    @brief Service to start the Default Error Tracer.
    @req [SWS_Det_00010], [SWS_Det_00025]
*/
void Det_Start (void);

/**
    @brief Service to report runtime errors. If a callout has been configured then this callout shall be
    called.
    @req [SWS_Det_01001], [SWS_Det_00039], [SWS_Det_00026]

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
Std_ReturnType Det_ReportRuntimeError (uint16 ModuleID, uint8 InstanceID, uint8 ApiId, uint8 ErrorId);

/**
    @brief Service to report transient faults. If a callout has been configured than this callout shall be
    called and the returned value of the callout shall be returned. Otherwise it returns immediately
    with E_OK.
    @req [SWS_Det_01003], [SWS_Det_00039], [SWS_Det_00026]

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
Std_ReturnType Det_ReportTransientFault (uint16 ModuleID, uint8 InstanceID, uint8 ApiId, uint8 ErrorId);

/**
    @brief Returns the version information of this module.
    @req [SWS_Det_00011]

    @param versioninfo Pointer to where to store the version information of this module.
*/
#if (DET_VERSIONINFO_API == STD_ON)
void Det_GetVersionInfo (Std_VersionInfoType* versioninfo);
#endif
/**@}*/

#endif /* DET */
