# 1 "c:\\IOT\\nodemcu\\dht\\app.ino"
# 2 "c:\\IOT\\nodemcu\\dht\\app.ino" 2
# 3 "c:\\IOT\\nodemcu\\dht\\app.ino" 2
# 4 "c:\\IOT\\nodemcu\\dht\\app.ino" 2

const char *ssid = "Multicampus_9999";
const char *password = "multi123";
const char *mqtt_server = "192.168.0.9";

MqttCom com;
DHT dht11(D6, DHT11);

void publish() {
    char msg[50];
    float fh, fc;

    fh = dht11.readHumidity(); // 습도 측정
    fc = dht11.readTemperature(); // 섭씨 온도 측정

    if (isnan(fh) || isnan(fc)) { // 측정 실패시에는 출력없이 리턴
        Serial.println("DHT11 read failed!!");
        return;
    }

    com.publish("iot/livingroom/temp", fc);
    com.publish("iot/livingroom/humi", fh);
}

void setup() {
    com.init(ssid, password);
    com.setServer(mqtt_server, 
# 30 "c:\\IOT\\nodemcu\\dht\\app.ino" 3 4
                              __null
# 30 "c:\\IOT\\nodemcu\\dht\\app.ino"
                                  , 
# 30 "c:\\IOT\\nodemcu\\dht\\app.ino" 3 4
                                    __null
# 30 "c:\\IOT\\nodemcu\\dht\\app.ino"
                                        );
    com.setInterval(2000, publish);
    dht11.begin();
}

void loop() {
    com.run();
}
