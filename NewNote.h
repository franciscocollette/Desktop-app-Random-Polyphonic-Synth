#pragma once
#include<iostream>; 
#include <random>;

class NewNote {
private:
	int bpm = 120;
	double sampleRate = 44100;  //has to be the same as the osc and main 
public:
	double freq = 0;
	double durationInSamples = 0;

	NewNote() {}  //constructor  // no need for destructor.... ?

	void process() {
		double freqArray[8] = { 440., 523.25, 587.33, 659.25, 783.99, 880., 1045.5, 1108.73 };
		// Seed the random number generator

		std::random_device rd1;
		std::mt19937 gen1(rd1());
		std::uniform_int_distribution<int> dist1(0, 7); // Uniform distribution for indices 0 to 7
		// Generate a random index
		int randomIndex = dist1(gen1);
		freq = freqArray[randomIndex];


		// i should make something like: little duration in notes means more probability of newNote
		double samples16th = 60 * sampleRate / bpm * 2 * 0.25;
		double samples8th = 60 * sampleRate / bpm * 2 * 0.5;
		double samplesQuarter = 60 * sampleRate / bpm * 2;
		double samplesQuarterAndHalf = 60 * sampleRate / bpm * 2 * 1.5;

		double durationArray[4] = { samples16th,samples8th,samplesQuarter,samplesQuarterAndHalf };
		std::random_device rd2;
		std::mt19937 gen2(rd2());
		std::uniform_int_distribution<int> dist2(0, 3);
		int randomIndex2 = dist2(gen2);
		durationInSamples = durationArray[randomIndex2];
	}

};