#include <iostream>
#include <string>
using namespace std;

class Timbre
{
private:
  static constexpr unsigned int ANNEE_COURANTE = 2016;

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
protected:
    string nom;
    unsigned annee;
    string pays;
    double valeur_faciale;

public:
  Timbre(const string &n, const unsigned a, const string &p="Suisse", const double vf=1.0)
        : nom(n), annee(a), pays(p), valeur_faciale(vf) {}

  unsigned int age() const {return ANNEE_COURANTE-annee;}

  virtual ostream& afficher(ostream& sortie) const {
        sortie << "Timbre de nom " << nom << " datant de " << annee << " (provenance "
               << pays << ") ayant pour valeur faciale " << valeur_faciale << " francs";
        return sortie;
    }

  virtual double vente() const {
        if (age()<5) return valeur_faciale;
        return static_cast<double>(age())*2.5*valeur_faciale;
    }
};

class Rare: public Timbre {
private:
    unsigned int exemplaires;
    static constexpr double PRIX_BASE_TRES_RARE = 600.;
    static constexpr double PRIX_BASE_RARE = 400.;
    static constexpr double PRIX_BASE_PEU_RARE = 50.;

public:
    Rare(
        const string &n,
        const unsigned a,
        const string &p = "Suisse",
        const double vf = 1.0,
        const unsigned int e = 100)
        : Timbre(n,a,p,vf), exemplaires(e) {}

    unsigned int nb_exemplaires() const {return exemplaires;}

    ostream& afficher(ostream& sortie) const {
        sortie << "Timbre rare (" << nb_exemplaires() << " ex.) de nom " << nom
               << " datant de " << annee << " (provenance "
               << pays << ") ayant pour valeur faciale " << valeur_faciale << " francs";
        return sortie;
    }

    double vente() const {
        double prix(PRIX_BASE_PEU_RARE);
        if (exemplaires<1000) prix = PRIX_BASE_RARE;
        if (exemplaires<100) prix = PRIX_BASE_TRES_RARE;
        return prix * (static_cast<double>(age())/ 10.0);
    }


};

class Commemoratif: public Timbre {
public:
    Commemoratif(const string &n, const unsigned a, const string &p = "Suisse", const double vf = 1.0)
        : Timbre(n,a,p,vf) {}

    ostream& afficher(ostream& sortie) const {
        sortie << "Timbre commémoratif de nom " << nom
               << " datant de " << annee << " (provenance "
               << pays << ") ayant pour valeur faciale " << valeur_faciale << " francs";
        return sortie;
    }

    double vente() const {
        return Timbre::vente()*2;
    }
};

ostream& operator<<(ostream& sortie, const Timbre &timbre) {
    timbre.afficher(sortie);
    return sortie;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/
int main()
{
  /* Ordre des arguments :
  *  nom, année d'émission, pays, valeur faciale, nombre d'exemplaires
  */
  Rare t1( "Guarana-4574", 1960, "Mexique", 0.2, 98 );
  Rare t2( "Yoddle-201"  , 1916, "Suisse" , 0.8,  3 );

  /* Ordre des arguments :
  *  nom, année d'émission, pays, valeur faciale, nombre d'exemplaires
  */
  Commemoratif t3( "700eme-501"  , 2002, "Suisse", 1.5 );
  Timbre       t4( "Setchuan-302", 2004, "Chine" , 0.2 );

  /* Nous n'avons pas encore le polymorphisme :-(
   * (=> pas moyen de faire sans copie ici :-( )  */
  cout << t1 << endl;
  cout << "Prix vente : " << t1.vente() << " francs" << endl;
  cout << t2 << endl;
  cout << "Prix vente : " << t2.vente() << " francs" << endl;
  cout << t3 << endl;
  cout << "Prix vente : " << t3.vente() << " francs" << endl;
  cout << t4 << endl;
  cout << "Prix vente : " << t4.vente() << " francs" << endl;

  return 0;
}
