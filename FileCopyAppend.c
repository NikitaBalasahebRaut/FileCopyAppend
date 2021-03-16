// Accept two file names from user and copy the contents of one file into another file at the end (Append).

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>


void FileCopyAppend(char *Src,char *Dest)
{
  int fddest = 0;
  int fdsrc = 0;
  int iRet = 0;
  int i = 0;
  char mug[100];

  fdsrc = open(Src,O_RDONLY);

  if(fdsrc == -1)
  {
     printf("Unable to open source file \n");
     return;
  }

  fddest = open(Dest,O_WRONLY | O_APPEND);

  if(fddest == -1)
  {
    printf("Unable to open destination file \n");
	close(fdsrc);
    return;
  }

     while((iRet = read(fdsrc,mug,sizeof(mug))) != 0)
	 {
		 printf("Iteration :%d size read : %d \n",i,iRet);
		 i++;
		 write(fddest,mug,iRet);
	 }
	 
	 close(fddest);
	 close(fdsrc);
}

int main()
{
 char name1[20];
 char name2[20];
 
 printf("Enter the source file name \n");
 scanf("%s",name1);
 printf("Enter the destination file name \n");
 scanf("%s",name2);
 
 FileCopyAppend(name1,name2);
 
return 0;
}

/*
Enter the source file name
india.txt
Enter the destination file name
bharat.txt
Iteration :0 size read : 68
*/