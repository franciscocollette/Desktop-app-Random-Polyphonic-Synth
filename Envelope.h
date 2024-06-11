#pragma once
#ifndef ENVELOPE_H
#define ENVELOPE_H

#include <cstdint>


class Envelope {
public:
    // Constructor
    Envelope(uint32_t attackSamples, uint32_t decaySamples, double sustainLevel, uint32_t sustainSamples, uint32_t releaseSamples);

    // Destructor
    ~Envelope();

    // Method to get the next envelope value
    double getNextValue();
    void retrigger(uint32_t durationInSamples);

private:
    enum EnvelopeStage { ATTACK, DECAY, SUSTAIN, RELEASE, DONE };

    uint32_t attackSamples_;
    uint32_t decaySamples_;
    double sustainLevel_;
    uint32_t sustainSamples_;
    uint32_t releaseSamples_;


    double currentSample_;
    EnvelopeStage stage_;
};

// declaring Function to create ADSR envelope
Envelope createADSR(double attackTime, double decayTime, double sustainLevel, double sustainTime, double releaseTime, double sampleRate);

#endif // ENVELOPE_H
