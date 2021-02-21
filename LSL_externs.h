#ifndef LSL_externs_H
#define LSL_externs_H

#ifdef EXPORTING_DLL
extern "C" __declspec(dllexport) void send_marker(const char* name);
extern "C" __declspec(dllexport) void init_LSL();
extern "C" __declspec(dllexport) void close_LSL();
#else
extern "C" __declspec(dllimport) void send_marker(const char* name);
extern "C" __declspec(dllimport) void init_LSL();
extern "C" __declspec(dllimport) void close_LSL();

#endif

#endif