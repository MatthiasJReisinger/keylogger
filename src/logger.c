/**
 * @author d412vv1n
 * @see logger.h
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "logger.h"

void log_line(const char *prefix, const char *format, va_list list) {
	char *postfix = "\n";
	int prefixLength = strlen(prefix);
	int formatLength = strlen(format);
	int postfixLength = strlen(postfix);
	char logOutput[prefixLength + formatLength + postfixLength + 1];

	strcpy(logOutput, prefix);
	strcat(logOutput, format);
	strcat(logOutput, postfix);

	vprintf(logOutput, list);
}

void log_debug(const char *string, ...) {
	if (LOG_DEBUG_ON) {
		va_list args;
		va_start(args, string);
		log_line("DEBUG: ", string, args);
		va_end(args);
	}
}

void log_info(const char *string, ...) {
	if (LOG_INFO_ON) {
		va_list args;
		va_start(args, string);
		log_line("INFO: ", string, args);
		va_end(args);
	}
}

void log_error(const char *string, ...) {
	if (LOG_ERROR_ON) {
		va_list args;
		va_start(args, string);
		log_line("ERROR: ", string, args);
		va_end(args);
	}
}


