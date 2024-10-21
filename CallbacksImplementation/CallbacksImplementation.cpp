
#include "CallbacksImplementation.h"
#include "ModelicaUtilities.h"
#include "importer.h"
#include <mutex>

using namespace std;

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

ModelicaUtilityFunctions_t* ModelicaUtilityFunctions_getModelicaUtilityFunctions() {
    static mutex m;
    static bool alreadyInitialized=false;
    static ModelicaUtilityFunctions_t callbacks;
    unique_lock<mutex> lock(m);
    if(alreadyInitialized==false)
    {
        IMPORT(void (*)(const char *), ModelicaMessage);
        IMPORT(void (*)(const char *, ...), ModelicaFormatMessage);
        IMPORT(void (*)(const char *, va_list), ModelicaVFormatMessage);
        IMPORT(void (*)(const char *), ModelicaError);
        IMPORT(void (*)(const char *), ModelicaWarning);
        IMPORT(void (*)(const char *, ...), ModelicaFormatWarning);
        IMPORT(void (*)(const char *, va_list), ModelicaVFormatWarning);
        IMPORT(void (*)(const char *, ...), ModelicaFormatError);
        IMPORT(void (*)(const char *, va_list), ModelicaVFormatError);
        IMPORT(char *(*)(size_t), ModelicaAllocateString);
        IMPORT(char *(*)(size_t), ModelicaAllocateStringWithErrorReturn);
        callbacks.ModelicaMessage                       = ModelicaMessage;
        callbacks.ModelicaFormatMessage                 = ModelicaFormatMessage;
        callbacks.ModelicaVFormatMessage                = ModelicaVFormatMessage;
        callbacks.ModelicaError                         = ModelicaError;
        callbacks.ModelicaWarning                       = ModelicaWarning;
        callbacks.ModelicaFormatWarning                 = ModelicaFormatWarning;
        callbacks.ModelicaVFormatWarning                = ModelicaVFormatWarning;
        callbacks.ModelicaFormatError                   = ModelicaFormatError;
        callbacks.ModelicaVFormatError                  = ModelicaVFormatError;
        callbacks.ModelicaAllocateString                = ModelicaAllocateString;
        callbacks.ModelicaAllocateStringWithErrorReturn = ModelicaAllocateStringWithErrorReturn;
        alreadyInitialized=true;
    }
    return &callbacks;
}


void ModelicaUtilityFunctions_freeModelicaUtilityFunctions(ModelicaUtilityFunctions_t *callbacks) {
    // nothing to do
}

#ifdef __cplusplus
}
#endif //__cplusplus
