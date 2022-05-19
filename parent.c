/*
 * The PARENT
 */

#include "local.h"

void main(){

    key_t key,key1;
    int shmid,shmid1;
    int the_wins_for1=0,the_wins_for2=0;
    char *data;
    char *data1; 
    char *the_end_fromTeam1;
    char *the_end_fromTeam2;
    //int mode,mode1;
    int id1,id2;
    //char * man = "hallo";

int c_id,tt;
char team[1];

if ((key = ftok("frist.txt", 'R')) == -1) /*Here the file must exist */ { 
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
        perror("shmat");
        exit(1);
    }
    //the another shared mem
    if ((key1 = ftok("second.txt", 'R')) == -1) /*Here the file must exist */ { 
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


while(the_wins_for1<3&&the_wins_for2<3){
for(int i =0; i<2; i++){
tt=i;

if ( (c_id = fork()) == -1 ) {
    perror("fork -- consumer");
    exit(7); 
  }
  
  else if ( c_id == 0 ) {
sprintf(team,"%d",tt);


    execl("./test", "./test",team , (char *) 0);
    if(i=0){
    id1=getpid();}
    else{
    id2=getpid();}
    //printf("\n");
    perror("execl -- test");
   // exit(8);
  }
if ( (c_id = fork()) == -1 ) {
    perror("fork -- consumer");
    exit(7); 
  }
  
  else if ( c_id == 0 ) {
sprintf(team,"%d",tt);


    execl("./thegraber", "./thegraber",team , (char *) 0);
    //printf("\n");
    perror("execl -- test");
   // exit(8);
  }
if ( (c_id = fork()) == -1 ) {
    perror("fork -- consumer");
    exit(7); 
  }
  
  else if ( c_id == 0 ) {
sprintf(team,"%d",tt);


    execl("./thehelper", "./thehelper",team , (char *) 0);
    //printf("\n");
    perror("execl -- test");
   // exit(8);
  }    
  
}
for(int i=0;i<600;i++){
sleep(1);}


char*firstTeam=data;
char*secondTeam=data1;

if(atoi(firstTeam)>atoi(secondTeam)){
printf("team 1 win\n");
the_wins_for1++;
the_wins_for2=0;
}
else if(atoi(firstTeam)==atoi(secondTeam)){
printf("drow\n");
the_wins_for1=0;
the_wins_for2++;
}
else{
printf("team 2 win\n");
the_wins_for1++;
the_wins_for2++;
}

//terminat all childs

}
//exit(1);



}
