#include <iostream>
template<size_t n>
struct fact { enum : size_t { res = fact<n - 1>::res * n }; };
template<>
struct fact<0> { enum : size_t { res = 1 }; };

template<int N> 
struct sum_of_numbers { enum : int { res = sum_of_numbers<N / 10>::res + N % 10 }; };
template<>
struct sum_of_numbers<0>{ enum : int { res }; };

template<size_t N, size_t min = 1,size_t max = N>
struct root {
private:
    static constexpr size_t mean = (min + max) / 2;
    static constexpr bool down = ((mean * mean) >= N);
public:
    static constexpr size_t res = root<N, (down ? min:mean + 1), (down ? mean:max)>::res;    
};
template<size_t N,size_t mid>
struct root<N, mid, mid> {
    static constexpr size_t res = mid;
};
int main() {
    std::cout << root<196>::res << "\n\0";
    std::cout << sum_of_numbers<5555>::res << "\n\0";
    std::cout << fact<12>::res << "\n\0";
    system("PAUSE");
    return 0;
}