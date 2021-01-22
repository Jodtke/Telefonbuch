/*
3.Telefonbuch update
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
  int n;
  char fname [30];

  printf("Bitte geben sie den Filenamen ein: ");
  gets(fname);
  fp=fopen(fname,"rbt");
  if (fp==NULL)
  {
    printf("File nicht gefunden\n");
    return 1;
  }
 
  printf("Geben sie die gewünschte Datensatznummer ein: ");
  scanf("%d",&n);
  fseek(fp,(n-1) * sizeof(tele),SEEK_SET);
  fread(&tele,sizeof(tele),1,fp);
  printf("%s %s\n",tele.name,tele.nummer);
  
  printf("neue Nummer?\n "),
  scanf("%s",&tele.nummer);
  fseek(fp,(n-1) * sizeof(tele),SEEK_SET);
  fwrite(&tele,sizeof(tele),1,fp);
 
  fclose(fp);
  
  system("PAUSE");	
  return 0;
}