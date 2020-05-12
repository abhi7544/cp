#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>


 int main() 
 {
//create
 int fd=creat("abhshek1.txt",00700);
  if(fd==-1)
  printf("File can not be created");
if(link("abhishek1.txt","Abhishek2.txt")<0)
{
    printf("Can not be linked\n");

}
else
printf("Linked\n");

 
//open
int fd2=open("abhshek1.txt",O_WRONLY);
if(fd2==-1)
printf("Unable to open and write in the file\n");
//write
int c_fd=dup(fd2);
write(fd2,"My Name is Abhishek.\n",20);
write(c_fd,"I am  in NITK\n",20);


int fd3=open("abhshek1.txt",O_RDONLY,00700);
if(fd3==-1)
printf("Unable to open and read the  file");
char buf[40];


lseek(fd3,0,SEEK_SET);
read(fd3,buf,40);
printf("%c",buf);


printf("\ncfd=%d fd=%d fd2=%d fd3=%d ",c_fd,fd,fd2,fd3);

printf("Content in file:%s",buf);

//close
close(fd);
close(fd2);close(fd3);close(c_fd);
  return 0;}