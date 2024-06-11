#pragma once
#pragma once
#ifndef __OSC_H__
#define __OSC_H__

#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <cmath>

const double M_PI = 3.14159265358979323846;
const unsigned int tableSize = 10000;
const double twopi = 8. * atan(1.);   // value of pi *2 
struct Table {

public:
    std::string waveType;

    Table(const std::string& a) : waveType(a) { };
    ~Table() {}

    void generate(double tab[tableSize]) {
        if (waveType == "sine") {
            for (int i = 0; i < tableSize; i++)
                tab[i] = sin(i * twopi / tableSize);  // fill the table with sine values
        }
        else if (waveType == "triangle") {
            // Fill the table with triangle wave values using Fourier series
            for (int i = 0; i < tableSize; i++) {
                double t = i * twopi / tableSize;
                tab[i] = 0.0;
                for (int n = 1; n <= 100; n += 2) { // Odd harmonics only for triangle wave
                    tab[i] += (1.0 / (n * n)) * sin(n * t); // Add nth harmonic
                }
                tab[i] *= 8.0 / (M_PI * M_PI); // Scale to have a peak-to-peak amplitude of 1
            }
        }
        else if (waveType == "square") {
            // Fill the table with square wave values using Fourier series
            for (int i = 0; i < tableSize; i++) {
                double t = i * twopi / tableSize;
                tab[i] = 0.0;
                for (int n = 1; n <= 60; n += 2) { // Increase number of harmonics for square wave
                    double amplitude = 1.0 / n; // Adjust amplitude as needed
                    tab[i] += amplitude * sin(n * t); // Add nth harmonic
                }
                // tab[i] *= 4.0 / M_PI; // Scale to have a peak-to-peak amplitude of 1
            }
        }
        else if (waveType == "sawtooth") {
            // Fill the table with sawtooth wave values using Fourier series
            for (int i = 0; i < tableSize; i++) {
                double t = i * twopi / tableSize;
                tab[i] = 0.0;
                for (int n = 1; n <= 50; n++) { // Using all harmonics for sawtooth wave
                    double amplitude = 1.0 / n; // Adjust amplitude as needed
                    tab[i] += amplitude * sin(n * t); // Add nth harmonic
                }
                tab[i] *= 2.0 / M_PI; // Scale to have a peak-to-peak amplitude of 1
            }
        }

        else {
            // Default behavior if waveType is not recognized
            std::cerr << "Unknown waveType: " << waveType << std::endl;
        }
    }
};

#endif