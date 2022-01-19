/**
    @file Det_User.c
    @brief Implementation of User Error Hooks and Callouts
*/

#include "Det_Externals.h"
#include <stdio.h>

Std_ReturnType MyErrorHook(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId) {
    printf("Reported Error: ModuleId:%d, InstanceId:%d, ApiId:%d, ErrorId:%d\n",
            ModuleId, InstanceId, ApiId, ErrorId);
    return E_OK;
}

Std_ReturnType MyErrorHook2(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId) {
    printf("Reported Error 2: ModuleId:%d, InstanceId:%d, ApiId:%d, ErrorId:%d\n",
            ModuleId, InstanceId, ApiId, ErrorId);
    return E_OK;
}

Std_ReturnType MyRuntimeErrorCallout(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId) {
    printf("Reported Runtime Error Callout: ModuleId:%d, InstanceId:%d, ApiId:%d, ErrorId:%d\n",
            ModuleId, InstanceId, ApiId, ErrorId);
    return E_OK;
}

Std_ReturnType MyRuntimeErrorCallout2(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId) {
    printf("Reported Runtime Error Callout 2: ModuleId:%d, InstanceId:%d, ApiId:%d, ErrorId:%d\n",
            ModuleId, InstanceId, ApiId, ErrorId);
    return E_OK;
}

Std_ReturnType MyTransientFaultCallout(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId) {
    printf("Reported Transient Fault Callout: ModuleId:%d, InstanceId:%d, ApiId:%d, ErrorId:%d\n",
            ModuleId, InstanceId, ApiId, ErrorId);
    return ModuleId == 0 ? E_OK : E_NOT_OK;
}

Std_ReturnType MyTransientFaultCallout2(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId) {
    printf("Reported Transient Fault Callout 2: ModuleId:%d, InstanceId:%d, ApiId:%d, ErrorId:%d\n",
            ModuleId, InstanceId, ApiId, ErrorId);
    return ModuleId == 0 ? E_OK : E_NOT_OK;
}
