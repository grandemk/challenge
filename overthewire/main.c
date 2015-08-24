#include <unistd.h>
#include <stdio.h>
int main(void)
{
    char *env[12];
    for (int i = 0; i < 10; ++i)
        snprintf(env[i], 1, "%i", i);

    env[11] = NULL;

    printf("try executing utumno5");
    execve("./utumno5", NULL, env);
    printf("failed executing utumno5");
    return 0;
}
