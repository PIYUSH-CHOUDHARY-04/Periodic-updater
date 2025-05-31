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



#include "percent_encod_decod.h"
#include "json_parser.h"



/**
 * @brief Macros
 */
#define APP_NAME			"MyApp0\0"
#define READLINK_PATH			"/proc/self/exe"

#define API_CREDS_JSON_FILE		"api_creds.json"
#define API_CREDS_JSON_FILE_STRLEN	0x0E /**< Number of chars in above macro */


#define API_CREDS_JSON_FOUND_FLAG	(1<<0)



#define COPY_FILE_BLOCKSIZE		(1<<11)



/**
 * @brief extern variable declarations
 */
extern unsigned char flag; /**< uses flag values defined above */
extern int retval; /**< Holds return value of functions */


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



#endif /* __MAIN_H__ */
