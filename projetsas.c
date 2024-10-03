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
int i;

void recherche(){
    for (i = 0; i < numrese ; i++){
        if(strcmp(nomm, reservation[i].nom) == 0){
                found++;
                break;
             }
    }
}

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
    
    for(i = 001; i < numrese ; i++){
            printf("la reference : %d",i);
    }
    
    numrese++;
    }

void modifier_ou_supprimer_une_reservation()
{
    printf("*******MODIFIER OU SUPPRIMER UNE RESERVATION*******\n");
    
    int choix;
    char nomm[50];
    
    printf("1.modifer une reservation . ");
    printf("2.supprimer une reservation . ");
    
    printf("veuillez entrer un choix :")
    scanf("%d", choix);
    
    if(choix == 1){
        printf("veuillez entrer la reservation que vous vouler modifier :")
        scanf("%s", nomm);
        
        recherche();
        
        if(found == 0)
           printf("Ce livre n'existe pas");
        else
           printf("entrer le nom a ajouté: ");
           scanf("%d", &reservation[i].nom);
           printf("le nom à été mis-à-jouré\n");
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