/* Autor: Gibram Oswaldo Andrade Baltazar
		  Yozhel Efrain Jimenez Lopez
   Materia: Probability and statistics
   programa: Hands - on 4 (agrupacion de datos)
   fecha: 29 octubre 2026
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main(){



using namespace std;

double datos[30] = {
    10.5, 14.2, 17.8, 20.1, 22.3, 25.0, 28.4, 30.2, 33.5, 36.1,
    38.0, 41.5, 43.8, 47.2, 50.0, 52.6, 55.1, 58.9, 61.3, 64.0,
    66.7, 70.2, 72.8, 75.4, 78.1, 81.5, 84.0, 86.3, 89.1, 91.5
};

int n = 30;

double min_val = datos[0];
double max_val = datos[0];

for (int i = 1; i < n; i++) {
        if (datos[i] < min_val) {
            min_val = datos[i];
        }
        if (datos[i] > max_val) {
            max_val = datos[i];
        }
    }

   
    double rango = max_val - min_val;

int k = round (1 + 3.322 * log10(n));
double amplitud = rango / k ;


int fa_acumulada = 0;
double fr_acumulada = 0.0;

	cout << fixed << setprecision(2);
cout << "----------------------------------------------------------------------------------\n";
cout << setw(6)  << "Clase" 
     << setw(16) << "Limite clase" 
     << setw(6)  << "f" 
     << setw(10) << "Xc" 
     << setw(6)  << "Fa" 
     << setw(8)  << "fr" 
     << setw(8)  << "fra" 
     << setw(12) << "Porcentaje %" << "\n";
cout << "----------------------------------------------------------------------------------\n";

for (int i = 0; i < k; i++) {
	double li = min_val + i * amplitud;
	double ls = li + amplitud;
	double xi = (ls + li) / 2.0;
	int fi = 0;
	for (int j = 0; j < n; j++) {
    if (i == k - 1) {
        if (datos[j] >= li && datos[j] <= ls) {
            fi++;
        }
    } else {
        if (datos[j] >= li && datos[j] < ls) {
            fi++;
        }
    }
}
	double fr = (double)fi / n;
	double porcentaje = fr * 100.0;
	fa_acumulada += fi;
	fr_acumulada += fr;	
	
cout << setw(6)  << (i + 1)
             << setw(8)  << li << " - " << setw(5) << ls
             << setw(6)  << fi
             << setw(10) << xi
             << setw(6)  << fa_acumulada
             << setw(8)  << fr
             << setw(8)  << fr_acumulada
             << setw(11) << porcentaje << "%\n";

}
cout << "----------------------------------------------------------------------------------\n";
    cout << setw(6)  << "TOTAL"
         << setw(16) << ""
         << setw(6)  << n
         << setw(10) << ""
         << setw(6)  << ""
         << setw(8)  << fr_acumulada
         << setw(8)  << ""
         << setw(11) << (fr_acumulada * 100.0) << "%\n";
    cout << "----------------------------------------------------------------------------------\n";
    return 0;
}

