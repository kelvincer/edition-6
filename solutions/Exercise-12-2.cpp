#include <string>

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

template <>
class KeyValuePair<const char *, const char *>
{
private:
   std::string key;
   std::string value;

public:
   KeyValuePair(const char *key, const char *value) : key(std::string(key)), value(std::string(value)) {}

   std::string getKey() { return key; }
   std::string getValue() { return value; }
};

int main()
{
   KeyValuePair<float, float> fkvp{1.2, 3.6};
   std::cout << fkvp.getKey() << std::endl;

   KeyValuePair kvp{1, 2};
   std::cout << kvp.getKey() << std::endl;
   std::cout << kvp.getValue() << std::endl;

   KeyValuePair<const char *, const char *> skvp("ros", "ario");

   std::cout << skvp.getKey() << std::endl;
}
