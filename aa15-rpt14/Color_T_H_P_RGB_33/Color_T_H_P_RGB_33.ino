#include <Arduino_LSM9DS1.h> //Include the library for 9-axis IMU

void setup(){
  Serial.begin(9600); //Serial monitor to display all sensor values 

  if (!IMU.begin()) //Initialize IMU sensor 
  { Serial.println("Failed to initialize IMU!"); while (1);}


float accel_x, accel_y, accel_z;
float gyro_x, gyro_y, gyro_z;
float mag_x, mag_y, mag_z;

void loop()
{
  //Accelerometer values 
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(accel_x, accel_y, accel_z);
  }
  //Gyroscope values 
  if (IMU.gyroscopeAvailable()) {
    IMU.readGyroscope(gyro_x, gyro_y, gyro_z);
  }
  //Magnetometer values 
  if (IMU.magneticFieldAvailable()) {
    IMU.readMagneticField(mag_x, mag_y, mag_z);
  }
  Serial.print("AA16,");
  Serial.print(accel_x,1);
  Serial.print(",");
  Serial.print(accel_y,1); 
  Serial.print(",");
  Serial.print(accel_z,1);
  Serial.print(",");
  Serial.print(gyro_x,1);
  Serial.print(",");
  Serial.print(gyro_y,1); 
  Serial.print(",");
  Serial.print(gyro_z,1);
  Serial.print(",");
  Serial.print(mag_x,1);
  Serial.print(",");
  Serial.print(mag_y,1); 
  Serial.print(",");
  Serial.println(mag_z,1);

  delay(1500);
}
