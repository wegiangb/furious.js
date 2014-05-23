#pragma once

#include <ppapi/c/ppb_console.h>
#include <ppapi/c/ppb_messaging.h>
#include <ppapi/c/ppb_var.h>
#include <ppapi/c/ppb_var_dictionary.h>
#include <ppapi/c/ppb_var_array.h>
#include <ppapi/c/ppb_var_array_buffer.h>

extern const struct PPB_Console_1_0* consoleInterface;
extern const struct PPB_Var_1_1* varInterface;
extern const struct PPB_Messaging_1_0* messagingInterface;
extern const struct PPB_VarDictionary_1_0* dictionaryInterface;
extern const struct PPB_VarArray_1_0* arrayInterface;
extern const struct PPB_VarArrayBuffer_1_0* bufferInterface;

#define NUMJS_VAR_FROM_STRING_LITERAL(string) \
	varInterface->VarFromUtf8(string, sizeof(string) - 1)

#define NUMJS_LOG(message, level) \
	{ \
		struct PP_Var varMessage = NUMJS_VAR_FROM_STRING_LITERAL(message); \
		consoleInterface->Log(instance, level, varMessage); \
		varInterface->Release(varMessage); \
	}

#define NUMJS_LOG_INFO(message) \
	NUMJS_LOG(message, PP_LOGLEVEL_LOG)

#define NUMJS_LOG_ERROR(message) \
	NUMJS_LOG(message, PP_LOGLEVEL_ERROR)
