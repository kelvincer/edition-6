#include <iostream>

template <typename Key, typename Value>
class KeyValuePair
{

private:
   Key key;
   Value value;

public:
   KeyValuePair(Key key, Value value) : key(key), value(value) {}

   Key getKey() { return key; }
   Value getValue() { return value; }
};

int main()
{
   KeyValuePair<float, float> fkvp{1.2, 3.6};
   std::cout << fkvp.getKey() << std::endl;

   KeyValuePair kvp {1, 2};
   std::cout << kvp.getKey() << std::endl;
   std::cout << kvp.getValue() << std::endl;
}
