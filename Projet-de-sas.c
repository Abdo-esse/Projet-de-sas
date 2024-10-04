#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Les variables que j'ai etuluse.
int choix,i,choix2,choix3,moyen,n,trouveS,trouveR,choix4,choix5;
//Les choix 1,2,3,4et 5 pour les menue switch.
//n pur la recherche.


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
} data;//My variable data ,
data p[100];
void Data_PARDEFAULT()//10 reservation default.
{

    const char noms[10][20] = {"Abdel ilhah", "Sara", "Omar", "Moad", "Samir", "Hajar", "Khalid", "Marwa", "Amine", "Amina"};
    const char prenoms[10][20] = {"ESSEMLALI", "HAJAWI", "CHBILI", "SAIDI", "ESSEMALI", "BOTAHRI", "ESSEMALI", "EL IDEISI", "ALIOU", "karoumi"};
    const int telephones[10] = {688062883, 733216576, 702030405, 662378945, 668094343, 612565609, 654654654, 787987987,654679874,699067732};
    const int ages[10] = {5, 30, 22, 28, 50, 14, 40, 8, 32,16};
    const char statuts[10][10] = {"valide", "reporte", "annule", "traite", "valide", "reporte", "valide", "annule", "traite", "valide"};
    const int jours[10] = {10, 15, 20, 5, 8, 12, 30, 1, 28, 19};
    const int mois[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int annees[10] = {2024, 20241, 2021, 2020, 2024, 2022, 2024, 2023, 2023, 2024};

    for (int j = 0; j < 10; j++)
        {
            strcpy(p[j].nom, noms[j]);
            strcpy(p[j].prenom, prenoms[j]);
            p[j].telephone = telephones[j];
            p[j].age = ages[j];
            p[j].date.jours = jours[j];
            p[j].date.mois = mois[j];
            p[j].date.annee = annees[j];
            strcpy(p[j].statut, statuts[j]);
            p[j].reference = j + 1;
            x++;
        }
}

void saiser()
{
    printf("=====================================================\n");
    printf("1-Ajouter une reservation\n");
    printf("2-Modifier ou supprimer une reservation\n");
    printf("3-Afficher les détails d'une reservation\n");
    printf("4-Tri des reservations\n");
    printf("5-Recherche des reservations\n");
    printf("6-Statistiques\n");
    printf("7-Quiter\n");
    printf("Choix nombre du menu : ");
    scanf("%d", &choix);
    printf("=====================================================\n");
}

void reservation()
{
    if (x >= 100)
        {
            printf("Limite de réservations atteinte.\n");

        }
    printf("=====================================================\n");
    printf("\t Veuillez remplire les information suivant\n");
    printf("Entrer votre nom: ");
    scanf(" %[^\n]s",&p[x].nom);
    printf("Entrer votre prenom: ");
    scanf(" %[^\n]s",&p[x].prenom);
    printf("Entrer votre N de telephon(212): ");
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
    printf("=====================================================\n");

    p[x].reference = x + 1;
    x++;
}

void afficher()
{
    for (i = 0; i < x; i++)
        {
            printf("\n----------------------------------------------\n\n");
            printf("Votre nom: %s\n", p[i].nom);
            printf("Votre prenom: %s\n", p[i].prenom);
            printf("Votre N de telephon(212): %d\n", p[i].telephone);
            printf("Votre age est: %d\n", p[i].age);
            printf("Date de reservation: %d/%d/%d\n", p[i].date.jours, p[i].date.mois, p[i].date.annee);
            printf("Votre statut: %s \n",p[i].statut);
            printf("Reference: %d\n", p[i].reference);
            printf("\n----------------------------------------------\n\n");
        }
    if (!x)
        {
            printf("N'existe pas aucan resirvstion\n");
        }
}

void modifier()//fonction de modification.
{

    printf("Entrer votre reference : ");
    scanf("%d", &n);
    int trouveM = 0;

    for (i = 0; i < x; i++)
        {
            if (n == p[i].reference)
                {
                    //la menu de modification posible.
                    printf("=====================================================\n");
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
                    printf("=====================================================\n");
                    trouveM = 1;

                    switch (choix2)
                        {
                        case 1://modification de nom.
                            printf("=====================================================\n");
                            printf("Votre dernier nom: %s\n", p[i].nom);
                            printf("Entrer la nouvelle nom: ");
                            scanf(" %[^\n]s",&p[i].nom);
                            printf("La reservation a ete modifier.\n");
                            printf("=====================================================\n");
                            break;
                        case 2://modification de prenom.
                            printf("=====================================================\n");
                            printf("Votre dernier prenom: %s\n", p[i].prenom);
                            printf("Entrer la nouvelle prenom: ");
                            scanf(" %[^\n]s",&p[i].prenom);
                            printf("La reservation a ete modifier.\n");
                            printf("=====================================================\n");
                            break;
                        case 3://modification de N tele
                            printf("=====================================================\n");
                            printf("Votre dernier N tele(212): %d\n", p[i].telephone);
                            printf("Entrer la nouvelle N tele(212): ");
                            scanf("%d",&p[i].telephone);
                            printf("La reservation a ete modifier.\n");
                            printf("=====================================================\n");
                            break;
                        case 4://modification de l'age
                            printf("=====================================================\n");
                            printf("Votre dernier age: %d\n", p[i].age);
                            printf("Entrer la nouvelle age: ");
                            scanf("%d",&p[i].age);
                            printf("La reservation a ete modifier.\n");
                            printf("=====================================================\n");
                            break;
                        case 5://modification de a date
                            printf("=====================================================\n");
                            printf("Votre dernier date: %d/%d/%d\n", p[i].date.jours, p[i].date.mois, p[i].date.annee);
                            printf("Entrer la nouvelle date:\n");
                            printf("L'anne: ");
                            scanf("%d", &p[i].date.annee);
                            printf("Le mois: ");
                            scanf("%d", &p[i].date.mois);
                            printf("Le jour: ");
                            scanf("%d", &p[i].date.jours);
                            printf("La reservation a ete modifier.\n");
                            printf("=====================================================\n");
                            break;
                        case 6://modification de statut.
                            printf("=====================================================\n");
                            printf("Votre dernier statut est : %s\n", p[i].statut);
                            printf("Entrer votre statut: valide \n reporte \n annule \n traite\n==>");
                            scanf(" %[^\n]s",&p[i].statut);
                            printf("La reservation a ete modifier.\n");
                            printf("=====================================================\n");
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

void supreme()//fonction de suprtion.
{
    printf("=====================================================\n");
    printf("Entrer votre reference : ");
    scanf("%d", &n);
    trouveS = 0;

    for (i=0; i<x; i++)
        {
            if(n==p[i].reference)
                {

                    trouveS=1;
                    for(int j=0; j<x-1; j++)
                        {
                            p[j]=p[j+1];
                        }
                    x--;
                    printf("La reservation a ete supprime.\n");
                    printf("=====================================================\n");
                }
        }

    if (!trouveS)
        {
            printf("Reference non trouvee\n");

        }
}
void rechercheR()//la fonction de recherche per reference
{
    printf("=====================================================\n");
    printf("Entrer votre reference : ");
    scanf("%d", &n);
    trouveR = 0;
    for(i=0; i<x; i++)
        {
            if (p[i].reference==n)
                {
                    printf("------------------------------------------------\n");
                    printf("Votre nom: %s\n", p[i].nom);
                    printf("Votre prenom: %s\n", p[i].prenom);
                    printf("Votre N de telephon(212): %d\n", p[i].telephone);
                    printf("Votre age : %d\n", p[i].age);
                    printf("Date de reservation: %d/%d/%d\n", p[i].date.jours, p[i].date.mois, p[i].date.annee);
                    printf("Votre statut: %s \n",p[i].statut);
                    printf("Reference: %d\n", p[i].reference);
                    trouveR=1;
                    printf("----------------------------------------------------\n");
                    break;
                }


        }
    if (!trouveR)
        {
            printf("Reference non trouvee\n");
        }


}
void rechercheN()//La fonction de recherch par nom
{
    printf("=====================================================\n");
    printf("Entrer le nom : ");
    scanf("%s",nomR);
    trouveR = 0;
    for(i=0; i<x; i++)
        {
            if(strcmp(p[i].nom,nomR)==0)
                {
                    printf("=====================================================\n");
                    printf("Votre nom: %s\n", p[i].nom);
                    printf("Votre prenom: %s\n", p[i].prenom);
                    printf("Votre N de telephon(212): %d\n", p[i].telephone);
                    printf("Votre age : %d\n", p[i].age);
                    printf("Date de reservation: %d/%d/%d\n", p[i].date.jours, p[i].date.mois, p[i].date.annee);
                    printf("Votre statut: %s \n",p[i].statut);
                    printf("Reference: %d\n", p[i].reference);
                    trouveR=1;
                    printf("=====================================================\n");
                    break;
                }

        }
    if (!trouveR)
        {
            printf("Reference non trouvee\n");
        }

}

int main()
{
    Data_PARDEFAULT();
    printf("\t Bien venu dans notre programme de gestion de reservation\n\n");

    do
        {
            saiser();
            switch (choix)
                {
                case 1:
                    reservation();
                    break;
                case 2:
                    printf("----------------------\n");
                    printf("1-modifier\n");
                    printf("2-supprimer \n");
                    printf("Choix nombre du menu : ");
                    scanf("%d", &choix3);
                    printf("--------------------------\n");
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
                    printf("---------------------------\n");
                    printf("1-Recherche par referenc.\n");
                    printf("2-Rrecherche par nome\n");
                    printf("Choix nombre du menu : ");
                    scanf("%d", &choix4);
                    printf("---------------------------\n");
                    switch (choix4)
                        {
                        case 1:
                            rechercheR();
                            break;
                        case 2:
                            rechercheN();
                            break;
                        default:
                            printf("Erreur,votre choix n'existe pas .\n");
                            break;
                        }
                    break;
                case 6:
                    printf("-----------------------------------\n");
                    printf("1-la moyenne d'age des patients.\n");
                    printf("2-le nombre de patients par d'age.\n");
                    printf("3- le nombre total de reservations par statut.\n");
                    printf("Choix nombre du menu : ");
                    scanf("%d", &choix5);
                    printf("-----------------------------------\n");
                    switch (choix5)
                        {
                        case 1:
                            for(i=0; i<x; i++)
                                {
                                    somme+=p[i].age;
                                    conteur1++;
                                }
                            moyen=somme/x;
                            printf("--------------------------------------------------------------\n");
                            printf("la moyenne d'âge des patients ayant reserve est: %d  \n",moyen);
                            break;
                        case 2:
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
                                }
                            printf("----------------------------------------------------------------------------\n");
                            printf("le nombre de patients par tranche entre l'age 0 et18 age est:%d\n",conteur2);
                            printf("-----------------------------------------------------------------------------\n");
                            printf("le nombre de patients par tranche ente l'age 19 et35 age est:%d\n",conteur3);
                            printf("-----------------------------------------------------------------------------\n");
                            printf("le nombre de patients par tranche d'age superieur a 36 age est:%d\n",conteur4);
                            break;
                        case 3:
                            printf("Erreur,votre choix n'existe pas \n");
                            break;
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

