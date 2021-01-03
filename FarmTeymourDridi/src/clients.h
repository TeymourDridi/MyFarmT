#ifndef FONCTIONS_H_ 
#define FONCTIONS_H_ 
#include <gtk/gtk.h>

typedef struct
{
  char jour[5],mois[3],anne[5];
}date;



struct client
{
   char nom[20],prenom[20],cin[15],tel[20],mail[30],adresse[50],sexe[10],dateinsc[15];
   date d;
};
typedef struct client client;

typedef struct
{
  int anne;
  float moy,somm;
}ct;

void ajouter(client c);
void modifier(char cin45[],client s);
void supprimer(char cinsupp[]);
client chercher(char cinch[]);
char* up(char* str[]);
void afficher(GtkWidget *liste);
int anneseche();
void afficherchu(GtkWidget *liste,client ch);
void afficherch(GtkWidget *liste,char cin[]);
int verif(char cinver[],char mailver[]);
int verifm(char mailver[]);
#endif
