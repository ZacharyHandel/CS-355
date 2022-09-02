class Player{
  public:
    Player(){	//constructor
		lastLocation = NULL;
		currentLocation = NULL;
	}

	void setCurrent(areaNode* loc){
        lastLocation = currentLocation;
		currentLocation = loc;
	}

	bool playerMoved(){
		return !(lastLocation == currentLocation);
	}

	areaNode* getCurrent(){
		return currentLocation;
	}

	//isGameOver should return: 0 for continue, 1 for win, 2 for lose
	int isGameOver(){	//new death system (GRADE)
		 if(currentLocation->info.getID() == 1)	//**here we are locating the info object of Area created in the areaNode struct. By this, we are able to access the values regarding getID and getGoal.
		 {
			return 2;
		 }
		 else if(currentLocation->info.getGoal() == 1)	//**
		 {
			return 1;
		 }
		 else if(currentLocation->info.getID() == 0 && currentLocation->info.getGoal() == 0)	//**
		 {
			return 0;
		 }
		 else
		 {
			return 0;
		 }
	}

  private:
		areaNode* currentLocation;
		areaNode* lastLocation;

};
