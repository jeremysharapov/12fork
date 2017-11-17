#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  printf("I'm the daddy, my PID is %d\n", getpid());
  int f = fork();
  int f2 = -1;
  if(f){
    f2 = fork();
  }
  if (!f || !f2){
    srand(f);  //gives children different seeds
    printf("I'm a child, my PID is %d\n", getpid());
    int rando = (rand() % 16) + 5;
    sleep(rando);
    printf("Child %d: I'm awake!\n", getpid());
    return rando;
  }
  else{
    int status;
    int cpid = wait(&status);
    printf("The child of pid %d was asleep for %d seconds\n", cpid, WEXITSTATUS(status));
    printf("Daddy is gone.\n");
  }
  return 0;
}
