#include <iostream>
#include <concepts>
#include <string>
#include <boost/type_index.hpp>

using namespace std;
using boost::typeindex::type_id_with_cvr;

template <typename T>
concept SupportsToString =
    // Check if std::to_string works
    requires(const T &t) {
       std::to_string(t);
    } ||
    // Or if it's already a string
    std::same_as<T, std::string>;

template <SupportsToString T, SupportsToString U>
auto concat(const T &t1, const U &u1)
{
   std::string v;

   if constexpr (std::same_as<T, std::string>)
   {
      v += t1;
   }
   else
   {
      v += std::to_string(t1);
   }

   if constexpr (std::same_as<U, std::string>)
   {
      v += u1;
   }
   else
   {
      v += std::to_string(u1);
   }

   return v;
}

int main()
{
   const std::string s1 = "12";
   const std::string s2 = "s2";

   const int i1 = 1290;

   std::cout << concat(i1, s2) << std::endl;
   std::cout << "Arg decltype(i) is " << type_id_with_cvr<decltype(concat(i1, s2))>().pretty_name() << '\n';
}
