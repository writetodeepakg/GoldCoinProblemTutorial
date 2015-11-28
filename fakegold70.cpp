#include "fakegold70.h"

fakegold70::fakegold70(int pos)				//constructor
	: _min_weighing(0),_max_weighing(0),_faulty_position(pos) {
		for(int i = 0; i < 70; i++) {
			_positions[i] = 1;
		}
		_positions[_faulty_position-1] = 0;
}
			
fakegold70::~fakegold70() {}			//destructor
void fakegold70::_release() {}

void fakegold70::_copy(const fakegold70& fg) {
	for(int i = 0; i < 70; i++) {
		_positions[i] = fg._positions[i];
		_faulty_position = fg._faulty_position;
		_min_weighing = fg._min_weighing;
		_max_weighing = fg._max_weighing;
	}
}

fakegold70::fakegold70(const fakegold70& fg) {  //copy constructor
	_copy(fg);
}

fakegold70& fakegold70::operator=(const fakegold70& fg) {
	if(this != &fg) {
		_release();
		_copy(fg);
	}
	return *this;
}

void fakegold70::findFakeCoinFrom8Coin(int start_position) {		// assuimg start position 1, comment will be as per postion 1 
	if(sumOfCoins(start_position,start_position+2) == sumOfCoins(start_position+3,start_position+5)) {  // faulty gold coin is at location 7-8
		cout << "Faulty gold coin is at location: " << start_position+6 << " - " << start_position + 7 << endl; 
		++_max_weighing;
		if(_positions[start_position+5] < _positions[start_position+6]) {
			++_max_weighing;
			cout << "Faulty gold coin is at location: " << start_position+6 << endl ;							// faulty gold coin is at location 7
		} 
		else {
			++_max_weighing;
			cout << "Faulty gold coin is at location: " << start_position+7 << endl;							// faulty gold coin is at location 8
		}
	}
	else if(sumOfCoins(start_position,start_position+2) < sumOfCoins(start_position+3,start_position+5))  { // faulty gold coin is at location 1-3
		cout << "Faulty gold coin is at location: " << start_position << " - " << start_position + 2 << endl;
		++_max_weighing;
		if(_positions[start_position - 1] == _positions[start_position])	{								// faulty gold coin is at location 3
			cout << "Faulty gold coin is at location: " << start_position+2 << endl;
			++_max_weighing;
		}
		else if(_positions[start_position - 1] < _positions[start_position])	{							// faulty gold coin is at location 1
			cout << "Faulty gold coin is at location: " << start_position << endl;
			++_max_weighing;
		}
		else {																									// faulty gold coin is at location 2
			cout << "Faulty gold coin is at location: " << start_position+1 << endl;
			++_max_weighing;
		}
	}	
	else { // faulty gold coin is at location 4-6
		cout << "Faulty gold coin is at location: " << start_position+3 << " - " << start_position + 5 << endl;
		++_max_weighing;
		if(_positions[start_position + 2] == _positions[start_position + 3])	{								// faulty gold coin is at location 6
			cout << "Faulty gold coin is at location: " << start_position + 5 << endl;
			++_max_weighing;
		}
		else if(_positions[start_position + 2] < _positions[start_position + 3 ])	{							// faulty gold coin is at location 4
			cout << "Faulty gold coin is at location: " << start_position +3 << endl;
			++_max_weighing;
		}
		else {																									// faulty gold coin is at location 5
			cout << "Faulty gold coin is at location: " << start_position + 4 << endl;
			++_max_weighing;
		}
	}
}

void fakegold70::findFakeCoinFrom24Coin(int start_position) {
	if(sumOfCoins(start_position,start_position+7) == sumOfCoins(start_position+8,start_position+15)) {  // faulty gold coin is at location 17-24
		cout << "Faulty gold coin is at location: " << start_position+16 << " - " << start_position + 23 << endl;
		++_max_weighing;
		findFakeCoinFrom8Coin(start_position+16);
	}
	else if(sumOfCoins(start_position,start_position+7) < sumOfCoins(start_position+8,start_position+15)) {  // faulty gold coin is at location 1-8
		cout << "Faulty gold coin is at location: " << start_position << " - " << start_position + 7 << endl;
		++_max_weighing;
		findFakeCoinFrom8Coin(start_position);
	}
	else {																									// faulty gold coin is at location 9-16
		++_max_weighing;
		cout << "Faulty gold coin is at location: " << start_position+8 << " - " << start_position + 15 << endl;
		findFakeCoinFrom8Coin(start_position+8);
	}
}

void fakegold70::findFakeCoinFrom70Coin(int start_position) {
	if(sumOfCoins(start_position,start_position+22) == sumOfCoins(start_position+23,start_position+45)) {  // faulty gold coin is at location 47-70
		cout << "Faulty gold coin is at location: " << start_position+46 << " - " << start_position + 69 << endl;
		++_max_weighing;
		findFakeCoinFrom24Coin(start_position+46);
	}
	else if(sumOfCoins(start_position,start_position+22) < sumOfCoins(start_position+23,start_position+45)) {  // faulty gold coin is at location 1-23
		cout << "Faulty gold coin is at location: " << start_position << " - " << start_position + 23 << endl;
		++_max_weighing;
		findFakeCoinFrom24Coin(start_position);
	}
	else {																									// faulty gold coin is at location 24-46
		++_max_weighing;
		cout << "Faulty gold coin is at location: " << start_position+23 << " - " << start_position + 46 << endl;
		findFakeCoinFrom24Coin(start_position+23);
	}
}

int fakegold70::sumOfCoins(int start,int end) {
	int sum = 0;
	for(int i = start; i <=end; i++) {
		sum += _positions[i-1];
	}
	return sum;
}