#include <string>

template <typename T>
concept Concept = requires(T t) {
   { std::to_string(t) } -> std::convertible_to<std::string>;
};

auto concat(Concept auto t, Concept auto u)
{
   return std::to_string(t) + std::to_string(u);
}

int main()
{
   std::cout << concat(1, 4) << std::endl;
}
