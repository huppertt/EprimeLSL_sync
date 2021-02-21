#include "pch.h"
#include "LSL_externs.h"
#include "lsl_cpp.h"

static lsl_streaminfo info;
static lsl_outlet outlet;


void init_LSL(const char* LSLname) {
	// initialize the LSL stream
	if (info) {
		info = lsl_create_streaminfo(LSLname, "Markers", 1, LSL_IRREGULAR_RATE, cft_string, "id23443");
		outlet = lsl_create_outlet(info, 0, 360);
	}
}

void send_marker(const char* name) {
	if (info) {
		lsl_push_sample_str(outlet, &name);
	}
}

void close_LSL() {
	if (info) {
		lsl_destroy_outlet(outlet);
		delete outlet;
		delete info;
	}
}