#include "pch.h"
#include "processEverything.h"
using namespace System::Windows::Forms;
std::string waveName = "sine";  //standard value to waveName
int LenghtInSeconds = 1;

//  D:\\maynooth\\music system progr 2\\csound and libsndfile\\archivaso.wav   --like this should be passed full path
void processEverything(const char* outputFileName) {
	SF_INFO sfinfoOut;
	SNDFILE* outfile;
    sfinfoOut.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;
    sfinfoOut.channels = 2;
    sfinfoOut.samplerate = 44100;
   //  Open the output file
    outfile = sf_open(outputFileName, SFM_WRITE, &sfinfoOut);
    if (!outfile) {
        MessageBox::Show("couldnt open file, try again!");
        sf_close(outfile);
        return;
    }

    double tab[tableSize];   // declaring a tab with the same size from tables.h
    Table tab1(waveName);         //creating a table object with the wave we want to generate 
    tab1.generate(tab);     //generating the wave and filling the tab with it

    std::vector<double> buff1(64);               // this is a vector<> (a dinamic array) 
    std::vector<double> buff2(64);
    std::vector<double> buff3(64);
    std::vector<double> buff4(64);
    std::vector<double> buffMix(64);        // initialize buffMix with the size of a buffer (osc.vsize)

    std::vector<std::vector<double>*> buffFixedList = { &buff1, &buff2, &buff3, &buff4 };
    buffersInOrder = { &buff1, &buff2, &buff3, &buff4 };   //fill the pointer list with the actual buffers, this list will vary its order 
    std::vector<double>* availableBuff;
    Osc* selectedOsc = nullptr;
    int currentBuff = 0;

    double freq1 = 440;
    double freq2 = 523.25;
    double freq3 = 220 * 1.5;
    double freq4 = 220;
    Osc osc1(0.5, freq1, tab, tableSize);
    Osc osc2(0.5, freq2, tab, tableSize);
    Osc osc3(0.5, freq3, tab, tableSize);
    Osc osc4(0.5, freq4, tab, tableSize);
    std::list<Osc*> oscList = { &osc1, &osc2, &osc3, &osc4 };

    double attackTime = 0.7;
    double decayTime = 0.2;
    double sustainLevel = 0.5; //  sustain level (0 to 1)
    double releaseTime = 0.3;
    double sustainTime = 0.8;
    double sampleRate = 44100;

    Envelope adsr1 = createADSR(attackTime, decayTime, sustainLevel, sustainTime, releaseTime, sampleRate);
    Envelope adsr2 = createADSR(attackTime, decayTime, sustainLevel, sustainTime, releaseTime, sampleRate);
    Envelope adsr3 = createADSR(attackTime, decayTime, sustainLevel, sustainTime, releaseTime, sampleRate);
    Envelope adsr4 = createADSR(attackTime, decayTime, sustainLevel, sustainTime, releaseTime, sampleRate);
    std::list<Envelope*> adsrList = { &adsr1, &adsr2, &adsr3, &adsr4 };

    NewNote newNote;
    newNote.process();
    bool trigerNewNote = false;
    double newNoteProbability = 1;     // probability of 1 new note per second
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0, 88200);   // Create a uniform distribution for generating random numbers


    for (int i = 0; i < osc1.sr * 2 * LenghtInSeconds ; i += osc1.vsize) {    // this is buffer processing, (each osc.vsize is a buffer)



        buff1 = osc1.process(0.2, freq1);
        buff2 = osc2.process(0.2, freq2);
        buff3 = osc3.process(0.2, freq3);
        buff4 = osc4.process(0.2, freq4);

        for (int j = 0; j < osc1.vsize; ++j) {    // this is single sample processing 
            for (int adsr = 0; adsr < adsrList.size(); adsr++) {
                double envelopeValue = (*(std::next(adsrList.begin(), adsr)))->getNextValue(); // the same maybe as : (*adsrList.begin()+adsr)->getNextValue(); asign envelopeValue to adsr1, adsr2, etc,
                (*buffFixedList[adsr])[j] *= envelopeValue;  // we assign envelopeValue to each sample in each buff
            }

            if (trigerNewNote == true) {
                availableBuff = selectAvailableBuff(buffersInOrder); // this returns a pointer
                newNote.process();
                if (availableBuff == &buff1) { adsr1.retrigger(newNote.durationInSamples); freq1 = newNote.freq; }
                if (availableBuff == &buff2) { adsr2.retrigger(newNote.durationInSamples); freq2 = newNote.freq; }
                if (availableBuff == &buff3) { adsr3.retrigger(newNote.durationInSamples); freq3 = newNote.freq; }
                if (availableBuff == &buff4) { adsr4.retrigger(newNote.durationInSamples); freq4 = newNote.freq; }
                trigerNewNote = false;
                break;
            }

            double randomValue = dis(gen); // Generate random number
            if (randomValue < newNoteProbability) {
             
                trigerNewNote = true;
            }


            buffMix[j] = buff1[j] + buff2[j] + buff3[j] + buff4[j];


        }


        sf_write_double(outfile, buffMix.data(), osc1.vsize);   //out.data() function pass a pointer instead of the array

    }

    sf_close(outfile);
    MessageBox::Show("file created succesfully in the path indicated!");


}

System::String^ testFunction() {
    System::String^ variable = "hoooola";
    return variable;
}