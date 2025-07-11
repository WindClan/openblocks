#pragma once

#include <cstdint>

typedef uint64_t tu_time_t;

// Provides a high-accuracy time since the program started in microseconds (via std::chrono)
tu_time_t tu_clock_micros();