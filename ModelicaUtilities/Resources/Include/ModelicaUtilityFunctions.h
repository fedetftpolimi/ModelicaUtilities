
#pragma once

#include <stddef.h>  // for size_t
#include <stdarg.h>  // for va_list

typedef struct {
	void  (*ModelicaMessage)(const char* str);
	void  (*ModelicaFormatMessage)(const char* str, ...);
	void  (*ModelicaVFormatMessage)(const char* str, va_list args);
	void  (*ModelicaError)(const char* str);
	void  (*ModelicaWarning)(const char* str);
	void  (*ModelicaFormatWarning)(const char* str, ...);
	void  (*ModelicaVFormatWarning)(const char* str, va_list args);
	void  (*ModelicaFormatError)(const char* str, ...);
	void  (*ModelicaVFormatError)(const char* str, va_list args);
	char* (*ModelicaAllocateString)(size_t len);
	char* (*ModelicaAllocateStringWithErrorReturn)(size_t len);
} ModelicaUtilityFunctions_t;
