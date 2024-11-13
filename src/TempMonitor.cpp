#include "TempMonitor.h"

// Construtor da classe TempMonitor
TempMonitor::TempMonitor() : recordIndex(0) {}

// Função de setup (inicialização)
void TempMonitor::setup() {
    pinMode(SENSOR_PIN, INPUT);
    inicializarSerial();
    Serial.println("Iniciando sistema de monitoramento de temperatura...");
}

// Função principal de loop
void TempMonitor::loop() {
    float valorSensor = lerSensor();
    if (valorSensor < 0) {
        tratarErroSensor();
        return;
    }

    float temperaturaC = calcularTemperaturaC(valorSensor);
    float temperaturaF = calcularTemperaturaF(temperaturaC);
    armazenarDados(temperaturaC, temperaturaF);
    enviarDadosIoT();
    exibirBancoDados();
    delay(DELAY_TIME);
}

// Função para inicializar a comunicação serial
void TempMonitor::inicializarSerial() {
    Serial.begin(9600);
}

// Função para ler o valor do sensor de temperatura
float TempMonitor::lerSensor() {
    int valor = analogRead(SENSOR_PIN);
    if (valor < 0 || valor > RESOLUTION) {
        return -1; // Valor inválido
    }
    return valor;
}

// Função para calcular a temperatura em Celsius
float TempMonitor::calcularTemperaturaC(float valorSensor) {
    float voltage = valorSensor * (VOLTAGE_REF / RESOLUTION);
    return (voltage - SENSOR_OFFSET) * CONVERSION_FACTOR;
}

// Função para calcular a temperatura em Fahrenheit
float TempMonitor::calcularTemperaturaF(float temperaturaC) {
    return (temperaturaC * 1.8) + 32;
}

// Função para armazenar os dados no pseudo banco de dados
void TempMonitor::armazenarDados(float temperaturaC, float temperaturaF) {
    tempDB[recordIndex].temperaturaC = temperaturaC;
    tempDB[recordIndex].temperaturaF = temperaturaF;
    tempDB[recordIndex].timestamp = millis();
    recordIndex = (recordIndex + 1) % MAX_RECORDS;
}

// Função para simular o envio dos dados para um servidor IoT
void TempMonitor::enviarDadosIoT() {
    Serial.print("Enviando dados para o servidor IoT (simulado)... ");
    Serial.print("Temperatura (°C): ");
    Serial.print(tempDB[recordIndex].temperaturaC);
    Serial.print(", Temperatura (°F): ");
    Serial.print(tempDB[recordIndex].temperaturaF);
    Serial.print(", Timestamp: ");
    Serial.println(tempDB[recordIndex].timestamp);
}

// Função para exibir o conteúdo completo do pseudo banco de dados
void TempMonitor::exibirBancoDados() {
    Serial.println("Exibindo banco de dados simulado:");
    for (int i = 0; i < MAX_RECORDS; i++) {
        Serial.print("Registro ");
        Serial.print(i + 1);
        Serial.print(" - Celsius: ");
        Serial.print(tempDB[i].temperaturaC);
        Serial.print(", Fahrenheit: ");
        Serial.print(tempDB[i].temperaturaF);
        Serial.print(", Timestamp: ");
        Serial.println(tempDB[i].timestamp);
    }
}

// Função para tratar erros de leitura do sensor
void TempMonitor::tratarErroSensor() {
    Serial.println("Erro na leitura do sensor. Verifique a conexão e o funcionamento do sensor.");
}
