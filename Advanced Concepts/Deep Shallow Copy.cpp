#include <cstring>
#include <iostream>

using namespace std;

class Person {
    // actually std::string is smart, and this demo will fail with std::string
    // so, we are using char*, just like cool kids....
    char* _name;

   public:
    Person() {
        string name = "anonymous";
        _name = new char[name.size()];
        strcpy(_name, name.data());
    }

    void setName(const string& name) {
        delete[] _name;  // delete the default name
        _name = new char[name.size()];
        strcpy(_name, name.data());
    }

    ~Person() {
        // NOTE: strlen(_name) != 0 may work to avoid double free?
        if (_name != nullptr && strlen(_name) != 0) {
            delete[] _name;
            _name = nullptr;
        }
    }

    char* toString() { return _name; }

    // we will rely on DEFAULT = operator in this version...
    // which is similar to:
    // Person& operator=(const Person& p) { _name = p._name; return *this; }

    // to fix this program uncomment the function below:
    // Person& operator=(const Person& p) {
    //     delete[] _name;  // delete previously set name
    //     _name = new char[strlen(p._name)];
    //     strcpy(_name, p._name);
    //     return *this;
    // }
};

int main() {
    // let us create two humans!
    Person p1, p2;

    cout << p1.toString() << " " << p2.toString() << "\n";
    // anonymous persons are almost identical to us, so we just = them...
    p2 = p1;

    // after a loooong time, we got the identity of p2!
    p2.setName("Satoshi Nakamoto");

    // we just changed name of p2, how p1 is affected??
    cout << p1.toString() << " " << p2.toString() << "\n";

    // shallow copy isn't what we want... we must define our own deep copy
    // version of the copy constructor (uncomment the deep copy constructor
    // (near line 39), re run this program, and observe the output)
}