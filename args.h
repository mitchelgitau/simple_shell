#ifndef _ARGS_H_
#define _ARGS_H_

#include "shell.h"

#define LOGFILE ".simple_shell_history"
#define MAXLOGSIZE 4096
#define MAXBUFREAD 1024

/* log01.c */
int _add_log(sev *ptr_sev);
int _write_log(sev *ptr_sev);
int _log_count(sev *ptr_sev);

#endif /* _ARGS_H_ */
