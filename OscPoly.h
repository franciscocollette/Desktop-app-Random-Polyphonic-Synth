
//this is referenced mostly from Victor's Lazzarini library "Aulib" - https://github.com/aulib/aulib


#ifndef __OSCMIO_H__
#define __OSCMIO_H__

#include <cmath>
#include <sndfile.h>
#include <vector>


struct Osc {

    double fr;
    double amp;
    const double* table;
    unsigned int size;
    double ph;
    std::vector<double> s;      //we can use vector instead of a  double* s to avoid free memory, 
    // vector is a dynamic array that automatic manages the memory
    unsigned int vsize;
    double sr;

    Osc(double a, double f, const double* t, unsigned int sz,
        double phs = 0., unsigned int vsz = 64,
        double esr = 44100.) :
        amp(a), fr(f), table(t), size(sz), ph(phs),
        s(vsz), vsize(vsz), sr(esr) { };

    ~Osc() {
        // No need for explicit memory deallocation for std::vector
    }

    std::vector<double> process(double a, double f) {
        double incr = size * f / sr;
        amp = a; fr = f;
        for (int i = 0; i < vsize; i++) {
            s[i] = amp * table[(int)ph];
            ph += incr;
            while (ph >= size) ph -= size;
            while (ph < 0) ph += size;
        }
        return s;
    }                            // this function will return an array of 64 samples (by default) 
                                  // this 64 values are taken from the values of the table. 

    std::vector<double> process(double a) {
        amp = a;
        return process(amp, fr);
    }                             // just a version only taking the amplitud

    std::vector<double> process() {
        return process(amp, fr);
    }                            // just a version only taking amplitud and frequency

    std::vector<double> process(const double* a, double f) {
        double incr = size * f / sr;
        f = fr;
        for (int i = 0; i < vsize; i++) {
            s[i] = a[i] * table[(int)ph];
            ph += incr;
            while (ph >= size) ph -= size;
            while (ph < 0) ph += size;
        }
        return s;
    }                                      //  same but, but it allows the user to pass an array of amplitudes
                                            //rather than a single amplitude value,
                                        // and it will return 64 values but using different amp each sample

    std::vector<double> process(const double* a) {
        return process(a, fr);
    }
    std::vector<double> process(const double* a, const double* f) {
        for (int i = 0; i < vsize; i++) {
            s[i] = a[i] * table[(int)ph];
            ph += size * f[i] / sr;
            while (ph >= size) ph -= size;
            while (ph < 0) ph += size;
        }
        return s;
    }

    std::vector<double> process(double a, double* f) {
        amp = a;
        for (int i = 0; i < vsize; i++) {
            s[i] = amp * table[(int)ph];
            ph += size * f[i] / sr;
            while (ph >= size) ph -= size;
            while (ph < 0) ph += size;
        }
        return s;
    }

};
#endif
