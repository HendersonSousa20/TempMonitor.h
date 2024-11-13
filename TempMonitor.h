#ifndef TEMPMONITOR_H
#define TEMPMONITOR_H

#include <Arduino.h>

// Constantes globais
#define SENSOR_PIN A0
#define VOLTAGE_REF 5.0
#define RESOLUTION 1024
#define SENSOR_OFFSET 0.5
#define CONVERSION_FACTOR 100.0
#define MAX_RECORDS 10
#define DELAY_TIME 20000

// Estrutura para armazenar dados de temperatura
struct TempData {
    float temperaturaC;
    float temperaturaF;
    unsigned long timestamp;
};

class TempMonitor {
public:
    TempMonitor();
    void setup();
    void loop();
    float lerSensor();
    float calcularTemperaturaC(float valorSensor);
    float calcularTemperaturaF(float temperaturaC);
    void armazenarDados(float temperaturaC, float temperaturaF);
    void enviarDadosIoT();
    void exibirBancoDados();

private:
    TempData tempDB[MAX_RECORDS];
    int recordIndex;
    void inicializarSerial();
    void tratarErroSensor();
};

#endif
