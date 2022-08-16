# voltageRegulation_turningServoOnOff
## Voltage Regulation circuits
Since the robot's main power source is 32V DC battery & there are several electronic boards need different voltage levels
<br/> , so we need a spacific IC called Voltage Regulator
<br/> The voltage regulator IC has various version & specifications , but all of them has 3 pins:
* INPUT pin
* GND pin
* OUTPUT pin
![alt text](https://components101.com/sites/default/files/component_pin/LM7815-IC-Pinout.png)
<br/> All the voltage regulator ICs are connected to a capacitor in the input & the output for 3 reasons :
* The first is to reduce the source impedance
* The seccond is act like a fillter to determines the noises
* The last one is for the stabilty for the output
<br/> & for more protection to the circuit, we will put a diode in series with the input capacitor
<br/> Here is the circuits for 12V,5V,3V
### 32V to 12V circuit
By using the 7812 voltage regulator 
<br/> Here is the circuit
<br/> ![alt text](https://protosupplies.com/wp-content/uploads/2017/11/7812-Basic-Circuit.jpg)
### 32V to 5V circuit
By using the 7805 voltage regulator 
<br/> Here is the circuit
<br/> ![alt text](https://github.com/Maashn5/voltageRegulation_turningServoOnOff/blob/main/voltag%20regulation%20circuits/32V%20to%205V.png)
<br/> [to simulate this circuit](https://www.tinkercad.com/things/laX98gXqM8H?sharecode=nQxdczENGlHFuVGhYSvVBZH5WhjC2RUMfmt_6S-hIGo)
### 32V to 3V circuit
By using the 7803 voltage regulator
<br/> But since tinkercad doesn't support 7803, so we will use LD1117V33 
<br/> LD1117V33 support -250mV to 15V input & get out 3.3 
<br/> Since LD1117V33 doesn't support 32V input , so we need to get down the voltage first by 7805
<br/> Here is the circuit
<br/> ![alt text](https://github.com/Maashn5/voltageRegulation_turningServoOnOff/blob/main/voltag%20regulation%20circuits/32V%20to%203.3V.png)
<br/> [to simulate this circuit](https://www.tinkercad.com/things/lfdQ7V9JM2c?sharecode=Mub9myPmo4xaRgHqd6fGn3wrFfofS_RkBZh2s5yQ234)
## Servo powering control
To control the power for one servo we can connect one of the digital output pin of the arduino to the power pin in the sevo motor
<br/> But for multiple sero motors we can't do the same thing, due to the high current that absorbed by th motors that <br/> the arduino can't handle, thus we must insert an intermidate circuit to control the servo's power
<br/> Let's first write a truth table for our circuit
|arduino signal | Servo status  |
| ------------- |:-------------:| 
| HIGH (1)      | HIGH (1) | 
| LOW (0)       | LOW (0)  |
<br/> From the truth table , this circuit is called Buffer (non-inverting) circuit 
<br/> There are sevral circuit for this purpose, one of the simplest circuit is by using BJT transistor with a resistance like the circut below
<br/> ![alt text](https://github.com/Maashn5/voltageRegulation_turningServoOnOff/blob/main/turn_on_off_servo/BJT%20with%20R%20Buffer%20circuit-schematic.png)
<br/> But one of the major disadvantage is the high power dissipation ,due the resistor & the bjt 
<br/> Second disadvantage is the high output voltage is less than the battery voltage
<br/> Due these disadvantages , we must use another circuit by different components
<br/> One of the most famous & efficient buffer circuit is the CMOS buffer circuit
<br/> Its power dissipation is almost zero & the high output voltage equals the battery voltage & the low output voltage equals zero ,since it uses PMOS & NMOS transistor only.
<br/> The circuit is below
<br/> ![alt text](https://github.com/Maashn5/voltageRegulation_turningServoOnOff/blob/main/turn_on_off_servo/CMOS%20buffer%20circuit-schematic.png)
<br/> [To simulate CMOS buffer circuit](https://www.multisim.com/content/LWUnAxBLKDmTSSk8Fo5zxj/cmos-buffer-circuit/)
<br/> By using the arduino & the push button to turn the servo on off , here is the circuit
<br/> ![alt text](https://github.com/Maashn5/voltageRegulation_turningServoOnOff/blob/main/turn_on_off_servo/CMOS%20buffer%20control%20servo.png)
<br/> Here is the code 
<br/> ``` C++
#include <Servo.h>

int a;//the switich indicator


Servo myServo;
void setup()
{
  pinMode(7, INPUT);
  pinMode(4, OUTPUT);

  myServo.attach(3);
}

void loop()
{
 a=digitalRead(7);//reading the switich value


  

  
  digitalWrite(4,a);// powering the servo by the switich


   if (a==HIGH){// if a is high then move the servo


  myServo.write(90);
  
  }

  
    
    
    
    
    

  
}
```
<br/> [To simulate CMOS buffer control servo power](https://www.tinkercad.com/things/cKn6IufRo5A?sharecode=IBcogcZwUY4ZSpuzyfJ9KExU3EoUowoByBjUf1ZP_E0)
