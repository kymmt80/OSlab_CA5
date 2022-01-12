#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char *convertIntegerToChar(int N)
{
    int m = N;
    int digit = 0;
    while (m)
    {
        digit++;
        m /= 10;
    }
    char *arr;
    char arr1[digit];
    arr = (char *)malloc(digit);
    int index = 0;
    while (N)
    {
        arr1[++index] = N % 10 + '0';
        N /= 10;
    }
    int i;
    for (i = 0; i < index; i++)
    {
        arr[i] = arr1[index - i];
    }
    arr[i] = '\0';
    return (char *)arr;
}

int main(int argc, char const *argv[])
{
    int pid_read, pid_power_2, pid_power_3;
    pid_read = fork();
    if (pid_read == 0)
    {
        char *j;

        int fd = 0;
        int prot = 0;
        void *addr = 0;

        fd = open("temp.txt", O_RDWR);

        j = mmap(addr, 10, prot, MAP_PRIVATE, fd, 0);
        printf(1,"%s\n", j);

        close(fd);
    }

    pid_power_2 = fork();
    if (pid_power_2 == 0)
    {
        char *j;

        int fd = 0;
        int prot = 0;
        void *addr = 0;

        fd = open("temp.txt", O_RDWR);

        j = mmap(addr, 10, prot, MAP_PRIVATE, fd, 0);

        char *t;

        int count = 0;
        for (t = j; *t != '\0'; t++)
        {
            int x = t[0] - '0';
            x = x * x;

            int a = x;
            while (x)
            {

                count *= 10;
                x /= 10;
            }
            count += a;
        }
        j = convertIntegerToChar(count);

        close(fd);
        printf(1,"%s\n", j);
    }

    pid_power_3 = fork();
    if (pid_power_3 == 0)
    {
        char *j;

        int fd = 0;
        int prot = 0;
        void *addr = 0;

        fd = open("temp.txt", O_RDWR);

        j = mmap(addr, 10, prot, MAP_PRIVATE, fd, 0);

        char *t;

        int count = 0;
        for (t = j; *t != '\0'; t++)
        {
            int x = t[0] - '0';
            x = x * x * x;

            int a = x;
            while (x)
            {

                count *= 10;
                x /= 10;
            }
            count += a;
        }
        j = convertIntegerToChar(count);

        close(fd);
        printf(1,"%s\n", j);
    }

    // while (1);

    return 0;
}