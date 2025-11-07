#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ======== Classe de base Ressource ========
class Ressource {
protected:
    int id;
    string titre;
    string auteur;
    int annee;

public:
    Ressource(int i, string t, string a, int n) {
        id = i;
        titre = t;
        auteur = a;
        annee = n;
    }

    virtual void afficherInfos() {
        cout << "ID: " << id << " | Titre: " << titre
             << " | Auteur: " << auteur << " | Annee: " << annee << endl;
    }

    bool operator==(Ressource &r) {
        return id == r.id;
    }

    string getTitre() { return titre; }
    int getAnnee() { return annee; }
    string getAuteur() { return auteur; }
};

// ======== Classe Livre (hérite de Ressource) ========
class Livre : public Ressource {
private:
    int nbPages;

public:
    Livre(int i, string t, string a, int n, int nb)
        : Ressource(i, t, a, n) {
        nbPages = nb;
    }

    void afficherInfos() override {
        cout << "[Livre] ";
        Ressource::afficherInfos();
        cout << "Nombre de pages: " << nbPages << endl;
    }

    void telecharger() {
        cout << "Telechargement du livre \"" << titre << "\" en cours..." << endl;
    }
};

// ======== Classe Mediatheque ========
class Mediatheque {
private:
    vector<Ressource*> ressources;

public:
    void ajouter(Ressource* r) {
        ressources.push_back(r);
    }

    void afficher() {
        cout << "\n=== Liste des ressources ===" << endl;
        for (auto r : ressources) {
            r->afficherInfos();
            cout << "---------------------" << endl;
        }
    }

    void rechercher(string titre) {
        cout << "\nRecherche par titre: " << titre << endl;
        for (auto r : ressources)
            if (r->getTitre() == titre)
                r->afficherInfos();
    }

    void rechercher(int annee) {
        cout << "\nRecherche par annee: " << annee << endl;
        for (auto r : ressources)
            if (r->getAnnee() == annee)
                r->afficherInfos();
    }

    void rechercher(string auteur, int annee) {
        cout << "\nRecherche par auteur + annee: " << auteur << ", " << annee << endl;
        for (auto r : ressources)
            if (r->getAuteur() == auteur && r->getAnnee() == annee)
                r->afficherInfos();
    }
};

// ======== Programme principal ========
int main() {
    Livre l1(1, "Le Petit Prince", "Saint-Exupery", 1943, 120);
    Livre l2(2, "Harry Potter", "J.K. Rowling", 1998, 350);
    Livre l3(3, "Apprendre le C++", "Prof Alain", 2020, 250);

    Mediatheque med;
    med.ajouter(&l1);
    med.ajouter(&l2);
    med.ajouter(&l3);

    med.afficher();

    cout << "\n=== Telechargement ===" << endl;
    l1.telecharger();
    l2.telecharger();

    cout << "\n=== Recherche ===" << endl;
    med.rechercher("Harry Potter");
    med.rechercher(2020);
    med.rechercher("Prof Alain", 2020);

    cout << "\n=== Comparaison ===" << endl;
    if (l1 == l2)
        cout << "Les deux livres ont le meme ID." << endl;
    else
        cout << "Les livres sont differents." << endl;

    return 0;
}
