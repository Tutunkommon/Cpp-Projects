
#include "modbuspp/modbus.h"
#include "clSpiralIO.h"


#include <chrono>
#include <thread>
#include <cstdio>



int main(int argc, char **argv){

        using namespace std::this_thread;
        using namespace std::chrono;

        modbus mb = modbus("192.168.101.5", 502);
        clStatus status;

        mb.modbus_set_slave_id(1);
        mb.modbus_connect();

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

