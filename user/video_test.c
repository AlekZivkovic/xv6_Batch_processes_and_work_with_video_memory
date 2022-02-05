#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"



#define CGA 0x0 ;
void ispis();

static int bg=0x1;
static int fg=14;
static int row=0;
static int col=0;
static char str[32]={'h','e','l','l','o',' ','w','o','r','l','d'};
char *pointer=str;

char help[6]={'-','-','h','e','l','p'};
char roww[5]={'-','-','r','o','w'};
char coll[5]={'-','-','c','o','l'};
char st[5]={'-','-','s','t','r'};
char nfg[4]={'-','-','f','g'};
char nbg[4]={'-','-','b','g'};
int
main(int argc, char *argv[])
{
	int  i;
	char *p,*p1;
	int boja=0x0000;

	ushort *crt=(ushort*)CGA;

	
	for(i = 1; i < argc; i++){
				
		p=&help[1];
		p1=help;
	
		if( (strcmpp(p1,argv[i],6)==0 && strlen(argv[i]) == 6 ) || ( strcmpp(p,argv[i],2)==0 && strlen(argv[i]) == 2 ) ){
			ispis();
			exit();
		}
		
		p=&roww[1];
		p1=roww;
	
		
		if((strcmpp(p1,argv[i],5)==0 && strlen(argv[i]) == 5 ) || (strcmpp(p,argv[i],2)==0 && strlen(argv[i]) == 2 ) ){
			if(i+1>argc && argv[i+1][0]=='-'){
				printf("video_test: params for %s are missing try help\n",argv[i]);
				exit();			
			}			
			
			row=atoi(argv[i+1])%26;
			if(row>0)
				row--;
			continue;
			
		}
		p=&coll[1];
		p1=coll;
	
		
		if((strcmpp(p1,argv[i],5)==0 && strlen(argv[i]) == 5 ) || (strcmpp(p,argv[i],2)==0 && strlen(argv[i]) == 2 ) ){
			if(i+1>argc && argv[i+1][0]=='-'){
				printf("video_test: params for %s are missing try help\n",argv[i]);
				exit();			
			}			
			
			col=atoi(argv[i+1])%81;
			if(col>0)
				col--;
			continue;
			
		}
		
		p=&st[1];
		p1=st;
	
		
		if((strcmpp(p1,argv[i],5)==0 && strlen(argv[i]) == 5 ) || (strcmpp(p,argv[i],2)==0 && strlen(argv[i]) == 2 ) ){
			if(i+1>argc && argv[i+1][0]=='-'){
				printf("video_test: params for %s are missing try help\n",argv[i]);
				exit();			
			}			
			
			strcpy(str,argv[i+1]);
			continue;
			
		}


		p1=nfg;
	
		
		if((strcmpp(p1,argv[i],4)==0 && strlen(argv[i]) == 4 ) ) {
			if(i+1>argc && argv[i+1][0]=='-'){
				printf("video_test: params for %s are missing try help\n",argv[i]);
				exit();			
			}			
			
			fg=atoi(argv[i+1])%16;
			
			continue;
			
		}

		p1=nbg;
		
		if((strcmpp(p1,argv[i],4)==0 && strlen(argv[i]) == 4 ) ) {
			if(i+1>argc && argv[i+1][0]=='-'){
				printf("video_test: params for %s are missing try help\n",argv[i]);
				exit();			
			}			
			
			bg=atoi(argv[i+1])%16;
			continue;
			
		}
		
		
		
	}
	boja= (boja &0xf000);
	boja|=(fg << 8);
	
	
	boja= (boja &0x0f00);
	boja|=(bg << 12 );
	
	
	
	int poz= 80*row+col;
	
	for(int i=0;i<strlen(str);i++){
		crt[poz++]=(str[i]&0xff) | boja;
	}
	


	exit();
}



void ispis(){

printf("\nUse this program to test direct video memmory mapping\n"
"Usage: video_test [OPTION]... [FILE]...\n"
"\nCommand line options\n"
"  -h,  --help: Show help prompt.\n"
"  -c,  --col: Change collum for printing.\n"
"  -r,  --row: Change row for printing \n"
"  -s,  --str: Change string output \n"
"  --fg: Change color text of string output \n"
"  --bg: Change color backround of string output \n");


return;
}
