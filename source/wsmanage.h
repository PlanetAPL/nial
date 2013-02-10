/*==============================================================

  WSMANAGE.H:  header for WSMANAGE.C

  COPYRIGHT NIAL Systems Limited  1983-2005

  This contains the prototypes of the workspace load and save functions

================================================================*/

/* Flags used by doloadsave */
enum {
  NC_WS_LOAD = 1, NC_WS_SAVE, NC_WS_LEAVING
};

enum {
  FORCE_EXTENSION = 1, NOFORCE_EXTENSION = 0
};

extern void wsdump(FILE * f1);
extern void wsload(FILE * f1, int user);
extern void check_ext(char *str, char *ext,int force);
extern int  loaddefs(int fromfile, char *fname, int mode);

