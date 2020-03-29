class Player {

protected:
string name;

public:
Player(const string &n);
virtual ~Player();

virtual const string & getType() const = 0;
virtual Move play(const State &s) = 0;

friend ostream & operator << (ostream &out, const Player &player);
};

class GreedyPlayer : public Player{
  
  private:
  
  string type;
  
  public:
    GreedyPlayer(const string &n) : Player(n){
      type = "Greedy";
    }
  
    virtual const string & getType() const override{
      return type;
    }
    
    virtual Move play(const State &state) override{
      int sh = 0;
      int sc = 0;
      for (int i = 0; i < state.getHeaps(); i++){
        if (state.getCoins(i) > sc){
          sc = state.getCoins(i);
          sh = i;
        }
      }
      Move Greedy(sh, sc, 0, 0);
      return Greedy;
    }
};

class SpartanPlayer : public Player{
  
  private:
  
  string type;
  
  public:
    SpartanPlayer(const string &n) : Player(n){
      type = "Spartan";
    }
  
    virtual const string & getType() const override{
      return type;
    }
    
    virtual Move play(const State &state) override{
      int sh = 0;
      int sc = 0;
      for (int i = 0; i < state.getHeaps(); i++){
        if (state.getCoins(i) > sc){
          sc = state.getCoins(i);
          sh = i;
        }
      }
      Move Spartan(sh, sc, 0, 0);
      return Spartan;
    }
};

class SneakyPlayer : public Player { 
public:
  SneakyPlayer(const string &n) : Player(n) {
    type = "Sneaky";
  }
  virtual const string & getType() const override {
	return type;	
  }

  virtual Move play(const State &state) override { 
  	int j = 0;
	while ( state.getCoins(j) == 0){
		j++;
	}
	int sh = j;
	int sc = state.getCoins(j);
	for (int i=j+1; i < state.getHeaps(); i++) {
		if ( (state.getCoins(i) < sc) && (state.getCoins(i) > 0 )) {
			sh = i;
			sc = state.getCoins(i);
		}
	}
	Move Sneaky(sh, sc, 0, 0);
return Sneaky;
  }
private:
	string type;
};

class RighteousPlayer : public Player{
  
  private:
  
  string type;
  
  public:
    RighteousPlayer(const string &n) : Player(n){
      type = "Righteous";
    }
  
    virtual const string & getType() const override{
      return type;
    }
    
    virtual Move play(const State &state) override{
      int sh = 0;
      int sc = state.getCoins(0);
      int th = 0;
      int tc = sc;
      for (int i = 0; i < state.getHeaps(); i++){
        if (state.getCoins(i) > sc){
          sc = state.getCoins(i);
          sh = i;
        }
        else if ( state.getCoins(i) < tc) {
				th = i;
				tc = state.getCoins(i);
			  }
      }
      sc -= sc/2;
      
      Move Righteous(sh, sc, th, sc-1);
      return Righteous;
    }
};




Player::Player(const string &n){
  name = n;
}

Player::~Player(){
  name.clear();
}

ostream & operator << (ostream &out, const Player &player){
  out << player.getType() << " player " << player.name;
  return out;
}



 
