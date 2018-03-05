#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <semaphore.h>
#include <sched.h>
#include <errno.h>
#include <dirent.h>

#include <SDL.h>

#include "quakedef.h"
#include "server.h"
#include "pcre.h"

#include "EX_browser.h"

int common_main(int argc, char **argv)
{
    printf("connectbr prototype\n");
    //COM_InitArgv (argc, argv);
    if (argc<2) {
        printf("Usage: connectbr <ip>\n");
        return 1;
    }
    Host_Init (argc, argv, 0);
    SB_PingTree_Wait();
    GetServerPingsAndInfos(true);
    SB_PingTree_Shutdown();
    //SB_ExecuteQueuedTriggers();
    //Cmd_TokenizeString("connectbr 95.31.7.191:30000\n");
    SB_PingTree_DumpPathStr(argv[1]);
    return 0;
}
