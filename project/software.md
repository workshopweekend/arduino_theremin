We will build the code in 3 stages.
1.	Light one LED with the distance sensor
2.	Light all LEDs at different distances from the sensor
3.	Add the pieze tone code to get music!


Light One LED with the distance sensor

1. Copy this code and paste it in a new Arduino sketch. <%= arduino_theremin_one_led.ino =%>
2. Ensure the pin numbers assigned in the code are the same as the ones on your connections on the breadboard.
3. Verify your code and Upload the code into the Arduino. 
4. You should see one LED light up, when your hand is between 4cm and 25 cm of the distance sensor. It should go off, at all other distances.

Light ALL LEDs with the distance sensor

We will extend the step above for all the connected LEDs. The code will look something like this. <%= arduino_theremin_all_leds.ino =%>
This code lights up the LEDs like a bar graph. More LEDs are lit, the farther your hand is from the sensor.

Add the Piezo

Now we will add sound to the project, with the piezo buzzer code. The tone definitions go at the top of the file. The code to play the tone is inserted with the LED code. Here is the reference. <%= arduino_theremin_final.ino =%>

