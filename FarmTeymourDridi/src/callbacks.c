#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "clients.h"

char cin45[50],cinsupp[50],cinch[50];
client c;
client ch;
client s;

void
on_buttonVAjout_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *nom1,*nom2,*prenom1,*prenom2,*mail1,*mail2,*adresse1,*adresse2,*sexe1,*sexe2,*cin1,*cin2,*mois1,*mois2,*jour1,*jour2,*anne1,*anne2,*tel1,*tel2,*checkcin1,*checkmail1,*ajsucc,*calend1;
    char nom[20],prenom[20],mail[30],adresse[50],cin[15],tel[20];
    int x=5,l=0;
    GtkRadioButton *Homme,*Femme;
    int joour,moois,annne,i=0;
   
    calend1 = lookup_widget(button, "Tlabelcheckcalendar") ;
    checkcin1 = lookup_widget(button, "labelVerifCin") ;
    checkmail1 = lookup_widget(button, "labelVerifMail") ;
    nom2 = lookup_widget(button, "labelVerifNom") ;
    prenom2 = lookup_widget(button, "labelVerifPrenom") ;
    adresse2 = lookup_widget(button, "labelVerifAdresse") ;
    jour2 = lookup_widget(button, "labelVerifJour") ;
    tel2 = lookup_widget(button, "labelVerifTel") ;
    ajsucc = lookup_widget(button, "labelAjoutSucc") ;
    
    gtk_label_set_text(GTK_LABEL(nom2)," ");
    gtk_label_set_text(GTK_LABEL(tel2)," ");
    gtk_label_set_text(GTK_LABEL(jour2)," ");
    gtk_label_set_text(GTK_LABEL(adresse2)," ");
    gtk_label_set_text(GTK_LABEL(prenom2)," ");
    gtk_label_set_text(GTK_LABEL(checkcin1)," ");
    gtk_label_set_text(GTK_LABEL(checkmail1)," ");
    gtk_label_set_text(GTK_LABEL(ajsucc)," ");
    gtk_label_set_text(GTK_LABEL(calend1)," ");

    nom1 = lookup_widget(button, "entryNom") ;
    strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(nom1)));
   while(i<strlen(c.nom))
    {
     if (((c.nom[i]<'a') || (c.nom[i]>'z')) && ((c.nom[i]<'A') || (c.nom[i]>'Z')))
      {
          gtk_label_set_markup (GTK_LABEL (nom2), "<span font_desc='medium italic'foreground='red'> INVALIDE !</span>");
         l=1;
      }
     i++;
    }
    if(strcmp(c.nom,"")==0)
      {
         gtk_label_set_markup (GTK_LABEL (nom2), "<span font_desc='medium italic'foreground='red'> Case Nom Vide !</span>");
         l=1;
      }
 i=0;
    prenom1 = lookup_widget(button, "entryPrenom") ;
    strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(prenom1)));
    while(i<strlen(c.prenom))
    {
     if (((c.prenom[i]<'a') || (c.prenom[i]>'z')) && ((c.prenom[i]<'A') || (c.prenom[i]>'Z')))
      {
          gtk_label_set_markup (GTK_LABEL (prenom2), "<span font_desc='medium italic'foreground='red'> INVALIDE !</span>");
         l=1;
      }
     i++;
    }
    if(strcmp(c.prenom,"")==0)
      {       gtk_label_set_markup (GTK_LABEL (prenom2), "<span font_desc='medium italic'foreground='red'> Case Prenom Vide !</span>");
         l=1;
      }
    cin1 = lookup_widget(button, "entryCin") ;
    strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(cin1)));i=0;
    if (strlen(c.cin)<8)
     {
       gtk_label_set_markup (GTK_LABEL (checkcin1), "<span font_desc='medium italic'foreground='red'> Entrez les 8 chiffres de CIN !</span>");l=1;
     }
    while(i<strlen(c.cin))
    {
     if ((c.cin[i]<'0') || (c.cin[i]>'9'))
      {
          gtk_label_set_markup (GTK_LABEL (checkcin1), "<span font_desc='medium italic'foreground='red'> CIN INVALIDE !</span>");
         l=1;
      }
     i++;
    }
    if((atof(c.cin)>19000000)||(atof(c.cin)<1))
      {       gtk_label_set_markup (GTK_LABEL (checkcin1), "<span font_desc='medium italic'foreground='red'> Cin Invalide !</span>");
         l=1;
      }
    if(strcmp(c.cin,"")==0)
      {       gtk_label_set_markup (GTK_LABEL (checkcin1), "<span font_desc='medium italic'foreground='red'> Case Cin Vide !</span>");
         l=1;
      }

    tel1 = lookup_widget(button, "entryTel") ;
    strcpy(c.tel,gtk_entry_get_text(GTK_ENTRY(tel1)));
    while(i<strlen(c.cin))
    {
     if ((c.tel[i]<'0') || (c.tel[i]>'9'))
      {
          gtk_label_set_markup (GTK_LABEL (tel2), "<span font_desc='medium italic'foreground='red'> N°TEL INVALIDE !</span>");
         l=1;
      }
     i++;
    }
    if((atof(c.tel)<20000000)||(atof(c.tel)<1))
      {       gtk_label_set_markup (GTK_LABEL (tel2), "<span font_desc='medium italic'foreground='red'> Tel Invalide !</span>");
         l=1;
      }
    if (strlen(c.tel)<8)
     {
       gtk_label_set_markup (GTK_LABEL (tel2), "<span font_desc='medium italic'foreground='red'> Entrez au moins 8 chiffres !</span>");l=1;
     }
    if(strchr(c.tel,' ')!=NULL)
      {       gtk_label_set_markup (GTK_LABEL (tel2), "<span font_desc='medium italic'foreground='red'> N°Tel INVALIDE !</span>");
         l=1;
      }
    if(strcmp(c.tel,"")==0)
      {       gtk_label_set_markup (GTK_LABEL (tel2), "<span font_desc='medium italic'foreground='red'> Case N°Tel Vide !</span>");
         l=1;
      }

    mail1 = lookup_widget(button, "entryMail") ;
    strcpy(c.mail,gtk_entry_get_text(GTK_ENTRY(mail1)));
    if (((strchr(c.mail, '@')==NULL)||(strchr(c.mail, '.')==NULL))||(strchr(c.mail, ' ')!=NULL))
      {
            gtk_label_set_markup (GTK_LABEL (checkmail1), "<span font_desc='medium italic'foreground='red'> E-MAIL Non Valide !</span>");
         l=1;
      }
      
    if(strcmp(c.mail,"")==0)
      {       gtk_label_set_markup (GTK_LABEL (checkmail1), "<span font_desc='medium italic'foreground='red'> Case E-MAIL Vide !</span>");
         l=1;
      }

    adresse1 = lookup_widget(button, "entryAdresse") ;
    strcpy(c.adresse,gtk_entry_get_text(GTK_ENTRY(adresse1)));
    if(strchr(c.adresse,' ')!=NULL)
      {    gtk_label_set_markup (GTK_LABEL (adresse2), "<span font_desc='medium italic'foreground='red'> Adresse Invalide !</span>");   
        l=1;
      }
    if(strcmp(c.adresse,"")==0)
      {    gtk_label_set_markup (GTK_LABEL (adresse2), "<span font_desc='medium italic'foreground='red'> Case Adresse Vide !</span>");   
        l=1;
      }

    anne1 = lookup_widget(button, "comboboxentryAnne") ;
    gchar *anne=gtk_combo_box_get_active_text(anne1);
    
    annne=atof(anne);
    if((annne<1910)||(annne>2004)) 
    {    gtk_label_set_markup (GTK_LABEL (jour2), "<span font_desc='medium italic'foreground='red'> Changez L'anneé !</span>");
       l=1;
    }
    if(strcmp(anne,"")==0)
      {     gtk_label_set_markup (GTK_LABEL (jour2), "<span font_desc='medium italic'foreground='red'> Case Anne Vide !</span>");  
         l=1;
      }
    
    mois1 = lookup_widget(button, "comboboxentryMois") ;
    gchar *mois=gtk_combo_box_get_active_text(mois1);
    
    
    moois=atof(mois);
    if((moois>12)||(moois<1)) 
    {    gtk_label_set_markup (GTK_LABEL (jour2), "<span font_desc='medium italic'foreground='red'> Entrez Mois entre 1 et 12 !</span>");
       l=1;
    }
    if(strcmp(mois,"")==0)
      {      gtk_label_set_markup (GTK_LABEL (jour2), "<span font_desc='medium italic'foreground='red'> Case Mois vide !</span>"); 
         l=1;
      }

    jour1 = lookup_widget(button, "comboboxentryJour") ;
    gchar *jour=gtk_combo_box_get_active_text(jour1);
    
    
    joour=atof(jour);
    if((joour>31)||(joour<1)) 
    {    gtk_label_set_markup (GTK_LABEL (jour2), "<span font_desc='medium italic'foreground='red'> Entrez Jour entre 1 et 31 !</span>");
       l=1;
    }
    if(strcmp(jour,"")==0)
      {     gtk_label_set_markup (GTK_LABEL (jour2), "<span font_desc='medium italic'foreground='red'> Case Jour vide !</span>");  
         l=1;
      } 
   
    x=verif(c.cin,c.mail);
    if(x==1)
     {   gtk_label_set_markup (GTK_LABEL (checkcin1), "<span font_desc='medium italic'foreground='red'> Veuillez Entrer Un Autre CIN !</span>");
gtk_label_set_markup (GTK_LABEL (checkmail1), "<span font_desc='medium italic'foreground='red'> Veuillez Entrez Un Autre E-MAIL !</span>");
       
     }
    if(x==2)
     {gtk_label_set_markup (GTK_LABEL (checkcin1), "<span font_desc='medium italic'foreground='red'> Veuillez Entrer Un Autre CIN !</span>");
       
     }
    if(x==3)
     {gtk_label_set_markup (GTK_LABEL (checkmail1), "<span font_desc='medium italic'foreground='red'> Veuillez Entrez Un Autre E-MAIL !</span>");
       
     }
    if(strcmp(c.dateinsc,"")==0)
     {
       gtk_label_set_markup (GTK_LABEL (calend1), "<span font_desc='medium italic'foreground='red'> Vous n'avez pas selectionner une Date !</span>");l=1;
     }

    if((x==0)&&(l!=1))
     { strcpy(c.d.jour,jour);strcpy(c.d.mois,mois);strcpy(c.d.anne,anne);
       ajouter(c);
       gtk_label_set_markup (GTK_LABEL (ajsucc), "<span font_desc='medium italic'foreground='brown'> Client Ajouter !</span>");
     }

   

}


void
on_buttonRAjout_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *Gestion_Des_Clients,*Principal2;


   Principal2 = create_Principal2 ();
  gtk_widget_show (Principal2);

  Gestion_Des_Clients=lookup_widget(button,"Gestion_Des_Clients");
  gtk_widget_destroy(Gestion_Des_Clients);
}


void
on_buttonCherchModif_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
  
  GtkWidget *nom1,*nom2,*prenom1,*prenom2,*mail1,*mail2,*cincheck1,*adresse1,*adresse2,*sexe1,*sexe2,*cin1,*cin2,*mois1,*mois2,*jour1,*jour2,*anne1,*anne2,*tel1,*tel2,*checkcin1,*checkmail1,*modifsucc,*rhomme,*rfemme;
  GtkWidget *window3 ;
  int x;
  int joour,moois,annne;
  cincheck1 = lookup_widget(button, "labelCheckCinModif2") ;
  gtk_label_set_text(GTK_LABEL(cincheck1),"");
  
  cin2 = lookup_widget(button, "entryCinModif") ;
  strcpy(cin45,gtk_entry_get_text(GTK_ENTRY(cin2)));
  x=verif(cin45,"");

    checkcin1 = lookup_widget(button, "labelCheckCinModif") ;
    checkmail1 = lookup_widget(button, "labelCheckMailModif") ;
    nom2 = lookup_widget(button, "labelCheckNomModif") ;
    prenom2 = lookup_widget(button, "labelCheckPreomModif") ;
    adresse2 = lookup_widget(button, "labelCheckAdresseModif") ;
    jour2 = lookup_widget(button, "labelCheckJourModif") ;
    tel2 = lookup_widget(button, "labelCheckTelModif") ;
    modifsucc = lookup_widget(button, "labelModifSucc") ;
    nom1 = lookup_widget(button, "entryNom2") ;
    prenom1 = lookup_widget(button, "entryPrenom2") ;
    cin1 = lookup_widget(button, "entryCin2") ;
    tel1 = lookup_widget(button, "entryTel2") ;
    mail1 = lookup_widget(button, "entryMail2") ;
    adresse1 = lookup_widget(button, "entryAdresse2") ;
    
    gtk_label_set_text(GTK_LABEL(nom2)," ");
    gtk_label_set_text(GTK_LABEL(tel2)," ");
    gtk_label_set_text(GTK_LABEL(jour2)," ");
    gtk_label_set_text(GTK_LABEL(adresse2)," ");
    gtk_label_set_text(GTK_LABEL(prenom2)," ");
    gtk_label_set_text(GTK_LABEL(checkcin1)," ");
    gtk_label_set_text(GTK_LABEL(checkmail1)," ");
    gtk_label_set_text(GTK_LABEL(modifsucc)," ");

 if(x==2)
   {
     
    c=chercher(cin45);

  gtk_entry_set_editable(GTK_ENTRY(nom1),TRUE);
  gtk_entry_set_editable(GTK_ENTRY(prenom1),TRUE);
  gtk_entry_set_editable(GTK_ENTRY(mail1),TRUE);
  gtk_entry_set_editable(GTK_ENTRY(cin1),TRUE);
  gtk_entry_set_editable(GTK_ENTRY(tel1),TRUE);
  gtk_entry_set_editable(GTK_ENTRY(adresse1),TRUE);

    nom1 = lookup_widget(button, "entryNom2") ;
    gtk_entry_set_text(GTK_ENTRY(nom1),c.nom);

    prenom1 = lookup_widget(button, "entryPrenom2") ;
    gtk_entry_set_text(GTK_ENTRY(prenom1),c.prenom);

    cin1 = lookup_widget(button, "entryCin2") ;
    gtk_entry_set_text(GTK_ENTRY(cin1),c.cin);

    tel1 = lookup_widget(button, "entryTel2") ;
    gtk_entry_set_text(GTK_ENTRY(tel1),c.tel);

    mail1 = lookup_widget(button, "entryMail2") ;
    gtk_entry_set_text(GTK_ENTRY(mail1),c.mail);

    adresse1 = lookup_widget(button, "entryAdresse2") ;
    gtk_entry_set_text(GTK_ENTRY(adresse1),c.adresse);
    
    joour=atof(c.d.jour);
    jour1 = lookup_widget(button, "comboboxentryJour2") ;
    gtk_combo_box_set_active(GTK_COMBO_BOX(jour1),joour);
    
    moois=atof(c.d.mois);
    mois1 = lookup_widget(button, "comboboxentryMois2") ;
    gtk_combo_box_set_active(GTK_COMBO_BOX(mois1),moois);

    annne=atof(c.d.anne);
    anne1 = lookup_widget(button, "comboboxentryAnne2") ;
    gtk_combo_box_set_active(GTK_COMBO_BOX(anne1),annne-1909);
    
     rhomme = lookup_widget(button, "Homme2") ;
     rfemme = lookup_widget(button, "Femme2") ;
    if(strcmp(c.sexe,"Homme")==0)
    {
      gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (rhomme),TRUE);
    }
    if(strcmp(c.sexe,"Femme")==0)
    {
      gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (rfemme),TRUE);
    }

    gtk_label_set_text(GTK_LABEL(nom2)," ");
    gtk_label_set_text(GTK_LABEL(tel2)," ");
    gtk_label_set_text(GTK_LABEL(jour2)," ");
    gtk_label_set_text(GTK_LABEL(adresse2)," ");
    gtk_label_set_text(GTK_LABEL(prenom2)," ");
    gtk_label_set_text(GTK_LABEL(checkcin1)," ");
    gtk_label_set_text(GTK_LABEL(checkmail1)," ");
    gtk_label_set_text(GTK_LABEL(modifsucc)," ");

   }
  else
   {
     cincheck1 = lookup_widget(button, "labelCheckCinModif2") ;
     gtk_label_set_markup (GTK_LABEL (cincheck1), "<span font_desc='medium italic'foreground='red'> CIN INEXISTANT !</span>");  
     
     nom1 = lookup_widget(button, "entryNom2") ;
    gtk_entry_set_text(GTK_ENTRY(nom1),"");

    prenom1 = lookup_widget(button, "entryPrenom2") ;
    gtk_entry_set_text(GTK_ENTRY(prenom1),"");

    cin1 = lookup_widget(button, "entryCin2") ;
    gtk_entry_set_text(GTK_ENTRY(cin1),"");

    tel1 = lookup_widget(button, "entryTel2") ;
    gtk_entry_set_text(GTK_ENTRY(tel1),"");

    mail1 = lookup_widget(button, "entryMail2") ;
    gtk_entry_set_text(GTK_ENTRY(mail1),"");

    adresse1 = lookup_widget(button, "entryAdresse2") ;
    gtk_entry_set_text(GTK_ENTRY(adresse1),"");
   
    jour1 = lookup_widget(button, "comboboxentryJour2") ;
    gtk_combo_box_set_active(GTK_COMBO_BOX(jour1),0);
    
    mois1 = lookup_widget(button, "comboboxentryMois2") ;
    gtk_combo_box_set_active(GTK_COMBO_BOX(mois1),0);

    anne1 = lookup_widget(button, "comboboxentryAnne2") ;
    gtk_combo_box_set_active(GTK_COMBO_BOX(anne1),0);
    
    gtk_entry_set_editable(GTK_ENTRY(nom1),FALSE);
    gtk_entry_set_editable(GTK_ENTRY(prenom1),FALSE);
    gtk_entry_set_editable(GTK_ENTRY(mail1),FALSE);
    gtk_entry_set_editable(GTK_ENTRY(cin1),FALSE);
    gtk_entry_set_editable(GTK_ENTRY(tel1),FALSE);
    gtk_entry_set_editable(GTK_ENTRY(adresse1),FALSE);

   }

}


void
on_buttonRModif_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *Gestion_Des_Clients,*Principal2;


   Principal2 = create_Principal2 ();
  gtk_widget_show (Principal2);

  Gestion_Des_Clients=lookup_widget(button,"Gestion_Des_Clients");
  gtk_widget_destroy(Gestion_Des_Clients);
}


void
on_buttonVModif_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonVSupp_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonRSupp_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *Gestion_Des_Clients,*Principal2;


   Principal2 = create_Principal2 ();
  gtk_widget_show (Principal2);

  Gestion_Des_Clients=lookup_widget(button,"Gestion_Des_Clients");
  gtk_widget_destroy(Gestion_Des_Clients);
}


void
on_buttonCherchSupp_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{ int x;
  GtkWidget *cin2,*cincheck1;
  GtkWidget *treeview1;
  cin2 = lookup_widget(button, "entryCinSupp") ;
  strcpy(cinsupp,gtk_entry_get_text(GTK_ENTRY(cin2)));
  strcpy(c.mail,"");
  x=verif(cinsupp,c.mail);
  cincheck1 = lookup_widget(button, "labelChekCinSupp") ;
  if(x==2)
   {
     supprimer(cinsupp);
  treeview1 = lookup_widget(button, "treeviewsupp") ;
  afficher(treeview1);
     gtk_label_set_markup (GTK_LABEL (cincheck1), "<span font_desc='medium italic'foreground='red'> Client Supprimer !</span>"); 
     
   }
  else
   { gtk_label_set_markup (GTK_LABEL (cincheck1), "<span font_desc='medium italic'foreground='red'> CIN INEXISTANT !</span>");   
     
   }

}


void
on_button7_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button8_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *Gestion_Des_Clients,*Principal2;


   Principal2 = create_Principal2 ();
  gtk_widget_show (Principal2);

  Gestion_Des_Clients=lookup_widget(button,"Gestion_Des_Clients");
  gtk_widget_destroy(Gestion_Des_Clients);
}


void
on_buttonCherchAffiche_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{ 
  GtkWidget *treeview1;
  GtkWidget *cin2;
  GtkNotebook *notebookc;
   
  
   
   
 
  cin2 = lookup_widget(button, "entryCherchAffiche") ;
  strcpy(cinch,gtk_entry_get_text(GTK_ENTRY(cin2)));
  ch=chercher(cinch);

  
  treeview1 = lookup_widget(button, "GTK_TREE_VIEWChAffich") ;
  
  afficherch(treeview1,cinch);
  gtk_tree_view_set_reorderable (GTK_TREE_VIEW (treeview1), FALSE);
}


void
on_button13_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  
}


void
on_button12_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button11_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *Gestion_Des_Clients,*Principal2,*nom1,*prenom1,*cin1,*tel1,*mail1,*adresse1;
  GtkWidget *treeview1;
  GtkWidget *treeview2;
  Gestion_Des_Clients = create_Gestion_Des_Clients ();
  gtk_widget_show (Gestion_Des_Clients);
  treeview1 = lookup_widget(Gestion_Des_Clients, "GTK_TREE_VIEWChAffich") ;
  afficher(treeview1);
  treeview2 = lookup_widget(Gestion_Des_Clients, "treeviewsupp") ;
  afficher(treeview2);
  
  strcpy(s.sexe,"Homme");
  strcpy(c.sexe,"Homme");
  nom1 = lookup_widget(Gestion_Des_Clients, "entryNom2") ;
  prenom1 = lookup_widget(Gestion_Des_Clients, "entryPrenom2") ;
  cin1 = lookup_widget(Gestion_Des_Clients, "entryCin2") ;
  tel1 = lookup_widget(Gestion_Des_Clients, "entryTel2") ;
  mail1 = lookup_widget(Gestion_Des_Clients, "entryMail2") ;
  adresse1 = lookup_widget(Gestion_Des_Clients, "entryAdresse2") ;

  gtk_entry_set_editable(GTK_ENTRY(nom1),FALSE);
  gtk_entry_set_editable(GTK_ENTRY(prenom1),FALSE);
  gtk_entry_set_editable(GTK_ENTRY(mail1),FALSE);
  gtk_entry_set_editable(GTK_ENTRY(cin1),FALSE);
  gtk_entry_set_editable(GTK_ENTRY(tel1),FALSE);
  gtk_entry_set_editable(GTK_ENTRY(adresse1),FALSE);

  Principal2=lookup_widget(button,"Principal2");
  gtk_widget_destroy(Principal2);

  
}


gboolean
on_comboboxentryJour_button_press_event
                                        (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data)
{

  return FALSE;
}


void
on_buttonModif1_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonVmodif1_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *nom1,*nom2,*prenom1,*prenom2,*mail1,*mail2,*adresse1,*adresse2,*sexe1,*sexe2,*cin1,*cin2,*mois1,*mois2,*jour1,*jour2,*anne1,*anne2,*tel1,*tel2,*checkcin1,*checkmail1,*modifsucc;
    char nom[20],prenom[20],mail[30],adresse[50],cin[15],tel[20];
    int l=0,joour,moois,annne,t=0,i=0;
    
    checkcin1 = lookup_widget(button, "labelCheckCinModif") ;
    checkmail1 = lookup_widget(button, "labelCheckMailModif") ;
    nom2 = lookup_widget(button, "labelCheckNomModif") ;
    prenom2 = lookup_widget(button, "labelCheckPreomModif") ;
    adresse2 = lookup_widget(button, "labelCheckAdresseModif") ;
    jour2 = lookup_widget(button, "labelCheckJourModif") ;
    tel2 = lookup_widget(button, "labelCheckTelModif") ;
    modifsucc = lookup_widget(button, "labelModifSucc") ;

    gtk_label_set_text(GTK_LABEL(nom2)," ");
    gtk_label_set_text(GTK_LABEL(tel2)," ");
    gtk_label_set_text(GTK_LABEL(jour2)," ");
    gtk_label_set_text(GTK_LABEL(adresse2)," ");
    gtk_label_set_text(GTK_LABEL(prenom2)," ");
    gtk_label_set_text(GTK_LABEL(checkcin1)," ");
    gtk_label_set_text(GTK_LABEL(checkmail1)," ");
    gtk_label_set_text(GTK_LABEL(modifsucc)," ");     

    nom1 = lookup_widget(button, "entryNom2") ;
    strcpy(s.nom,gtk_entry_get_text(GTK_ENTRY(nom1)));
    while(i<strlen(s.nom))
    {
     if (((s.nom[i]<'a') || (s.nom[i]>'z')) && ((s.nom[i]<'A') || (s.nom[i]>'Z')))
      {
          gtk_label_set_markup (GTK_LABEL (nom2), "<span font_desc='medium italic'foreground='red'> INVALIDE !</span>");
         l=1;
      }
     i++;
    }
    if(strcmp(s.nom,"")==0)
      {
         gtk_label_set_markup (GTK_LABEL (nom2), "<span font_desc='medium italic'foreground='red'> Case Nom vide !</span>");
         l=1;
      }

    prenom1 = lookup_widget(button, "entryPrenom2") ;
    strcpy(s.prenom,gtk_entry_get_text(GTK_ENTRY(prenom1)));i=0;
    while(i<strlen(s.prenom))
    {
     if (((s.prenom[i]<'a') || (s.prenom[i]>'z')) && ((s.prenom[i]<'A') || (s.prenom[i]>'Z')))
      {
          gtk_label_set_markup (GTK_LABEL (prenom2), "<span font_desc='medium italic'foreground='red'> INVALIDE !</span>");
         l=1;
      }
     i++;
    }
    if(strcmp(s.prenom,"")==0)
      {  gtk_label_set_markup (GTK_LABEL (prenom2), "<span font_desc='medium italic'foreground='red'> Case Prenom Vide !</span>");     
         l=1;
      }
     
    cin1 = lookup_widget(button, "entryCin2") ;
    strcpy(s.cin,gtk_entry_get_text(GTK_ENTRY(cin1)));i=0;
    if (strlen(s.cin)<8)
     {
       gtk_label_set_markup (GTK_LABEL (checkcin1), "<span font_desc='medium italic'foreground='red'> Entrez les 8 chiffres de CIN !</span>");l=1;
     }
    while(i<strlen(s.cin))
    {
     if ((s.cin[i]<'0') || (s.cin[i]>'9'))
      {
          gtk_label_set_markup (GTK_LABEL (checkcin1), "<span font_desc='medium italic'foreground='red'> INVALIDE !</span>");
         l=1;
      }
     i++;
    }
    if((strchr(s.cin,' ')!=NULL)||(atof(s.cin)<0))
      {       gtk_label_set_markup (GTK_LABEL (checkcin1), "<span font_desc='medium italic'foreground='red'> Cin Invalide !</span>");
         l=1;
      }
    if(strcmp(s.cin,"")==0)
      {  gtk_label_set_markup (GTK_LABEL (checkcin1), "<span font_desc='medium italic'foreground='red'> Case CIN Vide !</span>");     
         l=1;
      }

    tel1 = lookup_widget(button, "entryTel2") ;
    strcpy(s.tel,gtk_entry_get_text(GTK_ENTRY(tel1)));
    if(strchr(s.tel,' ')!=NULL)
      {       gtk_label_set_markup (GTK_LABEL (tel2), "<span font_desc='medium italic'foreground='red'> N°Tel INVALIDE !</span>");
         l=1;
      }
    if(strcmp(s.tel,"")==0)
      {  gtk_label_set_markup (GTK_LABEL (tel2), "<span font_desc='medium italic'foreground='red'> Case N°Tel Vide !</span>");     
         l=1;
      }

    mail1 = lookup_widget(button, "entryMail2") ;
    strcpy(s.mail,gtk_entry_get_text(GTK_ENTRY(mail1)));
    if (((strchr(s.mail, '@')==NULL)||(strchr(s.mail, '.')==NULL))||(strchr(s.mail, ' ')!=NULL))
      {
            gtk_label_set_markup (GTK_LABEL (checkmail1), "<span font_desc='medium italic'foreground='red'> E-MAIL Non Valide !</span>");
         l=1;
      }
    if(strcmp(s.mail,"")==0)
      {  gtk_label_set_markup (GTK_LABEL (checkmail1), "<span font_desc='medium italic'foreground='red'> Case E-Mail Vide !</span>");     
         l=1;
      }

    adresse1 = lookup_widget(button, "entryAdresse2") ;
    strcpy(s.adresse,gtk_entry_get_text(GTK_ENTRY(adresse1)));
    if(strchr(s.adresse,' ')!=NULL)
      {    gtk_label_set_markup (GTK_LABEL (adresse2), "<span font_desc='medium italic'foreground='red'> Adresse Invalide !</span>");   
        l=1;
      }
    if(strcmp(s.adresse,"")==0)
      {  gtk_label_set_markup (GTK_LABEL (adresse2), "<span font_desc='medium italic'foreground='red'> Case Adresse Vide !</span>");     
         l=1;
      }
    

    anne1 = lookup_widget(button, "comboboxentryAnne2") ;
    gchar *anne=gtk_combo_box_get_active_text(anne1);
    
    annne=atof(anne);
    if((annne<1910)||(annne>2016)) 
    {    gtk_label_set_markup (GTK_LABEL (jour2), "<span font_desc='medium italic'foreground='red'> Changez L'anneé !</span>");
       l=1;
    }
    if(strcmp(anne,"")==0)
      {  gtk_label_set_markup (GTK_LABEL (jour2), "<span font_desc='medium italic'foreground='red'> Case Anne Vide !</span>");     
         l=1;
      }
    
    mois1 = lookup_widget(button, "comboboxentryMois2") ;
    gchar *mois=gtk_combo_box_get_active_text(mois1);
    
    moois=atof(mois);
    if((moois>12)||(moois<1)) 
    {    gtk_label_set_markup (GTK_LABEL (jour2), "<span font_desc='medium italic'foreground='red'> Entrez Mois entre 1 et 12 !</span>");
       l=1;
    }
    if(strcmp(mois,"")==0)
      {  gtk_label_set_markup (GTK_LABEL (jour2), "<span font_desc='medium italic'foreground='red'> Case Mois Vide !</span>");     
         l=1;
      }

    jour1 = lookup_widget(button, "comboboxentryJour2") ;
    gchar *jour=gtk_combo_box_get_active_text(jour1);
    
    joour=atof(jour);
    if((joour>31)||(joour<1)) 
    {    gtk_label_set_markup (GTK_LABEL (jour2), "<span font_desc='medium italic'foreground='red'> Entrez Jour entre 1 et 31 !</span>");
       l=1;
    }
    if(strcmp(jour,"")==0)
      {  gtk_label_set_markup (GTK_LABEL (jour2), "<span font_desc='medium italic'foreground='red'> Case Jour Vide !</span>");     
         l=1;
      }

     if(strcmp(s.cin,cin45)!=0)
      {
        t= verif(s.cin,"");
        if(t==2)
          {  gtk_label_set_markup (GTK_LABEL (checkcin1), "<span font_desc='medium italic'foreground='red'> Cin Existant Pour D'autre Clients !</span>");
             l=1;
          }
      }
    
     if(strcmp(s.mail,c.mail)!=0)
      { 
        t=verifm(s.mail);
        if(t==3)
          {gtk_label_set_markup (GTK_LABEL (checkmail1), "<span font_desc='medium italic'foreground='red'> Email Existant Pour D'autre Clients !</span>");
          l=1;
          }
      }

    if(l!=1)
     {strcpy(s.d.jour,jour);strcpy(s.d.mois,mois);strcpy(s.d.anne,anne);
       modifier(cin45,s);
       gtk_label_set_markup (GTK_LABEL (modifsucc), "<span font_desc='medium italic'foreground='brown'> Client Modifier !</span>");
        strcpy(c.mail,s.mail);
        strcpy(cin45,s.cin);
        
     }
l=0;

}


void
on_Homme_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  
  if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (togglebutton)))
       {
          strcpy(c.sexe,"Homme");
          
       } 
  else 
       {
          strcpy(c.sexe,"Femme");
          
       }
}


void
on_GTK_TREE_VIEWChAffich_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
   GtkTreeIter iter;
  gchar* nom;
  gchar* prenom;
  gchar* mail;
  gchar* adresse;
  gchar* sexe;
  gchar* cin;
  gchar* mois;
  gchar* jour;
  gchar* anne;
  gchar* tel;
  GtkWidget *cin2,*cincheck1;
  GtkWidget *treeview1;
  
   treeview1 = lookup_widget(treeview, "GTK_TREE_VIEWChAffich") ;
   gtk_tree_view_set_reorderable (GTK_TREE_VIEW (treeview1), FALSE);
  
   GtkTreeModel *model = gtk_tree_view_get_model(treeview);
   if(gtk_tree_model_get_iter(model, &iter, path))
     {
         gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&nom,1,&prenom,2,&cin,3,&tel,4,&mail,5,&adresse,6,&jour,7,&mois,8,&anne,9,&sexe,-1);
     
     
                       cin2 = lookup_widget(treeview,"entryCherchAffiche") ;
                       gtk_entry_set_text(GTK_ENTRY(cin2),cin);
                       
                       c=chercher(cin);
                       afficherchu(treeview,c);


     }




}


void
on_TbuttonAffichtous_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *treeview1;
  treeview1 = lookup_widget(button, "GTK_TREE_VIEWChAffich") ;
  
  afficher(treeview1);
 gtk_tree_view_set_reorderable (GTK_TREE_VIEW (treeview1), TRUE);

}


void
on_Homme2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (togglebutton)))
       {
          strcpy(s.sexe,"Homme");
          
       } 
  else 
       {
          strcpy(s.sexe,"Femme");
          
       }
}


void
on_treeviewsupp_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
  GtkTreeIter iter;
  gchar* nom;
  gchar* prenom;
  gchar* mail;
  gchar* adresse;
  gchar* sexe;
  gchar* cin;
  gchar* mois;
  gchar* jour;
  gchar* anne;
  gchar* tel;
  GtkWidget *cin2,*cincheck1;



   GtkTreeModel *model = gtk_tree_view_get_model(treeview);
   if(gtk_tree_model_get_iter(model, &iter, path))
     {
         gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&nom,1,&prenom,2,&cin,3,&tel,4,&mail,5,&adresse,6,&jour,7,&mois,8,&anne,9,&sexe,-1);
     
     
                       cin2 = lookup_widget(treeview, "entryCinSupp") ;
                       gtk_entry_set_text(GTK_ENTRY(cin2),cin);
                       cincheck1 = lookup_widget(treeview, "labelChekCinSupp") ;
                       gtk_label_set_markup (GTK_LABEL (cincheck1), "<span font_desc='medium italic'foreground='red'> Client Supprimer !</span>");
                       
                       supprimer(cin);
                       afficher(treeview);


     }

}


void
on_TbuttonAffichsupp_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *treeview1;
  treeview1 = lookup_widget(button, "treeviewsupp") ;
  
  afficher(treeview1);
}


void
on_entryCin_changed                    (GtkEditable     *editable,
                                        gpointer         user_data)
{ int x=0;
  GtkWidget *checkcin1,*cin1;
  checkcin1 = lookup_widget(editable, "labelVerifCin") ;  
  gtk_label_set_text(GTK_LABEL(checkcin1)," ");
  cin1 = lookup_widget(editable, "entryCin") ;
    strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(cin1)));
   x=verif(c.cin,c.mail);
    if(x==2)
     {    gtk_label_set_markup (GTK_LABEL (checkcin1), "<span font_desc='italic'foreground='red'> CIN EXISTANT !</span>");
       
     }


    
}


void
on_entryMail_changed                   (GtkEditable     *editable,
                                        gpointer         user_data)
{int x=0;
    GtkWidget *checkmail1,*mail1;
    
    checkmail1 = lookup_widget(editable, "labelVerifMail") ;  
    gtk_label_set_text(GTK_LABEL(checkmail1)," ");
    
    mail1 = lookup_widget(editable, "entryMail") ;
    strcpy(c.mail,gtk_entry_get_text(GTK_ENTRY(mail1)));
    strcpy(c.cin,"");
    x=verif(c.cin,c.mail);
  if(x==3)
     {    gtk_label_set_markup (GTK_LABEL (checkmail1), "<span font_desc='italic'foreground='red'> E-MAIL EXISTANT !</span>");
       
     }
}


void
on_TbuttonAfficheAnSech_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{ 
    GtkWidget *ansech1;
    gchar *str;  
    int a;
    a=anneseche();
    str = g_strdup_printf ("%d",a);
    ansech1 = lookup_widget(button,"textviewAnseche") ;
    gtk_label_set_text(GTK_LABEL(ansech1),str);
    g_free (str);

}


void
on_TbuttonInitAjout_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *nom1,*nom2,*prenom1,*prenom2,*mail1,*mail2,*adresse1,*adresse2,*sexe1,*sexe2,*cin1,*cin2,*mois1,*mois2,*jour1,*jour2,*anne1,*anne2,*tel1,*tel2,*checkcin1,*checkmail1,*ajsucc,*rhomme,*calend1;

   checkcin1 = lookup_widget(button, "labelVerifCin") ;
    checkmail1 = lookup_widget(button, "labelVerifMail") ;
    nom2 = lookup_widget(button, "labelVerifNom") ;
    prenom2 = lookup_widget(button, "labelVerifPrenom") ;
    adresse2 = lookup_widget(button, "labelVerifAdresse") ;
    jour2 = lookup_widget(button, "labelVerifJour") ;
    tel2 = lookup_widget(button, "labelVerifTel") ;
    ajsucc = lookup_widget(button, "labelAjoutSucc") ;
    calend1 = lookup_widget(button, "Tlabelcheckcalendar") ;

    gtk_label_set_text(GTK_LABEL(nom2)," ");
    gtk_label_set_text(GTK_LABEL(tel2)," ");
    gtk_label_set_text(GTK_LABEL(jour2)," ");
    gtk_label_set_text(GTK_LABEL(adresse2)," ");
    gtk_label_set_text(GTK_LABEL(prenom2)," ");
    gtk_label_set_text(GTK_LABEL(checkcin1)," ");
    gtk_label_set_text(GTK_LABEL(checkmail1)," ");
    gtk_label_set_text(GTK_LABEL(ajsucc)," ");
    gtk_label_set_text(GTK_LABEL(calend1)," ");

    nom1 = lookup_widget(button, "entryNom") ;
    prenom1 = lookup_widget(button, "entryPrenom") ;
    cin1 = lookup_widget(button, "entryCin") ;
    tel1 = lookup_widget(button, "entryTel") ;
    mail1 = lookup_widget(button, "entryMail") ;
    adresse1 = lookup_widget(button, "entryAdresse") ;
    anne1 = lookup_widget(button, "comboboxentryAnne") ;
    mois1 = lookup_widget(button, "comboboxentryMois") ;
    jour1 = lookup_widget(button, "comboboxentryJour") ;
    rhomme = lookup_widget(button, "Homme") ;

    gtk_entry_set_text(GTK_ENTRY(nom1),"");

    gtk_entry_set_text(GTK_ENTRY(prenom1),"");

    gtk_entry_set_text(GTK_ENTRY(cin1),"");

    gtk_entry_set_text(GTK_ENTRY(tel1),"");

    gtk_entry_set_text(GTK_ENTRY(mail1),"");

    gtk_entry_set_text(GTK_ENTRY(adresse1),"");
   
    gtk_combo_box_set_active(GTK_COMBO_BOX(jour1),0);
    
    gtk_combo_box_set_active(GTK_COMBO_BOX(mois1),0);
   
    gtk_combo_box_set_active(GTK_COMBO_BOX(anne1),0);

    gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (rhomme),TRUE);


}


void
on_calendarAjout_day_selected          (GtkCalendar     *calendar,
                                        gpointer         user_data)
{
  GtkCalendar *inscdate,*inscdate1;
   int jour,mois,anne;
   char jour1[5],mois1[5],anne1[7];
   inscdate1 = lookup_widget(calendar, "calendarAjout") ;
   gtk_calendar_get_date(GTK_CALENDAR(inscdate1),&anne,&mois,&jour);
   mois=mois+1;
  snprintf(jour1, sizeof(jour1), "%d/", jour);
  snprintf(mois1, sizeof(mois1), "%d/", mois);
  snprintf(anne1, sizeof(anne1), "%d", anne);
  strcpy(c.dateinsc,jour1);
  strcat(c.dateinsc,mois1);
  strcat(c.dateinsc,anne1);
}


void
on_buttonModif2_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *nom1,*nom2,*prenom1,*prenom2,*mail1,*mail2,*cincheck1,*adresse1,*adresse2,*sexe1,*sexe2,*cin1,*cin2,*mois1,*mois2,*jour1,*jour2,*anne1,*anne2,*tel1,*tel2,*checkcin1,*checkmail1,*modifsucc,*rhomme,*rfemme;
  GtkWidget *window3 ;
  GtkNotebook *notebookc;
  int x;
  int joour,moois,annne;
  cincheck1 = lookup_widget(button, "labelCheckCinModif2") ;
  gtk_label_set_text(GTK_LABEL(cincheck1),"");
  
  notebookc=lookup_widget(button, "notebookclient") ;
  gtk_notebook_set_current_page (notebookc,1);
  
  cin2 = lookup_widget(button, "entryCinModif") ;
  gtk_entry_set_text(GTK_ENTRY(cin2),c.cin); 

  strcpy(cin45,c.cin);
  x=verif(cin45,"");

    checkcin1 = lookup_widget(button, "labelCheckCinModif") ;
    checkmail1 = lookup_widget(button, "labelCheckMailModif") ;
    nom2 = lookup_widget(button, "labelCheckNomModif") ;
    prenom2 = lookup_widget(button, "labelCheckPreomModif") ;
    adresse2 = lookup_widget(button, "labelCheckAdresseModif") ;
    jour2 = lookup_widget(button, "labelCheckJourModif") ;
    tel2 = lookup_widget(button, "labelCheckTelModif") ;
    modifsucc = lookup_widget(button, "labelModifSucc") ;
    nom1 = lookup_widget(button, "entryNom2") ;
    prenom1 = lookup_widget(button, "entryPrenom2") ;
    cin1 = lookup_widget(button, "entryCin2") ;
    tel1 = lookup_widget(button, "entryTel2") ;
    mail1 = lookup_widget(button, "entryMail2") ;
    adresse1 = lookup_widget(button, "entryAdresse2") ;
    
    gtk_label_set_text(GTK_LABEL(nom2)," ");
    gtk_label_set_text(GTK_LABEL(tel2)," ");
    gtk_label_set_text(GTK_LABEL(jour2)," ");
    gtk_label_set_text(GTK_LABEL(adresse2)," ");
    gtk_label_set_text(GTK_LABEL(prenom2)," ");
    gtk_label_set_text(GTK_LABEL(checkcin1)," ");
    gtk_label_set_text(GTK_LABEL(checkmail1)," ");
    gtk_label_set_text(GTK_LABEL(modifsucc)," ");

 if(x==2)
   {
     
    c=chercher(cin45);

  gtk_entry_set_editable(GTK_ENTRY(nom1),TRUE);
  gtk_entry_set_editable(GTK_ENTRY(prenom1),TRUE);
  gtk_entry_set_editable(GTK_ENTRY(mail1),TRUE);
  gtk_entry_set_editable(GTK_ENTRY(cin1),TRUE);
  gtk_entry_set_editable(GTK_ENTRY(tel1),TRUE);
  gtk_entry_set_editable(GTK_ENTRY(adresse1),TRUE);

    nom1 = lookup_widget(button, "entryNom2") ;
    gtk_entry_set_text(GTK_ENTRY(nom1),c.nom);

    prenom1 = lookup_widget(button, "entryPrenom2") ;
    gtk_entry_set_text(GTK_ENTRY(prenom1),c.prenom);

    cin1 = lookup_widget(button, "entryCin2") ;
    gtk_entry_set_text(GTK_ENTRY(cin1),c.cin);

    tel1 = lookup_widget(button, "entryTel2") ;
    gtk_entry_set_text(GTK_ENTRY(tel1),c.tel);

    mail1 = lookup_widget(button, "entryMail2") ;
    gtk_entry_set_text(GTK_ENTRY(mail1),c.mail);

    adresse1 = lookup_widget(button, "entryAdresse2") ;
    gtk_entry_set_text(GTK_ENTRY(adresse1),c.adresse);
    
    joour=atof(c.d.jour);
    jour1 = lookup_widget(button, "comboboxentryJour2") ;
    gtk_combo_box_set_active(GTK_COMBO_BOX(jour1),joour);
    
    moois=atof(c.d.mois);
    mois1 = lookup_widget(button, "comboboxentryMois2") ;
    gtk_combo_box_set_active(GTK_COMBO_BOX(mois1),moois);

    annne=atof(c.d.anne);
    anne1 = lookup_widget(button, "comboboxentryAnne2") ;
    gtk_combo_box_set_active(GTK_COMBO_BOX(anne1),annne-1909);
    
     rhomme = lookup_widget(button, "Homme2") ;
     rfemme = lookup_widget(button, "Femme2") ;
    if(strcmp(c.sexe,"Homme")==0)
    {
      gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (rhomme),TRUE);
    }
    if(strcmp(c.sexe,"Femme")==0)
    {
      gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (rfemme),TRUE);
    }

    gtk_label_set_text(GTK_LABEL(nom2)," ");
    gtk_label_set_text(GTK_LABEL(tel2)," ");
    gtk_label_set_text(GTK_LABEL(jour2)," ");
    gtk_label_set_text(GTK_LABEL(adresse2)," ");
    gtk_label_set_text(GTK_LABEL(prenom2)," ");
    gtk_label_set_text(GTK_LABEL(checkcin1)," ");
    gtk_label_set_text(GTK_LABEL(checkmail1)," ");
    gtk_label_set_text(GTK_LABEL(modifsucc)," ");

   }
  else
   {
     cincheck1 = lookup_widget(button, "labelCheckCinModif2") ;
     gtk_label_set_markup (GTK_LABEL (cincheck1), "<span font_desc='medium italic'foreground='red'> CIN INEXISTANT !</span>");  
     
     nom1 = lookup_widget(button, "entryNom2") ;
    gtk_entry_set_text(GTK_ENTRY(nom1),"");

    prenom1 = lookup_widget(button, "entryPrenom2") ;
    gtk_entry_set_text(GTK_ENTRY(prenom1),"");

    cin1 = lookup_widget(button, "entryCin2") ;
    gtk_entry_set_text(GTK_ENTRY(cin1),"");

    tel1 = lookup_widget(button, "entryTel2") ;
    gtk_entry_set_text(GTK_ENTRY(tel1),"");

    mail1 = lookup_widget(button, "entryMail2") ;
    gtk_entry_set_text(GTK_ENTRY(mail1),"");

    adresse1 = lookup_widget(button, "entryAdresse2") ;
    gtk_entry_set_text(GTK_ENTRY(adresse1),"");
   
    jour1 = lookup_widget(button, "comboboxentryJour2") ;
    gtk_combo_box_set_active(GTK_COMBO_BOX(jour1),0);
    
    mois1 = lookup_widget(button, "comboboxentryMois2") ;
    gtk_combo_box_set_active(GTK_COMBO_BOX(mois1),0);

    anne1 = lookup_widget(button, "comboboxentryAnne2") ;
    gtk_combo_box_set_active(GTK_COMBO_BOX(anne1),0);
    
    gtk_entry_set_editable(GTK_ENTRY(nom1),FALSE);
    gtk_entry_set_editable(GTK_ENTRY(prenom1),FALSE);
    gtk_entry_set_editable(GTK_ENTRY(mail1),FALSE);
    gtk_entry_set_editable(GTK_ENTRY(cin1),FALSE);
    gtk_entry_set_editable(GTK_ENTRY(tel1),FALSE);
    gtk_entry_set_editable(GTK_ENTRY(adresse1),FALSE);

   }

    
}


void
on_TbuttonInitModif_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *nom1,*nom2,*prenom1,*prenom2,*mail1,*mail2,*cincheck1,*adresse1,*adresse2,*sexe1,*sexe2,*cin1,*cin2,*mois1,*mois2,*jour1,*jour2,*anne1,*anne2,*tel1,*tel2,*checkcin1,*checkmail1,*modifsucc,*rhomme,*rfemme;
  GtkWidget *window3 ;
  
    cincheck1 = lookup_widget(button, "labelCheckCinModif2") ;
    gtk_label_set_text(GTK_LABEL(cincheck1),"");
  
    cin2 = lookup_widget(button, "entryCinModif") ;
    gtk_entry_set_text(GTK_ENTRY(cin2),"");
  

    checkcin1 = lookup_widget(button, "labelCheckCinModif") ;
    checkmail1 = lookup_widget(button, "labelCheckMailModif") ;
    nom2 = lookup_widget(button, "labelCheckNomModif") ;
    prenom2 = lookup_widget(button, "labelCheckPreomModif") ;
    adresse2 = lookup_widget(button, "labelCheckAdresseModif") ;
    jour2 = lookup_widget(button, "labelCheckJourModif") ;
    tel2 = lookup_widget(button, "labelCheckTelModif") ;
    modifsucc = lookup_widget(button, "labelModifSucc") ;
    nom1 = lookup_widget(button, "entryNom2") ;
    prenom1 = lookup_widget(button, "entryPrenom2") ;
    cin1 = lookup_widget(button, "entryCin2") ;
    tel1 = lookup_widget(button, "entryTel2") ;
    mail1 = lookup_widget(button, "entryMail2") ;
    adresse1 = lookup_widget(button, "entryAdresse2") ;
    
    gtk_label_set_text(GTK_LABEL(nom2)," ");
    gtk_label_set_text(GTK_LABEL(tel2)," ");
    gtk_label_set_text(GTK_LABEL(jour2)," ");
    gtk_label_set_text(GTK_LABEL(adresse2)," ");
    gtk_label_set_text(GTK_LABEL(prenom2)," ");
    gtk_label_set_text(GTK_LABEL(checkcin1)," ");
    gtk_label_set_text(GTK_LABEL(checkmail1)," ");
    gtk_label_set_text(GTK_LABEL(modifsucc)," ");
    
    nom1 = lookup_widget(button, "entryNom2") ;
    gtk_entry_set_text(GTK_ENTRY(nom1),"");

    prenom1 = lookup_widget(button, "entryPrenom2") ;
    gtk_entry_set_text(GTK_ENTRY(prenom1),"");

    cin1 = lookup_widget(button, "entryCin2") ;
    gtk_entry_set_text(GTK_ENTRY(cin1),"");

    tel1 = lookup_widget(button, "entryTel2") ;
    gtk_entry_set_text(GTK_ENTRY(tel1),"");

    mail1 = lookup_widget(button, "entryMail2") ;
    gtk_entry_set_text(GTK_ENTRY(mail1),"");

    adresse1 = lookup_widget(button, "entryAdresse2") ;
    gtk_entry_set_text(GTK_ENTRY(adresse1),"");
   
    jour1 = lookup_widget(button, "comboboxentryJour2") ;
    gtk_combo_box_set_active(GTK_COMBO_BOX(jour1),0);
    
    mois1 = lookup_widget(button, "comboboxentryMois2") ;
    gtk_combo_box_set_active(GTK_COMBO_BOX(mois1),0);

    anne1 = lookup_widget(button, "comboboxentryAnne2") ;
    gtk_combo_box_set_active(GTK_COMBO_BOX(anne1),0);
    
    gtk_entry_set_editable(GTK_ENTRY(nom1),FALSE);
    gtk_entry_set_editable(GTK_ENTRY(prenom1),FALSE);
    gtk_entry_set_editable(GTK_ENTRY(mail1),FALSE);
    gtk_entry_set_editable(GTK_ENTRY(cin1),FALSE);
    gtk_entry_set_editable(GTK_ENTRY(tel1),FALSE);
    gtk_entry_set_editable(GTK_ENTRY(adresse1),FALSE);
   


}

gboolean
on_GTK_TREE_VIEWChAffich_drag_drop     (GtkWidget       *widget,
                                        GdkDragContext  *drag_context,
                                        gint             x,
                                        gint             y,
                                        guint            time,
                                        gpointer         user_data)
{/*
GtkWidget *treeview1;
  treeview1 = lookup_widget(widget, "GTK_TREE_VIEWChAffich") ;
  
  afficher(treeview1);*/
  return FALSE;
}


void
on_GTK_TREE_VIEWChAffich_drag_end      (GtkWidget       *widget,
                                        GdkDragContext  *drag_context,
                                        gpointer         user_data)
{
 GtkTreeIter iter;
  gchar* nom;
  gchar* prenom;
  gchar* mail;
  gchar* adresse;
  gchar* sexe;
  gchar* cin;
  gchar* mois;
  gchar* jour;
  gchar* anne;
  gchar* tel;
  gchar* dateinsc;
  GtkWidget *cin2,*cincheck1;
  client cha;

 remove("infclients.txt");
 GtkTreePath *path;
 gint* x,y;

gtk_tree_view_get_path_at_pos(GTK_TREE_VIEW(widget),0,0,&path, NULL, NULL, NULL);

   GtkTreeModel *model = gtk_tree_view_get_model(widget);
   gtk_tree_model_get_iter(model, &iter, path);
    
      do
{
         gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&nom,1,&prenom,2,&cin,3,&tel,4,&mail,5,&adresse,6,&jour,7,&mois,8,&anne,9,&sexe,10,&dateinsc,-1);

                      strcpy(cha.cin,cin);
		       strcpy(cha.prenom,prenom);
		       strcpy(cha.nom,nom);
                       strcpy(cha.tel,tel);
                       strcpy(cha.mail,mail);
                       strcpy(cha.adresse,adresse);
                       strcpy(cha.d.jour,jour);
                       strcpy(cha.d.mois,mois);
                       strcpy(cha.d.anne,anne);
                       strcpy(cha.sexe,sexe);
                       strcpy(cha.dateinsc,dateinsc);
                ajouter(cha);
                       
                  
     }while(gtk_tree_model_iter_next (model,&iter)==TRUE);


    return TRUE;
                       
}


gboolean
on_GTK_TREE_VIEWChAffich_select_all    (GtkTreeView     *treeview,
                                        gpointer         user_data)
{/*
GtkWidget *Gestion_Des_Clients,*Principal2;


   Principal2 = create_Principal2 ();
  gtk_widget_show (Principal2);*/

  
  return FALSE;
}

/*
void
on_TbuttonAfficheAnSech_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

}*/


void
on_anplussech1_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *AnSech,*Principal2;
  AnSech = create_AnSech ();
  gtk_widget_show (AnSech);

  Principal2=lookup_widget(button,"Principal2");
  gtk_widget_destroy(Principal2);
}


void
on_buttonRetourAn_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *Principal2,*AnSech;
Principal2 = create_Principal2 ();
  gtk_widget_show (Principal2);

AnSech =lookup_widget(button,"AnSech");
  gtk_widget_destroy (AnSech);

  
}

