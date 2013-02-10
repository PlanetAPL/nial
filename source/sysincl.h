/*==============================================================

  HEADER SYSINCL.H

  COPYRIGHT NIAL Systems Limited  1983-2005

This header file is included in routines that need to import C libraries
for various systems and compilers. The defined symbols control which subset
of C libraries are brought in.

================================================================*/

/* MAJ this code should be checked for currency of C library usage */

/*
The following Define switches affect the code

SIGLIB -- gets the signal library <signal.h>
MATHLIB - gets the math library <math.h>
STLIB   - gets the string library <string.h>
CLIB    - gets <ctype.h>
SJLIB   - gets <setjmp.h>
STDLIB  - gets <stdlib.h>
STREAMLIB - gets <iostream.h>
ASSERTLIB - gets <assert.h>

IOLIB   - gets <stdio.h> and <sys/stat.h>
           plus
               <unistd.h> on UNIX systems
               and <dos.h> and <io.h> on Windows systems

TIMELIB - gets the time library <time.h> on Windows systems
          or <sys/types.h>, <sys/times.h>, <sys/param.h> on UNIX systems


LIMITLIB - gets <limits.h> 
            plus <float.h> on UNIX systems

VARARGSLIB - gets <stdarg.h> and <stddef.h>

WINDOWSLIB - gets <windows.h> under Windows systems

FLOATLIB - gets <float.h> used in handling floating point exceptions on Windows

PROCESSLIB - gets additional system libraries needed by process.c

SOCKETLIB - gets additional system libraries needed by sockets.c



*/

#ifdef SIGLIB
#include <signal.h>
#endif

#ifdef MATHLIB
#include <math.h>
#endif

#ifdef STLIB
#include <string.h>
#endif

#ifdef CLIB
#include <ctype.h>
#endif

#ifdef SJLIB
#include <setjmp.h>
#endif

#include <stdlib.h>

#ifdef STREAMLIB
#include <iostream>
#endif


#ifdef IOLIB                 

#include <stdio.h>
#include <sys/stat.h>

#include <errno.h>
#include <unistd.h>

#endif             

#ifdef TIMELIB               /* ( */

#ifdef TIMEHOOK

#include <sys/types.h>
#include <sys/times.h>
#include <sys/param.h>

#endif

#endif             /* TIMELIB  ) */


#ifdef LIMITLIB

#include <limits.h>

#endif


#include <stdarg.h>
#include <stddef.h>


#ifdef FLOATLIB
#include <float.h>
#endif

#ifdef PROCESSLIB
#include <sys/types.h>
#include <pwd.h>
#include <fcntl.h>
#include <netdb.h>
#include <errno.h>
#endif

#ifdef ASSERTLIB
#include <assert.h>
#endif



#ifdef SOCKETLIB

#  include <sys/socket.h>
#  include <netinet/in.h>
#  include <netdb.h>
#  include <sys/types.h>
#  include <fcntl.h>
#  include <errno.h>

#endif
    
