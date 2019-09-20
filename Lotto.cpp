#include <iostream>      
#include <thread>     
#include <atomic>  

using namespace std;

atomic<bool> ready1(false);
atomic<bool> ready2(false);
atomic<bool> ready3(false);

atomic<int> counter1 (0);
atomic<int> counter2 (0);
atomic<int> counter3 (0);

int i = 1;
	
void lotto_1(int id) {
	while (!ready1) {           
		std::this_thread::yield();
	}
	for (int i = 1; i < 7; i++) {
		counter1++;
		if(counter1 < 7) {
		    cout << id << " ";
		}
	}
}

void lotto_2(int id) {
	while (!ready2) {           
		std::this_thread::yield();
	}
	for (int i = 1; i < 7; i++) {
		counter2++;
		if(counter2 < 7) {
		    cout << id << " ";
		}
	}
}

void lotto_3(int id) {
	while (!ready3) {           
		std::this_thread::yield();
	}
	for (int i = 1; i < 7; i++) {
		counter3++;
		if(counter3 < 7) {
		    cout << id << " ";
		}
	}
}

int main (){
	
	//init threads 
	thread threads1[55];
	thread threads2[55];
	thread threads3[55];
	
	cout << "Lotto Winners!\n";
	
	//first thread winner 1
	for (int x = 1; x < 55; x++) 
		threads1[x]=std::thread(lotto_1,x) ;	
		
	cout << "\nFirst Place: ";
	ready1 = true; 
	this_thread::sleep_for(chrono::seconds(1));	
	
	//second thread winner 2
	for (int x = 1; x < 55; x++) 
		threads2[x]=std::thread(lotto_2,x);
	
	cout << "\nSecond Place: ";
	ready2 = true; 
	this_thread::sleep_for(chrono::seconds(1));	

	//third thread winner 3
	for (int y = 1; y < 55; y++)
		threads3[y]=std::thread(lotto_3,y);	
	 
	cout << "\nThird Place: ";
	ready3 = true; 
	this_thread::sleep_for(chrono::seconds(1));
	
  	return 0;
}
