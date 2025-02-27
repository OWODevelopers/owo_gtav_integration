#pragma once

#define OWODEVELOPMENT true

#if OWODEVELOPMENT

#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <sstream>

#define owoStringStream std::stringstream
#define owoString std::string
#define owoVector std::vector
#define owoSet std::set
#define owoMap std::map
#define owoToString(value) std::to_string(value)
#define owoStringNpos std::string::npos
#define WaitFor(time) std::this_thread::sleep_for(std::chrono::milliseconds(time));
#define ServerDiscoveryRate 500
#define CreateNew(a) new a
#define uniquePtr std::unique_ptr
#define sharedPtr std::shared_ptr
#define movePtr std::move
#define CreateNewUnique(a, b) uniquePtr<a>(new b)
#define owoport 54020
#define owoclamp(value, minimum, maximum) std::max(minimum, std::min(value, maximum))
#endif