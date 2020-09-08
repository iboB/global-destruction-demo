#define BUILDING_LIB 1
#include "lib.hpp"

#include <memory>
#include <thread>
#include <atomic>
#include <iostream>

class thread_runner::impl
{
public:
    impl()
    {
        m_run = true;
        m_thread = std::thread([this]() { run_thread(); });
    }

    ~impl()
    {
        std::cout << "DESTROYING" << std::endl;
        m_run = false;
        m_thread.join();
    }

    void run_thread()
    {
        while (m_run);
        std::cout << "STOPPED" << std::endl;
    }

    std::atomic_bool m_run = {};
    std::thread m_thread;
};

namespace
{
std::unique_ptr<thread_runner::impl> instance;
}

thread_runner::thread_runner() = default;
thread_runner::~thread_runner() = default;

void thread_runner::init()
{
    instance.reset(new thread_runner::impl);
}
