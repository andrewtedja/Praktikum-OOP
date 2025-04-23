export module math;

export int add(int a, int b)
{
    return a + b;
}

export int square(int x)
{
    return x * x;
}


export module stringutil;

#include <string>
#include <algorithm>

export std::string to_upper(const std::string& input) {
    std::string result = input;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}