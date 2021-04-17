#include <iostream>
namespace meta_function {
    template<int count, bool flag = (count > 0)>
    struct _abs { static constexpr int value = { flag ? count : (count * -1) }; };
    template<int count>
    inline constexpr size_t abs_v = _abs<count>::value;
    template<int count, int _pow>
    struct mpow { static constexpr size_t value = mpow<count, abs_v<_pow - 1>>::value * count; };
    template<size_t count>
    struct mpow<count, 0> { static constexpr size_t value = 1; };
    template<int count, int _pow>
    inline constexpr size_t mpow_v = mpow<count, _pow>::value;
    template<int n>
    struct fact { static constexpr size_t value = fact<abs_v<n> - 1>::value * abs_v<n>; };
    template<>
    struct fact<0> { static constexpr size_t value = 1; };
    template<int32_t count>
    inline constexpr size_t fact_v = fact<count>::value;
    template<int N>
    struct sum_of_numbers { static constexpr size_t value = sum_of_numbers<abs_v<N / 10>>::value + abs_v<N % 10>; };
    template<>
    struct sum_of_numbers<0> { static constexpr size_t value = 0; };
    template<int count>
    inline constexpr size_t sum_of_numbers_v = sum_of_numbers<count>::value;
    template<size_t N, size_t min = 1, size_t max = N>
    struct root {
    private:
        static constexpr size_t mean = (min + max) / 2;
        static constexpr bool down = ((mean * mean) >= N);
    public:
        static constexpr size_t value = root<N, (down ? min : mean + 1), (down ? mean : max)>::value;
    };
    template<size_t N, size_t mid>
    struct root<N, mid, mid> { static constexpr size_t value = mid; };
    template<size_t count>
    inline constexpr size_t root_v = root<count>::value;
    template<int N>
    struct count_of_numbers { static constexpr size_t value = count_of_numbers<abs_v<N / 10>>::value + 1; };
    template<>
    struct count_of_numbers<0> { static constexpr size_t value = 0; };
    template<int count>
    inline constexpr size_t count_of_numbers_v = count_of_numbers<count>::value;
    template<int N, int firstdel = 1, int count = 1>
    struct is_simple_numeric {
        static constexpr bool value = is_simple_numeric<N, firstdel + 1, (N% firstdel == 0 ? count + 1 : count)>::value;
    };
    template<int N, size_t count>
    struct is_simple_numeric<N, N, count> { static constexpr bool value = (count == 2? true : false); };
    template<>
    struct is_simple_numeric<1> { static constexpr bool value = true; };
    template<int count>
    inline constexpr bool is_simple_numeric_v = is_simple_numeric<count>::value;
}
int main() {
    using namespace meta_function;
    return 0;
}
