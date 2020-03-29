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

Player::Player(const string &n){
  name = n;
}

Player::~Player(){
  name.clear();
}

ostream & operator << (ostream &out, const Player &player){
  out<< getType() << " player " << player.name;
  return out;
}



 
