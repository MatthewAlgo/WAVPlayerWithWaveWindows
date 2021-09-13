#include <SFML/Audio.hpp>
#include <cmath>

#include <random>
#include <iomanip>
#include <iostream>
#include "graphics.h"
#include <SFML/System.hpp>
#include <list>

#include <filesystem>
#include <fstream>
#include <stdio.h>
#include <thread>
#include <chrono>
#include <vector>
#include <ctime>

class Synth {
private:
	std::string* pathtofile{ nullptr };
	std::unique_ptr<std::vector<sf::Int16>> samples{ std::make_unique <std::vector<sf::Int16>>() };
	
	std::list<int> mylist{};
	std::multiset<int> mymultiset{};
	sf::SoundBuffer buffer{};

public:


	//Constructors

	Synth(std::string path) : pathtofile{ new std::string{path} } {
		
		GetSamples();
		
	}
	void GetSamples() {
		buffer.loadFromFile(*pathtofile);
	}
	void StartTheDisco() {
		std::string temporaryuserinput{};
		std::string volume{};

		// std::cout << "Please set the pitch of your samples: " << std::endl;
		std::getline(std::cin, temporaryuserinput);
		std::cout << "\nPlease set the volume of your music: ";
		std::getline(std::cin, volume);
		
		float_t realvolume{ static_cast<float>(std::stoi(volume)) };
		long long pitch{ temporaryuserinput.empty() ? 0 : std::stoi(temporaryuserinput) };


		sf::Music music{};
		music.openFromFile(*pathtofile);
		music.setPitch(static_cast<float>(pitch));
		music.setVolume(realvolume);
		
		music.play();

	}


};

using std::ios;

std::string pathfile;

using functionpointer = const char*(*)(std::string filepath);
const char* path{ "G:\\Songs\\SNG" };

const char* convertpathfromfile(functionpointer func, std::string filepath){
	return func(filepath);
}

void printtostream(std::ostream& outputsteam, std::string message = "Insert your message here") {
	outputsteam << message;
}

void setstring(std::unique_ptr<std::string>& referencedstring, std::istream& input) {
	input >> *referencedstring;
}

long long posamp, negamp;
bool vernegamp = 0, verposamp = 0;
unsigned long long contor = 0;
std::vector <double> yvalues;
std::vector <double> xvalues;
sf::SoundBuffer Buffer;
clock_t t;
std::unique_ptr<std::string> pointertoinsertstring{ std::make_unique<std::string>() };

std::chrono::steady_clock::time_point* begin{ new std::chrono::steady_clock::time_point {} };
std::chrono::steady_clock::time_point* end{ new std::chrono::steady_clock::time_point {} };


__int64* maxamplitude{ new __int64{-1} };
__int64* minamplitude{ new __int64{2000000000LL} };



time_t current_time, beginningtime;
const sf::Int16* samples;
double busyness = 0;//OPTIMAL FOR PC -> 500;
sf::Int16 arrayofadresses[100000000];
//std::vector <sf::Int16> smpls;
sf::Int16 smpls[100000000], valueneg, valuepos;
sf::Int16 inverserawvaluesarray[100000000];
//std::vector <sf::Int16> samples;
int w1, w2, linearfunction, chronowin, scrrlwind;
int trand(double lower, double upper) {
	std::random_device random_device;
	std::mt19937 random_engine(random_device());
	std::uniform_int_distribution<int> distribution_1_1000(lower, upper);

	double randomNumber = distribution_1_1000(random_engine);

	return (int)randomNumber;
}
void fillarrayofadresses(const sf::Int16 array[], long long size) {
	for (unsigned int i = 0; i < size; i += 7) {
		arrayofadresses[i] = array[i];
	}
}
void linearfunctionofentireWAV(unsigned int i) {
	unsigned long long incr = 0;
	unsigned long long scrollpos = 1000 * i / Buffer.getSampleCount();
	setcurrentwindow(linearfunction);
	cleardevice();
	double increment = 1;
	double incrementforvals = Buffer.getSampleCount() / 2000;
	for (unsigned int i = 1; i < Buffer.getSampleCount(); i += incrementforvals) {
		line(incr, samples[i - 1] / 300 + 125, incr + increment, samples[i] / 300 + 125);
		incr += increment;
	}
	//std::cout << std::endl << std::endl << scrollpos << std::endl << std::endl;
	//line(0, 250, 1000, 250);
	//line(0, 325, 1000, 325);
	//setcolor(YELLOW);
	//circle(0, 325, 10);
	//circle(990, 325, 10);
	//line(0, 325, scrollpos, 325);
	//setcolor(RED);
	//circle(scrollpos, 325, 20);
	//setcolor(WHITE);
	setcurrentwindow(w1);
}
void showscrollwind(unsigned long long i) {
	setcurrentwindow(scrrlwind);
	unsigned long long scrollpos = 500 * i / Buffer.getSampleCount();
	setcolor(RED);
	line(0, 50, 500, 50);
	setcolor(YELLOW);
	circle(0, 50, 10);
	circle(490, 50, 10);
	line(0, 50, scrollpos, 50);
	circle(scrollpos, 50, 3);
	setcolor(WHITE);
	setcurrentwindow(w1);
}
void chronowindow(unsigned int i) {
	double idoub = i;
	//char toprint[10];
	setcurrentwindow(chronowin);
	cleardevice();
	current_time = time(NULL);
	//char name[20] = { '0' + seconds / 60,':',seconds % 60 + '0',0 };
	char name[20];
	long long seconds = current_time - beginningtime;
	//std::cout << std::endl << std::endl << seconds << std::endl << std::endl;
	if (seconds % 60 < 10) {
		name[0] = '0' + seconds / 60;
		name[1] = ':';
		name[2] = '0';
		name[3] = seconds % 60 + '0';
		name[4] = 0;
	}
	else {
		name[0] = '0' + seconds / 60;
		name[1] = ':';
		name[2] = seconds % 60 / 10 + '0';
		name[3] = seconds % 60 % 10 + '0';
		name[4] = 0;
	}
	char perc[30];
	short int cntesse = 0;
	int idoub2 = idoub * 100 / Buffer.getSampleCount() * 100;
	int cidoub2 = idoub2;
	while (cidoub2 != 0) {
		cntesse++;
		cidoub2 /= 10;
		//std::cout << std::endl << std::endl << cntesse << std::endl << std::endl;
	}
	switch (cntesse) {
	case 0:
		perc[0] = '0';
		perc[1] = ' ';
		perc[2] = '/';
		perc[3] = ' ';
		perc[4] = '1';
		perc[5] = '0';
		perc[6] = '0';
		perc[7] = 0;
	case 3:
		perc[0] = idoub2 / 100 % 10 + '0';
		perc[1] = ' ';
		perc[2] = '/';
		perc[3] = ' ';
		perc[4] = '1';
		perc[5] = '0';
		perc[6] = '0';
		perc[7] = 0;
	case 4:
		perc[0] = idoub2 / 1000 % 10 + '0';
		perc[1] = idoub2 / 100 % 10 + '0';
		perc[2] = ' ';
		perc[3] = '/';
		perc[4] = ' ';
		perc[5] = '1';
		perc[6] = '0';
		perc[7] = '0';
		perc[8] = 0;
	case 5:
		perc[0] = idoub2 / 10000 % 10 + '0';
		perc[1] = idoub2 / 1000 % 10 + '0';
		perc[2] = idoub2 / 100 % 10 + '0';
		perc[3] = ' ';
		perc[4] = '/';
		perc[5] = ' ';
		perc[6] = '1';
		perc[7] = '0';
		perc[8] = '0';
		perc[9] = 0;
	}
	//std::cout << std::endl << std::endl << seconds << std::endl << std::endl;
	//std::cout << std::endl << std::endl << std::endl << idoub*100/Buffer.getSampleCount() << std::endl << std::endl;
	//std::cout << std::endl << std::endl << std::endl << cntesse << std::endl << std::endl;
	//std::cout << seconds<<std::endl << std::endl << std::endl;
	setcolor(trand(1, 15));
	circle(200, 200, 150);

	setcolor(WHITE);

	settextstyle(1, HORIZ_DIR, 2);
	outtextxy(160, 110, "TIME");

	settextstyle(1, HORIZ_DIR, 2);
	outtextxy(170, 140, name);

	settextstyle(1, HORIZ_DIR, 2);
	outtextxy(90, 250, "PERCENTAGE");

	settextstyle(1, HORIZ_DIR, 2);
	outtextxy(140, 280, perc);
	setcurrentwindow(w1);
}

#define SAMPLESPERVIRTUALFRAME 3000


void printe_secondary(const sf::Int16 array[], long long size) {
	double increment = 1000 / Buffer.getSampleCount();
	//sf::Time delayTime = sf::milliseconds(0.01);
	//LENGTH: 31S
	//2815622
	//10^-5s
	double xvalue = 0;
	for (unsigned long long i = 1; i < size; i += 7) {
		//std::cout << array[i] << " ";
		//i............Buffer.getSampleCount()
		//unkn............100
		line(xvalue, array[i - 1] / 200 + 250, xvalue + increment, array[i] / 200 + 250);
		if (array[i] < negamp && vernegamp == 0) {
			vernegamp = 1;
			valueneg = array[i];
			negamp = valueneg;
			//std::cout << "THE NEW LOWEST AMPLITUDE: " << array[i] << std::endl;
		}
		else if (array[i] > posamp && verposamp == 0) {
			valuepos = array[i];
			posamp = valuepos;
			verposamp = 1;
			//std::cout << "THE NEW HIGHEST AMPLITUDE: " << array[i] << std::endl;
		}
		xvalue += 1;
		if (xvalue == 2000) {
			contor++;
			if (contor % 12 == 0) {
				chronowindow(i);
				//linearfunctionofentireWAV(i);
				showscrollwind(i);
				if (vernegamp == true) {
					std::cout << "THE NEW LOWEST AMPLITUDE: " << valueneg << std::endl;
					vernegamp = 0;
				}
				if (verposamp == true) {
					std::cout << "THE NEW HIGHEST AMPLITUDE: " << valuepos << std::endl;
					verposamp = 0;
				}
				std::cerr << "CURRENT MEMORY ACCESS FOR Y: " << &samples[i] << std::endl;
			}
			xvalue = 0;
			cleardevice();
		}
		while (busyness != 18000) { //17000PC
			busyness += 1;
			//busyness = 0;
		}
		busyness = 0;
		//sf::sleep(sf::microseconds(0));
	}
}
void printe(const sf::Int16 array[], long long size) {
	double increment = 1000 / Buffer.getSampleCount();
	//sf::Time delayTime = sf::milliseconds(0.01);
	//LENGTH: 31S
	//2815622
	//10^-5s
	auto duration = *end - *begin;
	double xvalue = 0;

	while (std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() < Buffer.getDuration().asMilliseconds()) {
		//std::cout << array[i] << " ";
		*end = std::chrono::high_resolution_clock::now();
		duration = *end - *begin;
		long long ms = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
		long long* currentmillis{ new long long {static_cast<long long>(std::chrono::duration_cast<std::chrono::milliseconds>(duration).count())} };
		long long* currentsamplestobeshownto{ new long long{*currentmillis * static_cast<long long>(Buffer.getSampleCount()) /
			static_cast<long long>(Buffer.getDuration().asMilliseconds())} };
		//std::cout << "\n" << " MILLIS: " << *currentmillis << " SAMPLES: " << *currentsamplestobeshownto << " TOTAL MILLIS:  " << static_cast<long long>(Buffer.getDuration().asMilliseconds()) <<
		//	"SAMPLE COUNT: " << static_cast<long long>(Buffer.getSampleCount()) << "\n";
		///line(xvalue, array[i - 1] / 100 + 500, xvalue + increment, array[i] / 100 + 500);
		for (long long* i{ new long long {static_cast<long long>(*currentsamplestobeshownto) - SAMPLESPERVIRTUALFRAME} }; *i < *currentsamplestobeshownto; *i = *i + 1) {
			if (*i >= 0 && *i <= Buffer.getSampleCount()) {
				line(*i - (static_cast<long long>(*currentsamplestobeshownto) - SAMPLESPERVIRTUALFRAME) < 0 ? 0 : *i - (static_cast<long long>(*currentsamplestobeshownto) - SAMPLESPERVIRTUALFRAME), array[*i] / 200 + 250, *i - (static_cast<long long>(*currentsamplestobeshownto) - SAMPLESPERVIRTUALFRAME) + increment,
					array[*i + 1] / 200 + 250);
				if (array[*i] < *minamplitude) {
					*minamplitude = array[*i];
					std::cout << "\nNEW LOWEST AMPLITUDE: " << *minamplitude << " POINTER TO: " << &array[*i] << "\n";
				}
				if (array[*i] > * maxamplitude) {
					*maxamplitude = array[*i];
					std::cout << "\nNEW HIGHEST AMPLITUDE: " << *maxamplitude << " POINTER TO: " << &array[*i] << "\n";
				}
				//std::cout << *i << " ";
			}
		}
		chronowindow(*currentsamplestobeshownto);
		showscrollwind(*currentsamplestobeshownto);
		cleardevice();
		//sf::sleep(sf::microseconds(0));
	}
#define INCREMENTRATE Buffer.getSampleCount()/2000
	unsigned long long* iterator{ new unsigned long long{0} };
	for (long long* i{ new long long{0} }; *i <= 2000; *i += 1) {
		if (*iterator + Buffer.getSampleCount() / 2000 < Buffer.getSampleCount() && *iterator >= 0)
			line(*i, array[*iterator] / 200 + 250, *i + 1, array[*iterator + Buffer.getSampleCount() / 2000] / 200 + 250);
		*iterator += Buffer.getSampleCount() / 2000;
	}
	std::cout << "MIN AMPLITUDE: " << *minamplitude << "\n" << "MAX AMPLITUDE: " << *maxamplitude << "\nPROGRAM END";
}



sf::Int16* Arraypointer(sf::Int16 array[]) {
	return array;
}
void inverserawvalues(const sf::Int16 array[], long long size) {
	sf::Int16 inverserawvaluesarray[100000000];
	for (unsigned int i = 0; i < Buffer.getSampleCount(); i++) {
		inverserawvaluesarray[i] = -array[i];
	}
}

void print(void (*functionpointer)(std::ostream& out, std::string message),std::string outputted) {
	functionpointer(std::cout, outputted);
}
void SHOWINITS() {
	std::cout << "____MUSIC PLAYER AND VISUALISER MADE BY MATT (V1.0)____" << std::endl;
	std::cout << "NUMBER OF CHANNELS: " << Buffer.getChannelCount() << std::endl;
	std::cout << "BUFFER DURATION: "<< Buffer.getDuration().asSeconds()<<std::endl;
	std::cout << "NUMBER OF SAMPLES: " << Buffer.getSampleCount() << std::endl;
	std::cout << "BUFFER SAMPLE RATE: " << Buffer.getSampleRate() << std::endl;

	auto lambda{ [](std::ostream& out, std::string message = "Output something") {
		out << message;
	} };
	print(lambda, "PLEASE INSERT THE FULL PATH OF YOUR AUDIO FILE\n\n");
	setstring(pointertoinsertstring, std::cin);

}
sf::Sound loadsound(std::string filename) {
	sf::SoundBuffer buff;
	buff.loadFromFile(filename);
	return sf::Sound(buff);
}
void printadressesinconsole() {

	double increment = 1000 / Buffer.getSampleCount();
	//LENGTH: 31S
	//2815622
	//10^-5s
	double xvalue = 0;
	for (unsigned int i = 1; i < Buffer.getSampleCount(); i += 7) {
	
		std::cout << &samples[i] << " ";
		
	}
}

void outputtofile(std::fstream* filetooutput) {

	*filetooutput << "THIS IS A TEST!";
}

int main() {

	SHOWINITS();
	chronowin = initwindow(400, 400, "CHRONO");
	w1 = initwindow(650, 500, "GRAPH VIEWER");
	linearfunction = initwindow(1000, 250, "ENTIRE WAV AT A GLANCE");
	scrrlwind = initwindow(500, 100, "SCROLL");
	setcurrentwindow(w1);
	settextstyle(1, HORIZ_DIR, 2);
	outtextxy(120, 200, "GRAPH VIEWER");
	setcurrentwindow(linearfunction);
	settextstyle(1, HORIZ_DIR, 2);
	outtextxy(300, 125, "ENTIRE WAV AT A GLANCE");

	const unsigned SAMPLES = 44100;
	const unsigned SAMPLE_RATE = 44100;
	const unsigned AMPLITUDE = 20000;

	sf::Int16 raw[SAMPLES];

	const double TWO_PI = 6.28318;
	const double increment = 440. / 44100;
	double x = 0;
	for (unsigned i = 0; i < SAMPLES; i++) {
		raw[i] = AMPLITUDE * sin(x * TWO_PI);
		x += increment;
		yvalues.push_back(raw[i] / 200 + 250);
		
	}
	
	for (double i = 0; i <= 10000; i += 0.1) {
		xvalues.push_back(i);
	}
	Synth MYSYNTH{ *pointertoinsertstring };
	MYSYNTH.StartTheDisco();

	
	if (!Buffer.loadFromFile(*pointertoinsertstring)){
		std::cout << "LOADING FAILED";
	}
	else {
		samples = Buffer.getSamples();
		showscrollwind(0);
		
		cleardevice();
		linearfunctionofentireWAV(0);
		beginningtime = time(NULL);

		chronowindow(0);
		
		std::cout << "SAMPLES: " << samples << " " << std::endl;
		std::cout << "SAMPLE COUNT: " << Buffer.getSampleCount() << " " << std::endl;
		std::cout << "SECOND ARRAY POINTER: " << Arraypointer(inverserawvaluesarray) << " " << std::endl;

		sf::Sound Sound;
		Sound.setBuffer(Buffer);
		
		Sound.play();
		*begin = std::chrono::high_resolution_clock::now();
		t = clock();
		
		printe(samples, Buffer.getSampleCount());
	}
	std::cin.get();
	getch();
	return 0;
}

