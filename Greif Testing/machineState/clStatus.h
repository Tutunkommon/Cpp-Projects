




class clStatus{	

	private:
		int state;
		int speed;
		int beltFeet;

	public:
		int setState(int newState){
			//  TO DO:  Report new state
			state = newState;
			return(0);
		};

		int setSpeed(int newSpeed){
			// TO DO:  Update machine speed
			speed = newSpeed;
			return(0);
		};

		int setBeltFeet(int newBeltFeet){

			// TO DO:  Update current belt feet reporting
			beltFeet = newBeltFeet;
			return(0);
		};

		int getState(){
			return(state);
		};

		int getSpeed(){
			return(speed);
		};

		int getBeltFeet(){
			return(beltFeet);
		};

};


