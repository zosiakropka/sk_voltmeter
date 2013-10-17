/* 
 * File:   main.cpp
 * Author: politechnika
 *
 * Created on October 8, 2013, 5:17 PM
 */

#include <iostream>


using namespace std;

int main(int argc, char** argv) {

    Voltmeter* v = new Voltmeter();
    v->simulate();

    return 0;
}

class Voltmeter {
private:
    double start, end;
    int shots, density;
    char* distribution;

    static const int DISTRIBUTIONS_N = 15;
    static const char* DISTRIBUTIONS [] = {
        "expo",
        "gaus", "gausn",
        "landau", "landaun",
        "pol0", "pol1", "pol2", "pol3", "pol4",
        "pol5", "pol6", "pol7", "pol8", "pol9"
    };

    void scanRange() {
        cout << "Range start: ";
        cin >> this->start;
        cout << "Range end: ";
        cin >> this->end;
    }

    void scanShots() {
        cout << "Shots: ";
        cin >> this->shots;
    }

    void scanDensity() {
        cout << "Density: ";
        cin >> this->density;
    }

    void scanDistribution() {
        int d;
        cout << "Select distribution function:" << endl;
        for (int i = 0; i < DISTRIBUTIONS_N; i++) {
            cout << '[]' << i << ']' << "\t" << DISTRIBUTIONS[i] << endl;
        }
        cin >> d;
        this->distribution = DISTRIBUTIONS[d];
    }

    double randGaus() {
        return rand->Gaus();
    }

    double randPoisson() {
        return rand->Poisson();
    }

    double randLandau() {
        return rand->Landau();
    }



public:

    Voltmeter() {
        scanRange();
        scanShots();
        scanDensity();
        scanDistribution();
    }

    void simulate() {

        TCanvas *canvas = new TCanvas();

        pad2 = new TPad();
        pad2->Draw();

        pad2->cd();
        histogram = new TH1F("histogram", "Voltmeter histogram", density, this->start, this->end);
        histogram->FillRandom(distribution, shots);
        histogram->Draw();
        canvas->Update();

    }
};





