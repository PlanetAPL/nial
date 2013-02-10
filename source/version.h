/*==============================================================

  VERSION.H:  

  COPYRIGHT NIAL Systems Limited  1983-2005

  This defines macros to set up the banner line for various versions.

================================================================*/

#ifndef _VERSION_H_
#define	_VERSION_H_

/* The banner information is constructed from:
   special
   nialversion
   machine
   opsys
   debugstatus
   date
*/

/*
   The internal variable systemname is used to set the Nial
   expression System that is available for programs to test which
   version is being used.  Only one of these cases is chosen.
*/

#ifndef __DATE__

/* compiler does not provide date functionality, set date directly
   below and remove the words (Possibly incorrect)*/

#define __DATE__ "Feb 07, 2007 (Possibly incorrect)"

#endif

/* Version 6.3 is the public domain version released as open source */

#define nialversion	" Version 6.3"


/*
   The internal variable systemname is used to set the Nial
   expression System that is available for programs to test which
   version is being used.  Only one of these cases is chosen.
*/

#define systemname	"UNIX"

#define machine		" Intel x86"
#define opsys		" MacOS X"

#ifdef STANDARD
#define special		"Standard"
#endif

#ifdef DEVELOPER
#define special         "NSL Internal"
#endif

#ifdef PROFESSIONAL
#define special		"Professional"
#endif

#ifdef PUBLIC
#define special		"Public Domain"
#endif

#ifdef RUNTIMEONLY
#define special		"Runtime"
#endif

#ifdef V4SHELL
#define special		"V4AT Shell"
#endif

#ifdef V4AT
#define special		"Version 4 Array Theory"
#endif


#ifdef V6SHELL
#define special		"V6AT Shell"
#endif

#ifdef DTU
#define special		"DTU Professional"
#endif

#ifndef special
#define special "(ERROR!!) No version specified e.g Professional)"
#endif

#ifdef DEBUG
#define debugstatus	" DEBUG"
#else
#define debugstatus	""
#endif


#endif
