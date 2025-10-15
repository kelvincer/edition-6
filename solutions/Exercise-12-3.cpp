#include <string>

template <typename Key, typename Value>
requires std::integral<Key> && std::floating_point<Value>
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

template <typename Key>
concept Integral = std::integral<Key>;

template <typename Value>
concept FloatingPoint = std::floating_point<Value>;

// template <Integral Key, FloatingPoint Value>
// class KeyValuePair
// {

// private:
//    Key key;
//    Value value;

// public:
//    KeyValuePair(Key key, Value value) : key(key), value(value) {}

//    Key getKey() { return key; }
//    Value getValue() { return value; }
// };

int main()
{
   KeyValuePair<int, float> fkvp{1, 3.6f};
   std::cout << fkvp.getKey() << std::endl;
}
