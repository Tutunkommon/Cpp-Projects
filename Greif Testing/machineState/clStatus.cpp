
#include "modbuspp/modbus.h"

#include <cstdio>



class clStatus{	

	private:
		int state;
		int speed;
		int beltFeet;

	public:
		int setState(int newState){
			//  TO DO:  Report new state
			return(0);
		};

		int setSpeed(int newSpeed){
			// TO DO:  Update machine speed
			return(0);
		};

		int setBeltFeet(int newBeltFeet){
		
			// TO DO:  Update current belt feet reporting
			beltFeet = newBeltFeet;
			printf("%d \n",newBeltFeet);
			
			return(0);
		};

};


int main(int argc, char **argv){
	modbus mb = modbus("192.168.0.1", 502);
	clStatus status;

	mb.modbus_set_slave_id(1);
	mb.modbus_connect();

	int x;
	uint16_t read_holding_regs[1];

	while(x < 50){
		mb.modbus_read_holding_registers(1,1,read_holding_regs);
		printf("%d \t %d \n",read_holding_regs[0],read_holding_regs[1]);

		if((read_holding_regs[0] > 0) || (read_holding_regs[1] > 0)){
			x++;
			status.setBeltFeet(x);
		}
	}
	return(0);
}
