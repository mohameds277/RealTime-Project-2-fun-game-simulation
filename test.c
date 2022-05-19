#include "local.h"


void main(int argc, char *argv[]){


   int x,a,u,y=100,z=0,z1,m=0,flage=0,flage2=0;
   //x for the water pick
   //a for the sand pick
   //from shared mem
   key_t key,key1,key2,key3;
    int shmid,shmid1,shmid2,shmid3;
    char *data;
    char *data1;
    char *data2;
    char *data3;
    char *water_delivered;
    char *my_location;
    char *graber_location;
    char *helper_loaction;
    //int mode,mode1;

    int j;
    char pos[1];
   
   if ( argc != 2) {
    fprintf(stderr, "%s producer_time consumer_time\n", argv[0]);
    exit(-1);
   }
   
   for(int i=0;i<2;i++){
   
   printf("arg  : %d\n",atoi(argv[i]));
   fflush(stdout);
   }
   
   if(atoi(argv[1]) == 0){
       if ((key = ftok("frist.txt", 'R')) == -1) /*Here the file must exist */ { 
      perror("ftok in test");
      exit(1);
    }
    /*  create the segment: */
    if ((shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT)) == -1) {
        perror("shmget in test");
        exit(1);
    }
    /* attach to the segment to get a pointer to it: */
    if ((data = shmat(shmid, NULL, 0)) == (void *)-1) {
        perror("shmatin test");
        exit(1);
    }
    
    if ((key1 = ftok("grab.txt", 'R')) == -1) /*Here the file must exist */ { 
      perror("ftok in test);
      exit(1);
    }
    /*  create the segment: */
    if ((shmid1 = shmget(key1, SHM_SIZE, 0644 | IPC_CREAT)) == -1) {
        perror("shmget in test);
        exit(1);
    }
    /* attach to the segment to get a pointer to it: */
    if ((data1 = shmat(shmid1, NULL, 0)) == (void *)-1) {
        perror("shmat in test);
        exit(1);
    }
    
     if ((key2 = ftok("help.txt", 'R')) == -1) /*Here the file must exist */ { 
      perror("ftok in test);
      exit(1);
    }
    /*  create the segment: */
    if ((shmid2 = shmget(key2, SHM_SIZE, 0644 | IPC_CREAT)) == -1) {
        perror("shmget in test);
        exit(1);
    }
    /* attach to the segment to get a pointer to it: */
    if ((data2 = shmat(shmid2, NULL, 0)) == (void *)-1) {
        perror("shmat in test);
        exit(1);
    }
   
       //printf("\n");
       //fflush(stdout);
       //sleep(1);
       
   if ((key3 = ftok("ostruction.txt", 'R')) == -1) /*Here the file must exist */ { 
      perror("ftok in test);
      exit(1);
    }
    /*  create the segment: */
    if ((shmid3 = shmget(key3, SHM_SIZE, 0644 | IPC_CREAT)) == -1) {
        perror("shmget in test);
        exit(1);
    }
    /* attach to the segment to get a pointer to it: */
    if ((data3 = shmat(shmid3, NULL, 0)) == (void *)-1) {
        perror("shmat in test);
        exit(1);
    }  
       //printf("\n");
       //fflush(stdout);
       //sleep(1);
      
   }
   else{
   
    if ((key = ftok("second.txt", 'R')) == -1) /*Here the file must exist */ { 
      perror("ftok in test);
      exit(1);
    }
    /*  create the segment: */
    if ((shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT)) == -1) {
        perror("shmget in test);
        exit(1);
    }
    /* attach to the segment to get a pointer to it: */
    if ((data = shmat(shmid, NULL, 0)) == (void *)-1) {
        perror("shmat in test);
        exit(1);
    }
    
    if ((key1 = ftok("grab1.txt", 'R')) == -1) /*Here the file must exist */ { 
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
    
     if ((key2 = ftok("help1.txt", 'R')) == -1) /*Here the file must exist */ { 
      perror("ftok in test);
      exit(1);
    }
    /*  create the segment: */
    if ((shmid2 = shmget(key2, SHM_SIZE, 0644 | IPC_CREAT)) == -1) {
        perror("shmget in test);
        exit(1);
    }
    /* attach to the segment to get a pointer to it: */
    if ((data2 = shmat(shmid2, NULL, 0)) == (void *)-1) {
        perror("shmat in test);
        exit(1);
    }
   
       //printf("\n");
       //fflush(stdout);
       //sleep(1);
       
   if ((key3 = ftok("ostruction1.txt", 'R')) == -1) /*Here the file must exist */ { 
      perror("ftok in test);
      exit(1);
    }
    /*  create the segment: */
    if ((shmid3 = shmget(key3, SHM_SIZE, 0644 | IPC_CREAT)) == -1) {
        perror("shmget in test);
        exit(1);
    }
    /* attach to the segment to get a pointer to it: */
    if ((data3 = shmat(shmid3, NULL, 0)) == (void *)-1) {
        perror("shmat in test);
        exit(1);
    }  
       //printf("\n");
       //fflush(stdout);
       //sleep(1);
   
   
   
   }
   
   sleep(1);
   
   
   graber_location=data1;
   x=atoi(graber_location);
   
   helper_loaction=data2;
   a=atoi(helper_loaction);
   
   
   



   while(y>0){

   
   
   for (int i = 0; i <= x; i++)
   {


    u=i;
       sprintf(pos,"%d",u);
      strncpy(data3, u, SHM_SIZE);
      graber_location=data1;
   x=atoi(graber_location);
   
   helper_loaction=data2;
   a=atoi(helper_loaction);
   
   printf("\r                                                        ");
   printf("\r");

   if(x==20){
   if(m!=0){
   z=z+m-(flage2*2);
   flage2=0;
   m=0;
   }
   else{
   z=z+10-(flage2*2);
   flage2=0;
   }
   break;}
   
   if(x==1){
   if(y>=10){
   y=y-10;}
   else{
   m=y;
   y=y-m;
   }
   }
   
   
   
    printf("%d",y);
    fflush(stdout);
       for (int j = 0; j < 20; j++)
       {
      
      
           if (j==i)
           {
           	printf("P2");
               fflush(stdout);
               if(j==x){
                   flage=1;
               
               }
               
           }
           else
             if(j==x){
               printf("P1");
               fflush(stdout);
               }
               else if(j==a){
               printf("P3");
               fflush(stdout);
               }else
               {
                 printf(".");
                 fflush(stdout);
             
             }
             
           
       }
       printf("%d",z);
       fflush(stdout);
       if(i%2==0 && x<20)
       x++;
       sleep(1);
   }
   
   for (int i = x; i >= 0; i--)
   {
   
   u=i;
       sprintf(pos,"%d",u);
      strncpy(data3, u, SHM_SIZE);
   
   graber_location=data1;
   x=atoi(graber_location);
   
   helper_loaction=data2;
   a=atoi(helper_loaction);
   
   printf("\r                                                      ");
   printf("\r");
   
   if(x==20)
   break;
  
  printf("%d",y);
  fflush(stdout);
       for (int j = 0; j < 20; j++)
       {
       if(x==19)
       break;
           if (j==i)
           {
               if(j==0 && flage==1){
                  y=y+2;
                  flage2++;
                  flage=0;
               
               }
           
               printf("P22");
               fflush(stdout);               
           }
           else
             
               if(j==x){
               printf("P11");
               fflush(stdout);
               }
               else if(j==x){
               printf("P1");
               fflush(stdout);
               }
               else if(j==a){
               printf("P3");
               fflush(stdout);
               }else
               {
                 printf(".");
                 fflush(stdout);
             
             }
           
       }
        printf("%d",z);
        fflush(stdout);
       
       if(i%2==0 && x<20)
       x++;
      
       sleep(1);
       
       
       }
       
       //send to the shmem the amount if water
       u=z;
       sprintf(pos,"%d",u);
      strncpy(data, u, SHM_SIZE);
       
   if(x==20||y==0){
   for(x; x> 0;){
   graber_location=data1;
   x=atoi(graber_location);
   
   
       printf("\r                                               ");
       printf("\r");
        printf("%d",y);
          if (j==x)
           {
               printf("P1");
               fflush(stdout); 
               x--;              
           }
           else
             {
               
                 printf(".");
                 fflush(stdout);
             
             
             }
       
       
       }
        printf("%d",z);
        fflush(stdout);
       
       //sleep(1);
   
   }   
      
   }
   
   exit(1);
   
   
  
}





