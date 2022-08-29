#include <WifiMiniCom.h>
#include <DHT.h>

DHT dht(D6, DHT11);
WifiMiniCom com;

const char *ssid = "Multicampus_9999";
const char *password = "multi123";


void check() {
    float humi = dht.readHumidity();
    float temp = dht.readTemperature();

    com.print(1, "H:", humi, "T:", temp);
}

void setup() {
    com.init(ssid, password);
    com.setInterval(2000, check);
    dht.begin();
}

void loop() {
    com.run();
}