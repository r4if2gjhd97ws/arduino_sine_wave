#include <Arduino.h>
#include <MozziGuts.h>
#include <Oscil.h>
#include <tables/sin2048_int8.h>

Oscil<SIN2048_NUM_CELLS, AUDIO_RATE> asin(SIN2048_DATA);

void setup()
{
  // put your setup code here, to run once:
}

void loop()
{
  // put your main code here, to run repeatedly:
}