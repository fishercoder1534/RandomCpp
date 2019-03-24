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

void Foo::myMethod1()
{
    cout << "In myMethod1!\n";
}

int main(int argc, char** argv) {
    cout << "Program started!\n";
    Foo* foo = new Foo();
    foo->myMethod1();
    delete foo;
}