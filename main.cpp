#define _CRT_SECURE_NO_WARNINGS

#include<iostream> 
#include<cstring> 
using namespace std;
class Car {
private:
	char number[20];
	float price;
public:
	Car(const char* n, float p) {
		strcpy(number, n);
		price = p;
	}
	void correctPrice(float discount) {
		price *= discount;
	}
	void shownumber(){
		std::cout << "车牌号:" << number << endl;
	}
		void showprice() {
		std::cout << "当前价格:" << price << endl;
	}
	};
int main() {
	Car myCar("晋w70301", 500000.0f); cout << "修改前:" << endl;
	myCar.shownumber();
	myCar.showprice();
	myCar.correctPrice(0.8f); cout << "修改后:" << endl;
	myCar.shownumber();
	myCar.showprice();
	return 0;
}
