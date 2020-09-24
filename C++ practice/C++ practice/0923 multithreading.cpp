#include "stdafx.h"
#include <thread>
#include <mutex>

typedef unsigned long long udlong;
mutex m;
#define THREAD_NUM 32
udlong extra = 0;
const udlong divide = pow(10, 9) + 7;
vector<thread> vecThread;

void get_extra(udlong num, udlong multiflier);

int main()
{
	udlong init, multiflier, year;
	Stopwatch watch;
	cout << "a, b, c �Է�: ";
	cin >> init >> multiflier >> year;
	watch.start();
	extra = init;
	udlong nRemainder = year / THREAD_NUM;
	udlong nExtra = year % THREAD_NUM;

	for (udlong i = 0, temp = 0; i < THREAD_NUM; ++i, temp++)
	{
		vecThread.emplace_back(thread(get_extra, nRemainder, multiflier));
		//cout << i + 1 << "���� ������ ����\n";
	}
	if(nExtra)
		vecThread.emplace_back(thread(get_extra, nExtra, multiflier));
	cout << "�� ������ ��: " << vecThread.size() << endl;
	for (udlong i = 0; i < THREAD_NUM; i++)
	{
		vecThread[i].join();
		//cout << "������ " << i + 1 << " ����\n";
	}
	watch.stop();
	cout << "��� : " << extra << endl;
	cout << "�ҿ�ð� : " << watch.getElapsedTime() << endl;

	return 0;
}



void get_extra(udlong num, udlong multiflier)
{
	udlong tempShare = num / 4;
	udlong tempRemainder = num % 4;
	udlong tempExtra = 1;
	
	for (udlong i = 0; i < tempShare; i++)
	{
		udlong temp = multiflier * multiflier * multiflier * multiflier;
		tempExtra = tempExtra * temp % divide;
	}

	udlong temp = pow(multiflier, tempRemainder);
	tempExtra = tempExtra * temp % divide;

	m.lock();
	extra = tempExtra * extra % divide;
	m.unlock();
}