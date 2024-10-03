#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int choix,i,choix2,choix3,moyen,n,trouveS,trouveR,choix4,choix5;
int reference = 0;
int x = 0;
int conteur1=0;
int conteur2=0;
int conteur3=0;
int conteur4=0;


int somme=0;
char nomR[50];

typedef struct
{
    int jours;
    int mois;
    int annee;
} ate;


typedef struct
{
    char nom[50];
    char prenom[50];
    int telephone;
    int age;
    char statut[20];
    int reference;
    ate date;
} data;

typedef struct
{
    char nom[50];
    char prenom[50];
    int telephone;
    int age;
    ate date;
    char statut[20];
    int reference;
} data_modifie;

data p[100];

void saiser()
{
    printf("1-Ajouter une reservation\n");
    printf("2-Modifier ou supprimer une reservation\n");
    printf("3-Afficher les détails d'une reservation\n");
    printf("4-Tri des reservations\n");
    printf("5-Recherche des reservations\n");
    printf("6-Statistiques\n");
    printf("7-Quiter\n");
    printf("Choix nombre du menu : ");
    scanf("%d", &choix);
}

void reservation()
{
    if (x >= 100)
        {
            printf("Limite de réservations atteinte.\n");

        }

    printf("Entrer votre nom: ");
    scanf(" %[^\n]s",&p[x].nom);
    printf("Entrer votre prenom: ");
    scanf(" %[^\n]s",&p[x].prenom);
    printf("Entrer votre N de telephon: ");
    scanf("%d", &p[x].telephone);
    printf("Entrer votre age: ");
    scanf("%d", &p[x].age);
    printf("Entrer l'annee: ");
    scanf("%d", &p[x].date.annee);
    printf("Entrer le mois: ");
    scanf("%d", &p[x].date.mois);
    printf("Entrer le jour: ");
    scanf("%d", &p[x].date.jours);
    printf("Entrer le statu \n valide \n reporte \n annule \n traite\n==>: ");
    scanf(" %[^\n]s",&p[x].statut);

    p[x].reference = x + 1;
    x++;
}

void afficher()
{
    for (i = 0; i < x; i++)
        {
            printf("Votre nom: %s\n", p[i].nom);
            printf("Votre prenom: %s\n", p[i].prenom);
            printf("Votre N de telephon: %d\n", p[i].telephone);
            printf("Votre age est: %d\n", p[i].age);
            printf("Date de reservation: %d/%d/%d\n", p[i].date.jours, p[i].date.mois, p[i].date.annee);
            printf("Votre statut: %s \n",p[i].statut);
            printf("Reference: %d\n", p[i].reference);
        }
    if (!x)
        {
            printf("N'existe pas aucan resirvstion\n");
        }
}

void modifier()
{
    data_modifie dm;
    printf("Entrer votre reference : ");
    scanf("%d", &n);
    int trouveM = 0;

    for (i = 0; i < x; i++)
        {
            if (n == p[i].reference)
                {
                    printf("\n\tEst-ce que tu peux modifier\n");
                    printf("1-votre nom \n");
                    printf("2-votre prenom\n");
                    printf("3-votre N de telephon \n");
                    printf("4-votre age \n");
                    printf("5-la date de votre reservation \n");
                    printf("6-Statut \n");
                    printf("7-Quiter\n");
                    printf("Choix nombre du menu : ");
                    scanf("%d", &choix2);
                    trouveM = 1;

                    switch (choix2)
                        {
                        case 1:
                            printf("Votre dernier nom: %s\n", p[i].nom);
                            printf("Entrer la nouvelle nom: ");
                            scanf(" %[^\n]s",&dm.nom);
                            strcpy(p[i].nom,dm.nom);
                            printf("La reservation a ete modifier.\n");
                            break;
                        case 2:
                            printf("Votre dernier prenom: %s\n", p[i].prenom);
                            printf("Entrer la nouvelle prenom: ");
                            scanf(" %[^\n]s",&dm.prenom);
                            strcpy(p[i].prenom, dm.prenom);
                            printf("La reservation a ete modifier.\n");
                            break;
                        case 3:
                            printf("Votre dernier N tele: %d\n", p[i].telephone);
                            printf("Entrer la nouvelle N tele: ");
                            scanf("%d",&dm.telephone);
                            p[i].telephone = dm.telephone;
                            printf("La reservation a ete modifier.\n");
                            break;
                        case 4:
                            printf("Votre dernier age: %d\n", p[i].age);
                            printf("Entrer la nouvelle age: ");
                            scanf("%d",&dm.age);
                            p[i].age = dm.age;
                            printf("La reservation a ete modifier.\n");
                            break;
                        case 5:
                            printf("Votre dernier date: %d/%d/%d\n", p[i].date.jours, p[i].date.mois, p[i].date.annee);
                            printf("Entrer la nouvelle date:\n");
                            printf("L'anne: ");
                            scanf("%d", &dm.date.annee);
                            printf("Le mois: ");
                            scanf("%d", &dm.date.mois);
                            printf("Le jour: ");
                            scanf("%d", &dm.date.jours);
                            p[i].date = dm.date;
                            printf("La reservation a ete modifier.\n");
                            break;
                        case 6:
                            printf("Votre dernier statut est : %s\n", p[i].statut);
                            printf("Entrer votre statut: valide \n reporte \n annule \n traite\n==>");
                            scanf(" %[^\n]s",&dm.statut);
                            strcpy(p[i].statut, dm.statut);
                            printf("La reservation a ete modifier.\n");
                            break;
                        case 7:
                            printf("Good bye\n");
                            return;
                        default:
                            printf("Erreur\n");
                            break;
                        }
                    break;
                }
        }

    if (!trouveM)
        {
            printf("Reference non trouvee\n");
        }
}

void supreme()
{
    printf("Entrer votre reference : ");
    scanf("%d", &n);
    trouveS = 0;

    for (i=0; i<x; i++)
        {
            if(n==p[i].reference)
                printf("supej");
            trouveS=1;
            for(int j=0; j<x-1; j++)
                {
                    p[j]=p[j+1];
                }
            x--;
            printf("La reservation a ete supprime.\n");



        }
    if (!trouveS)
        {
            printf("Reference non trouvee\n");

        }
}
void rechercheR()
{
    printf("Entrer votre reference : ");
    scanf("%d", &n);
    trouveR = 0;
    for(i=0; i<x; i++)
        {
            if (p[i].reference==n)
                {
                    printf("Votre nom: %s\n", p[i].nom);
                    printf("Votre prenom: %s\n", p[i].prenom);
                    printf("Votre N de telephon: %d\n", p[i].telephone);
                    printf("Votre age : %d\n", p[i].age);
                    printf("Date de reservation: %d/%d/%d\n", p[i].date.jours, p[i].date.mois, p[i].date.annee);
                    printf("Votre statut: %s \n",p[i].statut);
                    printf("Reference: %d\n", p[i].reference);
                    trouveR=1;
                    break;
                }


        }
    if (!trouveR)
        {
            printf("Reference non trouvee\n");
        }


}
void rechercheN()
{
    printf("Entrer le nom : ");
    scanf("%s",nomR);
    trouveR = 0;
    for(i=0; i<x; i++)
        {
            if(strcmp(p[i].nom,nomR)==0)
                {
                    printf("Votre nom: %s\n", p[i].nom);
                    printf("Votre prenom: %s\n", p[i].prenom);
                    printf("Votre N de telephon: %d\n", p[i].telephone);
                    printf("Votre age : %d\n", p[i].age);
                    printf("Date de reservation: %d/%d/%d\n", p[i].date.jours, p[i].date.mois, p[i].date.annee);
                    printf("Votre statut: %s \n",p[i].statut);
                    printf("Reference: %d\n", p[i].reference);
                    trouveR=1;
                    break;
                }

        }
    if (!trouveR)
        {
            printf("Reference non trouvee\n");
        }

}

void nbrage()
{

}



int main()
{
    do
        {
            saiser();
            switch (choix)
                {
                case 1:
                    reservation();
                    break;
                case 2:
                    printf("1-modifier\n");
                    printf("2-supprimer \n");
                    printf("Choix nombre du menu : ");
                    scanf("%d", &choix3);
                    switch (choix3)
                        {
                        case 1:
                            modifier();
                            break;
                        case 2:
                            supreme();
                            break;
                        }
                    break;
                case 3:
                    afficher();
                    break;
                case 4:
                    printf("Fonction de tri non implémentée.\n");
                    break;
                case 5:
                    printf("1-Recherche par referenc.\n");
                    printf("2-Rrecherche par nome\n");
                    printf("Choix nombre du menu : ");
                    scanf("%d", &choix4);
                    switch (choix4)
                        {
                        case 1:
                            rechercheR();
                            break;
                        case 2:
                            rechercheN();
                            break;
                        default:
                            printf("Erreur,votre choix n'existe pas");
                            break;

                        }

                    break;
                case 6:
                    printf("1-la moyenne d'age des patients.\n");
                    printf("2-le nombre de patients par d'age.\n");
                    printf("3- le nombre total de reservations par statut.\n");
                    printf("Choix nombre du menu : ");
                    scanf("%d", &choix5);
                    switch (choix5)
                        {
                        case 1:
                            for(i=0; i<x; i++)
                                {
                                    somme+=p[i].age;
                                    conteur1++;

                                }
                            moyen=somme/x;

                            printf("la moyenne d'âge des patients ayant reserve est: %d ",moyen);
                            break;

                            for(i=0; i<x; i++)
                                {
                                    if(p[i].age>0 && p[i].age<=18)
                                        {
                                            conteur2++;;
                                        }



                                    else if(p[i].age>18 && p[i].age<=35)
                                        {
                                            conteur3++;
                                        }



                                    else
                                        {
                                            conteur4++;
                                        }


                                    printf("le nombre de patients par tranche entre l'age 0 et18 age est:%d",conteur2);
                                    printf("le nombre de patients par tranche ente l'age 19 et35 age est:%d",conteur3);
                                    printf("le nombre de patients par tranche d'age superieur a 36 age est:%d",conteur4);
                                    break;
                                case 3:
                                    printf("jfjfjf");


                                }



                            break;
                        case 7:
                            printf("Quitter le programme\n");
                            break;
                        default:
                            printf("Le numero choisi n'est pas valide\n");
                        }
                }
        }
    while (choix != 7);

    return 0;
}

