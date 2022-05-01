// This #include statement was automatically added by the Particle IDE.
#include <PietteTech_DHT.h>

#define DHTTYPE  DHT11    
#define DHTPIN   D7


PietteTech_DHT DHT(DHTPIN, DHTTYPE);

void setup() {

    Particle.process();
    delay(1000);
    DHT.begin();
    
}

void loop() {
     //get the status.
    int status = DHT.acquireAndWait(1000);
    //get the tempuerature by Celsius.
    String temp = String(DHT.getCelsius());
    Particle.publish("temp3", temp, PRIVATE);
    delay(10000);
}