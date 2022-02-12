#include <MozziGuts.h>
#include <Oscil.h>
#include <tables/sin2048_int8.h>
#include <Smooth.h>


// output 25

// increase the rate of updateControl from the default of 50, to catch the piezo's rapid transieats
#define CONTROL_RATE 150

const int PIEZO_PIN = 4; // analog input for the piezo + connection. - connection to ground

Oscil<SIN2048_NUM_CELLS, AUDIO_RATE> aSin(SIN2048_DATA);

void setup()
{
  Serial.begin(115200);
  startMozzi(CONTROL_RATE);
}

void updateControl()
{
  // read the piezo
  int piezo_value = mozziAnalogRead(PIEZO_PIN); // value is 0-1023

  // print the value to the Serial monitor for debugging
  Serial.print("piezo_value = ");
  Serial.print(piezo_value);
  Serial.print("\t \t"); // tab

  int frequency = piezo_value * 3; // calibrate
  Serial.print("frequency = ");
  Serial.print(frequency);

  aSin.setFreq(frequency);

  Serial.println(); // next line
}

AudioOutput_t updateAudio()
{
  return MonoOutput::from8Bit(aSin.next());
}

void loop()
{
  audioHook();
}
