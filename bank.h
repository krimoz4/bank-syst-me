#ifndef BANK_H
#define BANK_H

#define MAX_NAME 50
#define MAX_EMAIL 50
#define MAX_ACCOUNTS 100

typedef struct{
    char Nom[MAX_NAME];
    char Prenom[MAX_NAME];
    char Email[MAX_EMAIL];
    int telephone[15];
    char adresse[15];
}utilisateur;

typedef struct {
    int numDeCompte;
    char prenom[MAX_NAME];
    char nom[MAX_NAME];
    char email[MAX_EMAIL];
    float solde;
    int active;
}compte;

void Enregistrer();
void Ajouter();
void Modifier();
void Supprimer();
void Afficher();
void Depots();
void Retrait();
void Transfert();
void RechercheParNom();
void RechercheParNum();
void TriParNom();
void TriParSolde();
void afficherTotalFonds();
#endif

