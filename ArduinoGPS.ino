#include<TinyGPSPlus.h>

TinyGPSPlus gps;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial2.begin(9600);
  Serial.println("GPS Start");

}

void loop() {
  while(Serial2.available()){
    gps.encode(Serial2.read());
    if (gps.location.isUpdated()){
      Serial.print("LAT= "); 
      Serial.print(gps.location.lat(), 6);
      Serial.print(" LON= "); 
      Serial.print(gps.location.lng(), 6);
      Serial.print(" ALT= "); 
      Serial.print(gps.altitude.value());
      Serial.print(" DAT= "); 
      Serial.print(gps.date.value());
      Serial.print(" SPD= "); 
      Serial.print(gps.speed.kmph());
      Serial.print(" HDG= "); 
      Serial.print(gps.course.deg());
      Serial.print(" SAT= "); 
      Serial.println(gps.satellites.value());
    }
    /*byte gpsdata = Serial2.read();
    Serial.write(gpsdata);*/
  }

}
