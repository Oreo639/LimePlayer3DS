#ifndef __ERROR_H__
#define __ERROR_H__

/* Errors that can't be explained with errno */
#define NDSP_INIT_FAIL			1000
#define DECODER_INIT_FAIL		1001
#define FILE_NOT_SUPPORTED		1002
#define DECODER_INIT_TIMEOUT		1003
#define UNSUPPORTED_CHANNELS		1004

#ifndef NODEBUGSTR
#define DEBUG(...) fprintf(stderr, __VA_ARGS__)
#else
#pragma message("Note: Debug strings are disabled.")
#define DEBUG(...)
#endif

#endif //ifndef __ERROR_H__
