
#include<setjmp.h>
#include<stdio.h>

int me_first(char *s,jmp_buf env){
    int i;
    i=setjmp(env);
    printf("me_first:I am returning after a setjmp:%s\n",s);
    return i;
}

int i_follow(int i,jmp_buf env){
    printf("i_follow:I'm gonna do a longjmp...\n");
        longjmp(env,i);
}


int main()
{
    jmp_buf env;
    if(me_first("IC-Labs",env)!=0) return 0;
    i_follow(3,env);

}
