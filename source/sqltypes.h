/*********************************************************************
** SQLTYPES.H - This file defines the types used in ODBC
**
** (C) Copyright 1995 By Microsoft Corp.
**
**     Created 4/10/95 for 2.50 specification
*********************************************************************/

#ifndef __SQLTYPES
#define __SQLTYPES

/* if ODBCVER is not defined, assume version 2.50 */
#ifndef ODBCVER
#define ODBCVER	0x0250
#endif

/* environment specific definitions */
#ifndef EXPORT
#define EXPORT   _export
#endif

/* define WINDOWS */
/* _WINDOWS_ is defined in windows.h for 32 bit    */
/* _INC_WINDOWS is defined in windows.h for 16 bit */
#if (defined(_WINDOWS_) || defined(_INC_WINDOWS)) && !defined(WINDOWS)
#define WINDOWS
#endif

#define SQL_API

#ifndef RC_INVOKED

#if !defined(WINDOWS) && !defined(FAR)
#define FAR
#endif

/* SQL portable types for C */
typedef unsigned char           UCHAR;
typedef signed char             SCHAR;
typedef long int                SDWORD;
typedef short int               SWORD;
typedef unsigned long int       UDWORD;
typedef unsigned short int      UWORD;

#if (ODBCVER >= 0x0200)
typedef signed long             SLONG;
typedef signed short            SSHORT;
typedef unsigned long           ULONG;
typedef unsigned short          USHORT;
#endif  /* ODBCVER >= 0x0200 */
typedef double                  SDOUBLE;
typedef double                  LDOUBLE;
typedef float                   SFLOAT;

typedef void FAR *              PTR;

typedef void FAR *              HENV;
typedef void FAR *              HDBC;
typedef void FAR *              HSTMT;

typedef signed short            RETCODE;

typedef UCHAR                   SQLCHAR;
typedef SCHAR                   SQLSCHAR;
typedef SDWORD                  SQLINTEGER;
typedef SWORD                   SQLSMALLINT;
typedef UDWORD                  SQLUINTEGER;
typedef UWORD                   SQLUSMALLINT;

typedef void FAR *              SQLPOINTER;

typedef SQLINTEGER		SQLHENV;
typedef SQLINTEGER		SQLHDBC;
typedef SQLINTEGER		SQLHSTMT;
typedef SQLSMALLINT             SQLRETURN;

typedef Widget                  SQLHWND;

/* transfer types for DATE, TIME, TIMESTAMP */
typedef struct tagDATE_STRUCT
{
        SQLSMALLINT    year;
        SQLUSMALLINT   month;
        SQLUSMALLINT   day;
} DATE_STRUCT;

typedef struct tagTIME_STRUCT
{
        SQLUSMALLINT   hour;
        SQLUSMALLINT   minute;
        SQLUSMALLINT   second;
} TIME_STRUCT;

typedef struct tagTIMESTAMP_STRUCT
{
        SQLSMALLINT    year;
        SQLUSMALLINT   month;
        SQLUSMALLINT   day;
        SQLUSMALLINT   hour;
        SQLUSMALLINT   minute;
        SQLUSMALLINT   second;
        SQLUINTEGER    fraction;
} TIMESTAMP_STRUCT;

#if (ODBCVER >= 0x0200)
typedef unsigned long int       BOOKMARK;
#endif  /* ODBCVER >= 0x0200 */

#endif 

#endif /* #ifndef __SQLTYPES */
