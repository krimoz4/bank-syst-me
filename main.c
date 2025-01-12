#include <stdio.h>
#include "bank.h"

int main() {
    int choice;

    do {
        printf("\n--- Banking System ---\n");
        printf("1. Create Account\n");
        printf("2. Add Account\n");
        printf("3. Modify Account\n");
        printf("4. Delete Account\n");
        printf("5. Display Accounts\n");
        printf("6. Deposit Money\n");
        printf("7. Withdraw Money\n");
        printf("8. Transfer Money\n");
        printf("9. Search by Account Number\n");
        printf("10. Search by Name\n");
        printf("11. Sort Accounts by Name\n");
        printf("12. Sort Accounts by Balance\n");
        printf("13. TotalFunds \n");
        printf("14. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: Enregistrer(); break;
            case 2: Ajouter(); break;
            case 3: Modifier(); break;
            case 4: Supprimer(); break;
            case 5: Afficher(); break;
            case 6: Depots(); break;
            case 7: Retrait(); break;
            case 8: Transfert(); break;
            case 9: RechercheParNum(); break;
            case 10: RechercheParNom(); break;
            case 11: TriParNom(); break;
            case 12: TriParSolde(); break;
            case 13: afficherTotalFonds(); break;
            case 14: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 14);

    return 0;
}
