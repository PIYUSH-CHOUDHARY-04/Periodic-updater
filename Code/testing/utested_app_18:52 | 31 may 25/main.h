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

#include "percent_encod_decod.h"

/**
 * @brief Macros
 */
#define API_CREDS_JSON_FILE		"api_creds.json"
#define API_CREDS_JSON_FILE_STRLEN	0x0E /**< Number of chars in above macro */


#define API_CREDS_JSON_FOUND_FLAG	(1<<0)



/**
 * @brief extern variable declarations
 */
extern unsigned char flag; /**< uses flag values defined above */


#endif /* __MAIN_H__ */
