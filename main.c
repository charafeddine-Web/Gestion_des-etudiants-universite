#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int Numero;
    char Nom[20];
    char Prenom[20];
    char DateNaissance[11];
    char Departement[50];
    float Notegeneral;
} data;
data Etudiants[1000];
int count = 5;

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
    int choixajoute;
    int Nnumber;
    printf(">>>-----------entre la methode d'ajout--------------<<<\n");
    printf("1-ajouter  etudiant\n2-retour au menu principal\n ");
    scanf("%d", &choixajoute);
     if (choixajoute == 1)
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
    else if (choixajoute == 2)
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
void Afficher_etudiant() {
    int choixafficher;
    printf("----------------------------Afficher les etudiants----------------------------\n\n");
    printf("Choisir une option pour afficher les etudiants\n");
    printf("1 : Afficher tous les etudiants\n");
    printf("2 : Afficher les etudiants par ordre alphabetique\n");
    printf("3 : Afficher les etudiants par moyenne generale\n");
    printf("4 : Afficher les etudiants ayant une moyenne >= 10/20\n");

    scanf("%d", &choixafficher);
    switch (choixafficher) {
    case 1:
        // Affichage de tous les etudiants
        for (int j = 0; j < count; j++) {
            printf("Numero : %d\n",Etudiants[j].Numero);
            printf("Nom : %s\n", Etudiants[j].Nom);
            printf("Prenom : %s\n", Etudiants[j].Prenom);
            printf("Date de naissance : %s\n", Etudiants[j].DateNaissance);
            printf("Departement : %s\n", Etudiants[j].Departement);
            printf("Note generale : %.2f\n\n", Etudiants[j].Notegeneral);
        }
        break;

    case 2:
        // Affichage des etudiants par ordre alphabetique
        printf("----------------------------Afficher les etudiants par ordre alphabetique----------------------------\n\n");
        int choixalpha;
        printf("1 - Ordre croissant (A a Z)\n");
        printf("2 - Ordre decroissant (Z a A)\n");
        printf("Entrer la methode : ");
        scanf("%d", &choixalpha);
        
        // Tri par ordre alphabetique
        if (choixalpha == 1) {
            // Tri croissant
            for (int i = 0; i < count - 1; i++) {
                for (int j = i + 1; j < count; j++) {
                    if (strcmp(Etudiants[i].Nom, Etudiants[j].Nom) > 0) {
                        data temp = Etudiants[i];
                        Etudiants[i] = Etudiants[j];
                        Etudiants[j] = temp;
                    }
                }
            }
        } else if (choixalpha == 2) {
            // Tri decroissant
            for (int i = 0; i < count - 1; i++) {
                for (int j = i + 1; j < count; j++) {
                    if (strcmp(Etudiants[i].Nom, Etudiants[j].Nom) < 0) {
                        data temp = Etudiants[i];
                        Etudiants[i] = Etudiants[j];
                        Etudiants[j] = temp;
                    }
                }
            }
        } else {
            printf("Choix invalide\n");
            break;
        }
        // Affichage apres tri
        for (int j = 0; j < count; j++) {
            printf("Nom : %s\n", Etudiants[j].Nom);
            printf("Numero : %d\n", Etudiants[j].Numero);
            printf("Prenom : %s\n", Etudiants[j].Prenom);
            printf("Date de naissance : %s\n", Etudiants[j].DateNaissance);
            printf("Departement : %s\n", Etudiants[j].Departement);
            printf("Note generale : %.2f\n\n", Etudiants[j].Notegeneral);
        }
        break;

    case 3:
        // Affichage des etudiants par moyenne generale
        printf("----------------------------Afficher les etudiants par moyenne generale----------------------------\n\n");
        int choixmoyen;
        printf("1 - De la note la plus elevee a la plus basse\n");
        printf("2 - De la note la plus basse a la plus elevee\n");
        printf("Entrer la methode : ");
        scanf("%d", &choixmoyen);

        // Tri par moyenne generale
        if (choixmoyen == 1) {
            // Tri decroissant
            for (int i = 0; i < count - 1; i++) {
                for (int j = 0; j < count - i - 1; j++) {
                    if (Etudiants[j].Notegeneral < Etudiants[j + 1].Notegeneral) {
                        data temp = Etudiants[j];
                        Etudiants[j] = Etudiants[j + 1];
                        Etudiants[j + 1] = temp;
                    }
                }
            }
        } else if (choixmoyen == 2) {
            // Tri croissant
            for (int i = 0; i < count - 1; i++) {
                for (int j = 0; j < count - i - 1; j++) {
                    if (Etudiants[j].Notegeneral > Etudiants[j + 1].Notegeneral) {
                        data temp = Etudiants[j];
                        Etudiants[j] = Etudiants[j + 1];
                        Etudiants[j + 1] = temp;
                    }
                }
            }
        } else {
            printf("Choix invalide\n");
            break;
        }
        // Affichage apres tri
        for (int j = 0; j < count; j++) {
            printf("Note generale : %.2f\n", Etudiants[j].Notegeneral);
            printf("Numero : %d\n",Etudiants[j].Numero);
            printf("Nom : %s\n", Etudiants[j].Nom);
            printf("Prenom : %s\n", Etudiants[j].Prenom);
            printf("Date de naissance : %s\n", Etudiants[j].DateNaissance);
            printf("Departement : %s\n\n", Etudiants[j].Departement);
        }
        break;

    case 4:
        // Affichage des etudiants ayant une moyenne >= 10
        printf("----------------------------Afficher les etudiants ayant une moyenne >= 10----------------------------\n\n");
        for (int j = 0; j < count; j++) {
            if (Etudiants[j].Notegeneral >= 10) {
                printf("Note generale : %.2f\n",Etudiants[j].Notegeneral);
                printf("Numero : %d\n", Etudiants[j].Numero);
                printf("Nom : %s\n", Etudiants[j].Nom);
                printf("Prenom : %s\n", Etudiants[j].Prenom);
                printf("Date de naissance : %s\n", Etudiants[j].DateNaissance);
                printf("Departement : %s\n\n", Etudiants[j].Departement);
            }
        }
        break;

    default:
        printf("Choix invalide\n");
        break;
    }
}
void Calculer_moyenne_generale()
{
    double somme_notes_universit = 0;
    int count_nombre_etudiant = 0;
    char departements[10][20];   // Tableau pour stocker les noms des departements
    double somme_dept[10] = {0}; // somme des notes pour chaque departement
    int count_dept[10] = {0};    // le nombre d'etudiants dans chaque departement
    int dept_count = 0;          // Compteur pour le nombre de departements uniques

    // Boucle pour parcourir tous les etudiants
    for (int i = 0; i < count; i++)
    {
        int dept_found = 0;
        // Boucle pour rechercher dans les departements connus
        for (int j = 0; j < dept_count; j++)
        {
            // Verifier si le departement de l'etudiant correspond à un departement dejà enregistre
            if (strcmp(Etudiants[i].Departement, departements[j]) == 0)
            {
                somme_dept[j] += Etudiants[i].Notegeneral;
                count_dept[j]++; // Augmenter le nombre d'etudiants dans ce departement
                dept_found = 1;  // Marquer le departement comme trouve
                break;           
            }
        }

        // Si le departement n'a pas ete trouve dans les departements connus
        if (!dept_found)
        {
            strcpy(departements[dept_count], Etudiants[i].Departement);
            // Initialiser la somme des notes pour ce nouveau departement
            somme_dept[dept_count] = Etudiants[i].Notegeneral;
            // Initialiser le nombre d'etudiants pour ce nouveau departement
            count_dept[dept_count] = 1;
            // Augmenter le compteur des departements
            dept_count++;
        }
        somme_notes_universit += Etudiants[i].Notegeneral;
        count_nombre_etudiant++;
    }

    // Afficher la moyenne des notes pour chaque departement
    printf("\nMoyenne generale de chaque departement :\n");
    for (int i = 0; i < dept_count; i++)
    {
        printf("Departement %s : %.2f\n", departements[i], somme_dept[i] / count_dept[i]);
    }

    if (count_nombre_etudiant > 0)
    {
        // Afficher la moyenne generale des notes pour tous les etudiants
        printf("Moyenne generale de l'universite : %.2f\n", somme_notes_universit / count_nombre_etudiant);
    }
    else
    {
        printf("Aucun etudiant pour calculer la moyenne.\n");
    }
}
void tri_par_notes(data etudiants[], int n)
{
    // data temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (etudiants[i].Notegeneral < etudiants[j].Notegeneral)
            {
                data temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    }
}
void Statistiques()
{
    int choixstatiq;
    float seuil = 0;
    char departements[50];
    int nombre_reussite[50] = {0};
    int dept_count = 0;

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
        printf("Le nombre des etudiants dans chaque departement:\n");
        int nombre_etudiants[50] = {0};
        for (int i = 0; i < count; i++)
        {
            int found = 0;
            for (int j = 0; j < dept_count; j++)
            {
                if (strcmp(Etudiants[i].Departement, departements[j]) == 0)
                {
                    nombre_etudiants[j]++;
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                strcpy(departements[dept_count], Etudiants[i].Departement);
                nombre_etudiants[dept_count] = 1;
                dept_count++;
            }
        }
        for (int i = 0; i < dept_count; i++)
        {
            printf("Departement %s : %d etudiants\n", departements[i], nombre_etudiants[i]);
        }
        break;
    case 3:
        // float seuil;
        printf("Entrer le seuil de moyenne : ");
        scanf("%f", &seuil);
        printf("Les etudiants ayant une moyenne generale superieure a %.2f:\n", seuil);
        for (int i = 0; i < count; i++)
        {
            if (Etudiants[i].Notegeneral > seuil)
            {
                printf("Numero: %d, Nom: %s, Prenom: %s, Note: %.2f\n",
                       Etudiants[i].Numero, Etudiants[i].Nom, Etudiants[i].Prenom, Etudiants[i].Notegeneral);
            }
        }
        break;
    case 4:
        if (count < 3)
        {
            printf("Il n'y a pas assez d'etudiants pour afficher les 3 meilleures notes.\n");
            return;
        }
        data etudiants_triees[100];
        size_t size_to_copy = sizeof(etudiants_triees); // size of destination buffer
        memcpy(etudiants_triees, Etudiants,size_to_copy);
        tri_par_notes(etudiants_triees, count);

        printf("Les 3 etudiants ayant les meilleures notes:\n");
        for (int i = 0; i < 3; i++)
        {
            printf("Numero: %d, Nom: %s, Prenom: %s, Note: %.2f\n",
                   etudiants_triees[i].Numero, etudiants_triees[i].Nom, etudiants_triees[i].Prenom, etudiants_triees[i].Notegeneral);
        }
        break;
    case 5:
        // char departements[50][50];
        // int nombre_reussite[50] = {0};
        // int dept_count = 0;

        for (int i = 0; i < count; i++)
        {
            if (Etudiants[i].Notegeneral >= 10)
            {
                int found = 0;
                for (int j = 0; j < dept_count; j++)
                {
                    if (strcmp(Etudiants[i].Departement, departements[j]) == 0)
                    {
                        nombre_reussite[j]++;
                        found = 1;
                        break;
                    }
                }
                if (!found)
                {
                    strcpy(departements[dept_count], Etudiants[i].Departement);
                    nombre_reussite[dept_count] = 1;
                    dept_count++;
                }
            }
        }

        printf("Le nombre des etudiants ayant reussi (Note >= 10) dans chaque departement:\n");
        for (int i = 0; i < dept_count; i++)
        {
            printf("Departement %s : %d etudiants\n", departements[i], nombre_reussite[i]);
        }
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
    printf("1 : rechercher les etudiants par nom\n");
    printf("2 : rechercher les etudiants par departement\n");
    printf("choisir une option pour rechercher les etudiants\n");
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
    Etudiants[0] = (data){1, "tbibzat", "charaf", "01/01/2000", "Computer Science", 16.5};
    Etudiants[1] = (data){2, "smaki", "rayan", "02/02/1999", "Mathematics", 9.0};
    Etudiants[2] = (data){3, "alaoui", "moncef", "03/03/1998", "Phisique", 17.0};
    Etudiants[3] = (data){4, "benkrara", "ahmed", "03/03/2000", "Computer Science", 19.50};
    Etudiants[4] = (data){5, "kharbach", "ayoub", "03/03/2002", "Computer Science", 10.00};

    int choix = 0;
    while (choix != 8)
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
        while (getchar() != '\n')
            ; // Nettoyer le buffer
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
            printf("Quitter le programme.\n");
            return 0;
        default:
            printf(" Choix invalide \n\n");
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}