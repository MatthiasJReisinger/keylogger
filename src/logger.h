/**
 * logging component for debugging
 *
 * @author d412vv1n
 */

#ifndef LOGGER_H
#define LOGGER_H

/**
 * configure this constants to turn on/off logging for the different
 * logging methods
 */
#define LOG_DEBUG_ON 0
#define LOG_INFO_ON 1
#define LOG_ERROR_ON 0

/**
 * this method is used like printf. it only prints "DEBUG: " in front of
 * your text and adds a new line at the end of your message.
 * this method should only be used for printing debug output during development.
 *
 * set the constant LOG_DEBUG_ON to 0 for turning off the output of this method.
 */
void log_debug(const char *info, ...);

/**
 * this method is used like printf. it only prints "INFO: " in front of
 * your text and adds a new line at the end of your message.
 * this logging method should not be used for debug outputs but for output
 * that is of interest for the user.
 *
 * set the constant LOG_INFO_ON to 0 for turning off the output of this method.
 */
void log_info(const char *info, ...);

/**
 * this method is used like printf. it only prints "ERROR: " in front of
 * your text and adds a new line at the end of your message.
 *
 * set the constant LOG_ERROR_ON to 0 for turning off the output of this method.
 */
void log_error(const char *error, ...);

#endif
