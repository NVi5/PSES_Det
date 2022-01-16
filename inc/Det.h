#include "Std_Types.h"

/* [SWS_Det_00210] */
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
