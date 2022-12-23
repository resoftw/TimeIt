#include <Windows.h>
#include <iostream>
#include <string>
#include <chrono>
#include <time.h>

int main(int argc,char* argv[])
{
    std::string s = "";
    for (int i = 1; i < argc; i++) {
        if (i > 1)s += " ";
        std::string tmp = argv[i];
        if (tmp.find_first_of(" \t")!=std::string::npos) {
            s += "\"";
            s += argv[i];
            s += "\"";
        } else s += argv[i];
    }
    auto t0 = std::chrono::high_resolution_clock::now();
    system(s.c_str());
    auto t1 = std::chrono::high_resolution_clock::now();
    auto elapsed = t1 - t0;
    auto dur = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
    std::cout << "Time: " << dur/1000000.0 << "\n";

}

