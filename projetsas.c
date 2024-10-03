#include <stdio.h>
#include <string.h>

struct date{
  int jour;
  int mois;
  int annee;
  };

struct reservation {
    char nom[30];
    char prenom[30];
    char telephone[20];
    int age;
    int statut;
    int reference;
    struct date dates;
};

struct reservation temp;

struct reservation reservations[200];

char nomtemp[20];
int numrese = 0;
int found = 0;
int choix;
int ref;
int i, j;

void ajouter_une_reservation(){
    printf("*******AJOUTER UNE RESERVATION*******\n");
    if(numrese < 200) {
    
    printf("entrez le nom : ");
    scanf("%s", reservations[numrese].nom);
    
    printf("entrez le prenom : ");
    scanf("%s", reservations[numrese].prenom);
    
    printf("entrez le numero de telephone : ");
    scanf("%s", reservations[numrese].telephone);
    
    printf("entrez l'age : ");
    scanf("%d", &reservations[numrese].age);
    
    printf("entrez le statut . \n");
    printf("1-valide .\n");
    printf("2-reporte .\n");
    printf("3-annule .\n");
    printf("4-traite .\n");
    
    printf("veulliez entrer un choix de statut :");
    scanf("%d", &reservations[numrese].statut);
    
    printf("entrez la date de reservation. \n");
    printf("le jour : ");
    scanf("%d", &reservations[numrese].dates.jour);
    printf("le mois : ");
    scanf("%d", &reservations[numrese].dates.mois);
    printf("l'annee : ");
    scanf("%d", &reservations[numrese].dates.annee);
     
    reservations[numrese].reference = numrese + 1 ;
    numrese++;
    }
    
    else
       printf("espace plein !");

}

void modifier_ou_supprimer_une_reservation()
{
    printf("*******MODIFIER OU SUPPRIMER UNE RESERVATION*******\n");
    
    
    printf("1.modifer une reservation .\n ");
    printf("2.supprimer une reservation .\n ");
    
    printf("veuillez entrer un choix :");
    scanf("%d", &choix);
    
    if(choix == 1){
      do{
        printf("veuillez entrer la reference de reservation que vous vouler modifier :");
        scanf("%d", &ref);
        
        for (i = 0; i < numrese ; i++){
            if(ref == reservations[i].reference){
                found++;
                break;
            }
        }
        
        if(found == 0)
           printf("Cette reference n'existe pas \n");
        else{
           printf("que ce que vous voulez modifier ?");
           printf("1.nom. \n");
           printf("2.prenom. \n");
           printf("3.telephone. \n");
           printf("4.age. \n");
           printf("5.statut. \n");
           printf("6.date de reservation. \n");
           printf("7.quitter ! \n");
           
           printf("veuillez entrer un choix :");
           scanf("%d", choix);
           
           switch (choix)
           {
           case 1:
                printf("entrer le nom a ajoute: ");
                scanf("%s", reservations[i].nom);
                printf("le nom à été mis-à-jouré\n");
                break;
              
           case 2:
                printf("entrer le prenom a ajoute: ");
                scanf("%s", &reservations[i].prenom);
                printf("le prenom à été mis-à-jouré\n");
                break;
              
          case 3:
                printf("entrer le telephone a ajoute: ");
                scanf("%s", &reservations[i].telephone);
                printf("le telephone à été mis-à-jouré\n");
                break;
                
          case 4:
                printf("entrer l'age a ajoute: ");
                scanf("%d", &reservations[i].age);
                printf("l'age à été mis-à-jouré\n");
                break;
                
          case 5:
                printf("entrez le statut a ajoute . ");
                printf("1-valide .");
                printf("2-reporte .");
                printf("3-annule .");
                printf("4-traite .");
    
                printf("veulliez entrer un choix de statut :");
                scanf("%s", &reservations[numrese].statut);
                printf("le statut à été mis-à-jouré\n");
                break;
                
          case 6:
                printf("entrez la date a ajoute. ");
                printf("le jour : ");
                scanf("%s", &reservations[numrese].dates.jour);
                printf("le mois : ");
                scanf("%s", &reservations[numrese].dates.mois);
                printf("l'annee : ");
                scanf("%s", &reservations[numrese].dates.annee);
                printf("la date à été mis-à-jouré\n");
                break;
              
          case 7:
                printf("vous avez quittez !");
                return ;
             
          default:
                printf("ce choix n'existe pas !");
          }
        }
      } while (choix != 7);
           
    }
    else if(choix == 2){
        printf("veuillez entrer la reference de reservation que vous vouler supprimer :");
        scanf("%d", &ref);
        
        for (i = 0; i < numrese ; i++){
            if(ref == reservations[i].reference){
                found++;
                break;
            }
        }
        
        if(found == 0)
           printf("Cette reference n'existe pas \n");
           
        else{
            reservations[i] = reservations[numrese-1];
            printf("la reservation est supprimer avec success.");
            numrese--;
        }
    }
    
    else
        printf("ce choix n'existe pas !");
}

void afficher_les_details_dune_reservation()
{
    printf("*******AFFICHER LES DETAILES DUNE RESERVATION*******\n");
    printf("veuillez entrer le reference de reservation que vous voulez :");
    scanf("%d", &ref);
        
    for (i = 0; i < numrese ; i++){
        if(ref == reservations[i].reference){
            found++;
            break;
        }
    }
    
    if(found == 0)
        printf("Cette reference n'existe pas \n");
    else{
        printf("nom : %s \n", reservations[numrese].nom);
        
        printf("prenom : %s \n", reservations[numrese].prenom);
        
        printf("telephone : %s \n", reservations[numrese].telephone);
        
        printf("age : %d \n\n", reservations[numrese].age);
        
        printf("statut : %d \n\n", reservations[numrese].statut);
        
        printf("reference : %d \n\n", reservations[numrese].reference);
        
        printf("date : %d/%d/%d \n", reservations[numrese].dates.jour , reservations[numrese].dates.mois , reservations[numrese].dates.annee);
        }
}

void  tri_des_reservations()
{
    printf("*******TRI DES RESERVATIONS*******\n");
    
    printf("veuillez entrer la maniere de tri que vous voulez");
    printf("1.Tri des reservations par Nom.\n ");
    printf("2.Tri des reservations par date. \n ");
    printf("3.Tri des reservations par statut. \n ");
    
    printf("veuillez entrer un choix :");
    scanf("%d", &choix);
    
    if(choix == 1){
        for (i = 0; i < numrese - 1; i++){
          for (j = 0; j < numrese-i- 1; j++){
               if (strcasecmp(reservations[j].nom,reservations[j+1].nom) == 1){
                   temp = reservations[j+1];
                   reservations[j+1] = reservations[j];
                   reservations[j] = temp;
               }
          }
        }
    }
    
    else if (choix == 2){
        (Optionnel)
    }
    
    else if (choix == 3){
        for (i = 0; i < numrese - 1; i++){
          for (j = 0; j < numrese-i- 1; j++){
               if (reservations[j].statut > reservations[j+1].statut){
                   temp = reservations[j+1];
                   reservations[j+1] = reservations[j];
                   reservations[j] = temp;
               }
          }
        }
    }
    
    else
        printf("ce choix n'existe pas !");
}

void recherche_des_reservations()
{
    printf("*******RECHERCHE DES RESERVATIONS*******\n");
    
    printf("veuillez entrer la maniere de recherche que vous voulez");
    printf("1.Recherche d'une reservation par reference unique.\n ");
    printf("2.Recherche d'une reservation par nom.. \n ");
    printf("3.Tri des reservations par statut. \n ");
    
    printf("veuillez entrer un choix :");
    scanf("%d", &choix);
    
    if(choix == 1){
        afficher_les_details_dune_reservation();
    }
    
    else if (choix == 2){
        printf("veuillez entrer le nom de reservation que vous voulez :");
    scanf("%s", &nomtemp);
        
    for (i = 0; i < numrese ; i++){
        if(strcmp(nomtemp,reservations[i].nom) == 0){
            found++;
            break;
        }
    }
    
    if(found == 0)
        printf("Ce nom n'existe pas \n");
    else{
        printf("nom : %s \n", reservations[numrese].nom);
        
        printf("prenom : %s \n", reservations[numrese].prenom);
        
        printf("telephone : %s \n", reservations[numrese].telephone);
        
        printf("age : %d \n\n", reservations[numrese].age);
        
        printf("statut : %d \n\n", reservations[numrese].statut);
        
        printf("reference : %d \n\n", reservations[numrese].reference);
        
        printf("date : %d/%d/%d \n", reservations[numrese].dates.jour , reservations[numrese].dates.mois , reservations[numrese].dates.annee);
        }
    }
    
    else if (choix == 3){
         (Optionnel)
    }
    
    else
        printf("ce choix n'existe pas !");
    
}

void statistiques()
{
    printf("*******STATISTIQUES*******\n");
    
    printf("veuillez entrer les statistiques que vous voulez");
    printf("1.calculer la moyenne d'age des patients ayant reserve.\n ");
    printf("2.afficher le nombre de patients par tranche d'age. \n ");//(ex. : 0-18 ans, 19-35 ans, 36+ ans).
    printf("3.generer des statistiques pour connaitre le nombre total de reservations par statut. \n ");
    
    printf("veuillez entrer un choix :");
    scanf("%d", &choix);
    
    if(choix == 1){
        
    }
    
    else if(choix == 2){
        
    }
    
    else if(choix == 3){
        
    }
    
    else
       printf("ce choix n'existe pas !");
}

int main() {
    
    int choix;
    
    do{
    printf("\n******** GESTION DES RESERVATIONS ********\n");
    printf("1.Ajouter une reservation. \n");
    printf("2.Modifier ou supprimer une reservation. \n");
    printf("3.Afficher les details d'une reservation. \n");
    printf("4.Tri des reservations. \n");
    printf("5.Recherche des reservations. \n");
    printf("6.Statistiques. \n");
    printf("7.quitter. \n");
    printf("choisissez un choix : ");
    scanf("%d", &choix);
    
    switch (choix)
        {
        case 1:
            ajouter_une_reservation();
            break;
        case 2:
            modifier_ou_supprimer_une_reservation();
            break;
        case 3:
            afficher_les_details_dune_reservation();
            break;
        case 4:
            tri_des_reservations();
            break;
        case 5:
            recherche_des_reservations();
            break;
        case 6:
            statistiques();
            break;
        case 7:
          printf("vous avez quittez !");
          return 0;
        default:
            printf("ce choix n'existe pas !");
        }
    }
    while (choix != 7);




    return 0;
}