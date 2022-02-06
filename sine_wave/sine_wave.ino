#include <MozziGuts.h>
#include <Oscil.h>               // Oscillator template
#include <tables/sin2048_int8.h> // sine table for oscillator

Oscil<SIN2048_NUM_CELLS, AUDIO_RATE> aSin(SIN2048_DATA);

// use #define for CONTROL_RATE, not a constant
#define CONTROL_RATE 64 // Hz, powers of 2 are most reliable

void setup()
{
  startMozzi(CONTROL_RATE);
  aSin.setFreq(440);
}

void updateControl()
{
}

AudioOutput_t updateAudio() {
  return Mono
}

void loop()
{
}
