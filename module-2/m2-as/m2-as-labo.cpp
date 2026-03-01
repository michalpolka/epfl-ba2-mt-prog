#include <iostream>
#include <string>
using namespace std;

class Souris
{
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/

  public:
    Souris(const double p, const string& c, const unsigned a = 0, const unsigned ev = 36)
      : poids(p), couleur(c), age(a), esperance_vie(ev), clonee(false) {
      cout << "Une nouvelle souris !" << endl;
    }

    Souris(Souris const& other)
      : poids(other.poids), couleur(other.couleur), age(other.age), esperance_vie((other.esperance_vie*4)/5), clonee(true){
      cout << "Clonage d'une souris !" << endl;
    }

    ~Souris() {
      cout << "Fin d'une souris..." << endl;
    }


    void afficher() const {
      cout << "Une souris " << couleur << (clonee? ", clonee, " : " ") << "de " << age << " mois"
      " et pesant " << poids << " grammes" << endl;
    }
    void vieillir() {
      ++age;
      if (clonee && age>(esperance_vie/2)) couleur = "verte";
    }
    void evolue() {
      age = esperance_vie-1;
      vieillir();
    }

  private:
    double poids;
    string couleur;
    unsigned age = 0;
    unsigned esperance_vie = 36;
    bool clonee;

  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

}; // fin de la classe Souris

int main()
{
  Souris s1(50.0, "blanche", 2);
  Souris s2(45.0, "grise");
  Souris s3(s2);
  // ... un tableau peut-être...
  s1.afficher();
  s2.afficher();
  s3.afficher();
  s1.evolue();
  s2.evolue();
  s3.evolue();
  s1.afficher();
  s2.afficher();
  s3.afficher();
  return 0;
}
