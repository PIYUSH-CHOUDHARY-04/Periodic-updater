#ifndef __MAIN_H__
#define __MAIN_H__

/** 
 * @file main.h
 * @brief Provide functions, macros, header files to main.c
 */

/**
 * @brief Header file inclusion
 */
#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<limits.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
#include<time.h>


#include "percent_encod_decod.h"
#include "json_parser.h"



/**
 * @brief Macros
 */
#define APP_NAME			"MyApp0"
#define READLINK_PATH			"/proc/self/exe"

#define API_CREDS_JSON_FILE		"api_creds.json"
#define API_CREDS_JSON_FILE_STRLEN	0x0E /**< Number of chars in above macro */

//flag macros
#define API_CREDS_JSON_FOUND_FLAG	(1<<0)


// file copying specific macros
#define COPY_FILE_BLOCKSIZE		(1<<11)

// Authorization URI generation specific macros
#define AUTH_URI_MAXSIZE		512

// Session check specific macros
#define DESKTOP_SESSION			"DESKTOP_SESSION"
#define XDG_CURRENT_DESKTOP		"XDG_CURRENT_DESKTOP"
#define XDG_SESSION_TYPE		"XDG_SESSION_TYPE"
#define DISPLAY 			"DISPLAY"
#define TTY				"tty"

// Random string generation specific macros
#define URAND				"/dev/urandom"
#define STD_CSRF_STR_SIZE		0x08


// Macro functions
#define FREE(x) do{if((x)){free((x)); (x)=NULL;}}while(0);


/**
 * @brief extern variable declarations
 */
extern unsigned char flag; /**< uses flag values defined above */
extern int retval; /**< Holds return value of functions returning int, used for functional call failure checking */


/**
 * @brief Function declarations.
 */
/**
 * @brief Function to copy a file from one directory to other
 * @param param1 passes the path of the destination, includes the exact file name into which data has to be copied not just directory name 
 * @param param2 passes the path of the file to be copied to destination
 * @return tells whether copy succeeded or not
 */
int copy_file(const char* dest, const char* file_path);

/**
 * @brief generates random string for CSRF protection on web reequests.
 * @param param1 passes the pointer to the array where random string will be stored
 * @param param2 passes the size of the random string
 * @return returns the pointer to populated random number string on success, NULL on failure
 */
unsigned char* csrf_prot_random_str(unsigned char* rand_str, int size);

/**
 * @brief creates an authorization URI from JSON object
 * @param param1 passes pointer to the json object
 * @return returns pointer to the dynamically allocated URI array.
 */
char* create_auth_uri(api_metadata* ap_md);

/**
 * @brief Checks user session minimality, if minimal or tty based, then GUI based browser won't be present, authorization must be done in some other way
 * param param1 passes the pointer to the enviromental path array which has to be parsed to check for session type
 * return returns 0 if session is GUI based, returns 1 if its minimal or tty based, more values may be added in future
 */
int check_session_type(char** environ_var);





#endif /* __MAIN_H__ */
