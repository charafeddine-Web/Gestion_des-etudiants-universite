#include <stdio.h>

typedef struct {
    int Numero;
    char Nom[20];
    char Prenom[20];
    char DateNaissance[11];
    char Departement[30];
    float Notegeneral;
}data;
// int maxetudiant=1000;
data Etudiants[1000]; 
int count=0;



void Ajouter_etudiant()
{
    int choixajoute=0;
    printf(">>>-----------entre la methode d'ajout--------------<<<\n");
    printf("1-ajouter etudiant\n2-ajouter multiple etudiants\n3-retour au menu principal\n ");  
    scanf("%d",&choixajoute);
    for (int i = 0; i < count; i++)
    {
        if (choixajoute==1)
        {
            printf("----------------------------ajouter etudiant----------------------------\n");
            printf("numero : ");
            scanf("%d",&Etudiants[count].Numero);
            printf("nom : ");
            scanf("%[^\n]s",Etudiants[count].Nom);
            printf("prenom : ");
            scanf("%[^\n]s",Etudiants[count].Prenom);
            printf("date de naissance ,format (jj/mm/aaaa) : ");
            scanf("%[^\n]s",Etudiants[count].DateNaissance);
            printf("departement : ");
            scanf("%[^\n]s",Etudiants[count].Departement);
            printf("note general : ");
            scanf("%f",&Etudiants[count].Notegeneral);
            count++;
        }
        else if (choixajoute==2){
            int nbretudiants=0;
            printf("----------------------------ajouter multiple etudiants----------------------------\n");
            printf("Combien d'étudiants souhaitez-vous ajouter  : ");
            scanf("%d",&nbretudiants);
            for(int i=0;i<nbretudiants;i++){
                printf("numero : ");
                scanf("%d",&Etudiants[count].Numero);
                printf("nom : ");
                scanf("%[^\n]s",Etudiants[count].Nom);
                printf("prenom : ");
                scanf("%[^\n]s",Etudiants[count].Prenom);
                printf("date de naissance ,format (jj/mm/aaaa) : ");
                scanf("%[^\n]s",Etudiants[count].DateNaissance);
                printf("departement : ");
                scanf("%[^\n]s",Etudiants[count].Departement);
                printf("note general : ");
                scanf("%f",&Etudiants[count].Notegeneral);
                count++;
            }
        }
        else if (choixajoute==3)
        {
            return ;
        }
        else{
            printf("choix invalide\n");
        }
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
    for(int j=0;j>count;j++){
        printf("le numero est:%d\n",Etudiants[j].Numero);
        printf("le nom est:%s\n",Etudiants[j].Nom);
        printf("le prenom est:%s\n",Etudiants[j].Prenom);
        printf("la date de naissance est:%s\n",Etudiants[j].DateNaissance);
        printf("le departement est:%s\n",Etudiants[j].Departement);
        printf("la note general est:%f\n",Etudiants[j].Notegeneral);
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
}

int main()
{
    int choix=0;
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
        printf("8-Quitter\n");
        printf("Donner votre choix : ");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            Ajouter_etudiant();
            break;
        case 2:
            Afficher_etudiant();
            break;
        case 3:
            printf("system Gestion des étudiants dans une université");
            break;

        case 4:
            printf("system Gestion des étudiants dans une université");
            break;

        case 5:
            printf("system Gestion des étudiants dans une université");
            break;

        case 6:
            printf("system Gestion des étudiants dans une université");
            break;
        case 7:
            printf("system Gestion des étudiants dans une université");
            break;
        case 8:
            printf("system Gestion des étudiants dans une université");
            break;
        default:
            printf(" Choix invalide \n\n");
            break;
        }

        
    }
    return 0;
}