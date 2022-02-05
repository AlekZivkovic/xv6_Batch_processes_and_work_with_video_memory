#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"




char _str [32]={'h','e','l','o','\0'};
char *str=_str;
int tick=100;


void ispis();
char help[6]={'-','-','h','e','l','p'};
char tic[7]={'-','-','t','i','c','k','s'};
char st[5]={'-','-','s','t','r'};
int
main(int argc, char *argv[])
{

	
	int  i;
	char *p,*p1;
	
	for(i = 1; i < argc; i++){
				
		p=&help[1];
		p1=help;
	
		if( (strcmpp(p1,argv[i],6)==0 && strlen(argv[i]) == 6 ) || ( strcmpp(p,argv[i],2)==0 && strlen(argv[i]) == 2 ) ){
			ispis();
			exit();
		}
		
		p=&tic[1];
		p1=tic;
	
		
		if((strcmpp(p1,argv[i],7)==0 && strlen(argv[i]) == 7 ) || (strcmpp(p,argv[i],2)==0 && strlen(argv[i]) == 2 ) ){
			if(i+1>argc && argv[i+1][0]=='-'){
				printf("print_str: params for %s are missing try help\n",argv[i]);
				exit();			
			}			
			
			tick=atoi(argv[i+1]);
			continue;
			
		}
		
		p=&st[1];
		p1=st;
	
		
		if((strcmpp(p1,argv[i],5)==0 && strlen(argv[i]) == 5 ) || (strcmpp(p,argv[i],2)==0 && strlen(argv[i]) == 2 ) ){
			if(i+1>argc && argv[i+1][0]=='-'){
				printf("print_str: params for %s are missing try help\n",argv[i]);
				exit();			
			}			
			
			strcpy(str,argv[i+1]);
			continue;
			
		}
		
		
		
	}


	sleep(tick);
	printf("%s \n",str);		


	exit();
}



void ispis(){

printf("\nUse this program to print string on a console with sleep involve\n"
"Usage: ptrint_str [OPTION]... [FILE]...\n"
"\nCommand line options\n"
"  -h,  --help: Show help prompt.\n"
"  -t,  --ticks: Change sleep time."
"  -s,  --str: Change string output \n");


return;
}
