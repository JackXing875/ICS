#include <unistd.h>

int main(int argc, char *argv[]) 
{
    const char msg[] = "Hello, World!\n";
    asm volatile (
        "mov $1, %%rax\n\t"        // sys_write
        "mov $1, %%rdi\n\t"        // fd = 1 (stdout)
        "lea %[str], %%rsi\n\t"    // buf = msg
        "mov %[len], %%rdx\n\t"    // len
        "syscall\n\t"
        :
        : [str]"m"(msg), [len]"r"(sizeof(msg)-1)
        : "rax", "rdi", "rsi", "rdx"
    );
    return 0;
}
