#include <stdio.h>
#include <string.h>

typedef struct
{
    int Numero;
    char Nom[20];
    char Prenom[20];
    char DateNaissance[11];
    char Departement[30];
    // int nbrModule;
    // float Notes[10];
    float Notegeneral;
} data;
// int maxetudiant=1000;
data Etudiants[1000];
int count = 0;
// float Calcule_note_ganeral(int nbrModule,float Notes[] ){
//     float somme =0;
//     for (int i = 0; i < nbrModule; i++)
//     {
//         somme += Notes[i];
//     }
//     float moyen= somme/nbrModule;
//     return moyen;
// }
void Ajouter_etudiant()
{
    int choixajoute = 0;
    int Nnumber;
    printf(">>>-----------entre la methode d'ajout--------------<<<\n");
    printf("1-ajouter etudiant\n2-ajouter multiple etudiants\n3-retour au menu principal\n ");
    scanf("%d", &choixajoute);

    if (choixajoute == 1)
    {
        printf("----------------------------ajouter etudiant----------------------------\n");
        printf("numero : ");
        scanf("%d", &Nnumber);
        int found = 0;
        for (int i = 0; i < count; i++)
        {
            if (Nnumber == Etudiants[i].Numero)
            {
                printf("le numero est deja existant\n");
                found = 1;
                return;
            }
        }
        if (!found)
        {

            Etudiants[count].Numero = Nnumber;
            printf("nom : ");
            scanf(" %s", Etudiants[count].Nom);
            printf("prenom : ");
            scanf(" %s", Etudiants[count].Prenom);
            printf("date de naissance ,format (jj/mm/aaaa) : ");
            scanf(" %s", Etudiants[count].DateNaissance);
            printf("departement : ");
            scanf(" %s", Etudiants[count].Departement);
            printf("note general : ");
            scanf("%f", &Etudiants[count].Notegeneral);
            count++;
            printf("etudiant ajoute avec succes\n");
            // printf("number de module : ");
            // scanf("%d",&Etudiants[count].nbrModule);
            // for(int i=0;i <Etudiants[count].nbrModule;i++){
            //     printf("note de module: ",i+1);
            //     scanf("%f",&Etudiants[count].Notes[i]);
            // }
        }
    }
    else if (choixajoute == 2)
    {
        int nbretudiants = 0;
        printf("----------------------------ajouter multiple etudiants----------------------------\n");
        printf("Combien d'Etudiants souhaitez-vous ajouter  : ");
        scanf("%d", &nbretudiants);
        for (int i = 0; i < nbretudiants; i++)
        {
            printf("numero : ");
            scanf("%d", &Nnumber);
            int found = 0;
            for (int j = 0; j < count; j++)
            {
                if (Nnumber == Etudiants[j].Numero)
                {
                    printf("le numero est deja existant\n");
                    found = 1;
                    return;
                }
            }
            if (!found)
            {

                Etudiants[count].Numero = Nnumber;
                printf("nom : ");
                scanf(" %[^\n]s", Etudiants[count].Nom);
                printf("prenom : ");
                scanf(" %[^\n]s", Etudiants[count].Prenom);
                printf("date de naissance ,format (jj/mm/aaaa) : ");
                scanf(" %[^\n]s", Etudiants[count].DateNaissance);
                printf("departement : ");
                scanf(" %[^\n]s", Etudiants[count].Departement);
                printf("note general : ");
                scanf("%f", &Etudiants[count].Notegeneral);
                count++;
                printf("etudiant ajoute avec succes\n");
            }
        }
    }
    else if (choixajoute == 3)
    {
        return;
    }
    else
    {
        printf("choix invalide\n");
    }
}
void Modifier_etudiant()
{
}
void supprimer_etudiant()
{
}
void Afficher_etudiant()
{
    int choixafficher;
    printf("----------------------------Afficher les etudiants----------------------------\n\n");
    printf("choisir une option pour afficher les etudiants\n");
    printf("1 : afficher tous les etudiants\n");
    // printf("2 : afficher les etudiants par alphabetique \n");
    printf("2 : afficher les etudiants par  moyenne generale\n");
    scanf("%d", &choixafficher);
    switch (choixafficher)
    {
    case 1:
        for (int j = 0; j < count; j++)
        {
            printf("le numero est:%d\n", Etudiants[j].Numero);
            printf("le nom est:%s\n", Etudiants[j].Nom);
            printf("le prenom est:%s\n", Etudiants[j].Prenom);
            printf("la date de naissance est:%s\n", Etudiants[j].DateNaissance);
            printf("le departement est:%s\n", Etudiants[j].Departement);
            printf("la note general est:%f\n\n", Etudiants[j].Notegeneral);
        }
        break;
    case 2:
        //    for(int i=0;i<count-1;i++){
        //     for(int j=i+1;j<count -i-1;j++){
        //         if(){

        //         }
        //     }
        //    }
        break;
    }
}
void Calculer_moyenne_generale()
{
}
void Statistiques()
{
}
void Rechercher_etudiant()
{
    char Snom[50];
    int choixsearch;
    printf("----------------------------Rechercher les etudiants----------------------------\n\n");
    printf("choisir une option pour rechercher les etudiants\n");
    printf("1 : rechercher les etudiants par nom\n");
    printf("2 : rechercher les etudiants par departement\n");
    scanf("%d", &choixsearch);
    if (choixsearch == 1)
    {
        printf("entrer le nom de l'etudiant que vous voulez rechercher\n");
        scanf("%s", &Snom);
        for (int i = 0; i < count; i++)
        {
            if (strcmp(Etudiants[i].Nom, Snom) == 0)
            {
                printf("le numero est:%d\n", Etudiants[i].Numero);
                printf("le nom est:%s\n", Etudiants[i].Nom);
                printf("le prenom est:%s\n", Etudiants[i].Prenom);
                printf("la date de naissance est:%s\n", Etudiants[i].DateNaissance);
                printf("le departement est:%s\n", Etudiants[i].Departement);
                printf("la note general est:%f\n\n", Etudiants[i].Notegeneral);
            }
        }
    }
    else if (choixsearch == 2)
    {
        printf("mooooooooooooyeeeeeeeeeeeen");
    }
    else
    {
        printf("le nom n'existe pas\n");
    }
}

int main()
{
    int choix = 0;
    while (choix <= 8)
    {
        printf(">>>>>>-----------------------------------------------------------------------<<<<<<<<<<\n");
        printf("\t\t system Gestion des Etudiants dans une universite \n");
        printf(">>>>>>-----------------------------------------------------------------------<<<<<<<<\n\n");

        printf("1-Ajouter_etudiant\n");
        printf("2-Modifier_etudiant\n");
        printf("3-supprimer_etudiant\n");
        printf("4-Afficher_etudiant\n");
        printf("5-Calculer_moyenne_generale\n");
        printf("6-Statistiques\n");
        printf("7-Rechercher_etudiant\n");
        printf("8-Quitter\n\n");
        printf("Donner votre choix : \n");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            Ajouter_etudiant();
            break;
        case 2:
            break;
        case 3:
            printf("system Gestion des étudiants dans une université");
            break;

        case 4:
            Afficher_etudiant();
            break;

        case 5:
            printf("system Gestion des étudiants dans une université");
            break;

        case 6:
            printf("system Gestion des étudiants dans une université");
            break;
        case 7:
            Rechercher_etudiant();
            break;
        case 8:
            return 0;
            break;
        default:
            printf(" Choix invalide \n\n");
            break;
        }
    }
    return 0;
}