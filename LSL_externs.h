#pragma once

#ifdef LSL_EXTERNS_EXPORTS
#define LSL_EXTERNS_API __declspec(dllexport)
#else
#define LSL_EXTERNS_API __declspec(dllimport)
#endif

extern "C" LSL_EXTERNS_API void send_marker(const char* name);

extern "C" LSL_EXTERNS_API void init_LSL(const char* LSLname);

extern "C" LSL_EXTERNS_API void close_LSL();