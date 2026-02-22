#include <iostream>
using namespace std;

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

class Patient {
public:
    void init(const double p, const double t) {
        if (p<0 || t<0) {
            varpoids = 0;
            vartaille = 0;
            return;
        }
        varpoids = p;
        vartaille = t;
    }

    void afficher() const {
        cout << "Patient : " << varpoids << " kg pour " << vartaille << " m" << endl;
    }

    double poids() const {
        return varpoids;
    }

    double taille() const {
        return vartaille;
    }

    double imc() const {
        if (vartaille == 0) return 0;
        return varpoids/(vartaille * vartaille);
    }

private:
    double varpoids = 0;
    double vartaille = 0;
};

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
    Patient quidam;
    double poids, taille;
    do {
        cout << "Entrez un poids (kg) et une taille (m) : ";
        cin >> poids >> taille;
        quidam.init(poids, taille);
        quidam.afficher();
        cout << "IMC : " << quidam.imc() << endl;
    } while (poids * taille != 0.0);
    return 0;
}
