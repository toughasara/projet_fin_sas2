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

struct reservation reservations[200];
int numrese = 0;
int found = 0;
int ref;
int i;

void ajouter_une_reservation(){
    printf("*******AJOUTER UNE RESERVATION*******\n");
    if(numrese < 200) {
    printf("entrez le nom : ");
    scanf("%s", &reservations[numrese].nom);
    
    printf("entrez le prenom : ");
    scanf("%s", &reservations[numrese].prenom);
    
    printf("entrez le numero de telephone : ");
    scanf("%s", &reservations[numrese].telephone);
    
    printf("entrez l'age : ");
    scanf("%d", &reservations[numrese].age);
    
    printf("entrez le statut . ");
    printf("1-valide .");
    printf("2-reporte .");
    printf("3-annule .");
    printf("4-traite .");
    
    printf("veulliez entrer un choix de statut :");
    scanf("%s", &reservations[numrese].statut);
    
    printf("entrez la date de reservation. ");
    printf("le jour : ");
    scanf("%s", &reservations[numrese].dates.jour);
    printf("le mois : ");
    scanf("%s", &reservations[numrese].dates.mois);
    printf("l'annee : ");
    scanf("%s", &reservations[numrese].dates.annee);
    
    for(i = 11; i < numrese ; i++){
            printf("la reference : %d",i);
    }
    
    numrese++;
    }

void modifier_ou_supprimer_une_reservation()
{
    printf("*******MODIFIER OU SUPPRIMER UNE RESERVATION*******\n");
    
    int choix;
    
    printf("1.modifer une reservation . ");
    printf("2.supprimer une reservation . ");
    
    printf("veuillez entrer un choix :");
    scanf("%d", choix);
    
    if(choix == 1){
        printf("veuillez entrer la reference de reservation que vous vouler modifier :")
        scanf("%d", &ref);
        
        for (i = 0; i < numrese ; i++){
            if(ref == reservations[i].refernce){
                found++;
                break;
            }
        }
        
        if(found == 0)
           printf("Cette reference n'existe pas");
        else{
           printf("que ce que vous voulez modifier ?")
           printf("1.nom. \n");
           printf("2.prenom. \n");
           printf("3.telephone. \n");
           printf("4.age. \n");
           printf("5.statut. \n");
           printf("6.reference. \n");
           printf("7.date de reservation. \n");
           
           printf("veuillez entrer un choix :");
           scanf("%d", choix);
           
           switch (choix)
           {
           case 1:
                printf("entrer le nom a ajouté: ");
                scanf("%s", &referenses[i].nom);
                printf("le nom à été mis-à-jouré\n");
                break;
              
           case 2:
                printf("entrer le prenom a ajouté: ");
                scanf("%s", &referenses[i].prenom);
                printf("le prenom à été mis-à-jouré\n");
                break;
              
          case 3:
                printf("entrer le telephone a ajouté: ");
                scanf("%s", &referenses[i].telephone);
                printf("le telephone à été mis-à-jouré\n");
                break;
                
          case 4:
                printf("entrer l'age a ajouté: ");
                scanf("%s", &referenses[i].age);
                printf("l'age à été mis-à-jouré\n");
                break;
          case 5:
            recherche_des_reservations();
              break;
          case 6:
            statistiques();
              break;
          case 7:
          printf("vous avez quittez !");
             break;
        default:
            printf("ce choix n'existe pas !");
        }
        }
        
           
    }
    else if(choix == 2){
        
    }
    
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