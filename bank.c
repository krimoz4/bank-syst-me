#include <stdio.h>
#include <stdlib.h>
#include "bank.h"



void Enregistrer(){
     FILE*f=fopen("utilisateur.csv","a");
     utilisateur b;
        printf("Saisir votre nom et prenom::");
        scanf("%s %s",b.Nom,b.Prenom);
        printf("Saisir votre email:");
        scanf("%s",b.Email);
        printf("Saisir votre numero de telephone:");
        scanf("%d",&b.telephone);
        printf("saisir votre adresse:");
        scanf("%s",b.adresse);
        fprintf(f,"%s-%s-%s-%d-%s\n",b.Nom,b.Prenom,b.Email,b.telephone,b.adresse);
         printf("Compte enregistre avec succes !\n");
     fclose(f);
}

void Ajouter() {
 FILE *file = fopen("accounts.csv", "a");
    compte a;
    printf("saisir le numero du compte:");
    scanf("%d",&a.numDeCompte);
    printf("Saisir le nom et prenom du client:");
    scanf("%s %s",a.nom,a.prenom);
    printf("Saisir l email du client:");
    scanf("%s",&a.email);
    printf("Saisir le solde du client:");
    scanf("%f",&a.solde);
    a.active=1;
    fprintf(file,"%d %s %s %s %.2f %d\n",a.numDeCompte,a.nom,a.prenom,a.email,a.solde,a.active);
    printf("Compte ajoute avec succes !\n");
 fclose(file);
}

void Modifier() {
    int num;
    printf("saisir le numero du compte a modifier:");
    scanf("%d",&num);
    FILE*file=fopen("accounts.csv", "r");
    FILE*temp=fopen("temp.csv","w");
    compte a;
    int found = 0;
    while(fscanf(file,"%d %s %s %s %f %d",&a.numDeCompte,a.nom,a.prenom,a.email,&a.solde,&a.active)!= EOF){
        if(a.numDeCompte==num){
            printf("saisir le numero du compte:");
            scanf("%d",&a.numDeCompte);
            printf("Saisir le nouveau nom et prenom du client:");
            scanf("%s %s",a.nom,a.prenom);
            printf("Saisir le nouveau email du client:");
            scanf("%s",&a.email);
            printf("Saisir le nouveau solde du client:");
            scanf("%f",&a.solde);
            a.active=1;
            found=1;
            fprintf(temp,"%d %s %s %s %.2f %d\n",a.numDeCompte,a.nom,a.prenom,a.email,a.solde,a.active);
        }
    }
    fclose(file);
    fclose(temp);
    remove("accounts.csv");
    rename("temp.csv", "accounts.csv");

    if (found) {
        printf("Compte modifie avec succes !\n");
    } else {
        printf("Compte introuvable.\n");
    }
}

void Supprimer() {
    int num;
    printf("Saisir le numero du compte a supprime: ");
    scanf("%d", &num);
    FILE *file = fopen("accounts.csv", "r");
    FILE *temp = fopen("temp.csv", "w");
    compte a;
    int found = 0;

    while (fscanf(file,"%d %s %s %s %f %d",&a.numDeCompte,a.nom,a.prenom,a.email,&a.solde,&a.active) != EOF) {
        if (a.numDeCompte == num) {
            a.active = 0;
            found = 1;
        }
        fprintf(temp,"%d %s %s %s %.2f %d\n",a.numDeCompte,a.nom,a.prenom,a.email,a.solde,a.active);
    }

    fclose(file);
    fclose(temp);
    remove("accounts.csv");
    rename("temp.csv", "accounts.csv");

    if (found) {
        printf("Compte supprime avec succes !\n");
    } else {
        printf("Compte introuvable.\n");
    }
}

void Afficher(){
    FILE *file = fopen("accounts.csv", "r");
    compte a;
    printf("\n Numero du compte | Nom | Prenom | Email | Solde | Statut\n");
    printf("-----------------------------------------------------------------------\n");

    while (fscanf(file, "%d %s %s %s %f %d",&a.numDeCompte,a.nom,a.prenom,a.email,&a.solde,&a.active) != EOF) {
        printf("%d | %s | %s | %s | %.2f | %s\n",a.numDeCompte,a.nom,a.prenom,a.email,a.solde,a.active ? "Active" : "Inactive");
    }
    fclose(file);
}
void EnregistrementTransaction(int du, int vers, float montant, const char *type) {
    FILE *t = fopen("Transaction.csv", "a");
    fprintf(t, "%d,%d,%.2f,%s\n", du, vers, montant, type);
    fclose(t);
}

void Depots() {
    int num;
    float montant;
    printf("Saisir le numero du compte: ");
    scanf("%d", &num);
    printf("Saisir le montant:");
    scanf("%f", &montant);
    FILE *file = fopen("accounts.csv", "r");
    FILE*temp=fopen("temp.csv","w");
    compte a;
    int found=0;
    while (fscanf(file, "%d %s %s %s %f %d",&a.numDeCompte,a.nom,a.prenom,a.email,&a.solde,&a.active) != EOF){
        if(num==a.numDeCompte){
            a.solde+=montant;
            found=1;
        }
    fprintf(temp,"%d %s %s %s %.2f %d\n",a.numDeCompte,a.nom,a.prenom,a.email,a.solde,a.active);
    }

    fclose(file);
    fclose(temp);
    remove("accounts.csv");
    rename("temp.csv", "accounts.csv");

    if (found){
        EnregistrementTransaction(num, num, montant, "Depot");
        printf("Depot reussi !\n");
    } else {
        printf("Compte introuvable ou inactif.\n");
    }

}

void Retrait(){
    int num;
    float montant;
    printf("Saisir le numero du compte: ");
    scanf("%d", &num);
    printf("Saisir le montant:");
    scanf("%f", &montant);
    FILE *file = fopen("accounts.csv", "r");
    FILE*temp=fopen("temp.csv","w");
    compte a;
    int found=0;
    while (fscanf(file, "%d %s %s %s %f %d",&a.numDeCompte,a.nom,a.prenom,a.email,&a.solde,&a.active) != EOF){
        if(num==a.numDeCompte){
          if (a.solde >= montant) {
            a.solde-=montant;
            found=1;
       }
    }
    fprintf(temp,"%d %s %s %s %.2f %d\n",a.numDeCompte,a.nom,a.prenom,a.email,a.solde,a.active);
    }

    fclose(file);
    fclose(temp);
    remove("accounts.csv");
    rename("temp.csv", "accounts.csv");

    if (found){
        EnregistrementTransaction(num, num, montant, "Retrait");
        printf("Retrait reussi !\n");
    } else {
        printf("Solde insuffisants ou compte introuvable.\n");
    }
}

void Transfert(){
    int num1, num2;
    float montant;
    printf("Enter Sender Account Number: ");
    scanf("%d", &num1);
    printf("Enter Receiver Account Number: ");
    scanf("%d", &num2);
    printf("Enter amount to transfer: ");
    scanf("%f", &montant);

    Retrait(num1,montant);
    Depots(num2,montant);
    EnregistrementTransaction(num1, num2, montant, "Transfert");
    printf("Transfert avec success!\n");
}

void RechercheParNom(){
   char nom[MAX_NAME];
   printf("Saisir le nom: ");
   scanf("%s", nom);

   FILE *file = fopen("accounts.csv", "r");
   compte a;
   int found = 0;

   while (fscanf(file, "%d %s %s %s %f %d", &a.numDeCompte, a.nom, a.prenom, a.email, &a.solde, &a.active) != EOF) {
       if (strcasecmp(a.nom, nom) == 0) {
           printf("Compte trouve: %d | %s %s | %s | %.2f | %s\n", a.numDeCompte, a.nom, a.prenom, a.email, a.solde, a.active ? "Active" : "Inactive");
           found = 1;
       }
   }
   fclose(file);

   if (!found) {
       printf("Aucun compte trouve avec le nom donne.\n");
   }
}

void RechercheParNum(){
    int num;
    printf("Saisir le numero de compte a chercher: ");
    scanf("%d", &num);

    FILE *file = fopen("accounts.csv", "r");
    compte a;
    int found = 0;

    while (fscanf(file, "%d %s %s %s %f %d", &a.numDeCompte, a.nom, a.prenom, a.email, &a.solde, &a.active) != EOF) {
        if (a.numDeCompte == num) {
            printf("Compte trouve: %d | %s %s | %s | %.2f | %s\n", a.numDeCompte, a.nom, a.prenom, a.email, a.solde, a.active ? "Active" : "Inactive");
            found = 1;
            break;
        }
    }
    fclose(file);

    if (!found) {
        printf("Aucun compte trouve avec le numero donne.\n");
    }
}

void TriParNom(){
    FILE *file = fopen("accounts.csv", "r");
    compte acc[MAX_ACCOUNTS];
    int c = 0;

    while (fscanf(file, "%d %s %s %s %f %d", &acc[c].numDeCompte, acc[c].nom, acc[c].prenom, acc[c].email, &acc[c].solde, &acc[c].active) != EOF) {
        c++;
    }
    fclose(file);

    for (int i = 0; i < c - 1; i++) {
        for (int j = i + 1; j < c; j++) {
            if (strcasecmp(acc[i].nom, acc[j].nom) > 0) {
                compte temp = acc[i];
                acc[i] = acc[j];
                acc[j] = temp;
            }
        }
    }

    printf("\nComptes tries par nom:\n");
    for (int i = 0; i < c; i++) {
        printf("%d | %s %s | %.2f\n", acc[i].numDeCompte, acc[i].nom, acc[i].prenom, acc[i].solde);
    }
}

void TriParSolde(){
    FILE *file = fopen("accounts.csv", "r");
    compte acc[MAX_ACCOUNTS];
    int c = 0;

    while (fscanf(file, "%d %s %s %s %f %d", &acc[c].numDeCompte, acc[c].nom, acc[c].prenom, acc[c].email, &acc[c].solde, &acc[c].active) != EOF) {
        c++;
    }
    fclose(file);

    for (int i = 0; i < c - 1; i++) {
        for (int j = i + 1; j < c; j++) {
            if (acc[i].solde < acc[j].solde) {
                compte temp = acc[i];
                acc[i] = acc[j];
                acc[j] = temp;
            }
        }
    }

    printf("\nComptes tries par solde:\n");
    for (int i = 0; i < c; i++) {
        printf("%d | %s %s | %.2f\n", acc[i].numDeCompte, acc[i].nom, acc[i].prenom, acc[i].solde);
    }
}
void afficherTotalFonds() {
    FILE *file = fopen("accounts.csv", "r");
    compte acc[MAX_ACCOUNTS];
    float total= 0;
    int c=0;
    while (fscanf(file, "%d %s %s %s %f %d", &acc[c].numDeCompte, acc[c].nom, acc[c].prenom, acc[c].email, &acc[c].solde, &acc[c].active) != EOF) {
        c++;
    }
    for (int i=0;i<c;i++) {
        total+=acc[i].solde;
    }
    fclose(file);

    printf("Total des Fonds Disponibles dans la Banque : %.2f DHS\n", total);
}
