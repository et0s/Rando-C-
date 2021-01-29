#include <iostream>
#include "global.h"

#ifdef UNICODE
    wchar_t* szNewText = L"we love Bob!";
#else
    char szNewText[] = "we love Bob!"; //empty array pointer syntax
#endif

// #include "lol"  <-- will check lol in the current directoy then check for lol in <file> directory
enum lol {
    RED,
    BLUE,
    GREEN
};

// Macros
#define BUFFER_SIZE 1024
// macros can hold int, string, bool, etc...

// Multi-line buffers
#define NUMBERS 1, \
2, \
3
#define IM_COOL "hi", \
"hello world", \
"what's up"
// multi-line buffers act as an array when initialized with a primitive data type
std::string x[] = {IM_COOL};

// Function like macros
#define lang_init() c_init()
void c_init(){
    std::cout << "Function like macros" << std::endl;
}
#define add(x, y) (x + y)

#ifndef FILE_FOO_SEEN
#define FILE_FOO_SEEN
//If a header file happens to be included twice, the compiler will process its contents twice
//This is very likely to cause an error, e.g. when the compiler sees the same structure definition twice
//Even if it does not, it will certainly waste time

// the entire file
//.. (for example:).
int im_here = 69;

#endif

#ifndef TEST_AGAIN_SEEN
#define TEST_AGAIN_SEEN

int test_again = 420;

#endif

typedef int feet;       //typedef
typedef bool freewill;  //typedef
int g = 2;              //global variable

//Conditional Compilation - macros are nice because you do not need to explicity define their resources
/*  EXAMPLE.H - Example header file  */
#if !defined( EXAMPLE_H ) //Generally, we use !defined(...) or defined(...) for multi-line directive statements 
#define EXAMPLE_H

class Example
{

};

#endif // !defined( EXAMPLE_H )

#define NEWLINE '\n'
#define MY_PRINT(x) \
{ std::cout << x << std::endl; std::cout << x << std::endl; }

struct Person {
    char * Name;
    short Age;
};

#include <string>

#define WIDTH 80
#define ADD( X, Y ) (X + Y)
#undef WIDTH
#undef ADD
#ifndef WIDTH
#define WIDTH 70
#endif

class ZUS{
    public:
        int helloZUS(){
            std::string sss = "Hello World";  //operator overloading
            std::string str("Hello World");
            unsigned short dim = 20;
            char (*pchar)[10] = new char[dim][10]; //high "abstracted" level memory allocation
            char **mpchar = (char**) malloc(10 * sizeof(*mpchar)); //low level level memory allocation
            for(int i = 0; i < 10; i++){
                mpchar[i] =  (char *) malloc(10 * sizeof(**mpchar));
            }
            char fixed[10][10] = {{0}};
            char * data; //void pointer
            int len;
            data = (char *) str.c_str();
            len = str.length();
            mpchar[4][2] = 'a';
            std::cout << mpchar[4][2] << data[2];
            return 1;
        }
};
struct Base{
    virtual void f(){
        std::cout << "base\n" << std::endl;
    }
    Base();
    protected:
        int m;
        int gx;
        typedef int value_type;
    private:
        int z;
};
Base::Base(){
    m = 420;
    gx = 68;
}
struct Derived: Base{
    // auto int gx; //storage classes: register, auto, static, extern, mutable
    //using-declerative because you are using to declare the variable.
    void helloWorld(){
        std::cout << m << this->gx; //structs and even unions can be objects in the stack or on the free store
                                    //
    }
};
/*
things that are "encapsulated": (accessible using the scope resolution operator)
    1. UDT: Classes, structs, and unions.
    2. Namespaces
    */
struct testConst {
    int ixx = 0; //auto is the default storage class (stack)
    testConst(){
        //constructor
    }
    const void canYouSeeMe(){
        this->ixx = 1;
    }
}; //udt requires semicolon
#include <stdlib.h>
_Noreturn void stop_now(){
    abort();
}
//Great idea for unicode
#ifdef UNICODE
typedef wchar_t TCHAR;
#else
typedef char TCHAR;
#endif
//Nested vs. Local UDT.
/* UDT = user-defined data type */
//All UDT and Namespaces are global 
void testInnerClass(){
    class inner{
        void testInnerInnerClass(){
            class innerInner{

            };
        }
    };
}
//don't forget to compile with -std=gnu++2a to adhere to ISO C++17
class XYZ { public: int x; protected: int y; };
//Primary-expression
//1. name (namespace, UDT's)
//2. this
//3. literals
void testInnerStruct(){
    struct inner{
        inline void testInnerInnerStruct(){
            struct innerInner{

            };
        }
        void otherFunction(){
            testInnerInnerStruct(); 
        }
    };
}
/*the main difference between function overloading
    and template functions is that templates functions
    have ident*/
struct C {
    constexpr unsigned int abs(int t) {
        //std::cout << "hello world";
        return t>0?t:-t;
    }
    unsigned int abxs(int t) const {
        std::cout << "hello world";
        return 1;
    }
};
class CXX {
    private:
        unsigned long c;
    public:
        void functionSXX() volatile {
            this->c;
        }
    //you are not allowed to write defin
};
//EVERYTING IS GLOBAL INSIDE THE NAMESPACE
namespace testNamespace { //anonymous namespace (unreachable)
    /*mutable specifier only applies to class objects. */
    int z = 443;
    /*you can define member variables/functions/UDT's inside a namespace
    */
   /* a storage class can only be specified for objects and functions! */
   /* so you are not allowed to use: 
    static class Shape{
        const int i = 0;
    };
    */
   class Shape{ //this becomes an "Abstract" class.
                    /* "Abstract" classes have one or more PURE virtual function */
       protected:
            float l;
        public:
            float ll;
            void get_data(){
                std::cin >> l; //cannot use getline since input is not a string.
            }
        virtual float area() =0; /* PURE virtual function */
   };
    //THERE ARE DIFFERENT FORMS OF INHERITANCE IN C++
    //WHAT THE...?????????????????
    // access specifiers are most for inheritance in c++
    // inheritance is by default public (public=public, protected=protected)
    // YOU CAN NEVER INHERIT PRIVATE MEMBERS.
   struct Square : public Shape {
        float area(){
            return l*l;
        }
   };
   struct Square2 : protected Shape {
       float area(){
           return 3.14;
       }
   };
   //scope resolution operator (::) is only used with namespace or classes.
   //operator->() is the only operator member access operator vs. dot operator.
   class Square3 { //remember about scope prioritization young padawan
    public:
        Square3() noexcept{
            
        }
       void foo(){
            int asdasd;
           std::cin >> asdasd;
           const int xas = asdasd;  //const is a runtime constant and constexpr is a compile-time constant
           Square2 sq2; sq2.area(); /*no issue because base function
                                                    is a pure virtual function
                                                    and Square2 is a struct*/
           Square sq; sq.ll = 2.12;
           //auto is not a type specifier. it is a storage class.
           int x = 10;
           int * xadp = &x;
           struct A{
               void foo(const int* f){}
           };
           A a;
           A& a_ref1 = a;  // an lvalue reference
    //    A&& a_ref2 = a;  // an rvalue reference
            /* There are two main reasons you want dynamic memory allocation:
                1. you don't know the size of the object at compile time
                2. you want to store something on the free store (heap) until you 'delete' it */
            A *aa = new A();   /* Oh heaps! Don't lose this address matie! */
            /* Memory:
                1. Register (< ISO C++12)
                2. Cache (L1, L2, L3, TLB)
                3. Main memory (Virtual)
                    - heap
                    - stack
                    - css (> 0)
                        - bss (<= 0)
                4. External disk (HDD, SSD, etc..) */
            std::cout << aa << std::endl;
       }
   };
}
/* you are not allowed to write definition code inside a namespace
 or a user defined data type.
    i.e. CXX cxx = new CXX();
    you can only write definition code inside of a function
    or a global lambda.
*/
// ALL FUNCTIONS **DEFINED** INSIDE A CLASS ARE INLINE BY DEFAULT
/* Main difference between lambda and inline function is that
    labmda is a object type and inline is a function type. */
int swap(int&& x, const int& y){ //rvalue in an argument means a throwaway...
    return 10;
}
int main(){
    using namespace testNamespace;  //the c++ vscode tool is actually helping me learn...
    //LOCAL SCOPE identifiers  >  NAMESPACE identifiers
    // Did you know? You can using multiple namespace (including duplicates) on the same line!
    {
    int a{10}; //interesting way to declare a int variable
    int za = a + 2;
    int &ref = a; //declaring reference to already created variable
    }
    /* rules of references vs. pointers:
        1. a reference must be initialized when it is declared, whereas a pointer can be
        any vlaue anytime after its declared.
        2. a pointer can be assigned to NULL, references cannot be NULL
        3. pointer needs to be dereferenced with a *, references can be used simply by name.
        4. a pointer can be changed to point to any variable of the same type. Reference
        can only be initialized once to a variable, and cannot change from herethere. */
    int a = 5;
    int *p;
    p = &a;
    int b =6;
    p = &b; //since it's a pointer this is OK
    /* uses of lvalue references:
        1. lvalue references can be used to alias an existing object
        2. they can also be used to implement pass by reference semantics. <-- THE MAIN REASON */
    int z = 20;
    // Square3 sq3;
    // sq3.foo();
    std::cout << z << std::endl;
    const int& axas = a;
    swap(100, axas);
    C ccc;
    const C cccc; //you can make const variables, member functions and objects.
    const C& ref = ccc; /*lvalue reference. ref is a pointer that
                             acts as an object */
    /*even tho there is a variable CXX in <stdlib.h>
    because of scope prioritization, everyone here gets
    first dips on the names within this local namespace
    */
    lol l = GREEN; //can't tell if it's typedef or a enum :/
    {
        C c; /* <-- we call this "defining" an object but 
                    it's actually both declaring and defining */
        std::cout << std::endl << c.abxs(10);
    }
    static int asdasd;
    //typedef
    freewill fw = true;
    //variable_list
    // int i,j, k = 20;
    // char c, ch;
    // float f, salary;
    // double d, df = 3.14;

    //global variables
    // std::cout << g << std::endl;

    //C++ literals
    // int lit = 0x30; //fixed in value in src code
    //wchar_t = L'x';

    //Once-Only Headers
    // std::cout << im_here << std::endl;
    // std::cout << test_again << std::endl;

    //Macros
    // std::cout << BUFFER_SIZE << std::endl;
    // for(int i = 0; i < 3; i ++){
    //     std::cout << x[i] << std::endl;
    // }

    //Function like macros
    // lang_init();
    // std::cout << add(10, 20) << std::endl;
    // const int x = 20;
    // MY_PRINT("Sipper");

    //storage classes
    {
    auto xd = 20;
    auto a { 42 };
    auto d(3.14123123);
    }
    // register double r = 20;
    
    // for(static int i = 0; i < 10; i++);
    // std::cout << i << std::endl;

    //Declare a Person object
    // Person myFriend;
    // Person& rFriend = myFriend; // holds the address of an object but behaves syntatically like an object
    // std::cout << rFriend.Name << " is " << myFriend.Name << std::endl;
    // std::string s = std::string("h") + "e" + "ll" + "o";
    // std::cout << s;
    size_t t = 0;
    //external linking vs. internal linking is different from static linking vs. dynamic linking.
    // P.S. there can be many forms of linking in programs.
    // int g = 20;
    // std::cout << ::g; //::g means that you want to access the x variable inside the parent namespace
    // std::cout << g;     // you are allowed to redfine the global variable inside a local scope.
    // std::cout << gx;
    // std::cout << sizeof(short);  //sizeof() operator

    //Basic Input Output
    // std::string name;
    // std::cin >> name;
    // std::getline(std::cin, name);
    // std::cout << name;

    // switch(10){
    //     case 10:
    //         std::cout << "hello";
    //     case 20:
    //         std::cout << "world";
    //     case 30:
    //         std::cout << "from";
    //     case 40:
    //         std::cout << "efe";
    //     default:
    //         std::cout << "!";
    // }

    //Size of array
    int test[100];
    std::cout << "Length of the array = " << sizeof(test) / sizeof(*test) << std::endl;
    ZUS obj;
    obj.helloZUS();
    Derived d;
    d.helloWorld();
    std::string helllo = "helllo";              //all the same
    std::string lora("hello");                  //all the same
    std::string mater = std::string("hello");   //all the same
    const int c = 20;
    return 0;
}
class S{
    public: //access specificer block
        int square(int s); //member functions are implicity inline
        class S_X;
};
//this is a (global) function:
void helloWorld(){

}
//this is a member function:
class test{
    private:
        inline void helloWorld(){
            std::cout << "Hello World!";
        }
        void helloWorld2();
};
void helloWorld2(){
    std::cout << "Hello World!";
}
//best way of classifying inline functions
inline int cube(int s){
    return s * s * s;
}

inline int S::square(int s){  //appropriate way to declare member functions
    return s * s * s;
}
//initializing structs and unions
typedef struct {int k; int l; int a[2];} T; /*whenever using conventional 
                                            multi line operations as inline 
                                            operations please don't forget to
                                            use semicolons. */
T asd = {.k = 10, 
    .l = 20,
};
/*there are no such things as private/protected/public UDT's or namespaces
    everyting other than access specifier inside the UDT's cannot be categorized
    as private/protected/public. */

// also constructors can have member initializer lists. as long as the member.
// including you too (looks at const and volatiles).
//    =========== USE RUNESCAPE LOGIC TODO YOUR BYTE ARITHMETIC. ===========
    // 100k = 100KB
    // 1mil = 1MB
    // 1bil = 1GB
    
/*extern is inter program communication, 
    but not to confuse the acronym with IPC,
    we can call it external linking :333 uWu */
//TODO:
//1. rvalue and lvalues.
//1. Exceptions in C++
class ExceptionObject{
    public:
       std::string myMessage(){ return "here"; }
};
void asdHelloFunction (){ /*throw(ExceptionObject){ generally speaking we never make throw 
                                declerations because they are inefficient for the compiler 
                                also doesn't allow dynamic exception specifications */
    int f = 0;
    if (f){
        // throw ExceptionObject();
    }
}
//2. Operator Overloading
//4. Container Classes