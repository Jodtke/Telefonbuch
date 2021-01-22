/*
2.Telefonbuch ausgeben
*/

#include <stdio.h>
#include <stdlib.h>

struct telefonbuch
{
  char name[30];
  char nummer[20];
};

int main()
{
  FILE*fp;
  struct telefonbuch tele;
  char fname [30];
  int n;
  
  printf("Bitte geben sie den Filenamen ein: ");
  gets(fname);
  fp=fopen(fname,"rb");
  if (fp==NULL)
  {
    printf("File nicht gefunden\n");
    return 1;
  }
  n = 1;
  while(fread(&tele,sizeof(tele),1,fp)>0)
  {
    printf("%d %s %s\n",n, tele.name,tele.nummer);
    n++;
  }

  if(feof(fp))
  {
             printf("File- Ende\n");
  }
  else
  {
     printf("File- Fehler\n");
  }
 
  fclose(fp);
  
  system("PAUSE");	
  return 0;
}