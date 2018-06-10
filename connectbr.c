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

void proxy_json(void)
{

}

int common_main(int argc, char **argv)
{
    //proxy_json();
    //if (1) return 1;
    char str_adr[255];
    printf("connectbr prototype\n");
    //COM_InitArgv (argc, argv);
    if (argc<2) {
        printf("no arguments given, waiting for user input\n");
        printf("Type address of server: ");
        scanf("%s",str_adr);
    }
    else {
        strncpy(str_adr,argv[1],255);
    }
    Host_Init (argc, argv, 0);
    netadr_t adr;

    if (!NET_StringToAdr(str_adr, &adr)) {
        Com_Printf("Invalid address\n");
        return 1;
    }

    SB_PingTree_Wait();
    GetServerPingsAndInfos(true);
    SB_PingTree_Shutdown();
    SB_PingTree_DumpPathStr(str_adr);

#ifdef _WIN32
    if (argc<2) {
        printf("press any key...");
        getchar();
   }
#endif
    return 0;
}
