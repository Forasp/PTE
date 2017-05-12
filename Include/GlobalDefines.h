#ifndef INCLUDE_GLOBALDEFINES
#define INCLUDE_GLOBALDEFINES

#define NULL 0
#define SAFE_DELETE(x) if(x){delete x;}x=NULL
#define SAFE_ARRAY_DELETE(x) if(x){delete[] x;}x=NULL

#ifdef _WIN32
#define GET_CSTRING_SIZE(x) (sizeof(char) + strlen(x))
#endif
#ifdef __linux__
#define GET_CSTRING_SIZE(x) (strlen(x))
#endif

#endif
