#include "clients.h"
#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>
#include <ctype.h>

enum
 {
  ENOM,
  EPRENOM,
  ECIN,
  ETEL,
  EMAIL,
  EADRESSE, 
  EJOUR,
  EMOIS,
  EANNE,
  ESEXE,
  EDATEINSC,
  COLUMNS,
  };

void ajouter(client c)
{
   
    FILE *fc=NULL;
    fc=fopen("infclients.txt","a+");
    
    fprintf(fc,"%s %s %s %s %s %s %s %s %s %s %s\n",c.nom,c.prenom,c.cin,c.tel,c.mail,c.adresse,c.d.jour,c.d.mois,c.d.anne,c.sexe,c.dateinsc);
fclose(fc);

}
void modifier(char cin45[],client s)
{
  FILE *f;
    FILE *ftemp;
    ftemp=NULL;
    client c;
   
    f=fopen("infclients.txt","a+");
    ftemp=fopen("infclients.txt.temp","a+");
    if (f!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",c.nom,c.prenom,c.cin,c.tel,c.mail,c.adresse,c.d.jour,c.d.mois,c.d.anne,c.sexe,c.dateinsc)!=EOF)
        {
            if(strcmp(cin45,c.cin)==0)
            {
		       strcpy(c.cin,s.cin);
		       strcpy(c.prenom,s.prenom);
		       strcpy(c.nom,s.nom);
                       strcpy(c.tel,s.tel);
                       strcpy(c.mail,s.mail);
                       strcpy(c.adresse,s.adresse);
                       strcpy(c.d.jour,s.d.jour);
                       strcpy(c.d.mois,s.d.mois);
                       strcpy(c.d.anne,s.d.anne);
                       strcpy(c.sexe,s.sexe);
            }
            fprintf(ftemp,"%s %s %s %s %s %s %s %s %s %s %s\n",c.nom,c.prenom,c.cin,c.tel,c.mail,c.adresse,c.d.jour,c.d.mois,c.d.anne,c.sexe,c.dateinsc);
        }

    }
    fclose(ftemp);
    fclose(f);
    remove("infclients.txt");
    rename("infclients.txt.temp","infclients.txt");
}

void supprimer(char cinsupp[])
{
    FILE *f;
    FILE *ftemp;
    ftemp=NULL;
    client c;
    char cin0[15];
    strcpy(cin0,"sSs");
   
    f=fopen("infclients.txt","r+");
    ftemp=fopen("infclients.txt.temp","a+");
    if (f!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",c.nom,c.prenom,c.cin,c.tel,c.mail,c.adresse,c.d.jour,c.d.mois,c.d.anne,c.sexe,c.dateinsc)!=EOF)
        {
            if(strcmp(cinsupp,c.cin)==0)
            {
		       strcpy(c.cin,cin0);
		       
            }
            if(strcmp(cin0,c.cin)!=0)
               {
                 fprintf(ftemp,"%s %s %s %s %s %s %s %s %s %s %s\n",c.nom,c.prenom,c.cin,c.tel,c.mail,c.adresse,c.d.jour,c.d.mois,c.d.anne,c.sexe,c.dateinsc);
               }
         }
    }
    fclose(ftemp);
    fclose(f);
    remove("infclients.txt");
    rename("infclients.txt.temp","infclients.txt");
}


client chercher(char cinch[])
{
  FILE *f;
   
    client c;
   
   
    f=fopen("infclients.txt","r+");
    
    if (f!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",c.nom,c.prenom,c.cin,c.tel,c.mail,c.adresse,c.d.jour,c.d.mois,c.d.anne,c.sexe,c.dateinsc)!=EOF)
        {
            if(strcmp(cinch,c.cin)==0)
            {
		      return c;
            }
            if(strcmp(cinch,c.nom)==0)
            {
		      return c;
            }
            if(strcmp(cinch,c.dateinsc)==0)
            {
		      return c;
            }
          
        }

    }
    
    fclose(f);
    
}
char* up(char* str[]) 
{ 
  int i=0;
  char *str1=malloc(51); 
  strcpy(str1,str);
  for(i=0;i<=strlen(str1);i++){
      if((str1[i]>=65)&&(str1[i]<=90)){
         str1[i]=str1[i]+32;}
   }
  return str1;
}

void afficher(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char nom[20];
char prenom[20];
char cin[15];
char tel[20];
char mail[30];
char adresse[50];
char sexe[10];
char jour[5];
char mois[5];
char anne[7];
char dateinsc[12];
store=NULL;


FILE *f;

store=gtk_tree_view_get_model(liste);


if(store==NULL)
{
renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Nom",renderer, "text",ENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Prenom",renderer, "text",EPRENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Cin",renderer, "text",ECIN,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("N°Tel",renderer, "text",ETEL,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("E-Mail",renderer,"text",EMAIL,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Adresse",renderer, "text",EADRESSE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Jour",renderer, "text",EJOUR,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Mois",renderer, "text",EMOIS,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Année",renderer, "text",EANNE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Sexe",renderer, "text",ESEXE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Date D'Inscription",renderer, "text",EDATEINSC,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f = fopen("infclients.txt","r");
if(f==NULL)
{
  return;
}
else
{
 f=fopen("infclients.txt","a+");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",nom,prenom,cin,tel,mail,adresse,jour,mois,anne,sexe,dateinsc)!=EOF)
  {
    gtk_list_store_append (store,&iter);
gtk_list_store_set(store,&iter,ENOM,nom,EPRENOM,prenom,ECIN,cin,ETEL,tel,EMAIL,mail,EADRESSE,adresse,EJOUR,jour,EMOIS,mois,EANNE,anne,ESEXE,sexe,EDATEINSC,dateinsc, -1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}

}



void afficherchu(GtkWidget *liste,client ch)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char nom[20];
char prenom[20];
char cin[15];
char tel[20];
char mail[30];
char adresse[50];
char sexe[10];
char jour[5];
char mois[5];
char anne[7];
char dateinsc[12];
store=NULL;


FILE *f;

store=gtk_tree_view_get_model(liste);


if(store==NULL)
{
renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Nom",renderer, "text",ENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Prenom",renderer, "text",EPRENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Cin",renderer, "text",ECIN,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("N°Tel",renderer, "text",ETEL,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("E-Mail",renderer,"text",EMAIL,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Adresse",renderer, "text",EADRESSE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Jour",renderer, "text",EJOUR,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Mois",renderer, "text",EMOIS,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Année",renderer, "text",EANNE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Sexe",renderer, "text",ESEXE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Date D'Inscription",renderer, "text",EDATEINSC,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f = fopen("infclients.txt","r");
if(f==NULL)
{
  return;
}
else
{
 f=fopen("infclients.txt","a+");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",nom,prenom,cin,tel,mail,adresse,jour,mois,anne,sexe,dateinsc)!=EOF)
  { 
    if (strcmp(ch.cin,cin)==0)
     {
    gtk_list_store_append (store,&iter);
gtk_list_store_set(store,&iter,ENOM,nom,EPRENOM,prenom,ECIN,cin,ETEL,tel,EMAIL,mail,EADRESSE,adresse,EJOUR,jour,EMOIS,mois,EANNE,anne,ESEXE,sexe,EDATEINSC,dateinsc, -1);
     }
  }
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}

}

void afficherch(GtkWidget *liste,char cinch[])
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
int x=0;
char nom[20];
char prenom[20];
char cin[15];
char tel[20];
char mail[30];
char adresse[50];
char sexe[10];
char jour[5];
char mois[5];
char anne[7];
char dateinsc[12];
store=NULL;


FILE *f;

store=gtk_tree_view_get_model(liste);


if(store==NULL)
{
renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Nom",renderer, "text",ENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Prenom",renderer, "text",EPRENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Cin",renderer, "text",ECIN,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("N°Tel",renderer, "text",ETEL,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("E-Mail",renderer,"text",EMAIL,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Adresse",renderer, "text",EADRESSE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Jour",renderer, "text",EJOUR,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Mois",renderer, "text",EMOIS,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Année",renderer, "text",EANNE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Sexe",renderer, "text",ESEXE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Date D'Inscription",renderer, "text",EDATEINSC,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f = fopen("infclients.txt","r");
if(f==NULL)
{
  return;
}
else
{
 f=fopen("infclients.txt","a+");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",nom,prenom,cin,tel,mail,adresse,jour,mois,anne,sexe,dateinsc)!=EOF)
  { 
    if (strcmp(up(cinch),up(adresse))==0)
     {
    gtk_list_store_append (store,&iter);
gtk_list_store_set(store,&iter,ENOM,nom,EPRENOM,prenom,ECIN,cin,ETEL,tel,EMAIL,mail,EADRESSE,adresse,EJOUR,jour,EMOIS,mois,EANNE,anne,ESEXE,sexe,EDATEINSC,dateinsc, -1);x=1;
     }
}
rewind(f);
   while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",nom,prenom,cin,tel,mail,adresse,jour,mois,anne,sexe,dateinsc)!=EOF)
  { 
    if ((strcmp(up(cinch),up(nom))==0)&&(x!=1))
     {
    gtk_list_store_append (store,&iter);
gtk_list_store_set(store,&iter,ENOM,nom,EPRENOM,prenom,ECIN,cin,ETEL,tel,EMAIL,mail,EADRESSE,adresse,EJOUR,jour,EMOIS,mois,EANNE,anne,ESEXE,sexe,EDATEINSC,dateinsc, -1);
     }
    if ((strcmp(up(cinch),up(prenom))==0)&&(x!=1))
     {
    gtk_list_store_append (store,&iter);
gtk_list_store_set(store,&iter,ENOM,nom,EPRENOM,prenom,ECIN,cin,ETEL,tel,EMAIL,mail,EADRESSE,adresse,EJOUR,jour,EMOIS,mois,EANNE,anne,ESEXE,sexe,EDATEINSC,dateinsc, -1);
     }
    if ((strcmp(up(cinch),up(tel))==0)&&(x!=1))
     {
    gtk_list_store_append (store,&iter);
gtk_list_store_set(store,&iter,ENOM,nom,EPRENOM,prenom,ECIN,cin,ETEL,tel,EMAIL,mail,EADRESSE,adresse,EJOUR,jour,EMOIS,mois,EANNE,anne,ESEXE,sexe,EDATEINSC,dateinsc, -1);
     }
    if ((strcmp(up(cinch),up(dateinsc))==0)&&(x!=1))
     {
    gtk_list_store_append (store,&iter);
gtk_list_store_set(store,&iter,ENOM,nom,EPRENOM,prenom,ECIN,cin,ETEL,tel,EMAIL,mail,EADRESSE,adresse,EJOUR,jour,EMOIS,mois,EANNE,anne,ESEXE,sexe,EDATEINSC,dateinsc, -1);
     }
    if ((strcmp(up(cinch),up(mail))==0)&&(x!=1))
     {
    gtk_list_store_append (store,&iter);
gtk_list_store_set(store,&iter,ENOM,nom,EPRENOM,prenom,ECIN,cin,ETEL,tel,EMAIL,mail,EADRESSE,adresse,EJOUR,jour,EMOIS,mois,EANNE,anne,ESEXE,sexe,EDATEINSC,dateinsc, -1);
     }
    if ((strcmp(up(cinch),up(cin))==0)&&(x!=1))
     {
    gtk_list_store_append (store,&iter);
gtk_list_store_set(store,&iter,ENOM,nom,EPRENOM,prenom,ECIN,cin,ETEL,tel,EMAIL,mail,EADRESSE,adresse,EJOUR,jour,EMOIS,mois,EANNE,anne,ESEXE,sexe,EDATEINSC,dateinsc, -1);
     }
    if ((strcmp(up(cinch),up(sexe))==0)&&(x!=1))
     {
    gtk_list_store_append (store,&iter);
gtk_list_store_set(store,&iter,ENOM,nom,EPRENOM,prenom,ECIN,cin,ETEL,tel,EMAIL,mail,EADRESSE,adresse,EJOUR,jour,EMOIS,mois,EANNE,anne,ESEXE,sexe,EDATEINSC,dateinsc, -1);
     }
     
  }
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}x=0;

}

int verif(char cinver[],char mailver[])
{
  int x=0;

  FILE *f;
   
    client l;
   
   
    f=fopen("infclients.txt","a+");
    
    if (f!=NULL)
    {//g_print("%s\n\n",mailver);
        while((fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",l.nom,l.prenom,l.cin,l.tel,l.mail,l.adresse,l.d.jour,l.d.mois,l.d.anne,l.sexe,l.dateinsc)!=EOF)&&(x!=1)&&(x!=2)&&(x!=3))
        {
            if((strcmp(mailver,l.cin)==0) && (strcmp(mailver,l.mail)==0))
              {
                      x=1;
		      return x;break;
              }
                 else if(strcmp(cinver,l.cin)==0)
                   {
                      x=2;
		      return x;break;
                   }
                     
                     else if(strcmp(mailver,l.mail)==0)
                       {
                         x=3;
		         return x;break;
                       }
                                   

        }
      return x;
    }
    
    fclose(f);

}

int verifm(char mailver[])
{
  int x=0;

  FILE *f;
   
    client l;
   
   
    f=fopen("infclients.txt","a+");
    
    if (f!=NULL)
    {
        while((fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",l.nom,l.prenom,l.cin,l.tel,l.mail,l.adresse,l.d.jour,l.d.mois,l.d.anne,l.sexe,l.dateinsc)!=EOF)&&(x!=1)&&(x!=2)&&(x!=3))
        {
             if(strcmp(mailver,l.mail)==0)
                       {
                         x=3;
		         return x;
                       }
                                   

        }
      return x;
    }
    
    fclose(f);

}

int anneseche()
{
    FILE *f=NULL;
    ct at;
    int n1,n2,n3,annee;
    float hum;
    int t[90000];
    int i=0,x=0,j=1,min=0;
    int n[20];
    int anne[20];
    float somm[20];
    float moy[20];

    f=fopen("humid.txt","r");
if(f!=NULL)
      {
         while(fscanf(f,"%d %d %d %d %f\n",&n1,&n2,&n3,&annee,&hum)!=NULL)//si la tache ne s'execute pas changez NULL en EOF
            {
               t[i]=annee;
            i++;
            }
      i=0;
fclose(f);
 f=fopen("humid.txt","r");                                         

         while(fscanf(f,"%d %d %d %d %f\n",&n1,&n2,&n3,&annee,&hum)!=NULL)//si la tache ne s'execute pas changez NULL en EOF
            {

               if (t[i]!=t[i+1])
                 {   anne[x]=annee;
                     n[x]=j;
                     x++;

                    j=1;

                 }
               else
                 {
                   j++;
                 }
              somm[x]+=hum;

              i++;
             }
    }
      fclose(f);

     for(i=0;i<x;i++)
     {
        moy[i]=(somm[i]/n[i]);

     }
       for (i=0;i<x;i++)
        {
         if(moy[i]<moy[min])
          {
            min=i;
          }
        }
     at.moy=moy[min];
     at.somm=somm[min];
     at.anne=anne[min];
return anne[min];

}









