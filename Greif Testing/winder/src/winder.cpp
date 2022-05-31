

#include "clSpiralIO.h"


#include <chrono>
#include <thread>
#include <cstdio>



int main(int argc, char **argv){

	using namespace std::this_thread;
	using namespace std::chrono;

	clsSpiralIO line1("192.168.101.1");

	int x;
	uint16_t read_holding_regs[1];

	while(x < 50){
			mb.modbus_read_holding_registers(0,2,read_holding_regs);

			if(read_holding_regs[0] > 0){
					x++;
					status.setBeltFeet(x);
			}
			sleep_for(seconds(1));
	}
	return(0);
}

