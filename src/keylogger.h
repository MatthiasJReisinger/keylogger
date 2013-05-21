/**
 * key logger component
 * the key logger is a singleton which is only accessible
 * through the methods declared here. the key logger is a thread.
 * there can only be one key logger at a time.
 *
 * @author d412vv1n
 */

#ifndef KEYLOGGER_H
#define KEYLOGGER_H

/**
 * starts the key logger in a separate thread. if the key logger
 * has already been started, subsequent calls of this method are
 * ignored.
 * 
 * @return 0 if the key logger started successfully, 1 if it could
 *		   not be started
 */
int startKeylogger(void);

/**
 * stops the key logger and clears all resources the key logger
 * has been using. after the key logger has been stopped through this
 * method, it can be started again through the startKeylogger() method.
 *
 * @return 0 if the key logger stopped successfully, 1 if there was an error
 */
int stopKeylogger(void);

#endif
