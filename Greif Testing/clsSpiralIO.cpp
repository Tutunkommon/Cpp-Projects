
#ifndef modbus
#define modbus
#include "modbuspp/modbus.h"
#endif



class clsSpiralIO{

	private:
		unsigned short reg412289;
		unsigned short reg412290;
		unsigned short dummySpeedLo;
		unsigned short dummySpeedHi;
		unsigned short currentSpeedLo;
		unsigned short currentSpeedHi;
		unsigned short totalCountLo;
		unsigned short totalCountHi;

		modbus mb;



	public:

		bool  :  restartEnable;			//412289.10
		bool  :  bottomBypass;			//412289.11
		bool  :  estopOK;				//412289.12
		bool  :  resetCount;			//412289.13
		bool  :  FPMDummy;				//412289.14
		bool  :  jogFestoonFWD;			//412290.0
		bool  :  jogFestoonREV;			//412290.1
		bool  :  jogHarpFWD;			//412290.2
		bool  :  jogHarpREV;			//412290.3
		bool  :  jogOpen;				//412290.4
		bool  :  jogClose;				//412290.5
		long  :  totalCount;			//412291.LONG
		long  :  speed;					//412293.LONG
		long  :  dummySpeed;			//412295.LONG
		bool  :  supressEncoder;		//400001.4
		bool  :  markerAirTaylorsFull;	//400518.10
		bool  :  markerInkTaylorsFull;	//400518.11
		long  :  totalFeet;				//totalCount / 12
		bool  :  tubeMarkerAir;			//000515
		bool  :  tubeMarkerInk;			//000516
		bool  :  horn;					//000517


		clsSpiralIO(char* ipAddress){

			mb = modbus(ipAddress, 502);
			mb.modbus_set_slave_id(1);
			mb.modbus_connect();
		};


		void setRestartEnable(bool val){
			restartEnable = val;
		};

		void setBottomBypass(bool val){
			bottomBypass = val;
		};

		bool getEstopState(){
            return(estopOK);
		};

		void setResetCount(bool val){
			resetCount = val;
		};

		void setDummyMode(bool val){
			FPMDummy = val;
		};

		void setJogFestoonFWD(bool val){
            jogFestoonFWD = val;
		};




};





