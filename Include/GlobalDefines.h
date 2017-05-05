#ifndef INCLUDE_GLOBALDEFINES
#define INCLUDE_GLOBALDEFINES

#define NULL 0
#define SAFE_DELETE(x) if(x){delete x;}x=NULL
#define SAFE_ARRAY_DELETE(x) if(x){delete[] x;}x=NULL

#endif
