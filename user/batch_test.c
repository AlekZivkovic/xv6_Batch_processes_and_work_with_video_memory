#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/job.h"


/*
typedef struct job_{
	int id;
	int proc_id; //da bi znali koji proc radi posao      prosledjuje se id proca 
	int pred_id;
	char prog[32];
	char argv[8][32];
}job;
*/

static int testing=0;

int
main(int argc, char *argv[])
{
	
	
	job posao[3];
	
	posao[0]=( struct job_ ){0,-2,-1,{'/','b','i','n','/','p','r','i','n','t','_','s','t','r','\0'}, 
		{ {'p','r','i','n','t','_','s','t','r','\0'}, {'-','t','\0'}, {'1','0','0','\0'}, {'-','s','\0'}, {'f','i','r','s','t','\0'} } };
	
	posao[1]=( struct job_ ){1,-2,-1,{'/','b','i','n','/','p','r','i','n','t','_','s','t','r','\0'}, 
		{ {'p','r','i','n','t','_','s','t','r','\0'}, {'-','t','\0'}, {'3','0','0','\0'}, {'-','s','\0'}, {'s','e','c','o','n','d','\0'} } };

	posao[2]=( struct job_ ){2,-2,1,{'/','b','i','n','/','p','r','i','n','t','_','s','t','r','\0'}, 
		{ {'p','r','i','n','t','_','s','t','r','\0'}, {'-','t','\0'}, {'1','0','0','\0'}, {'-','s','\0'}, {'t','h','i','r','d','\0'} } };

	
	//printf("\\\\\\\\\\ \n PRVI TEST\n \\\\\\\\\\\\\\\\ \n");
	start_batch(posao,3);
	
	while(testing <3){
		testing++;

		wait();
			
	}
	
	//printf("\n ===================================\n");
	
	testing=0;
	job posao1[4];

	posao1[0]=( struct job_ ){0,-2,-1,{'/','b','i','n','/','p','r','i','n','t','_','s','t','r','\0'}, 
		{ {'p','r','i','n','t','_','s','t','r','\0'}, {'-','s','\0'}, {'f','i','r','s','t','\0'} } };
	
	posao1[1]=( struct job_ ){1,-2,0,{'/','b','i','n','/','p','r','i','n','t','_','s','t','r','\0'}, 
		{ {'p','r','i','n','t','_','s','t','r','\0'}, {'-','s','\0'}, {'s','e','c','o','n','d','\0'} } };

	posao1[2]=( struct job_ ){2,-2,0,{'/','b','i','n','/','p','r','i','n','t','_','s','t','r','\0'}, 
		{ {'p','r','i','n','t','_','s','t','r','\0'}, {'-','s','\0'}, {'t','h','i','r','d','\0'}, {'-','t','\0'}, {'2','0','0','\0'} } };

	posao1[3]=( struct job_ ){3,-2,2,{'/','b','i','n','/','p','r','i','n','t','_','s','t','r','\0'}, 
		{ {'p','r','i','n','t','_','s','t','r','\0'}, {'-','s','\0'}, {'f','o','r','t','h','\0'} } };
	
	//printf("\\\\\\\\\\ \n DRUGI TEST\n \\\\\\\\\\\\\\\\ \n");	
	start_batch(posao1,4);
	
	while(testing <4){
		testing++;
		wait();
	}
	//printf("\n ===================================\n");
	exit();
}
