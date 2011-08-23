#include <kernel/kstdlib.h>

#define kTaskListBase (task_t *)0x20000
#define kTaskCount (int *)0x509
#define kTaskCurrent (int *)0x50D
#define kTaskPID (pid_t *)0x511

#define kTaskSpaceStart (void *)0x100000
#define kTaskSpacePerTask 0x10000
#define kTaskSpacePerKernTask 0x10000

typedef unsigned int pid_t;

typedef struct {
	char ldt[16];
	pid_t pid;
	unsigned int edi;
	unsigned int esi;
	unsigned int ebp;
	unsigned int esp;
	unsigned int ebx;
	unsigned int edx;
	unsigned int ecx;
	unsigned int eax;
	unsigned int ds;
	unsigned int ss;
	unsigned int gs;
	unsigned int fs;
	unsigned int es;
	unsigned int cs;
	unsigned int eip;
	unsigned int eflags;
	char * basePtr;
} __attribute__((__packed__)) task_t;


void task_list_reset ();
int task_list_count ();
pid_t task_list_current ();
osStatus task_get (pid_t pid, task_t * destination);
pid_t task_next_pid ();
osStatus task_kill (pid_t pid);
osStatus task_start (char * codeBase, unsigned short length, pid_t * pid);

