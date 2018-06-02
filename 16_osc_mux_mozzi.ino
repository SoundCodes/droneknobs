/**
 * This example demonstrates how to read analog signals
 * It assumes there are potentiometers connected
 * to the 16 channels of the 74HC4067 mux/demux
 * 
 * For more about the interface of the library go to
 * https://github.com/pAIgn10/MUX74HC4067
 * 
 *     Analog Inputs: A0-A5, A6 - A11 (on digital pins 4, 6, 8, 9, 10, and 12). 

 */

#include "MUX74HC4067.h"
#include <MozziGuts.h>
#include <Oscil.h>
#include <tables/cos8192_int8.h>
#include <mozzi_midi.h>

// Creates a MUX74HC4067 instance
// 1st argument is the Arduino PIN to which the EN pin connects
// 2nd-5th arguments are the Arduino PINs to which the S0-S3 pins connect
MUX74HC4067 mux(13, 11, 7, 5, 3);
#define CONTROL_RATE 128

// harmonics
Oscil<COS8192_NUM_CELLS, AUDIO_RATE> aCos1(COS8192_DATA);
Oscil<COS8192_NUM_CELLS, AUDIO_RATE> aCos2(COS8192_DATA);
Oscil<COS8192_NUM_CELLS, AUDIO_RATE> aCos3(COS8192_DATA);
Oscil<COS8192_NUM_CELLS, AUDIO_RATE> aCos4(COS8192_DATA);
Oscil<COS8192_NUM_CELLS, AUDIO_RATE> aCos5(COS8192_DATA);
//Oscil<COS8192_NUM_CELLS, AUDIO_RATE> aCos6(COS8192_DATA);
//Oscil<COS8192_NUM_CELLS, AUDIO_RATE> aCos7(COS8192_DATA);
//Oscil<COS8192_NUM_CELLS, AUDIO_RATE> aCos8(COS8192_DATA);
//
//Oscil<COS8192_NUM_CELLS, AUDIO_RATE> aCos9(COS8192_DATA);
//Oscil<COS8192_NUM_CELLS, AUDIO_RATE> aCos10(COS8192_DATA);
//Oscil<COS8192_NUM_CELLS, AUDIO_RATE> aCos11(COS8192_DATA);
//Oscil<COS8192_NUM_CELLS, AUDIO_RATE> aCos12(COS8192_DATA);
//Oscil<COS8192_NUM_CELLS, AUDIO_RATE> aCos13(COS8192_DATA);
//Oscil<COS8192_NUM_CELLS, AUDIO_RATE> aCos14(COS8192_DATA);
//Oscil<COS8192_NUM_CELLS, AUDIO_RATE> aCos15(COS8192_DATA);
//Oscil<COS8192_NUM_CELLS, AUDIO_RATE> aCos16(COS8192_DATA);


// volume controls
Oscil<COS8192_NUM_CELLS, CONTROL_RATE> kVol1(COS8192_DATA);
Oscil<COS8192_NUM_CELLS, CONTROL_RATE> kVol2(COS8192_DATA);
Oscil<COS8192_NUM_CELLS, CONTROL_RATE> kVol3(COS8192_DATA);
Oscil<COS8192_NUM_CELLS, CONTROL_RATE> kVol4(COS8192_DATA);
Oscil<COS8192_NUM_CELLS, CONTROL_RATE> kVol5(COS8192_DATA);
//Oscil<COS8192_NUM_CELLS, CONTROL_RATE> kVol6(COS8192_DATA);
//Oscil<COS8192_NUM_CELLS, CONTROL_RATE> kVol7(COS8192_DATA);
//Oscil<COS8192_NUM_CELLS, CONTROL_RATE> kVol8(COS8192_DATA);
//
//Oscil<COS8192_NUM_CELLS, CONTROL_RATE> kVol9(COS8192_DATA);
//Oscil<COS8192_NUM_CELLS, CONTROL_RATE> kVol10(COS8192_DATA);
//Oscil<COS8192_NUM_CELLS, CONTROL_RATE> kVol11(COS8192_DATA);
//Oscil<COS8192_NUM_CELLS, CONTROL_RATE> kVol12(COS8192_DATA);
//Oscil<COS8192_NUM_CELLS, CONTROL_RATE> kVol13(COS8192_DATA);
//Oscil<COS8192_NUM_CELLS, CONTROL_RATE> kVol14(COS8192_DATA);
//Oscil<COS8192_NUM_CELLS, CONTROL_RATE> kVol15(COS8192_DATA);
//Oscil<COS8192_NUM_CELLS, CONTROL_RATE> kVol16(COS8192_DATA);

// audio volumes updated each control interrupt and reused in audio till next control
char v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12,v13,v14,v15,v16;


void setup()
{
	Serial.begin(9600);  // Initializes serial port
    // Waits for serial port to connect. Needed for Leonardo only
    while ( !Serial ) ;
	
	// Configures how the SIG pin will be interfaced
	// e.g. The SIG pin connects to PIN A0 on the Arduino,
	//      and PIN A0 is a analog input
	mux.signalPin(A0, INPUT, ANALOG);
 
  // set harmonic frequencies
  aCos1.setFreq(mtof(60));
  aCos2.setFreq(mtof(74));
  aCos3.setFreq(mtof(64));
  aCos4.setFreq(mtof(77));
  aCos5.setFreq(mtof(67));
//  aCos6.setFreq(mtof(81));
//  aCos7.setFreq(mtof(60));
//  aCos8.setFreq(mtof(75));
//  aCos9.setFreq(mtof(75));
//  aCos10.setFreq(mtof(72));
//  aCos11.setFreq(mtof(74));
//  aCos12.setFreq(mtof(65));
//  aCos13.setFreq(mtof(55));
//  aCos14.setFreq(mtof(85));
//  aCos15.setFreq(mtof(78));
//  aCos16.setFreq(mtof(64));
//  aCrunchySound.setFreq(100);

// set volume change frequencies
  kVol1.setFreq(4.43f); // more of a pulse
  kVol2.setFreq(0.0245f);
  kVol3.setFreq(0.019f);
  kVol4.setFreq(0.07f);
  kVol5.setFreq(0.047f);
//  kVol6.setFreq(0.031f);
//  kVol7.setFreq(0.0717f);
//  kVol8.setFreq(0.041f);
//  kVol9.setFreq(4.43f); // more of a pulse
//  kVol10.setFreq(0.0245f);
//  kVol11.setFreq(0.019f);
//  kVol12.setFreq(0.07f);
//  kVol13.setFreq(0.047f);
//  kVol14.setFreq(0.031f);
//  kVol15.setFreq(0.0717f);
//  kVol16.setFreq(0.041f);

  v1=v2=v3=v4=v5=127; //=v6=v7=v8=v9=v10=v11=v12=v13=v14=v15=v16
  
  startMozzi(CONTROL_RATE);
 
}

// Reads the 16 channels and reports on the serial monitor
// the corresponding value read by the A/D converter
void loop()
{
	int data;

	for (byte i = 0; i < 5; ++i)
	{
		// Reads from channel i. Returns a value from 0 to 1023
		data = mux.read(i);

//		Serial.print("Potentiometer at channel ");
//		Serial.print(i);
//		Serial.print(" is at ");
//		Serial.print((double)(data));
//		Serial.println("%%");
	}
//	Serial.println();

    audioHook();

//	delay(10);
}

void updateControl(){
   //byte ac80= mux.read(0);
    //aCos8.setFreq(ac80*8);    
    
   aCos1.setFreq((mozziAnalogRead(A1)*8));
   aCos2.next();
  aCos3.next();
  aCos4.next();
  aCos5.next();
//  aCos6.setFreq(mux.read(6)*8);
//  aCos7.setFreq(mux.read(7)*8);
   v1 = mux.read(0)/12; // going at a higher freq, this creates zipper noise, so reduce the gain
   v2 = mux.read(1)/12;
   v3 = mux.read(2)/12;
   v4 = mux.read(3)/12;
   v5 = mux.read(4)/12;
//   v6 = kVol6.next();
//   v7 = kVol7.next();
//   v8 = kVol8.next();

//   Serial.print("sensor_value = ");
//  Serial.println(A0);
}

int updateAudio(){
  long asig = (long)
    aCos1.next()*v1 +
    aCos2.next()*v2 +
    aCos3.next()*v3 +
    aCos4.next()*v4 +
    aCos5.next()*v5 ;
//    aCos6.next()*v6 +
//    aCos7.next()*v7 +
//    aCos8.next()*v8 +
//    aCos9.next()*v9 +
//    aCos10.next()*v10 +
//    aCos11.next()*v11 +
//    aCos12.next()*v12 +
//    aCos13.next()*v13 +
//    aCos14.next()*v14 +
//    aCos15.next()*v15 +
//    aCos16.next()*v16;
  asig >>= 6;
  return (int) asig;
}
