#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int distance(int x, int y)
{
  return abs(x - y);
}

class Creature
{
  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
protected:
    string nom_;
    int niveau_;
    int points_de_vie_;
    int force_;
    int position_;

public:
    Creature(const string &n, const int lvl, const int pv, const int f, const int pos = 0)
        : nom_(n), niveau_(lvl), points_de_vie_(pv), force_(f), position_(pos) {}

    bool vivant() const {return points_de_vie_>0;}
    int points_attaque() const {return vivant()? niveau_*force_ : 0;}
    void deplacer(const int delta) {if (vivant()) position_+=delta;}
    void adieu() const {cout << nom_ << " n'est plus !" << endl;}
    void faiblir(const int dmg) {
        points_de_vie_-=dmg;
        if (!vivant()) {
            points_de_vie_ = 0;
            adieu();
        }
    }
    void afficher() const {
        cout << nom_
            << ", niveau: " << niveau_
            << ", points de vie: " << points_de_vie_
            << ", force: " << force_
            << ", points d'attaque: " << points_attaque()
            << ", position: " << position_ << endl;
    }
    int position() const {return position_;}
};

class Dragon : public Creature {
private:
    int portee_flamme_;

public:
    Dragon(const string &n, const int lvl, const int pv, const int f, const int pf, const int pos = 0)
        : Creature(n,lvl,pv,f,pos), portee_flamme_(pf) {}

    void voler(const int pos) {
        position_ = pos;
    }
    void souffle_sur(Creature& bete) {
        const int dist ( distance( bete.position() , position_) );
        if (vivant() && bete.vivant() && dist<=portee_flamme_) {
            bete.faiblir(points_attaque());
            faiblir(dist);
            if (vivant() && !bete.vivant()) {
                niveau_++;
            }
        }
    }
};


class Hydre : public Creature {
private:
    int longueur_cou_;
    int dose_poison_;

public:
    Hydre(const string &n, const int lvl, const int pv, const int f, const int lc, const int dp, const int pos = 0)
        : Creature(n,lvl,pv,f,pos), longueur_cou_(lc), dose_poison_(dp) {}

    void empoisonne(Creature& bete) {
        const int dist (distance(bete.position(), position_));
        if (vivant() && bete.vivant() && dist<=longueur_cou_) {
            bete.faiblir(points_attaque()+dose_poison_);
            if (vivant() && !bete.vivant()) {
                niveau_++;
            }
        }
    }
};

void combat(Dragon& d, Hydre& h) {
    h.empoisonne(d);
    d.souffle_sur(h);
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/
int main()
{
  Dragon dragon("Dragon rouge"   , 2, 10, 3, 20         );
  Hydre  hydre ("Hydre maléfique", 2, 10, 1, 10, 1,  42 );

  dragon.afficher();
  cout << "se prépare au combat avec :" << endl;
  hydre.afficher();

  cout << endl;
  cout << "1er combat :" << endl;
  cout << "    les créatures ne sont pas à portée, donc ne peuvent pas s'attaquer."
       << endl;
  combat(dragon, hydre);

  cout << "Après le combat :" << endl;
  dragon.afficher();
  hydre.afficher();

  cout << endl;
  cout << "Le dragon vole à proximité de l'hydre :" << endl;
  dragon.voler(hydre.position() - 1);
  dragon.afficher();

  cout << endl;
  cout << "L'hydre recule d'un pas :" << endl;
  hydre.deplacer(1);
  hydre.afficher();

  cout << endl;
  cout << "2e combat :" << endl;
  cout << "\
  + l'hydre inflige au dragon une attaque de 3 points\n\
      [ niveau (2) * force (1) + poison (1) = 3 ] ;\n\
  + le dragon inflige à l'hydre une attaque de 6 points\n\
      [ niveau (2) * force (3) = 6 ] ;\n\
  + pendant son attaque, le dragon perd 2 points de vie supplémentaires\n\
       [ correspondant à la distance entre le dragon et l'hydre : 43 - 41 = 2 ].\
" << endl;
  combat(dragon, hydre);

  cout << "Après le combat :" << endl;
  dragon.afficher();
  hydre.afficher();

  cout << endl;
  cout << "Le dragon avance d'un pas :" << endl;
  dragon.deplacer(1);
  dragon.afficher();

  cout << endl;
  cout << "3e combat :" << endl;
  cout << "\
  + l'hydre inflige au dragon une attaque de 3 points\n\
      [ niveau (2) * force (1) + poison (1) = 3 ] ;\n\
  + le dragon inflige à l'hydre une attaque de 6 points\n\
      [ niveau (2) * force (3) = 6 ] ;\n\
  + pendant son attaque, le dragon perd 1 point de vie supplémentaire\n\
       [ correspondant à la distance entre le dragon et l'hydre : 43 - 42 = 1 ] ;\n\
  + l'hydre est vaincue et le dragon monte au niveau 3.\
" << endl;
  combat(dragon, hydre);

  cout << "Après le combat :" << endl;
  dragon.afficher();
  hydre.afficher();

  cout << endl;
  cout << "4e Combat :" << endl;
  cout << "    quand une créature est vaincue, rien ne se passe." << endl;
  combat(dragon, hydre);

  cout << "Après le combat :" << endl;
  dragon.afficher();
  hydre.afficher();

  return 0;
}
