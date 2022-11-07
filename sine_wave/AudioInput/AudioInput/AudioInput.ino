
#include <MozziGuts.h>
#include <Arduino.h>

//#define USE_AUDIO_INPUT true

void setup()
{
  Serial.begin(115200);
  Serial.print("num_analog_inputs = ");
  Serial.print(NUM_ANALOG_INPUTS);
  startMozzi();
}

void updateControl()
{
  for (int i = 1; i < NUM_ANALOG_INPUTS; i++)
  { // analog 0 is configured for audio
    Serial.print(mozziAnalogRead(i));
    Serial.print("\t");
  }

  Serial.println();
}

AudioOutput_t updateAudio()
{
  int asig = getAudioInput(); // range 0 to 1023
  asig = asig - 512;          // now range is -512 to 512
  return MonoOutput::fromAlmostNBit(9, asig).clip();
}

void loop()
{
  audioHook();
}
