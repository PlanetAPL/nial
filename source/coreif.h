/*=============================================================
 *
 * HEADER   COREIF.H
 *

  COPYRIGHT NIAL Systems Limited  1983-2005

  This file contains the prototypes of the external interface to 
  the core interpreter.

================================================================

 * PURPOSE:
 * This file should be included by any module that wishes to use
 * the Core Nial Interface (as defined below).  This file provides
 * about 20 interface functions to the Core Nial Interpreter.
 * To use the Core Interpreter an application would typically
 * issue the following call sequence:
 *
 *    NC_LoadLibrary();
 *    NC_InitNial(...);
 *
 *    ---> followed by as many call to:
 *    NC_NialInterpret("each each tell tell 10",...);
 *    char *output = NC_GetBuffer();
 *    ---> as desired
 *
 * The remainder of the routines are used to set up more complex
 * IO for the Core and to manage Interpreted sessions (typically
 * used by GUI interfaces to the Core).
 *
 * The IO and session routines need not be used if the application
 * is content with extracting the results from a simple text buffer.
 *
 * USE OF THIS INCLUDE:
 * Before this file is included, one of the following defined
 * must be set:
 *
 *   UNIXSYS            - All Unix systems that will link in niallib.o
 *   WIN32SLIB          - Win32s systems that will link in the library
 *   WIN32SDLL          - Win32s systems that will use the library as
 *                        as a DLL.  In addition, when using this mode,
 *                        all includes of this file should also define
 *                        either PRIMARY or SECONDARY.  Only ONE file
 *                        should include this with PRIMARY defined, and
 *                        all other must include this with SECONDARY
 *                        defined.
 *============================================================= */

#ifndef	_COREIF_H_  /* ( */
#define	_COREIF_H_

#include "switches.h"
#include "messages.h"

typedef long NC_IOContext,
            NC_WindowSettings,
            NC_SessionSettings;


#ifndef LPSTR
#define LPSTR char *
#endif

#define EXTERN extern

#if      defined(__cplusplus)
extern      "C"
{
#endif

/* INITIALIZATION commands */
EXTERN LPSTR NC_LoadLibrary(void);
EXTERN int  NC_UnLoadLibrary(void);
EXTERN int  NC_SetNialRoot(char *inRoot);
EXTERN int
NC_InitNial(long inSessionSettings,
            long inDefaultWindSettings,
            long inDefaultIOContext);
EXTERN int  NC_StopNial(void);


/* SESSIONSETTINGS commands */
EXTERN long NC_CreateSessionSettings(void);
EXTERN int
NC_SetSessionSetting(long ioSettings,
                     long inFeature, long inValue);
EXTERN int
NC_GetSessionSetting(long ioSettings,
                     long inFeature, long *inValue);
EXTERN int  NC_DestroySessionSettings(long ioSettings);
EXTERN int
NC_SetCheckUserBreak(long ioSettings,
                     long (*inFunc) (long));


/* WINDOWSETTINGS commands */
EXTERN long NC_CreateWindowSettings(void);
    EXTERN int NC_SetWindowSetting(long ioSettings, long inFeature, long inValue);
    EXTERN int NC_SetWindowSettingP(long ioSettings, long inFeature, char * inValue);
    
EXTERN int
NC_GetWindowSetting(long ioSettings,
                    long inFeature, long *outValue);
EXTERN LPSTR NC_GetPrompt(long inSettings);
EXTERN int  NC_DestroyWindowSettings(long ioSettings);


/* IOCONTEXT commands */
EXTERN long NC_CreateIOContext(void);
EXTERN int  NC_SetIOMode(long ioIOContext, long inMode);
EXTERN int
NC_SetWriteCommand(long ioIOContext,
                   void (*inFunc) (void *, LPSTR), void *inTheArg);
EXTERN int
NC_SetReadStringCommand(long ioIOContext,
                        LPSTR(*inFunc) (void *), void *inTheArg);
EXTERN int
NC_SetReadCharCommand(long ioIOContext,
                      char (*inFunc) (void *), void *inTheArg);
EXTERN int  NC_DestroyIOContext(long ioIOContext);


/* BUFFER commands */
EXTERN int  NC_SetBufferSize(long inSize, long inIncrement);
EXTERN LPSTR NC_GetBuffer(void);
EXTERN int  NC_CopyBuffer(LPSTR, long);
EXTERN void NC_ResetBuffer(void);


/* INTERPRETER command */
EXTERN int
NC_CommandInterpret(LPSTR inCommand,
                    long ioParams,
                    long inIOContext);


#if      defined(__cplusplus)
}
#endif

/*-- Global variables,types and macros to hold the actual DLL functions */
/* INITIALIZATION commands */
typedef int FUN_TYPE(*SETNIALROOT) (LPSTR);
typedef int FUN_TYPE(*INITNIAL) (long, long, long);
typedef int FUN_TYPE(*STOPNIAL) (void);


/* SESSION SETTINGS commands */
typedef long FUN_TYPE(*CREATESESSIONSETTINGS) (void);
typedef int
FUN_TYPE(*SETSESSIONSETTING) (long,
                              long, long);
typedef int
FUN_TYPE(*GETSESSIONSETTING) (long,
                              long, long *);
typedef int FUN_TYPE(*DESTROYSESSIONSETTINGS) (long);
typedef int FUN_TYPE(*SETCHECKUSERBREAK) (long, long (*fn) (long));


/* WINDOW SETTINGS commands */
typedef long FUN_TYPE(*CREATEWINDOWSETTINGS) (void);
typedef int
FUN_TYPE(*SETWINDOWSETTING) (long,
                             long, long);
typedef int
FUN_TYPE(*GETWINDOWSETTING) (long,
                             long, long *);
typedef LPSTR FUN_TYPE(*GETPROMPT) (long);
typedef int FUN_TYPE(*DESTROYWINDOWSETTINGS) (long);

/* IOCONTEXT commands */
typedef long FUN_TYPE(*CREATEIOCONTEXT) (void);
typedef int FUN_TYPE(*SETIOMODE) (long, long);
typedef int
FUN_TYPE(*SETWRITECOMMAND) (long,
                            void (*) (void *, LPSTR),
                            void *);
typedef int
FUN_TYPE(*SETREADSTRINGCOMMAND) (long,
                                 LPSTR(*) (void *), void *);
typedef int
FUN_TYPE(*SETREADCHARCOMMAND) (long,
                               char (*) (void *), void *);
typedef int FUN_TYPE(*DESTROYIOCONTEXT) (long);


/* BUFFER commands */
typedef int FUN_TYPE(*SETBUFFERSIZE) (long, long);
typedef LPSTR FUN_TYPE(*GETBUFFER) (void);
typedef int FUN_TYPE(*COPYBUFFER) (LPSTR, long);
typedef int FUN_TYPE(*RESETBUFFER) (void);


/* INTERPRETER command */
typedef int
FUN_TYPE(*COMMANDINTERPRET) (LPSTR, long,
                             long);

/* The following structure hold function pointers to all the DLL
 * access functions.  The structure form is convenient for later
 * declarations in secondary modules
 */
typedef struct {
/* INITIALIZATION commands */
  SETNIALROOT NC_SetNialRoot_fun;
  INITNIAL    NC_InitNial_fun;
  STOPNIAL    NC_StopNial_fun;
/* SESSION SETTINGS commands */
  CREATESESSIONSETTINGS NC_CreateSessionSettings_fun;
  SETSESSIONSETTING NC_SetSessionSetting_fun;
  GETSESSIONSETTING NC_GetSessionSetting_fun;
  DESTROYSESSIONSETTINGS NC_DestroySessionSettings_fun;
  SETCHECKUSERBREAK NC_SetCheckUserBreak_fun;
  /* WINDOW SETTINGS commands */
  CREATEWINDOWSETTINGS NC_CreateWindowSettings_fun;
    SETWINDOWSETTING NC_SetWindowSetting_fun;
  GETWINDOWSETTING NC_GetWindowSetting_fun;
  GETPROMPT   NC_GetPrompt_fun;
  DESTROYWINDOWSETTINGS NC_DestroyWindowSettings_fun;
/* IOCONTEXT commands */
  CREATEIOCONTEXT NC_CreateIOContext_fun;
  SETIOMODE   NC_SetIOMode_fun;
  SETWRITECOMMAND NC_SetWriteCommand_fun;
  SETREADSTRINGCOMMAND NC_SetReadStringCommand_fun;
  SETREADCHARCOMMAND NC_SetReadCharCommand_fun;
  DESTROYIOCONTEXT NC_DestroyIOContext_fun;
/* BUFFER commands */
  SETBUFFERSIZE NC_SetBufferSize_fun;
  GETBUFFER   NC_GetBuffer_fun;
  COPYBUFFER  NC_CopyBuffer_fun;
  RESETBUFFER NC_ResetBuffer_fun;
/* INTERPRETER command */
  COMMANDINTERPRET NC_CommandInterpret_fun;
}           NC_CoreFunctions_struct;


struct NC_FunctionLoadTable_struct {
  long        index;
  LPSTR       LoadName;
  FARPROC    *FunctionPointer;
};

/* INITIALIZATION commands */
#define NC_InitNial          (NC_CoreFunctions.NC_InitNial_fun)
#define NC_StopNial          (NC_CoreFunctions.NC_StopNial_fun)
#define NC_SetNialRoot       (NC_CoreFunctions.NC_SetNialRoot_fun)

/* SESSION SETTINGS commands */
#define NC_CreateSessionSettings 	(NC_CoreFunctions.NC_CreateSessionSettings_fun)
#define NC_SetSessionSetting 		(NC_CoreFunctions.NC_SetSessionSetting_fun)
#define NC_GetSessionSetting 		(NC_CoreFunctions.NC_GetSessionSetting_fun)
#define NC_DestroySessionSettings 	(NC_CoreFunctions.NC_DestroySessionSettings_fun)
#define NC_SetCheckUserBreak 	(NC_CoreFunctions.NC_SetCheckUserBreak_fun)

/* WINDOW SETTINGS commands */
#define NC_CreateWindowSettings 	(NC_CoreFunctions.NC_CreateWindowSettings_fun)
#define NC_SetWindowSetting 		(NC_CoreFunctions.NC_SetWindowSetting_fun)
#define NC_GetWindowSetting 		(NC_CoreFunctions.NC_GetWindowSetting_fun)
#define NC_GetPrompt 				(NC_CoreFunctions.NC_GetPrompt_fun)
#define NC_DestroyWindowSettings (NC_CoreFunctions.NC_DestroyWindowSettings_fun)

/* IOCONTEXT commands */
#define NC_CreateIOContext 		(NC_CoreFunctions.NC_CreateIOContext_fun)
#define NC_SetIOMode 				(NC_CoreFunctions.NC_SetIOMode_fun)
#define NC_SetWriteCommand 		(NC_CoreFunctions.NC_SetWriteCommand_fun)
#define NC_SetReadStringCommand 	(NC_CoreFunctions.NC_SetReadStringCommand_fun)
#define NC_SetReadCharCommand 	(NC_CoreFunctions.NC_SetReadCharCommand_fun)
#define NC_DestroyIOContext 		(NC_CoreFunctions.NC_DestroyIOContext_fun)


/* BUFFER commands */
#define NC_SetBufferSize 	(NC_CoreFunctions.NC_SetBufferSize_fun)
#define NC_GetBuffer 		(NC_CoreFunctions.NC_GetBuffer_fun)
#define NC_CopyBuffer      (NC_CoreFunctions.NC_CopyBuffer_fun)
#define NC_ResetBuffer 		(NC_CoreFunctions.NC_ResetBuffer_fun)


/* INTERPRETER command */
#define NC_CommandInterpret (NC_CoreFunctions.NC_CommandInterpret_fun)

#endif             /* WINDLL ) */

#endif             /* _COREIF_H_  ) */
