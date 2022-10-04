#include <Adafruit_Sensor.h> //instalar a biblioteca “Adafruit Unified Sensor”
#include <DHT.h> //instalar a biblioteca "DHT"

#define DHTTYPE DHT22
const int DHT_PIN = 15; //Mudar a pinagem se necessario
DHT dht(DHT_PIN, DHTTYPE);

String readDHTTemperature() {
  float t = dht.readTemperature();
  if (isnan(t)) {    
    Serial.println("Falha ao ler o sensor DHT!");
    return "--";
  }
  else {
    Serial.println(t);
    return String(t);
  }
}

String readDHTHumidity() {
  float h = dht.readHumidity();
  if (isnan(h)) {
    Serial.println("Falha ao ler o sensor DHT!");
    return "--";
  }
  else {
    Serial.println(h);
    return String(h);
  }
}

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  readDHTTemperature();
  readDHTHumidity();
  Serial.println("---");
  delay(1000);
}
//////////////////////////////////////////////////////////

// #include <SimpleDHT.h> //Instalar biblioteca SimpleDHT.h
//const int DHT_PIN = 15;

// SimpleDHT22 dht;

// uint32_t lastTimeRead = 0;
// #define INTERVAL 5000;
// typedef struct{
//   float temperature, humidity;
// }Sensor;

// Sensor sensor;
// Sensor readSensor()
// {
//   float t, h;
//   //Coloca o valor lido da temperatura em t e da umidade em h
//   int status = dht.read2(DHT_PIN, &t, &h, NULL);
 
//   //Se a leitura foi bem sucedida
//   if (status == SimpleDHTErrSuccess) {
//     //Os valores foram lidos corretamente, então é seguro colocar nas variáveis
//     sensor.temperature = t;
//     sensor.humidity = h;
//   }

//   return sensor;
// }

// void setup() {
//   Serial.begin(115200);
// }

// void loop() {
//     unsigned long now = millis();

//   //Se passou o intervalo desde a última leitura
//   if((now - lastTimeRead) > 5000){
//     //Faz a leitura do sensor
//     readSensor();
//     Serial.println("Temp: " + String(sensor.temperature, 2) + "°C");
//     Serial.println("Humidity: " + String(sensor.humidity, 1) + "%");
//     //Marca quando ocorreu a última leitura
//     lastTimeRead = now;
//   }
// }
/////////////////////////////////////////////

// #include "DHTesp.h" //Instalar DHTesp

// const int DHT_PIN = 15;

// DHTesp dhtSensor;

// void setup() {
//   Serial.begin(115200);
//   dhtSensor.setup(DHT_PIN, DHTesp::DHT22);
// }

// void loop() {
//   TempAndHumidity  data = dhtSensor.getTempAndHumidity();
//   Serial.println("Temp: " + String(data.temperature, 2) + "°C");
//   Serial.println("Humidity: " + String(data.humidity, 1) + "%");
//   Serial.println("---");
//   delay(1000);
// }