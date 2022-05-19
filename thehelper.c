#include "local.h"


void main(int argc, char *argv[]){


   int x=1,y=100,z=0,m=0,flage=0,flage2=0;
   //x for the water pick
   //a for the sand pick
   //from shared mem
   char *the_Obstruction_location;
   key_t key,key1;
    int shmid,shmid1;
    char *data;
    char *data1;
    char *man;
    char pos[1];
   
   if ( argc != 2) {
    fprintf(stderr, "%s producer_time consumer_time\n", argv[0]);
    exit(-1);
   }
   
   for(int i=0;i<2;i++){
   
   printf("arg  : %d\n",atoi(argv[i]));
   fflush(stdout);
   }
   
   while(1){
   
   if(atoi(argv[1]) == 0){
   
    if ((key = ftok("help.txt", 'R')) == -1) /*Here the file must exist */ { 
      perror("ftok in help");
      exit(1);
    }
    /*  create the segment: */
    if ((shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT)) == -1) {
        perror("shmget in help");
        exit(1);
    }
    /* attach to the segment to get a pointer to it: */
    if ((data = shmat(shmid, NULL, 0)) == (void *)-1) {
        perror("shmat in help");
        exit(1);
    }
   
       //printf("\n");
       //fflush(stdout);
       //sleep(1);
       
   if ((key1 = ftok("ostruction.txt", 'R')) == -1) /*Here the file must exist */ { 
      perror("ftok in help");
      exit(1);
    }
    /*  create the segment: */
    if ((shmid1 = shmget(key1, SHM_SIZE, 0644 | IPC_CREAT)) == -1) {
        perror("shmget in help");
        exit(1);
    }
    /* attach to the segment to get a pointer to it: */
    if ((data1 = shmat(shmid1, NULL, 0)) == (void *)-1) {
        perror("shmat in help");
        exit(1);
    }
    the_Obstruction_location=data1;    
      
   }
   else{
    if ((key = ftok("help1.txt", 'R')) == -1) /*Here the file must exist */ { 
      perror("ftok");
      exit(1);
    }
    /*  create the segment: */
    if ((shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT)) == -1) {
        perror("shmget");
        exit(1);
    }
    /* attach to the segment to get a pointer to it: */
    if ((data = shmat(shmid, NULL, 0)) == (void *)-1) {
        perror("shmat in help");
        exit(1);
    }
    
    if ((key1 = ftok("ostruction1.txt", 'R')) == -1) /*Here the file must exist */ { 
      perror("ftok");
      exit(1);
    }
    /*  create the segment: */
    if ((shmid1 = shmget(key1, SHM_SIZE, 0644 | IPC_CREAT)) == -1) {
        perror("shmget");
        exit(1);
    }
    /* attach to the segment to get a pointer to it: */
    if ((data1 = shmat(shmid1, NULL, 0)) == (void *)-1) {
        perror("shmat");
        exit(1);
    }
    
    the_Obstruction_location=data1;
    }
   
   if ( argc != 2) {
    fprintf(stderr, "%s producer_time consumer_time\n", argv[0]);
    exit(-1);
   }
   
   
   
   for(int i=0; i> atoi(the_Obstruction_location);i++){
   the_Obstruction_location=data1;
      int j=i;
      sprintf(pos,"%d",j);
      strncpy(data, j, SHM_SIZE);
      /* printf("\r                                               ");
       printf("\r");
        printf("%d",y);
          if (j==i)
           {
               printf("P11");
               fflush(stdout); 
               x--;              
           }
           else
             {               
                 printf(".");
                 fflush(stdout);
             }*/
             
             sleep(1);
       }
       
   for(int i=atoi(the_Obstruction_location); i> 0;i--){
   int j=i;
      sprintf(pos,"%d",j);
   strncpy(data, j, SHM_SIZE);
       //printf("\r                                               ");
       //printf("\r");
        //printf("%d",y);
          /*if (j==i)
           {
               printf("P11");
               fflush(stdout); 
               x--;              
           }
           else
             {              
                 printf(".");
                 fflush(stdout);
             }*/
             sleep(1);
       }
       }  
}   
   
