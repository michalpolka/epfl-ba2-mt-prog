#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Pour simplifier
typedef string Forme   ;
typedef string Couleur ;

class Brique
{
private:
  Forme   forme   ;
  Couleur couleur ;

public:
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
  Brique(const Forme& f, const Couleur& c)
    : forme(f), couleur(c) {}

  ostream& afficher(ostream& sortie) const {
    if (couleur.empty()) sortie << forme;
    else sortie << "(" << forme << ", " << couleur << ")";
    return sortie;
  }

};

class Construction
{
  friend class Grader;

public:
  Construction(const Brique& b)
    : contenu({{{b}}}) {}

  ostream& afficher(ostream& sortie) const {
    for (int i(0); i<contenu.size(); ++i) {
      cout << "Couche " << contenu.size()-i-1 << " :" << endl;
      for (const auto & j : contenu[i]) {
        for (const auto & k : j) {
          k.afficher(sortie);
          sortie << " ";
        }
        cout << endl;
      }
    }
    return sortie;
  }

  const Construction operator^(Construction c) const {
    for (const auto& couche : contenu) {
      c.contenu.push_back(couche);
    }
    return c;
  }

  void operator^=(const Construction& c) {
    *this = *this ^ c;
  }

  const Construction operator-(const Construction& c) const {
    if (c.contenu.size() < contenu.size()) return *this;

    Construction out = *this;
    for (int i(0); i < out.contenu.size(); ++i) {
      for (const auto& j : c.contenu[i]) {
        out.contenu[i].push_back(j);
      }
    }
    return out;
  }

  void operator-=(const Construction& c) {
    *this = *this - c;
  }

  const Construction operator+(const Construction& c) const {
    if (c.contenu.size() < contenu.size()) return *this;
    if (c.contenu[0].size() < contenu[0].size()) return *this;

    Construction out = *this;
    for (int i(0); i<out.contenu.size(); ++i) {
      for (int j(0); j<out.contenu[i].size(); ++j) {
        for (const auto& k : c.contenu[i][j]) {
          out.contenu[i][j].push_back(k);
        }
      }
    }
    return out;
  }

  void operator+=(const Construction& c) {
    *this = *this + c;
  }



private:
  vector<vector<vector<Brique>>> contenu; // contenu[i][j][k] => i = 1st vector, j = 2nd vector, k = 3rd vector

};

ostream& operator<<(ostream& sortie, const Construction & construction) {
  construction.afficher(sortie);
  return sortie;
}

const Construction operator*(const unsigned int n, const Construction & a)
{
  Construction out = a;
  for (int i(1); i<n; ++i) {
    out += a;
  }
  return out;
}

const Construction operator/(const unsigned int n, const Construction & a)
{
  Construction out = a;
  for (int i(1); i<n; ++i) {
    out ^= a;
  }
  return out;
}

const Construction operator%(const unsigned int n, const Construction & a)
{
  Construction out = a;
  for (int i(1); i<n; ++i) {
    out -= a;
  }
  return out;
}

const Construction operator+(const Brique& b1, const Brique& b2) {
  Construction c(b1);
  c += Construction(b2);
  return c;
}

const Construction operator+(const Brique& b1, Construction c) {
  c = Construction(b1) + c;
  return c;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  // Modèles de briques
  Brique toitD("obliqueD", "rouge");
  Brique toitG("obliqueG", "rouge");
  Brique toitM(" pleine ", "rouge");
  Brique mur  (" pleine ", "blanc");
  Brique vide ("                 ", "");

  unsigned int largeur(4);
  unsigned int profondeur(3);
  unsigned int hauteur(3); // sans le toit

  // on construit les murs
  Construction maison( hauteur / ( profondeur % (largeur * mur) ) );

  // on construit le toit
  Construction toit(profondeur % ( toitG + 2*toitM + toitD ));
  toit ^= profondeur % (vide + toitG + toitD);

  // on pose le toit sur les murs
  maison ^= toit;

  // on admire notre construction
  cout << maison << endl;

  return 0;
}
