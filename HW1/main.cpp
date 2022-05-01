//
//  main.cpp
//  HW1
//
//  Created by alexkhrystoforov on 01.05.2022.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <string>
#include <unistd.h>

using namespace std;


int fibo(int x) {
    if (x == 0) return 0;
    else if (x == 1) return 1;
    return fibo(x - 1) + fibo(x - 2);
}

void print_fibo(int n) {
    vector<int> vec;
    for (auto i = 0; i < n; i++ ) {
        vec.push_back(fibo(i));
    }

    for (auto value:vec) {
        cout << value << " ";
    }
}

void sleeping(int time_for_sleep) {
    time_for_sleep *= 1000000;
    usleep(time_for_sleep);
    cout << endl;
    cout << "I slept for "<< time_for_sleep/1000000 << " seconds";
    cout << endl;

}

void write_text_file () {
//    string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

    ofstream outfile ("test.txt");
    auto start = chrono::system_clock::now();

//    while (true) {
    for (auto i = 0; i < 100000000 ; i++) {
        outfile << i << endl;
        outfile.flush();

        if (chrono::system_clock::now() - start > chrono::seconds(5)) {
            break;
        }
    }

    outfile.close();
}

void download_from_web() {

}


int main() {
    print_fibo(10);
    sleeping(5);
    write_text_file();
    download_from_web();
}

