#ifndef INCLUDE_GLOBALDEFINES
#define INCLUDE_GLOBALDEFINES

#ifndef NULL
#define NULL 0
#endif

#define SAFE_DELETE(x) if(x){delete x;}x=NULL
#define SAFE_ARRAY_DELETE(x) if(x){delete[] x;}x=NULL

#define GET_CSTRING_SIZE(x) (sizeof(char) + strlen(x))

#endif
