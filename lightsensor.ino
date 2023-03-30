// Bevan Fairleigh
// 

// This #include statement was automatically added by the Particle IDE.
#include <BH1750.h>

// This #include statement was automatically added by the Particle IDE.
// #include <ThingSpeak.h>


// Define our instance of the BH1750 light meter
BH1750 lightMeter;



void setup()
{

    // Open the I2C channel, and turn the sensor on to read light levels
    lightMeter.begin();
    lightMeter.switch_power_on();

}




void loop()
{
    // Poll the BH1750 to get current light level in lux
    float lux = lightMeter.get_light_level();
    String lux_string = String(lux);
    
    // Publish to our webhook
    Particle.publish("LightSensor", lux_string, PRIVATE);
    
    delay(30000);
    
}
