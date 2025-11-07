#include <iostream>
#include <string>
using namespace std;

class Client {
public:
    string nom;
    string CIN;
    int idClient;

    void saisirClient() {
        cout << "Nom du client: ";
        cin >> nom;
        cout << "CIN: ";
        cin >> CIN;
        cout << "ID client: ";
        cin >> idClient;
    }

    void afficherClient() {
        cout << "Nom: " << nom << ", CIN: " << CIN << ", ID: " << idClient << endl;
    }
};

class CompteBancaire {
private:
    string codeSecret;
    double solde;

public:
    int numero;
    Client client;

    void creerCompte() {
        cout << "=== Création de compte ===" << endl;
        cout << "Numéro du compte: ";
        cin >> numero;
        client.saisirClient();
        cout << "Code secret: ";
        cin >> codeSecret;
        cout << "Solde initial: ";
        cin >> solde;
    }

    void deposer(double montant) {
        solde = solde + montant;
        cout << "Depot de " << montant << " DH effectué !" << endl;
    }

    void retirer(double montant) {
        if (montant <= solde)
            solde = solde - montant;
        else
            cout << "Solde insuffisant !" << endl;
    }

    void afficherCompte() {
        cout << "Compte N°" << numero << " | Solde: " << solde << " DH" << endl;
        client.afficherClient();
    }
};

int main() {
    CompteBancaire c1, c2;
    cout << "Création du 1er compte :" << endl;
    c1.creerCompte();
    cout << "\nCréation du 2ème compte :" << endl;
    c2.creerCompte();

    cout << "\n--- Opérations ---" << endl;
    c1.deposer(500);
    c2.retirer(200);

    cout << "\n--- Infos Comptes ---" << endl;
    c1.afficherCompte();
    c2.afficherCompte();

    return 0;
}
