#define EXPORTING_DLL

#include "pch.h"
#include "LSL_externs.h"
#include "lsl_cpp.h"
#include <iostream>



static lsl_streaminfo info;
static lsl_outlet outlet;

using namespace std;

void init_LSL() {
	const char* LSLname = "eprime";
	// initialize the LSL stream
		info = lsl_create_streaminfo(LSLname, "Markers", 1, LSL_IRREGULAR_RATE, cft_string, "id23443");
		outlet = lsl_create_outlet(info, 0, 360);
		MessageBox(NULL, L"LSL Thread Created", L"DLL CALL", MB_OK);
}

void send_marker(const char* name) {
	cout << "Trying" << endl;
	if (info) {
		lsl_push_sample_str(outlet, &name);
		MessageBox(NULL, L"LSL MARKER Sent", L"DLL CALL", MB_OK);
	}
}

void close_LSL() {
	cout << "Closing thread" << endl;
	if (info) {
		lsl_destroy_outlet(outlet);
		delete outlet;
		delete info;
	}
}