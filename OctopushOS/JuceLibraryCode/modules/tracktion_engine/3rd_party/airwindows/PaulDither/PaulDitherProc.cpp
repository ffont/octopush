/* ========================================
 *  PaulDither - PaulDither.h
 *  Copyright (c) 2016 airwindows, All rights reserved
 * ======================================== */

#ifndef __PaulDither_H
#include "PaulDither.h"
#endif

void PaulDither::processReplacing(float **inputs, float **outputs, VstInt32 sampleFrames)
{
    float* in1  =  inputs[0];
    float* in2  =  inputs[1];
    float* out1 = outputs[0];
    float* out2 = outputs[1];

    double currentDitherL;
    double currentDitherR;

    long double inputSampleL;
    long double inputSampleR;

    while (--sampleFrames >= 0)
    {
        inputSampleL = *in1;
        inputSampleR = *in2;
        if (inputSampleL<1.2e-38 && -inputSampleL<1.2e-38) {
            static int noisesource = 0;
            //this declares a variable before anything else is compiled. It won't keep assigning
            //it to 0 for every sample, it's as if the declaration doesn't exist in this context,
            //but it lets me add this denormalization fix in a single place rather than updating
            //it in three different locations. The variable isn't thread-safe but this is only
            //a random seed and we can share it with whatever.
            noisesource = noisesource % 1700021; noisesource++;
            int residue = noisesource * noisesource;
            residue = residue % 170003; residue *= residue;
            residue = residue % 17011; residue *= residue;
            residue = residue % 1709; residue *= residue;
            residue = residue % 173; residue *= residue;
            residue = residue % 17;
            double applyresidue = residue;
            applyresidue *= 0.00000001;
            applyresidue *= 0.00000001;
            inputSampleL = applyresidue;
        }
        if (inputSampleR<1.2e-38 && -inputSampleR<1.2e-38) {
            static int noisesource = 0;
            noisesource = noisesource % 1700021; noisesource++;
            int residue = noisesource * noisesource;
            residue = residue % 170003; residue *= residue;
            residue = residue % 17011; residue *= residue;
            residue = residue % 1709; residue *= residue;
            residue = residue % 173; residue *= residue;
            residue = residue % 17;
            double applyresidue = residue;
            applyresidue *= 0.00000001;
            applyresidue *= 0.00000001;
            inputSampleR = applyresidue;
            //this denormalization routine produces a white noise at -300 dB which the noise
            //shaping will interact with to produce a bipolar output, but the noise is actually
            //all positive. That should stop any variables from going denormal, and the routine
            //only kicks in if digital black is input. As a final touch, if you save to 24-bit
            //the silence will return to being digital black again.
        }

        inputSampleL *= 8388608.0;
        inputSampleR *= 8388608.0;
        //0-1 is now one bit, now we dither

        currentDitherL = (rand()/(double)RAND_MAX);
        currentDitherR = (rand()/(double)RAND_MAX);

        inputSampleL += currentDitherL;
        inputSampleR += currentDitherR;

        inputSampleL -= previousDitherL;
        inputSampleR -= previousDitherR;

        inputSampleL = floor(inputSampleL);
        inputSampleR = floor(inputSampleR);

        previousDitherL = currentDitherL;
        previousDitherR = currentDitherR;

        //Paul Frindle: It's true that the dither itself can sound different
        //if it's given a different freq response and you get to hear it.
        //The one we use most is triangular single pole high pass dither.
        //It not freq bent enough sound odd, but is slightly less audible than
        //flat dither. It can also be easily made by taking one sample of dither
        //away from the previous one - this gives you the triangular PDF and the
        //filtering in one go :-)


        inputSampleL /= 8388608.0;
        inputSampleR /= 8388608.0;

        *out1 = inputSampleL;
        *out2 = inputSampleR;

        *in1++;
        *in2++;
        *out1++;
        *out2++;
    }
}

void PaulDither::processDoubleReplacing(double **inputs, double **outputs, VstInt32 sampleFrames)
{
    double* in1  =  inputs[0];
    double* in2  =  inputs[1];
    double* out1 = outputs[0];
    double* out2 = outputs[1];

    double currentDitherL;
    double currentDitherR;

    long double inputSampleL;
    long double inputSampleR;

    while (--sampleFrames >= 0)
    {
        inputSampleL = *in1;
        inputSampleR = *in2;
        if (inputSampleL<1.2e-38 && -inputSampleL<1.2e-38) {
            static int noisesource = 0;
            //this declares a variable before anything else is compiled. It won't keep assigning
            //it to 0 for every sample, it's as if the declaration doesn't exist in this context,
            //but it lets me add this denormalization fix in a single place rather than updating
            //it in three different locations. The variable isn't thread-safe but this is only
            //a random seed and we can share it with whatever.
            noisesource = noisesource % 1700021; noisesource++;
            int residue = noisesource * noisesource;
            residue = residue % 170003; residue *= residue;
            residue = residue % 17011; residue *= residue;
            residue = residue % 1709; residue *= residue;
            residue = residue % 173; residue *= residue;
            residue = residue % 17;
            double applyresidue = residue;
            applyresidue *= 0.00000001;
            applyresidue *= 0.00000001;
            inputSampleL = applyresidue;
        }
        if (inputSampleR<1.2e-38 && -inputSampleR<1.2e-38) {
            static int noisesource = 0;
            noisesource = noisesource % 1700021; noisesource++;
            int residue = noisesource * noisesource;
            residue = residue % 170003; residue *= residue;
            residue = residue % 17011; residue *= residue;
            residue = residue % 1709; residue *= residue;
            residue = residue % 173; residue *= residue;
            residue = residue % 17;
            double applyresidue = residue;
            applyresidue *= 0.00000001;
            applyresidue *= 0.00000001;
            inputSampleR = applyresidue;
            //this denormalization routine produces a white noise at -300 dB which the noise
            //shaping will interact with to produce a bipolar output, but the noise is actually
            //all positive. That should stop any variables from going denormal, and the routine
            //only kicks in if digital black is input. As a final touch, if you save to 24-bit
            //the silence will return to being digital black again.
        }

        inputSampleL *= 8388608.0;
        inputSampleR *= 8388608.0;
        //0-1 is now one bit, now we dither

        currentDitherL = (rand()/(double)RAND_MAX);
        currentDitherR = (rand()/(double)RAND_MAX);

        inputSampleL += currentDitherL;
        inputSampleR += currentDitherR;

        inputSampleL -= previousDitherL;
        inputSampleR -= previousDitherR;

        inputSampleL = floor(inputSampleL);
        inputSampleR = floor(inputSampleR);

        previousDitherL = currentDitherL;
        previousDitherR = currentDitherR;

        //Paul Frindle: It's true that the dither itself can sound different
        //if it's given a different freq response and you get to hear it.
        //The one we use most is triangular single pole high pass dither.
        //It not freq bent enough sound odd, but is slightly less audible than
        //flat dither. It can also be easily made by taking one sample of dither
        //away from the previous one - this gives you the triangular PDF and the
        //filtering in one go :-)


        inputSampleL /= 8388608.0;
        inputSampleR /= 8388608.0;

        *out1 = inputSampleL;
        *out2 = inputSampleR;

        *in1++;
        *in2++;
        *out1++;
        *out2++;
    }
}
