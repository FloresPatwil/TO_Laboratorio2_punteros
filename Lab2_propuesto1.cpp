#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class AnalizadorOperacion {
public:
    static bool esOperacionValida(char op) {
        return (op == '+' || op == '-' || op == '*' || op == '/');
    }
};

class AdministradorOperacion {
public:
    static double realizarOperacion(double num1, double num2, char op) {
        double resultado = 0.0;
        switch (op) {
            case '+':
                resultado = num1 + num2;
                break;
            case '-':
                resultado = num2 - num1;
                break;
            case '*':
                resultado = num1 * num2;
                break;
            case '/':
                if (num2 != 0)
                    resultado = num1 / num2;
                else {
                    cout << "Error: División por cero no está permitida." << endl;
                    return 0.0;
                }
                break;
        }
        return resultado;
    }
};

class ProcesadorCalculadora {
public:
    static double calcular(const string& input) {
        stringstream ss(input);
        double resultado = 0.0;
        char ultimoOperador = '+';
        while (!ss.eof()) {
            double numero;
            char op;
            ss >> numero >> op;
            if (AnalizadorOperacion::esOperacionValida(op)) {
                if (ultimoOperador == '*' || ultimoOperador == '/') {
                    resultado = AdministradorOperacion::realizarOperacion(resultado, numero, ultimoOperador);
                } else {
                    resultado = AdministradorOperacion::realizarOperacion(numero, resultado, ultimoOperador);
                }
                ultimoOperador = op;
            } else {
                cout << "Operador inválido: " << op << endl;
                return 0.0;
            }
        }
        return resultado;
    }
};
int main() {
    while (true)
    {
        string input;
        cout << "Ingrese la operacion matematica: ";
        getline(cin, input);
        double resultado = ProcesadorCalculadora::calcular(input);
        cout << "El resultado es: " << resultado << endl;
    }
    return 0;
}
