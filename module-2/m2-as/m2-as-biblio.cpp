#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*******************************************
 * Completez le programme a partir d'ici.
 *******************************************/
// Chaines de caractères à utiliser pour les affichages:
/*

été jeté

d'un

n'est

L'oeuvre

bibliothèque

détruit

*/

class Auteur {
public:
    Auteur(const string& nom = "", const bool prime = false)
        : nom(nom), prime(prime) {}
    Auteur(Auteur const& other) = delete;

    string getNom() const {return nom;}
    bool getPrix() const {return prime;}

private:
    string nom;
    bool prime;
};

class Oeuvre {
public:
    Oeuvre(const string& titre, const Auteur& auteur, const string& langue )
        : titre(titre), auteur(auteur), langue(langue) {}
    Oeuvre(const Oeuvre& other) = delete;
    ~Oeuvre() {
        cout << "L'oeuvre \"" << titre << ", " << auteur.getNom() << ", en " << langue << "\" n'est plus disponible." << endl;

    }

    string getTitre() const {return titre;}
    string getLangue() const {return langue;}
    const Auteur& getAuteur() const {return auteur;}
    void affiche() {
        cout << titre << ", " << auteur.getNom() << ", en " << langue << endl;
    }


private:
    string titre;
    const Auteur& auteur;
    string langue;
};

class Exemplaire {
public:
    Exemplaire(const Oeuvre& oeuvre)
        : oeuvre(oeuvre) {
        cout << "Nouvel exemplaire de : " << oeuvre.getTitre() << ", " << oeuvre.getAuteur().getNom() << ", en " << oeuvre.getLangue() << endl;
    }
    Exemplaire(const Exemplaire& other)
        : oeuvre(other.oeuvre) {
        cout << "Copie d'un exemplaire de : " << oeuvre.getTitre() << ", " << oeuvre.getAuteur().getNom() << ", en " << oeuvre.getLangue() << endl;
    }
    ~Exemplaire() {
        cout << "Un exemplaire de \"" << oeuvre.getTitre() << ", " << oeuvre.getAuteur().getNom() << ", en " << oeuvre.getLangue() << "\" a été jeté !" << endl;
    }

    const Oeuvre& getOeuvre() const {return oeuvre;}
    void affiche() const {
        cout << "Exemplaire de : " << oeuvre.getTitre() << ", " << oeuvre.getAuteur().getNom() << ", en " << oeuvre.getLangue() << endl;
    }

private:
    const Oeuvre& oeuvre;
};

class Bibliotheque {
public:
    Bibliotheque(const string& nom)
        : nom(nom) {
        cout << "La bibliothèque " << nom << " est ouverte !" << endl;
    }
    Bibliotheque(const Bibliotheque& other) = delete;
    ~Bibliotheque() {
        cout << "La bibliothèque " << nom << " ferme ses portes," << endl
             << "et détruit ses exemplaires : " << endl;
        for (const Exemplaire* ex : lib) delete ex;
    }

    string getNom() const {return nom;}

    void stocker(const Oeuvre& oeuvre, const unsigned exemplaires=1) {
        for (unsigned i(0); i<exemplaires; ++i) {
            lib.push_back(new Exemplaire(oeuvre));
        }
    }

    void lister_exemplaires(const string& langue="") const {
        for (const Exemplaire* ex : lib) {
            if (ex->getOeuvre().getLangue() == langue || langue.empty()) ex->affiche();
        }
    }

    unsigned compter_exemplaires(const Oeuvre& oeuvre) const {
        unsigned count(0);
        for (const Exemplaire* ex : lib) {
            if (ex->getOeuvre().getTitre()==oeuvre.getTitre()) ++count;
        }
        return count;
    }

    void afficher_auteurs(const bool primes=false) {
        for (const Exemplaire* ex : lib) {
            if (ex->getOeuvre().getAuteur().getPrix() || !primes) {
                cout << ex->getOeuvre().getAuteur().getNom() << endl;
            }
        }

    }


private:
    string nom;
    vector<Exemplaire*> lib;

};

/*******************************************
 * Ne rien modifier apres cette ligne.
 *******************************************/

int main()
{
  Auteur a1("Victor Hugo"),
         a2("Alexandre Dumas"),
         a3("Raymond Queneau", true);

  Oeuvre o1("Les Misérables"           , a1, "français" ),
         o2("L'Homme qui rit"          , a1, "français" ),
         o3("Le Comte de Monte-Cristo" , a2, "français" ),
         o4("Zazie dans le métro"      , a3, "français" ),
         o5("The Count of Monte-Cristo", a2, "anglais" );

  Bibliotheque biblio("municipale");
  biblio.stocker(o1, 2);
  biblio.stocker(o2);
  biblio.stocker(o3, 3);
  biblio.stocker(o4);
  biblio.stocker(o5);

  cout << "La bibliothèque " << biblio.getNom()
       << " offre les exemplaires suivants :" << endl;
  biblio.lister_exemplaires();

  const string langue("anglais");
  cout << " Les exemplaires en "<< langue << " sont :" << endl;
  biblio.lister_exemplaires(langue);

  cout << " Les auteurs à succès sont :" << endl;
  biblio.afficher_auteurs(true);

  cout << " Il y a " << biblio.compter_exemplaires(o3) << " exemplaires de "
       << o3.getTitre() << endl;

  return 0;
}
