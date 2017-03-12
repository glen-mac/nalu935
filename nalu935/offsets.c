#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/utsname.h>

#include "offsets.h"

uint64_t allproc_offset;
uint64_t kernproc_offset;
uint64_t procoff;
uint64_t rootvnode_offset;

void init_offsets() {
    struct utsname u = { 0 };
    uname(&u);

    printf("sysname: %s\n", u.sysname);
    printf("nodename: %s\n", u.nodename);
    printf("release: %s\n", u.release);
    printf("version: %s\n", u.version);
    printf("machine: %s\n", u.machine);

    allproc_offset = 0x;
    procoff = 0x;
    rootvnode_offset = 0x;

    /*
    Offsets shared by:
    - @iosusr
    - @OothecaPickle
    */

    if (strcmp(u.version, "Darwin Kernel Version 15.6.0: Fri Aug 19 10:37:55 PDT 2016; root:xnu-3248.61.1~1/RELEASE_ARM_S5L8950X") == 0) {
        allproc_offset = 0x45f2c8;
        rootvnode_offset = 0x419128;
    } // iPhone5,1-5,4 Offsets

    if (strcmp(u.version, "Darwin Kernel Version 15.6.0: Fri Aug 19 10:37:55 PDT 2016; root:xnu-3248.61.1~1/RELEASE_ARM_S5L8945X") == 0) {
        allproc_offset = 0x45717c;
        rootvnode_offset = 0x411120;
    } // iPad3,1-3,3 Offsets
    
    if (strcmp(u.version, "Darwin Kernel Version 15.6.0: Fri Aug 19 10:37:55 PDT 2016; root:xnu-3248.61.1~1/RELEASE_ARM_") == 0) {
        allproc_offset = ;
        rootvnode_offset = ;
    } // iPhone Offsets

    if (strcmp(u.version, "Darwin Kernel Version 15.6.0: Fri Aug 19 10:37:55 PDT 2016; root:xnu-3248.61.1~1/RELEASE_ARM_") == 0) {
        allproc_offset = ;
        rootvnode_offset = ;
    } // iPad Offsets
    
    }//some beta ios
    else {
        printf("missing offset, prob crashing\n");
    }
}
