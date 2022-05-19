#include "local.h"


void main(int argc, char *argv[]){

// put the sleep in all the childs
    key_t key;
    int shmid;
    char *data;
    char *man;
    //int mode,mode1;

    int j;
    char pos[1];

   int x=1,y=100,z=0,m=0,flage=0,flage2=0;
   //x for the water pick
   //a for the sand pick
   //from shared mem
   
  
   
   for(int i=0;i<2;i++){
   
   printf("arg  : %d\n",atoi(argv[i]));
   fflush(stdout);
   }
   while(1){
   
   if(atoi(argv[1]) == 0){
   
    if ((key = ftok("grab.txt", 'R')) == -1) /*Here the file must exist */ { 
      perror("ftok in grab");
      exit(1);
    }
    /*  create the segment: */
    if ((shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT)) == -1) {
        perror("shmget in grab");
        exit(1);
    }
    /* attach to the segment to get a pointer to it: */
    if ((data = shmat(shmid, NULL, 0)) == (void *)-1) {
        perror("shmat in grab");
        exit(1);
    }
   
   
       //printf("\n");
       //fflush(stdout);
       //sleep(1);
      
   }
   else{
    if ((key = ftok("grab1.txt", 'R')) == -1) /*Here the file must exist */ { 
      perror("ftok in grab");
      exit(1);
    }
    /*  create the segment: */
    if ((shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT)) == -1) {
        perror("shmget in grab");
        exit(1);
    }
    /* attach to the segment to get a pointer to it: */
    if ((data = shmat(shmid, NULL, 0)) == (void *)-1) {
        perror("shmat in grab");
        exit(1);
    }
    }
   
   if ( argc != 2) {
    fprintf(stderr, "%s producer_time consumer_time\n", argv[0]);
    exit(-1);
   }
   
   
   
   for(int i=1; i> 20;i++){
      j=i;
      sprintf(pos,"%d",j);
      strncpy(data, j, SHM_SIZE);
       /*printf("\r                                               ");
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
       
   for(int i=19; i> 0;i--){
   j=i;
      sprintf(pos,"%d",j);
   strncpy(data, j, SHM_SIZE);
       /*printf("\r                                               ");
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
       
       }  
}
