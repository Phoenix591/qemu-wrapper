/*
 * pass arguments to qemu binary
 */

#include <string.h>
#include <unistd.h>

/* Some defaults for people who don't want to use 
	a build system or command line defines */

#ifndef CPU
#define CPU cortex-a72
#endif

#ifndef ARCH
#define ARCH aarch64
#endif

int main(int argc, char **argv, char **envp) {
	char *newargv[argc + 3];

	newargv[0] = argv[0];
	newargv[1] = "-cpu";
	newargv[2] = CPU; /* here you can set the cpu you are
	building for */

	memcpy(&newargv[3], &argv[1], sizeof(*argv) * (argc -1));
	newargv[argc + 2] = NULL;
	return execve("/usr/bin/qemu-"ARCH, newargv, envp);
}
