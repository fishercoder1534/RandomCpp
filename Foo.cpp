#include "Foo.h"
using namespace std;

Foo::Foo()
{
    cout<<"I am a happy constructor that calls myMethod\n";
}

Foo::~Foo()
{
printf("I am a happy destructor that would do cleanup here.\n");
}

int main(int argc, char** argv) {
    cout << "Program started!\n";
    Foo* foo = new Foo();
    delete foo;
}