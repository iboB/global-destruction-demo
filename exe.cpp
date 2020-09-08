#include "lib.hpp"

#include <iostream>
#include <thread>
#include <chrono>

int main()
{
    thread_runner::init();

    using namespace std::literals::chrono_literals;
    std::this_thread::sleep_for(1s);

    return  0;
}
