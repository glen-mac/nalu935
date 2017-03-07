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
    */

    if (strcmp(u.version, "Darwin Kernel Version 16.3.0: Tue Nov 29 21:40:09 PST 2016; root:xnu-3789.32.1~4/RELEASE_ARMv7_") == 0) {
        allproc_offset = 0x;
        rootvnode_offset = 0x;
    }
