#include <stdio.h>
#include <string.h>

typedef struct
{
    int Numero;
    char Nom[20];
    char Prenom[20];
    char DateNaissance[11];
    char Departement[30];
    float Notegeneral;
} data;
data Etudiants[1000] ;
// {
//     {1, "tbibzat", "charaf", "01/01/2000", "Computer Science", 16.5},
//     {2, "smaki", "rayan", "02/02/1999", "Mathematics", 9.0},
//     {3, "alaoui", "moncef", "03/03/1998", "Computer Science", 17.0},
// };
// int count = sizeof(Etudiants) / sizeof(Etudiants[0]);

// data Etudiants[1000];
int count = 0;

int recherch_simpel(int Numero)
{
    for (int i = 0; i < count; i++)
    {
        if (Etudiants[i].Numero == Numero)
        {
            return i;
        }
    }
    return -1;
}
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

        // int found = 0;
        while (1)
        {
            printf("numero : ");
            scanf("%d", &Nnumber);
            int indexsearch = recherch_simpel(Nnumber);
            if (indexsearch != -1)
            {
                printf("le numero est deja existant\n");
            }
            else
            {
                break;
            }
        }
        Etudiants[count].Numero = Nnumber;
        printf("nom : ");
        scanf(" %s", Etudiants[count].Nom);
        printf("prenom : ");
        scanf(" %[^\n]s", Etudiants[count].Prenom);
        printf("date de naissance ,format (jj/mm/aaaa) : ");
        scanf(" %s", Etudiants[count].DateNaissance);
        printf("departement : ");
        scanf(" %[^\n]s", Etudiants[count].Departement);
        printf("note general : ");
        scanf(" %.2f", &Etudiants[count].Notegeneral);
        count++;
        printf("etudiant ajoute avec succes\n");
    }
    else if (choixajoute == 2)
    {
        int nbretudiants = 0;
        printf("----------------------------ajouter multiple etudiants----------------------------\n");
        printf("Combien d'Etudiants souhaitez-vous ajouter  : ");
        scanf("%d", &nbretudiants);
        for (int i = 0; i < nbretudiants; i++)
        {
            while (1)
            {
                printf("numero : ");
                scanf("%d", &Nnumber);
                int indexsearch = recherch_simpel(Nnumber);
                if (indexsearch != -1)
                {
                    printf("le numero est deja existant\n");
                }
                else
                {
                    break;
                }
            }

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
    int choixmodif = 0;
    printf("----------------------------modifier un etudiant----------------------------\n");
    printf("entrer le numero de l'etudiant a modifier : ");
    scanf("%d", &choixmodif);
    int choixmod = recherch_simpel(choixmodif);
    if (choixmod != -1)
    {
        printf("entrer le nouveau nom de l'etudiant : ");
        scanf(" %[^\n]s", Etudiants[choixmod].Nom);
        printf("entrer le nouveau prenom de l'etudiant : ");
        scanf(" %[^\n]s", Etudiants[choixmod].Prenom);
        printf("entrer la nouvelle date de naissance de l'etudiant ,format (jj/mm/aaaa) : ");
        scanf(" %[^\n]s", Etudiants[choixmod].DateNaissance);
        printf("entrer  le nouveau departement de l'etudiant : ");
        scanf(" %[^\n]s", Etudiants[choixmod].Departement);
        printf("entrer la nouvelle note de l'etudiant : ");
        scanf("%f", &Etudiants[choixmod].Notegeneral);
    }
}
void supprimer_etudiant()
{
    int choixsupprimer;

    printf("----------------------------supprimer un etudiant----------------------------\n");
    printf("entrer le numero de l'etudiant a supprimer : ");
    scanf("%d", &choixsupprimer);
    int choixsupp = recherch_simpel(choixsupprimer);
    if (choixsupp != -1)
    {
        int confirmation;
        printf("etes vous sur de supprimer cet etudiant ? (1 pour oui ,0 pour non) : ");
        scanf("%d", &confirmation);
        if (confirmation == 1)
        {
            for (int j = choixsupp; j < count - 1; j++)
            {
                Etudiants[j] = Etudiants[j + 1];
            }
            count--;
        }
        else
        {
            printf("suppression annulee\n");
            return;
        }
    }
    else
    {
        printf("l'etudiant n'existe pas\n");
    }
}
void Afficher_etudiant()
{
    int choixafficher;
    printf("----------------------------Afficher les etudiants----------------------------\n\n");
    printf("choisir une option pour afficher les etudiants\n");
    printf("1 : afficher tous les etudiants\n");
    printf("2 : afficher les etudiants par alphabetique \n");
    printf("3 : afficher les etudiants par  moyenne generale\n");
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
            printf("la note general est:%.2f\n\n", Etudiants[j].Notegeneral);
        }
        break;
    case 2:
        for (int i = 0; i < count - 1; i++)
        {
            int minindex = i;
            for (int j = i + 1; j < count; j++)
            {
                if (strcmp(Etudiants[minindex].Nom, Etudiants[j].Nom) > 0)
                {
                    minindex = j;
                }
            }
            data temp = Etudiants[i];
            Etudiants[i] = Etudiants[minindex];
            Etudiants[minindex] = temp;
        }
        for (int j = 0; j < count; j++)
        {
            printf("le nom est:%s\n", Etudiants[j].Nom);
            printf("le numero est:%d\n", Etudiants[j].Numero);
            printf("le prenom est:%s\n", Etudiants[j].Prenom);
            printf("la date de naissance est:%s\n", Etudiants[j].DateNaissance);
            printf("le departement est:%s\n", Etudiants[j].Departement);
            printf("la note general est:%.2f\n\n", Etudiants[j].Notegeneral);
        }
        break;
    case 3:
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = 0; j < count - i - 1; j++)
            {
                if (Etudiants[j].Notegeneral < Etudiants[j + 1].Notegeneral)
                {
                    data tp = Etudiants[j];
                    Etudiants[j] = Etudiants[j + 1];
                    Etudiants[j + 1] = tp;
                }
            }
        }
        for (int j = 0; j < count; j++)
        {
            if (Etudiants[j].Notegeneral >= 10)
            {
                printf("la note general est:%.2f\n", Etudiants[j].Notegeneral);
                printf("le numero est:%d\n", Etudiants[j].Numero);
                printf("le nom est:%s\n", Etudiants[j].Nom);
                printf("le prenom est:%s\n", Etudiants[j].Prenom);
                printf("la date de naissance est:%s\n", Etudiants[j].DateNaissance);
                printf("le departement est:%s\n\n", Etudiants[j].Departement);
            }
        }
        break;
    default:
        printf("choix invalide");
        break;
    }
}
void Calculer_moyenne_generale()
{

    double somme_notes_université = 0;
    int count_nombre_etudiant = 0;
    char departements[10][20];
    double somme_dept[10] = {0};
    int count_dept[10] = {0};
    int dept_count = 0;

    for (int i = 0; i < count; i++)
    {
        int dept_found = 0;
        for (int j = 0; j < dept_count; j++)
        {
            if (strcmp(Etudiants[i].Departement, departements[j]) == 0)
            {
                somme_dept[j] += Etudiants[i].Notegeneral;
                count_dept[j]++;
                dept_found = 1;
                break;
            }
        }

        if (!dept_found)
        {
            strcpy(departements[dept_count], Etudiants[i].Departement);
            somme_dept[dept_count] = Etudiants[i].Notegeneral;
            count_dept[dept_count] = 1;
            dept_count++;
        }
        somme_notes_université += Etudiants[i].Notegeneral;
        count_nombre_etudiant++;
    }

    printf("\nMoyenne générale de chaque département :\n");
    for (int i = 0; i < dept_count; i++)
    {
        printf("Département %s : %.2f\n", departements[i], somme_dept[i] / count_dept[i]);
    }

    if (count_nombre_etudiant > 0)
    {
        printf("Moyenne générale de l'université : %.2f\n", somme_notes_université / count_nombre_etudiant);
    }
    else
    {
        printf("Aucun étudiant pour calculer la moyenne.\n");
    }
}
void Statistiques()
{
    int choixstatiq;

    printf("1- Afficher le nombre total des etudiants inscrits\n");
    printf("2- Afficher le nombre des etudiants dans chaque departement\n");
    printf("3- Afficher les etudiants ayant une moyenne generale superieure a un certain seuil\n");
    printf("4- Afficher les 3 etudiants ayant la meilleure notes \n");
    printf("5- Afficher le nombre des etudiants ayant reussi dans chaque departement Note>=10 \n");
    printf("6- retour au menu principal\n");
    printf("choisir le type de statistique : ");
    scanf("%d", &choixstatiq);
    switch (choixstatiq)
    {
    case 1:
        if (count == 0)
        {
            printf("Aucun etudiant dans la liste.\n");
            return;
        }
        else
        {
            printf("le nombre total des etudiants inscrits est:%d\n", count);
        }
        break;
    case 2:
        // printf("le nombre des etudiants dans chaque departement\n");
        // char dep[50];
        // for(int i=0;i<count-1;i++){
        //     for(int j=i+1;j<count;j++){
        //         if(Etudiants[i].Departement==Etudiants[j].Departement){
        //             count++;
        //         }
        //     }
        // }
        // float totalScore = 0;
        // // Calculate the total score
        // for (int i = 0; i < count; i++)
        // {
        //     totalScore += Etudiants[i].Notegeneral;
        // }
        // // Calculate the average score
        // float moyenne = totalScore / count;
        // printf("La moyenne generale des etudiants est: %.2f\n", moyenne);
        break;
        break;
    case 3:
        printf("les etudiants ayant une moyenne generale superieure a un certain seuil\n");
        break;
    case 4:
        printf("les 3 etudiants ayant la meilleure notes\n");
        break;
    case 5:
        printf("le nombre des etudiants ayant reussi dans chaque departement Note>=10\n");
        break;
    case 6:
        return;
        break;
    default:
        printf("choix invalide\n");
        break;
    }
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
        char Sdepartement[20];
        printf("entrer le departement de l'etudiant que vous voulez rechercher\n");
        scanf("%s", &Sdepartement);
        for (int i = 0; i < count; i++)
        {
            if (strcmp(Etudiants[i].Departement, Sdepartement) == 0)
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
    else
    {
        printf("choix invalide\n\n");
    }
}

int main()
{   
    // Etudiants[0]=(data){1, "tbibzat", "charaf", "01/01/2000", "Computer Science", 16.5};
    // Etudiants[1]=(data){2, "smaki", "rayan", "02/02/1999", "Mathematics", 9.0};
    // Etudiants[2]=(data){3, "alaoui", "moncef", "03/03/1998", "Computer Science", 17.0};
    
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
            Modifier_etudiant();
            break;
        case 3:
            supprimer_etudiant();
            break;

        case 4:
            Afficher_etudiant();
            break;

        case 5:
            Calculer_moyenne_generale();
            break;

        case 6:
            Statistiques();
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