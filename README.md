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
![alt text](https://protosupplies.com/wp-content/uploads/2017/11/7812-Basic-Circuit.jpg)
### 32V to 5V circuit
By using the 7805 voltage regulator 
<br/> Here is the circuit
![alt text](https://github.com/Maashn5/voltageRegulation_turningServoOnOff/blob/main/voltag%20regulation%20circuits/32V%20to%205V.png)
![to simulate this circuit]()
### 32V to 3V circuit
## Servo powering  control
