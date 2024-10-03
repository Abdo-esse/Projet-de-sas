#include <stdio.h>
#include <stdlib.h>
#include<string.h>


int choix,i;
 int reference=0;
 int x=10;
typedef struct{
    int jours ;
    int mois;
    int annee;

}ate;
typedef struct{
   char nom[50];
   char prenom[50];
   int telephone;
   int age;
   char statut[20];
   int reference;
   ate date;

}data;
data p[100];
void saiser(){
        printf("1-Ajouter une reservation\n");
        printf("2-Modifier ou supprimer une reservation\n");
        printf("3-Afficher les détails d'une reservation \n");
        printf("4-Tri des reservations \n");
        printf("5-Recherche des reservations\n");
        printf("6-Statistiques\n");
        printf("7-Quiter\n");
        printf("Choix nombre du menu :");
        scanf("%d",&choix);
}
void reservation(){
    for( i=0;i<100;i++){
    printf("Entrer votre nom: ");
    scanf(" %[^\n]s",&p[i].nom);
    printf("Entrer votre prenom: ");
    scanf(" %[^\n]s",&p[i].prenom);
    printf("Entrer votre N de telephon: ");
    scanf(" %d",&p[i].telephone);
    x++;
    printf("Entrer la date : ");
    printf("Entrer l'anne: ");
    scanf(" %d",&p[i].date.annee);
    printf("Entrer le mois: ");
    scanf(" %d",&p[i].date.mois);
    printf("Entrer le jour: ");
    scanf(" %d",&p[i].date.jours);
    break;
    }
}

void afficher(){
    for( i=0;i<100;i++){
    printf(" votre nom:%s \n",p[i].nom);
    printf(" votre prenom: %s\n",p[i].prenom);
    printf(" votre N de telephon: %d\n",p[i].telephone);
    printf(" la date de votre reservation : ");
    printf(" %d \\ %d \\ %d \n",p[i].date.jours,p[i].date.mois,p[i].date.annee);
    printf(" le reference :%d \n",x);
    break;
    }
}


int main(){
    do{
        saiser();
        switch (choix){
        case 1:
            reservation();
            break;
        case 2:
            printf("en cour de modiffier");
            break;
        case 3:
            afficher();
            break;
        case 4:
            printf("en cour de modiffier");
            break;
        case 5:
            printf("en cour de modiffier");
            break;
        case 6:
            printf("en cour de modiffier");
            break;
       case 7:
                printf("Quitter le programme\n");
                break;
       default:
                printf("Le numero choisi n'est pas valide \n");


        }
    }while(choix != 7);



    return 0;
}
