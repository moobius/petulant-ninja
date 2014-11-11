#ifndef __CDCERROR_H__
#define __CDCERROR_H__

#define TRY(_errcode_, _try_) if((_errcode_ = _try_) != kCDCError_Success) goto catch
#define CATCH catch:

enum {
      kCDCError_Failure = 0,
      kCDCError_Success = 1,
} CDCError;

#endif
