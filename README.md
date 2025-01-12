# Système de Gestion Bancaire

## Description
Ce projet consiste en le développement d'une application console en langage C permettant la gestion des comptes clients et des transactions bancaires. Les données sont stockées dans des fichiers CSV pour garantir une gestion efficace et structurée.

## Fonctionnalités

### 1. Gestion des comptes clients
- Enregistrement des utilisateurs avec les informations personnelles :
  - Nom
  - Prénom
  - Adresse
  - Email
  - Numéro de téléphone
  - Numéro de compte
- Ajout, modification et suppression de comptes clients.
- Affichage de la liste des comptes avec :
  - Numéro de compte
  - Nom
  - Prénom
  - Solde
  - Email
  - Statut du compte (actif/inactif)

### 2. Gestion des transactions
- **Dépôt** : Ajouter un montant au solde d'un compte.
- **Retrait** : Retirer un montant du solde d'un compte.
- **Transfert** : Transférer des fonds entre deux comptes.
- Historique des transactions enregistré dans un fichier CSV.

### 3. Recherche et tri
- Recherche de comptes par **Nom** ou **Numéro de compte**.
- Tri des comptes par **Nom** ou **Solde**.

### 4. Rapports
- Génération de rapports sur l'historique des transactions d'un compte.
- Affichage du total des fonds disponibles dans la banque.

### 5. Stockage des données
- Sauvegarde des informations des clients et des transactions dans des fichiers CSV.

## Prérequis
- **Langage de programmation** : C
- **Environnement de développement** : GCC ou tout autre compilateur C compatible
- **Système d'exploitation** : Windows, Linux ou macOS

## Organisation du projet
```
├── main.c                # Point d'entrée de l'application
├── accounts.c            # Gestion des comptes clients
├── transactions.c        # Gestion des transactions
├── reports.c             # Génération des rapports
├── data                 
│   ├── clients.csv       # Données des comptes clients
│   └── transactions.csv  # Historique des transactions
    └── utilisateur.csv   # Donnée des utilisateur
├── README.md             # Documentation du projet
```


## Équipe de développement
- Projet réalisé par **Ouddir Akram**,**Belghali Hamza**, **Sarsar Elmehdi**, **Benchagra Iyad**, **Ezzen Hamza**



