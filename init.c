#include <sys/mount.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/reboot.h>
#include <linux/reboot.h>

int main(void) {
    mount("proc", "/proc", "proc", 0, NULL);
    mount("sysfs", "/sys", "sysfs", 0, NULL);
    printf("NimomOS starting... Niminit succeeded...\n");

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        execl("/bin/sh", "sh", NULL);
        perror("execl failed");
        exit(1);
    } else {
        waitpid(pid, NULL, 0);
        
        printf("Shell exited. Shutting down NimomOS...\n");
        reboot(LINUX_REBOOT_CMD_POWER_OFF);
        while(1) { sleep(1); }
    }

    return 0;
}
