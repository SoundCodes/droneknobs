# droneknobs
Knobs that make Drone


Modified slightly the code Tim Barrass using Mozzi library

 This Demonstrates using analog inputs from 16 channel multiplexer «CD74HC4067» control oscillators, phase modulation
 and smoothing a control signal at audio rate to avoid clicks.
 Also demonstrates AutoMap, which maps unpredictable inputs to a set range.
 
  The circuit:
     Audio output on digital pin 9 (on a Uno, Leonardo and Nano), or 
     Potentiometers on 0-9 on 4067b Mux
     Potentiometers on A1 A2 A3 A4 A5 A6 A7 A8 A10 A11 on Leonardo
     check the README or http://sensorium.github.com/Mozzi/
     
 * It assumes there are potentiometers connected to the 10 Channels of the 74HC4067 mux/demux and having the Signal pin Connected to A0  while the other pings as per the Library example and having the https://github.com/pAIgn10/MUX74HC4067 library installed
 * 
 * For more about the interface of the library go to
 * https://github.com/pAIgn10/MUX74HC4067

This Panel of Knobs enables osscilators and the control modultaion. 

Cosine wave table is used and the freq rage is 8hz to 8184hz
While the controlmodulation is 0 - 127
