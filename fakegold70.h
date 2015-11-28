#include "..\util\util.h"

class fakegold70 {
public:
	fakegold70(int pos =3);			//constructor
	~fakegold70();			//sestructor
	fakegold70(const fakegold70& fg); //copy constructor though its not really required to implement as no dynamic memory allocation
	fakegold70& operator=(const fakegold70& fg); //assigenment operator though its not really required to implement as no dynamic memory allocation
	void findFakeGlodCoin(void);
	int sumOfCoins(int start,int end);
	int getMaxWeighing() { return _max_weighing; }
	int getMinWeighing() { return _min_weighing; }
	void findFakeCoinFrom8Coin(int start_position);
	void findFakeCoinFrom24Coin(int start_position);
	void findFakeCoinFrom70Coin(int start_position);
	
private:
	void _copy(const fakegold70& fg);
	void _release();
	int _positions[70];
	int _faulty_position;
	int _min_weighing;
	int _max_weighing;
};