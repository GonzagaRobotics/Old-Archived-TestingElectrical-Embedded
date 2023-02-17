//Author Ryan Leahy
//Date 02/16/2023
//Platform ESP32 PICO V4

//Add the following from the arduino library manager (How I did it) or the platformio library manager
//Adafruit LSI3MDL
//Adafruit Adafruit LSM6DS
//TinyGPSPlus
//SensorFusion (Make sure to install version 1.04 to avoid a weird bug)

//For the LSM6DSL (Gyroscope)
#include <Adafruit_ISM330DHCX.h>
#include <Adafruit_LSM6DS.h>
#include <Adafruit_LSM6DS3.h>
#include <Adafruit_LSM6DS33.h>
#include <Adafruit_LSM6DS3TRC.h>
#include <Adafruit_LSM6DSL.h>
#include <Adafruit_LSM6DSO32.h>
#include <Adafruit_LSM6DSOX.h>

//For the LIS3MDL (Magnetometer)
#include <Adafruit_LIS3MDL.h>

//For decoding NMEA 0183 data being sent back from the GPS module on UART1
#include <TinyGPS++.h>

//For the I2C bus for the Gyroscope and Magnetometer
#include <Wire.h>

//For combining acceleration, gyroscope, and magnetometer data into roll pitch yaw
#include <SensorFusion.h>

//To understand where the gps/imu module header maps to: https://maker.pro/storage/g9KLAxU/g9KLAxUiJb9e4Zp1xcxrMhbCDyc3QWPdSunYAoew.png
//Pin 1-10 are mapped the same way as the gps/imu module.
//But for time saving I'll also write it out here using the wire colors I had attached to the unit on 02/16/2023
//RED    - 3.3V
//BROWN  - SDA
//BLACK  - SCL
//WHITE  - GPIO4 of PI (Just plug it into a pin you won't use and leave it floating)
//GRAY   - GND
//ORANGE - 5V
//YELLOW - 5V
//GREEN  - GND
//BLUE   - TX on UART 1
//PURPLE - RX on UART 1 

TinyGPSPlus gps;
int RX1 = 9; //Purple wire (GPIO9)
int TX1 = 10; //Blue wire (GPIO10)

Adafruit_LSM6DSL gyroscope;
Adafruit_LIS3MDL magnetometer;

//Fusion Library variables
SF fusion;
float gx, gy, gz;
float ax, ay, az;
float mx, my, mz;
float deltat;
float pitch, roll, yaw;

void setup() {
  Wire.setPins(SDA, SCL); //SDA GPIO21, SCL GPIO22
  Serial.begin(115200); //UART0 - Used to provide feedback to computer
  Serial1.begin(9600, SERIAL_8N1, RX1, TX1); //UART1 - Used to communicate with GPS and receive NMEA 0183 messages back (these get parsed by tinygps)

  if(!gyroscope.begin_I2C())
  {
    Serial.println("LSM6DSL(Gyroscope) is not detected on I2C bus, check wiring and address");
    while(1);
  }

  if(!magnetometer.begin_I2C())
  {
    Serial.println("LSI3MDL(Magnetometer) is not detected on I2C bus, check wiring and address");
    while(1);
  }
}

void loop() {
  sensors_event_t accel_event, gyro_event, temp_event, magnet_event; //adafruit library function that holds I2C responses

  //Make I2C request for acceleration, gyroscope, and temperature data
  //Temp data is currently not being used as of 02/16/2023
  gyroscope.getEvent(&accel_event, &gyro_event, &temp_event);
  
  //Write out the data into variables to make the madgwickUpdate call not terribly long
  gx = gyro_event.gyro.x; gy = gyro_event.gyro.y; gz = gyro_event.gyro.z;
  ax = accel_event.acceleration.x; ay = accel_event.acceleration.y; az = accel_event.acceleration.z;
  
  magnetometer.getEvent(&magnet_event);

  mx = magnet_event.magnetic.x; my = magnet_event.magnetic.y; mz = magnet_event.magnetic.z;

  deltat = fusion.deltatUpdate(); //no clue what this does but it's necessary apparently

  //applies the madgwick algorithm to fuse all these pieces of data together to create a quarterion.
  //We can pull the needed data from the quarterion to get heading.
  fusion.MadgwickUpdate(gx, gy, gz, ax, ay, az, mx, my, mz, deltat);
  pitch = fusion.getPitch(); roll = fusion.getRoll(); yaw = fusion.getYaw();

  //This loops through the UART1 interface to grab all the GPS data
  while(Serial1.available() > 0)
  {
    //parses the gps data from the UART1 interface
    if(gps.encode(Serial1.read()))
    {
      //Makes sure the GPS data has a lock so that its returning actual data
      if(gps.location.isValid())
      {
        Serial.print("Lat: ");
        Serial.print(gps.location.lat(), 10);
        Serial.print(" Long: ");
        Serial.println(gps.location.lng(), 10);
      }
      else
        Serial.println("No gps signal");

      //Put the IMU print statements here simply to slow down how often they print.
      //GPS was being overshadowed by the imu.
      Serial.print("Pitch: ");
      Serial.print(pitch);
      Serial.print(" Roll: ");
      Serial.print(roll);
      Serial.print(" Yaw: ");
      Serial.println(yaw);
    }
  }
}
