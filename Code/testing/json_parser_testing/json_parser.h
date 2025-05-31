#ifndef __JSON_PARSER_H__
#define __JSON_PARSER_H__

/**
 * @file json_parser.h
 * @brief Provides declarations and macros for json_parser.c , this parser is specific to application design thus may not be useful out of the project.
 */

/**
 * @brief Header files
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/**
 * @Brief Macros
 */
#define METADATA_ATTR_MAXSIZE 	128



// Hardcoding google's JSON object keys and count
#define KEY_COUNT			0x07
#define CLIENT_ID			"client_id\0"
#define PROJECT_ID			"project_id\0"
#define AUTH_URI			"auth_uri\0"
#define TOKEN_URI			"token_uri\0"
#define AUTH_PROVIDER_X509_CERT_URL	"auth_provider_x509_cert_url\0"
#define CLIENT_SECRET			"client_secret\0"
#define REDIRECT_URI			"redirect_uris\0"

#define JSON_STRUCTURAL_DIFF		0x03






/**
 * @brief Structure definitions
 */
typedef struct {
	char client_id[METADATA_ATTR_MAXSIZE];
	char project_id[METADATA_ATTR_MAXSIZE]; 
	char auth_uri[METADATA_ATTR_MAXSIZE];
	char token_uri[METADATA_ATTR_MAXSIZE];
	char auth_provider_x509_cert_url[METADATA_ATTR_MAXSIZE];
	char client_secret[METADATA_ATTR_MAXSIZE];
	char redirect_uri[METADATA_ATTR_MAXSIZE];
} api_metadata;



/**
 * @brief Parses the .json file and creates a .conf binary file which can be interpreted as some struct
 * @param param1 passes the path to the json file
 * @param param2 passes the pointer to the api_metadata structure
 * @return returns 0 on success
 */
int parse_json(const char* json_path,api_metadata* api_md);

#endif /* __JSON_PARSER_H__ */
