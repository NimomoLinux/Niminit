#include <sys/mount.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/reboot.h>
#include <linux/reboot.h>

int main(void)
{
    if (mount("proc", "/proc", "proc", 0, NULL) < 0)
        perror("mount /proc");

    if (mount("sysfs", "/sys", "sysfs", 0, NULL) < 0)
        perror("mount /sys");

    printf("NimomOS starting...\n");
    fflush(stdout);

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        printf("Starting shell...\n");
        fflush(stdout);

        execl("/bin/sh", "sh", NULL);

        perror("execl /bin/sh");
        _exit(1);
}
