/*1 4 7 for no error
  0 0 0 for error in 1
  1 1 2 for error in 2
  0 1 2 for error in 3
  1 2 3 for error in 4*/
#include<setjmp.h>
#include<stdio.h>

int fun4(jmp_buf env , int i)
{
    if (i == 0) longjmp(env, 4);
    return 10;
}
int fun3(jmp_buf env, int j)
{
    if (j == 3) longjmp(env, 3);
    return fun4(env, j + 1);
}
int fun2(jmp_buf env, int p, int q)
{
    if (p == 2) longjmp(env, 2);
    return fun3(env, p + q) + fun3(env, p - q);
}
int fun1(jmp_buf env, int l, int m, int n)
{
    if ((l + m + n) == 0) longjmp(env, 1);
    return fun2(env, l + m, l + n);
}

int main()
{
    jmp_buf env;
    int s, l, m, n;
    printf("Enter values(integer) for l m and n please\n");
    scanf("%d%d%d", &l, &m, &n);
    s = setjmp(env);
    if (s != 0) {
        printf("There is an error in function %d exiting..\n", s);
        return 0;
    }
    fun1(env, l, m, n);
    printf("The functions executed normally\n");
}

