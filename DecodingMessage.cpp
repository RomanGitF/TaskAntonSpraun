#include <iostream>

using namespace std;

enum class Register {
	U,
	L,
	P
};

void NextRegister(Register& reg);

int CalcNumber(int number, Register& reg);

char GetLetters(int number, Register& reg);

char GetSign(int number);

string DecodingCin();

int main() {
	string answer = DecodingCin();
	cout << answer << endl;
}

char GetLetters(int number, Register& reg){
	char letter;
	switch(reg) {
		case Register::U:
		letter = static_cast<char>(number-1+int('A'));
		break;
		case Register::L:
		letter =  static_cast<char>(number-1+int('a'));
		break;
		case Register::P:
		letter = GetSign(number);
		break;
	}
	return letter;
}

char GetSign(int number){
	char sign;
	switch(number) {
		case 1:
		sign = '!';
		break;
		case 2:
		sign = '?';
		break;
		case 3:
		sign = ',';
		break;
		case 4:
		sign = '.';
		break;
		case 5:
		sign = ' ';
		break;
		case 6:
		sign = ';';
		break;
		case 7:
		sign = '"';
		break;
		case 8:
		sign = '\'';
		break;	
	}
	return sign;
}

string DecodingCin(){
	
	string result;
	
	int number = 0;
	Register shift = Register::U;
	char sign = cin.get();
	bool enter = false;
	while (!enter) {
		if (sign == 10) {
			enter = true;}
		if(isdigit(sign)) {
			number *= 10;
			number += sign-'0';
		} else {
			int calc_number = CalcNumber(number, shift);
			if (calc_number == 0) {
				NextRegister(shift);
			} else {
				result += GetLetters(calc_number, shift);
			}
			number = 0;
		}
		if(!enter) {
			sign = cin.get();
		}
	}
	return result;
}

int CalcNumber(int number, Register& reg){
	int res = 0;
	switch(reg) {		
		case Register::U:
	res = number%27;
	break;
		case Register::L:
	res = number%27;
	break;		
		case Register::P:
	res = number%9;
	break;		
	}

	return res;
}

void NextRegister(Register& reg){
	if (reg == Register::P) {
		reg = Register::U;
		return;
	}
	int next = static_cast<int>(reg);
	reg = static_cast<Register>(++next);
}
