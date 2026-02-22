#include <iostream>
using namespace std;

/*******************************************
 * Complétez le programme à partir d'ici.
 *******************************************/

class Tirelire {
public:
    double getMontant() const {
        return montant;
    }
    void afficher() const {
        if (montant<0.01) cout << "Vous etes sans le sou." << endl;
        else cout << "Vous avez : " << montant << " euros dans votre tirelire." <<
            endl;
    }
    void secouer() const {
        if (montant>0.01) cout << "Bing bing" << endl;
    }
    void remplir(const double x) {
        if (x>=0) montant += x;
    }
    void vider() {
        montant = 0;
    }
    void puiser(const double x) {
        if (x>=0) montant -= x;
        if (montant<0) montant = 0;
    }
    bool montant_suffisant(const double budget, double& solde) {
        if (budget < 0) {
            solde = montant;
            return true;
        }
        if (montant >= budget) {
            solde = montant-budget;
            return true;
        }
        solde = budget-montant;
        return false;
    }
    double calculerSolde(double budget) {
        if (budget<0) return montant;
        return montant-budget;
    }

private:
    double montant = 0;
};

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
    Tirelire piggy;

    piggy.vider();
    piggy.secouer();
    piggy.afficher();

    piggy.puiser(20.0);
    piggy.secouer();
    piggy.afficher();

    piggy.remplir(550.0);
    piggy.secouer();
    piggy.afficher();

    piggy.puiser(10.0);
    piggy.puiser(5.0);
    piggy.afficher();

    cout << endl;

    // le budget de vos vacances de rève.
    double budget;

    cout << "Donnez le budget de vos vacances : ";
    cin >> budget;

    // ce qui resterait dans la tirelire après les
    // vacances
    double solde(0.0);

    if (piggy.montant_suffisant(budget, solde)) {
        cout << "Vous êtes assez riche pour partir en vacances !"
             << endl
             << "Il vous restera " << solde << " euros"
             << " à la rentrée." << endl << endl;
        piggy.puiser(budget);
    } else {
        cout << "Il vous manque " << solde << " euros"
             << " pour partir en vacances !" << endl << endl;
    }
    return 0;
}
