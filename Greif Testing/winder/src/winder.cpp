

#include "modbus.h"
#include "clsSpiralIO.h"

#include <chrono>
#include <thread>
#include <cstdio>
#include <iostream>

using namespace std;


int main(int argc, char **argv){

	using namespace std::this_thread;
	using namespace std::chrono;

	clsSpiralIO line1;

	int x;
	uint16_t read_holding_regs[1];


	cout << line1.getEstopState();


	return(0);
}

