#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char *convertIntegerToChar(int N)
{

    // Count digits in number N
    int m = N;
    int digit = 0;
    while (m)
    {

        // Increment number of digits
        digit++;

        // Truncate the last
        // digit from the number
        m /= 10;
    }

    // Declare char array for result
    char *arr;

    // Declare duplicate char array
    char arr1[digit];

    // Memory allocation of array
    arr = (char *)malloc(digit);

    // Separating integer into digits and
    // accommodate it to character array
    int index = 0;
    while (N)
    {

        // Separate last digit from
        // the number and add ASCII
        // value of character '0' is 48
        arr1[++index] = N % 10 + '0';

        // Truncate the last
        // digit from the number
        N /= 10;
    }

    // Reverse the array for result
    int i;
    for (i = 0; i < index; i++)
    {
        arr[i] = arr1[index - i];
    }

    // Char array truncate by null
    arr[i] = '\0';

    // Return char array
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
        printf("%s\n", j);

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
        printf("%s\n", j);
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
        printf("%s\n", j);
    }

    // while (1);

    return 0;
}