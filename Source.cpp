#include<iostream>
#include<iomanip>

using namespace std;

class Airtime {
	int hours;
	int minutes;
	int seconds;
public:
	//Airtime():hours(0), minutes(0), seconds(0){}
	Airtime(int h = 0, int m = 0, int s = 0) {
		this->hours = h;
		this->minutes = m;
		this->seconds = s;
	}
	Airtime(const Airtime& t) //Copy Constructor
	{
		hours = t.hours;
		minutes = t.minutes;
		seconds = t.seconds;
	}
	void setter();
	void getter();
	Airtime operator+=(Airtime t);
	bool operator>(Airtime t);
	Airtime operator++();
	Airtime operator++(int);
	Airtime operator=(const Airtime& t);
};
void Airtime::setter()
{
	cout << " Enter Hours: ";
	cin >> hours;
	cout << " Enter Minutes: ";
	cin >> minutes;
	cout << " Emter Seconds: ";
	cin >> seconds;

}
void Airtime::getter()
{
	cout << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << endl;
}

Airtime Airtime::operator=(const Airtime& t)
{
	hours = t.hours + 1;
	minutes = t.minutes + 2;
	seconds = t.seconds + 3;
	return *this;
}

Airtime Airtime::operator+=(Airtime t)
{
	this->hours += t.hours;
	this->minutes += t.minutes;
	this->seconds = t.seconds;
	return *this;
}
bool Airtime::operator>(Airtime t)
{
	if (this->hours > t.hours)
		return true;
	else if (this->hours == t.hours && this->minutes > t.minutes)
		return true;
	else if (this->hours == t.hours && this->minutes == t.minutes && this->seconds > seconds)
		return true;
	else
		return false;
}
Airtime Airtime::operator++()
{
	++this->hours;
	++this->minutes;
	++this->seconds;
	return *this;
}
Airtime Airtime::operator++(int)
{
	Airtime temp = *this;
	++this->hours;
	++this->minutes;
	++this->seconds;
	return temp;
}
int main()
{
	Airtime t1(8);
	Airtime t2(3);
	Airtime t3 = t2;

	//cout << (t2 > t1);
	t3 = t2 = t1;
	t2.getter();
	t1.getter();
	t3.getter();

}