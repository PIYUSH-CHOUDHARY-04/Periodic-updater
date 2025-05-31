#ifndef __PERCENT_ENCOD_DECOD__
#define __PERCENT_ENCOD_DECOD__

/** 
 * @file percent_encod_decod.h
 * @brief Provide functions for percent encryption and decryption
 * @see https://datatracker.ietf.org/doc/html/rfc3986#section-2.3
 */



/**
 * @brief Macros.
 */
#define BYTE 		        0x100
#define PERC_ENC_SIZE 	    0x03
#define ASCII_REDUC_VAL0    0x30 // for mapping '0'-'9' ==> 0x00-0x09
#define ASCII_REDUC_VAL1    0x37 // for mapping 'A'-'F' ==> 0x0A-0x0F


/**
 * @brief Lookup table for percent encoding.
 */
extern const unsigned char EncLT[BYTE][PERC_ENC_SIZE+1]; // +1 for '\0' for readability.



/**
 * @brief Performs percent encoding for URIs.
 * @param param1 passes pointer to the plain text.
 * @param param2 passes the size of the input plain text.
 * @param param3 passes the pointer to the array where encoded text will be stored. (ostream array must be at minimum, 3 times the size of istream)
 * @return returns the length of the encoded text.
 */
unsigned int percent_encode(unsigned char* istream, unsigned int size_istream, unsigned char* ostream);

/**
 * @brief Performs percent decoding for URIs.
 * @param param1 passes the pointer to the encoded text.
 * @param param2 passes the size of the encoded text.
 * @param param3 passes the pointer to the array where decoded text will be stored. (ostream array must be at minimum of same size of istream)
 * @return returns the length of the decoded text.
 */
unsigned int percent_decode(unsigned char* istream, unsigned int size_istream, unsigned char* ostream);



#endif /* __PERCENT_ENCOD_DECOD__ */
