/*
1.Telefonbuch anlegen
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
  float n,t;
  char fname [30];
  char eing[10];

  printf("Eingabe des Filenamen: ");
  gets(fname);
  fp=fopen(fname,"wb");
  if(fp==NULL)
  {
             printf("Fehler");
             return 1;
  }
  fp=fopen(fname,"wb");
  do
  {
   printf("Geben sie den Namen ein:\n");
   fgets(tele.name,sizeof(tele.name),stdin);
   printf("Geben sie die Telefonnummer ein:\n");
   fgets(tele.nummer,sizeof(tele.nummer),stdin);
   fwrite(&tele,sizeof(tele),1,fp);
   printf("weiterer Datensatz (j/n): ");
   fgets(eing,sizeof(eing),stdin);
  }
  while (eing[0]!='n');
  
  fclose(fp);
  
  system("PAUSE");	
  return 0;
}