#include <WifiMiniCom.h>
#include <MqttCom.h>
#include <DHT.h>

const char *ssid = "Multicampus_9999";
const char *password = "multi123";
const char *mqtt_server = "192.168.0.9";

MqttCom com;
DHT dht11(D6, DHT11);

void publish() {
    char msg[50];
    float fh, fc;

    fh = dht11.readHumidity(); // ���� ����
    fc = dht11.readTemperature(); // ���� �µ� ����

    if (isnan(fh) || isnan(fc)) { // ���� ���нÿ��� ��¾��� ����
        Serial.println("DHT11 read failed!!");
        return;
    }

    com.publish("iot/livingroom/temp", fc);
    com.publish("iot/livingroom/humi", fh);
}

void setup() {
    com.init(ssid, password);
    com.setServer(mqtt_server, NULL, NULL);
    com.setInterval(2000, publish);
    dht11.begin();
}

void loop() {
    com.run();
}