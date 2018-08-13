#pragma once
class Data {
public:
	int id;		// 1~10000
	int date;	// 20000000~20999999
	Data() : id(0), date(0) {}
	Data(int _id, int _date) : id(_id), date(_date) {}
	~Data() {}

	void printData() {
		printf("id : %5d, date : %9d\n", id, date);
	}
};

