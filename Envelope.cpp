#include "pch.h"
#include "Envelope.h"
#include <cmath>
#include <iostream>

Envelope::Envelope(uint32_t attackSamples, uint32_t decaySamples, double sustainLevel, uint32_t sustainSamples, uint32_t releaseSamples)
    : attackSamples_(attackSamples), decaySamples_(decaySamples), sustainLevel_(sustainLevel), sustainSamples_(sustainSamples), releaseSamples_(releaseSamples),
    currentSample_(0), stage_(ATTACK) {}

Envelope::~Envelope() {}

double Envelope::getNextValue() {
    switch (stage_) {
    case ATTACK:
        if (currentSample_ < attackSamples_) {
            //     if (currentSample_ == 0) { currentSample_++; return 0.0; } // this is to see if I can get rid of the click in each triggering
            currentSample_++;
            return currentSample_ / static_cast<double>(attackSamples_);
        }
        else {
            stage_ = DECAY;
            currentSample_ = 0;
            return 1.0; // End of attack phase
        }
    case DECAY:
        if (currentSample_ < decaySamples_) {
            currentSample_++;
            return 1.0 - ((1.0 - sustainLevel_) * (currentSample_ / static_cast<double>(decaySamples_)));
        }
        else {
            stage_ = SUSTAIN;
            currentSample_ = 0;
            return sustainLevel_; // End of decay phase
        }
    case SUSTAIN:
        if (currentSample_ < sustainSamples_) {
            currentSample_++;
            return sustainLevel_; // Sustain level
        }
        else {
            stage_ = RELEASE;
            currentSample_ = 0;
            return sustainLevel_;  //end of the sustain
        }
    case RELEASE:
        if (currentSample_ < releaseSamples_) {
            currentSample_++;
            return sustainLevel_ * (1.0 - (currentSample_ / static_cast<double>(releaseSamples_)));
        }
        else {
            stage_ = DONE;
            return 0.0; // End of release phase
        }
    case DONE:
        return 0.0; // Envelope finished
    }
}

void Envelope::retrigger(uint32_t durationInSamples) {
    sustainSamples_ = durationInSamples;
    currentSample_ = 0;
    stage_ = ATTACK;
    std::cout << "retriggering envelope" << "with a duration of " << durationInSamples << "samples" << std::endl;
}


// defining Function to create ADSR envelope
Envelope createADSR(double attackTime, double decayTime, double sustainLevel, double sustainTime, double releaseTime, double sampleRate) {
    // Calculate envelope durations in samples
    uint32_t attackSamples = static_cast<uint32_t>(attackTime * sampleRate * 2);
    uint32_t decaySamples = static_cast<uint32_t>(decayTime * sampleRate * 2);
    uint32_t sustainSamples = static_cast<uint32_t>(sustainTime * sampleRate * 2);
    uint32_t releaseSamples = static_cast<uint32_t>(releaseTime * sampleRate * 2);

    // Create ADSR envelope object
    Envelope envelope(attackSamples, decaySamples, sustainLevel, sustainSamples, releaseSamples);
    return envelope;
}

