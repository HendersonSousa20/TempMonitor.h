### TempMonitor Library

Welcome to the **TempMonitor** library! This library is designed to facilitate the monitoring of temperature using analog sensors connected to a microcontroller, such as an Arduino. It provides a complete solution for reading, processing, storing, and displaying temperature data, as well as simulating the sending of this data to an IoT server.

### Biblioteca TempMonitor

Bem-vindo à biblioteca **TempMonitor**! Esta biblioteca foi desenvolvida para facilitar o monitoramento de temperatura utilizando sensores analógicos conectados a um microcontrolador, como o Arduino. Ela oferece uma solução completa para leitura, processamento, armazenamento e exibição de dados de temperatura, além de simular o envio desses dados para um servidor IoT.

#### Features / Funcionalidades

- **Sensor Reading / Leitura de Sensor**: Reads analog values from a temperature sensor connected to a specified pin. / Lê valores analógicos de um sensor de temperatura conectado a um pino especificado.
- **Temperature Calculation / Cálculo de Temperatura**: Converts the sensor values to temperatures in Celsius and Fahrenheit. / Converte os valores lidos do sensor para temperaturas em Celsius e Fahrenheit.
- **Data Storage / Armazenamento de Dados**: Stores temperature data in a simulated database with a capacity of up to 10 records. / Armazena dados de temperatura em um banco de dados simulado com capacidade para até 10 registros.
- **Simulated IoT Sending / Envio Simulado para IoT**: Simulates sending temperature data to an IoT server, displaying the data on the serial monitor. / Simula o envio dos dados de temperatura para um servidor IoT, exibindo os dados no monitor serial.
- **Data Display / Exibição de Dados**: Displays all stored records in the simulated database on the serial monitor. / Exibe todos os registros armazenados no banco de dados simulado no monitor serial.

#### Installation / Instalação

1. Download the TempMonitor library files (`TempMonitor.h` and `TempMonitor.cpp`). / Baixe os arquivos da biblioteca TempMonitor (`TempMonitor.h` e `TempMonitor.cpp`).
2. Place the files in a folder named `TempMonitor` inside your Arduino libraries directory. / Coloque os arquivos em uma pasta chamada `TempMonitor` dentro do diretório de bibliotecas do Arduino.
3. Include the library in your Arduino sketch using `#include "TempMonitor.h"`. / Inclua a biblioteca no seu sketch do Arduino usando `#include "TempMonitor.h"`.

#### Usage / Uso

Here is an example of how to use the TempMonitor library in your Arduino sketch: / Aqui está um exemplo de como usar a biblioteca TempMonitor no seu sketch do Arduino:

```cpp
#include "TempMonitor.h"

TempMonitor tempMonitor;

void setup() {
    tempMonitor.setup();
}

void loop() {
    tempMonitor.loop();
}
```

#### API Reference / Referência da API

##### Class: TempMonitor / Classe: TempMonitor

- **TempMonitor()**: Constructor for the TempMonitor class. / Construtor da classe TempMonitor.
- **void setup()**: Initializes the sensor and serial communication. / Inicializa o sensor e a comunicação serial.
- **void loop()**: Main loop function that reads the sensor, calculates temperatures, stores data, simulates sending data to IoT, and displays data. / Função principal de loop que lê o sensor, calcula as temperaturas, armazena os dados, simula o envio dos dados para IoT e exibe os dados.
- **float lerSensor()**: Reads the value from the temperature sensor. / Lê o valor do sensor de temperatura.
- **float calcularTemperaturaC(float valorSensor)**: Calculates the temperature in Celsius from the sensor value. / Calcula a temperatura em Celsius a partir do valor do sensor.
- **float calcularTemperaturaF(float temperaturaC)**: Converts the temperature from Celsius to Fahrenheit. / Converte a temperatura de Celsius para Fahrenheit.
- **void armazenarDados(float temperaturaC, float temperaturaF)**: Stores the temperature data in the simulated database. / Armazena os dados de temperatura no banco de dados simulado.
- **void enviarDadosIoT()**: Simulates sending the temperature data to an IoT server. / Simula o envio dos dados de temperatura para um servidor IoT.
- **void exibirBancoDados()**: Displays the contents of the simulated database. / Exibe o conteúdo do banco de dados simulado.
- **void inicializarSerial()**: Initializes serial communication. / Inicializa a comunicação serial.
- **void tratarErroSensor()**: Handles sensor reading errors. / Trata erros de leitura do sensor.

#### Example Code / Código de Exemplo

```cpp
#include "TempMonitor.h"

TempMonitor tempMonitor;

void setup() {
    tempMonitor.setup();
}

void loop() {
    tempMonitor.loop();
}
```

#### Detailed Description / Descrição Detalhada

The **TempMonitor** library is designed to simplify the process of monitoring temperature using analog sensors. It provides a modular and easy-to-use interface for reading sensor data, calculating temperatures, storing data, and simulating the sending of data to an IoT server. The library is structured to be robust and maintainable, with clear separation of concerns and error handling. / A biblioteca **TempMonitor** foi desenvolvida para simplificar o processo de monitoramento de temperatura utilizando sensores analógicos. Ela oferece uma interface modular e fácil de usar para leitura de dados do sensor, cálculo de temperaturas, armazenamento de dados e simulação de envio de dados para um servidor IoT. A biblioteca é estruturada para ser robusta e de fácil manutenção, com clara separação de responsabilidades e tratamento de erros.

##### Constants / Constantes

- **SENSOR_PIN**: The analog pin to which the temperature sensor is connected. / O pino analógico ao qual o sensor de temperatura está conectado.
- **VOLTAGE_REF**: The reference voltage of the Arduino (in Volts). / A tensão de referência do Arduino (em Volts).
- **RESOLUTION**: The resolution of the ADC (10 bits). / A resolução do ADC (10 bits).
- **SENSOR_OFFSET**: The offset of the sensor (in Volts). / O offset do sensor (em Volts).
- **CONVERSION_FACTOR**: The conversion factor of the sensor (10mV/°C). / O fator de conversão do sensor (10mV/°C).
- **MAX_RECORDS**: The maximum capacity of the simulated database. / A capacidade máxima do banco de dados simulado.
- **DELAY_TIME**: The interval between readings (in milliseconds). / O intervalo entre as leituras (em milissegundos).

##### Data Structure / Estrutura de Dados

- **TempData**: A structure to store temperature data, including temperature in Celsius and Fahrenheit, and a timestamp. / Uma estrutura para armazenar dados de temperatura, incluindo temperatura em Celsius e Fahrenheit, e um timestamp.

##### Methods / Métodos

- **setup()**: Initializes the sensor pin and serial communication, and prints a startup message. / Inicializa o pino do sensor e a comunicação serial, e imprime uma mensagem de inicialização.
- **loop()**: The main loop function that performs the following steps: / A função principal de loop que executa os seguintes passos:
  1. Reads the sensor value. / Lê o valor do sensor.
  2. Calculates the temperature in Celsius and Fahrenheit. / Calcula a temperatura em Celsius e Fahrenheit.
  3. Stores the temperature data in the simulated database. / Armazena os dados de temperatura no banco de dados simulado.
  4. Simulates sending the data to an IoT server. / Simula o envio dos dados para um servidor IoT.
  5. Displays the contents of the simulated database. / Exibe o conteúdo do banco de dados simulado.
  6. Waits for a specified delay time before repeating the process. / Aguarda um tempo de atraso especificado antes de repetir o processo.
- **lerSensor()**: Reads the analog value from the temperature sensor and returns it. If the value is invalid, it returns -1. / Lê o valor analógico do sensor de temperatura e o retorna. Se o valor for inválido, retorna -1.
- **calcularTemperaturaC(float valorSensor)**: Converts the sensor value to voltage and calculates the temperature in Celsius. / Converte o valor do sensor para tensão e calcula a temperatura em Celsius.
- **calcularTemperaturaF(float temperaturaC)**: Converts the temperature from Celsius to Fahrenheit
- **calcularTemperaturaF(float temperaturaC)**: Converts the temperature from Celsius to Fahrenheit. / Converte a temperatura de Celsius para Fahrenheit.
- **armazenarDados(float temperaturaC, float temperaturaF)**: Stores the temperature data in the simulated database, updating the index in a circular manner. / Armazena os dados de temperatura no banco de dados simulado, atualizando o índice de forma circular.
- **enviarDadosIoT()**: Simulates sending the temperature data to an IoT server by printing the data to the serial monitor. / Simula o envio dos dados de temperatura para um servidor IoT, imprimindo os dados no monitor serial.
- **exibirBancoDados()**: Displays all records in the simulated database on the serial monitor. / Exibe todos os registros no banco de dados simulado no monitor serial.
- **inicializarSerial()**: Initializes serial communication at a baud rate of 9600. / Inicializa a comunicação serial a uma taxa de 9600 baud.
- **tratarErroSensor()**: Prints an error message to the serial monitor if the sensor reading is invalid. / Imprime uma mensagem de erro no monitor serial se a leitura do sensor for inválida.

 #### License / Licença
 
This library is open-source and available under the MIT License. Feel free to use, modify, and distribute it as needed. / Esta biblioteca é de código aberto e está disponível sob a licença MIT. 
Sinta-se à vontade para usar, modificar e distribuir conforme necessário. 

#### Contributions / Contribuições

Contributions are welcome! If you have any suggestions, improvements, or bug fixes, please submit a pull request or open an issue on the GitHub repository. / Contribuições são bem-vindas! Se você tiver sugestões, melhorias ou correções de bugs, envie um pull request ou abra uma issue no repositório GitHub.
