



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
		
		bool    restartEnable;			//412289.10
		bool    bottomBypass;			//412289.11
		bool    estopOK;				//412289.12
		bool    resetCount;				//412289.13
		bool    FPMDummy;				//412289.14
		bool    jogFestoonFWD;			//412290.0
		bool    jogFestoonREV;			//412290.1
		bool    jogHarpFWD;				//412290.2
		bool    jogHarpREV;				//412290.3
		bool    jogOpen;				//412290.4
		bool    jogClose;				//412290.5
		long    totalCount;				//412291.LONG
		long    speed;					//412293.LONG
		long    dummySpeed;				//412295.LONG
		bool    supressEncoder;			//400001.4
		bool    markerAirTaylorsFull;	//400518.10
		bool    markerInkTaylorsFull;	//400518.11
		bool    tubeMarkerAir;			//000515
		bool    tubeMarkerInk;			//000516
		bool    horn;					//000517
		
		uint16_t readHoldingRegs[5];
		uint16_t writeRegisters[2];
    
		
		int readBits(){			//  get bool values
		
			//  Read registers 412289 and 412290
			mb.modbus_read_holding_registers(12289, 2, readHoldingRegs);
			
			//  Update bool values with newest data
			
			restartEnable 	= 	readHoldingRegs[0] & (1<<10);
			bottomBypass 	= 	readHoldingRegs[0] & (1<<11);
			estopOK 		= 	readHoldingRegs[0] & (1<<12);
			resetCount 		= 	readHoldingRegs[0] & (1<<13);
			FPMDummy 		= 	readHoldingRegs[0] & (1<<14);
			
			jogFestoonFWD	=	readHoldingRegs[1] & (1<<0);
			jogFestoonREV	=	readHoldingRegs[1] & (1<<1);
			jogHarpFWD		=	readHoldingRegs[1] & (1<<2);
			jogHarpREV		=	readHoldingRegs[1] & (1<<3);
			jogOpen			=	readHoldingRegs[1] & (1<<4);
			jogClose		=	readHoldingRegs[1] & (1<<5);
			
			return(0);
		};
		
		int writeBits(){		//  Set bool values
		
			uint16_t  word89, word90;
			
			word89 |= (restartEnable<<10);
			word89 |= (bottomBypass<<11);
			word89 |= (estopOK<<12);
			word89 |= (resetCount<<13);
			word89 |= (FPMDummy<<14);
			
			word90 |= (jogFestoonFWD<<0);
			word90 |= (jogFestoonREV<<1);
			word90 |= (jogHarpFWD<<2);
			word90 |= (jogHarpREV<<3);
			word90 |= (jogOpen<<4);
			word90 |= (jogClose<<5);
			
			writeRegisters[0] = word89;
			writeRegisters[1] = word90;
			
			mb.modbus_write_registers(12289, 2, writeRegisters);	
		};
		
		
	public:

		clsSpiralIO(){
			modbus mb = modbus("192.168.101.5", 502);

			mb.modbus_set_slave_id(1);
			mb.modbus_connect();
		};


		void setRestartEnable(bool val){
			int result;
			result = readBits();
			restartEnable = val;
			result = writeBits();
		};

		void setBottomBypass(bool val){
			int result;
			result = readBits();
			bottomBypass = val;
			result = writeBits();
		};

		bool getEstopState(){
			int result;
			result = readBits();
	        return(estopOK);
		};

		void setResetCount(bool val){
			int result;
			result = readbits();
			resetCount = val;
			result = writeBits();
		};

		void setDummyMode(bool val){
			int result;
			result = readBits();
			FPMDummy = val;
			result = writeBits();
		};

		void setJogFestoonFWD(bool val){
			int result;
			result = readBits();
        	jogFestoonFWD = val;
			result = writeBits();
		};
		
		void setJogFestoonRev(bool val){
			int result;
			result = readBits();
			jogFestoonREV = val;
			result = writeBits();
		};
		
		void setHarpFWD(bool val){
			int result;
			result = readBits();
			jogHarpFWD = val;
			result = writeBits();
		};
		
		void setHarpREV(bool val){
			int result;
			result = readBits();
			jogHarpREV = val;
			result = writeBits();
		};
		
		void setJogOpen(bool val){
			int result;
			result = readBits();
			jogOpen = val;
			result = writeBits();
		};
		
		void setJogClose(bool val){
			int result;
			result = readBits();
			jogClose = val;
			result = writeBits();
		};
		
		uint32_t getTotalCount(){
			uint32_t count;
			mb.modbus_read_holding_registers(12291, 2, readHoldingRegs);
			count = (readHoldingRegs[0]<<16)+readHoldingRegs[1];
			return(count);
		};
		
		uint32_t getSpeed(){
			uint32_t speed;
			mb.modbus_read_holding_registers(12293, 2, readHoldingRegs);
			speed = (readHoldingRegs[0]<<16)+readHoldingRegs[1];
			return(speed);
		};
		
		void setDummySpeed(uint32_t dummySpeed){
			writeRegisters[0] = dummySpeed & 0x00ff;
			writeREgisters[1] = (dummySpeed >> 16) & 0x00ff;
			mb.modbus_write_registers(12295, 2, writeRegisters);
		};
			
			

};





