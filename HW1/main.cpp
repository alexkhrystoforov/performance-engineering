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
#include <time.h>
//#include <cpr/cpr.h>


using namespace std;


struct check_time {
    check_time(string name) : func_name(name) {
        start = chrono::high_resolution_clock::now() ;
    }
    
    ~check_time() {
        auto stop = chrono::high_resolution_clock::now();
        cout << endl << func_name << " func takes: " << chrono::duration_cast<chrono::seconds>(stop - start).count() << " seconds." << endl;
    }

private:
  const string func_name;
    chrono::time_point<chrono::high_resolution_clock> start;
};

    
int fibo(int x) {
    if (x == 0) return 0;
    else if (x == 1) return 1;
    return fibo(x - 1) + fibo(x - 2);
}

void print_fibo(int n) {
    check_time check_time("fibo");
    
    vector<int> vec;
    for (auto i = 0; i < n; i++ ) {
        vec.push_back(fibo(i));
    }

    for (auto value:vec) {
        cout << value << " ";
    }
}

void sleeping(int time_for_sleep) {
    check_time check_time("sleeping");
    time_for_sleep *= 1000000;
    usleep(time_for_sleep);
    cout << endl;
    cout << "I slept for "<< time_for_sleep/1000000 << " seconds";
    cout << endl;

}

void write_text_file () {
    check_time check_time("write text file");

    ofstream outfile ("test.txt");
    auto start = chrono::system_clock::now();

    for (auto i = 0; i < 100000000 ; i++) {
        outfile << i << endl;
        outfile.flush();

        if (chrono::system_clock::now() - start > chrono::seconds(7)) {
            break;
        }
    }

    outfile.close();
}


size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string* data) {
    data->append((char*) ptr, size * nmemb);
    return size * nmemb;
}


void download_from_web(){
//    cpr::Response r = cpr::Get(
//            cpr::Url{"https://jsonplaceholder.typicode.com/todos/1"});
}


int main() {

    print_fibo(43);
    sleeping(5);
    write_text_file();
    download_from_web();
}

