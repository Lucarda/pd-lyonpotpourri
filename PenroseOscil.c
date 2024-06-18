#include <math.h>
#include "PenroseOscil.h"


t_float frequencyToIncrement( t_float samplingRate, t_float frequency, int bufferLength ) {
  return (frequency / samplingRate) * (t_float) bufferLength;
}

void makeSineBuffer( t_float *buffer, int bufferLength ) {
  int   i;
  t_float myTwoPi = 8. * atan(1.);

  for ( i=0; i <= bufferLength; i++ )
    *(buffer+i) = sin( myTwoPi * ((t_float) i / (t_float) bufferLength) );

  return;
}


t_float bufferOscil( t_float *phase, t_float increment, t_float *buffer,
                   int bufferLength )
{
  t_float sample;

  while ( *phase > bufferLength )
    *phase -= bufferLength;

  while ( *phase < 0. )
    *phase += bufferLength;

  sample = *( buffer + (int) (*phase) );

  *phase += increment;

  return sample;
}
