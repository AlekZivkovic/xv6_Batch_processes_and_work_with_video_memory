

//jobless sluzi kao bool za tren posao;
#define MAXJOBS 64

typedef struct job_{
	int id;
	int proc_id; //da bi znali koji proc radi posao      prosledjuje se id proca 
	int pred_id;
	char prog[32];
	char argv[8][32];
}job;




