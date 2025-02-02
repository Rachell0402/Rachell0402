#include <iostream>
#include <string>

using namespace std;

// Clase base Vehiculo
class Vehiculo {
protected:
    string marca;
    string modelo;
    int anio; // Cambié 'año' a 'anio' para evitar posibles conflictos

public:
    // Constructor de la clase base
    Vehiculo(string marca, string modelo, int anio) {
        this->marca = marca;
        this->modelo = modelo;
        this->anio = anio;
    }

    // Método para mostrar la información del vehículo
    virtual void mostrarInfo() {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Año: " << anio << endl; // Mostramos el 'anio' en lugar de 'año'
    }

    // Método para arrancar el vehículo (genérico)
    virtual void arrancar() {
        cout << "El vehículo está arrancando." << endl;
    }
};

// Clase derivada Coche
class Coche : public Vehiculo {
private:
    int numPuertas;

public:
    // Constructor del Coche
    Coche(string marca, string modelo, int anio, int numPuertas)
        : Vehiculo(marca, modelo, anio) {
        this->numPuertas = numPuertas;
    }

    // Método para mostrar la información del coche
    void mostrarInfo() override {
        Vehiculo::mostrarInfo();
        cout << "Número de puertas: " << numPuertas << endl;
    }

    // Método para arrancar el coche
    void arrancar() override {
        cout << "El coche " << modelo << " está arrancando." << endl;
    }
};

// Clase derivada Moto
class Moto : public Vehiculo {
private:
    bool tieneCasco;

public:
    // Constructor de la Moto
    Moto(string marca, string modelo, int anio, bool tieneCasco)
        : Vehiculo(marca, modelo, anio) {
        this->tieneCasco = tieneCasco;
    }

    // Método para mostrar la información de la moto
    void mostrarInfo() override {
        Vehiculo::mostrarInfo();
        cout << "¿Tiene casco incluido? " << (tieneCasco ? "Sí" : "No") << endl;
    }

    // Método para arrancar la moto
    void arrancar() override {
        cout << "La moto " << modelo << " está arrancando." << endl;
    }
};

// Clase derivada Camion
class Camion : public Vehiculo {
private:
    float capacidadCarga;

public:
    // Constructor del Camión
    Camion(string marca, string modelo, int anio, float capacidadCarga)
        : Vehiculo(marca, modelo, anio) {
        this->capacidadCarga = capacidadCarga;
    }

    // Método para mostrar la información del camión
    void mostrarInfo() override {
        Vehiculo::mostrarInfo();
        cout << "Capacidad de carga: " << capacidadCarga << " toneladas" << endl;
    }

    // Método para arrancar el camión
    void arrancar() override {
        cout << "El camión " << modelo << " está arrancando." << endl;
    }
};

// Programa principal
int main() {
    // Crear objetos de las clases derivadas
    Coche coche("Toyota", "Corolla", 2020, 4);
    Moto moto("Yamaha", "YZF-R1", 2023, true);
    Camion camion("Mercedes", "Actros", 2018, 15.5);

    // Mostrar información y arrancar vehículos
    cout << "Información del Coche:" << endl;
    coche.mostrarInfo();
    coche.arrancar();
    cout << endl;

    cout << "Información de la Moto:" << endl;
    moto.mostrarInfo();
    moto.arrancar();
    cout << endl;

    cout << "Información del Camión:" << endl;
    camion.mostrarInfo();
    camion.arrancar();
    cout << endl;

    return 0;
}
