/* simplesh.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main()
{
char buf[256];
char *argv[50];
int narg;
pid_t pid;
while (1) {
	printf("shell> ");
	gets(buf);
	narg = getargs(buf, argv);
	pid = fork();
	if (pid == 0)
		execvp(argv[0], argv);
	else if (pid > 0)
		wait((int *) 0);
	else
		perror("fork failed");
	}//while문
}//main 문


int getargs(char *cmd, char **argv){	
int narg = 0;
printf("\n 입력하신 명령어 %s 입니다. \n ",cmd);

if(!strcmp(cmd,"exit")){
printf("\n프로그램을 종료합니다 \n");
exit(0);

}



while (*cmd) {
	if (*cmd == ' ' || *cmd == '\t')
			*cmd++ = '\0';

   else if(*cmd == '>' || *cmd == '>'+'>' || *cmd =='<'){
			
         argv[narg]=(char*)0;
                 printf("여기통과");
          execvp(argv[0],argv);
            argv[narg++] = cmd++;
            cmd++;
         
    
				
}	
		else {
				argv[narg++] = cmd++;
		while (*cmd != '\0' && *cmd != ' '&& *cmd != '\t')
		cmd++;
			}//else문

}//while문
/*
int i=0;
for(i=0;i<10;i++){
printf("%s\n",argv[i]);
}
*/

argv[narg] = NULL;

return narg;

}//함수
