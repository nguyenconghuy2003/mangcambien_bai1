#include <Arduino.h>
#include <Wire.h>
#include <BH1750.h>

// Khai báo đối tượng BH1750
BH1750 lightMeter;

void setup() {
    Serial.begin(115200);
    Wire.begin(D2, D1); // SDA = D2, SCL = D1
    if (lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE)) {
        Serial.println("Cảm biến BH1750 đã khởi động thành công!");
    } else {
        Serial.println("Lỗi! Không thể khởi động cảm biến BH1750.");
    }
}

void loop() {
    float lux = lightMeter.readLightLevel();
    Serial.print("Cường độ ánh sáng: ");
    Serial.print(lux);
    Serial.println(" lx");

    delay(1000); // Đọc mỗi giây
}