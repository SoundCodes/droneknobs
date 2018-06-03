# droneknobs
#### Knobs that make Drone

Its a Synth made during [KYTA 2017](https://issuu.com/shazeb/docs/kyta_2017_catalog) at Kalga as part of Residency for a new [notional experimental quadrophonic audio environment](https://sound.codes/works/kyta-karma-quad/) in the Himalayas. 
![droneknobs](https://i.imgur.com/QMfgMAg.jpg)

The facility will be open to experimental sound artists from the summer of 2018 as a making,  listening and hacking space. 
Check the making and the story behind this on [youtube](https://www.youtube.com/watch?v=MHGiTG6djZ0)



Modified slightly the code by Tim Barrass using Mozzi library


This built demonstrates analog inputs from 16 channel multiplexer «CD74HC4067» and control oscillators, phase modulation and smoothing a control signal at audio rate. Also demonstrates AutoMap, which maps unpredictable inputs to a set range.
 
  ## The circuit:
     Leonardo: 
     Audio output on digital pin 9 (on a Uno, Leonardo and Nano), or 
     Potentiometers on A1 A2 A3 A4 A5 A6 A7 A8 A10 A11 on Leonardo
     MUX74HC4067:
     EN pin connects to 13
     S0 » 11, S1 » 7, S2 » 5, S3 » 3
     Potentiometers on 0-9
 
###### Dependencies 
[Mozzi](http://sensorium.github.com/Mozzi/)
[CD74HC4067](https://github.com/pAIgn10/MUX74HC4067)



This Panel of Knobs enables oscillators and the control modulation. 

     Cosine wave table is used and the freq range is 8hz to 8184hz
     While the control-modulation is 0 - 127

Use this Code in Various permutation changing the analog input for oscillators and control modulators.
3 Nano + Mux, 3 Leonardo + 2 Mux and One Uno along is being used in the Panel.

Only One Leonardo is sufficient for the design with Mux used as input for mux and get all the potentiometers into one Leonardo. Doing that was making the control oscillations clicky and buggy as ATmega32u4 is not able to process 50+ simultaneous oscillators.
