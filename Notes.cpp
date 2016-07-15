/** QUESTIONS **/


/** COMPILED VS. INTERPRETED LANGUAGES
    
    Conceptually, code of a compiled language undergoes a preprocessing step 
    to create executable machine code. An interpreted language is executed 
    "in real-time". In principle, however, a language is independent of these 
    processes. In practice, the distinction may still be ambiguous, as several 
    programming languages have had both treatments, and moreover, some rely on 
    a combination of both.
*/


/** IMPERATIVE VS. DECLARATIVE PROGRAMMING

    Imperative programming is a paradigm in which statements change a 
    program's state e.g. C++. Procedural programming is a subcategory of this, 
    where the code is organised into sub-routines. Object-oriented programming 
    takes this even futher. A declarative language expresses logical 
    statements without specifying how they should be accomplished (this is done 
    by the machine). It often follows a formal logic e.g. SQL (though SQL is 
    also procedural => multi-paradigm). Declarative expresses 'what', rather 
    than 'how'.
*/


/** BENEFITS OF OBJECT-ORIENTED PROGRAMMING

    Aside from the typical features of imperative languages, the main tenets 
    of OOP programming languages are:
*/


/** CLASSES AND OBJECTS */

class UserDefinedType {

};

void instantiate_as_object() {
    // user-defined types (classes) modelling entities, instantiated as objects
    UserDefinedType udp;
}


/** INHERITANCE

    Inheritance is a mechanism of abstraction in modelling, but also 
    facilitates code reuse. Given a parent class,
*/

class Parent {
public:
    int x;
private:
    int y;
protected:
    int z;
};

// We can create a derived, child class
class Child : Parent {};

/** 
    Private members are not inherited. Another type of inheritance, 
    interfacing, occurs when inheriting from an abstract class. An abstract 
    class is a class with at least one pure (denoted by =0) virtual function. 
    Note there is also such a thing as a (non-pure) virtual function. The 
    difference is that this provides an implementation. This also facilitates 
    polymorphism. There are also other types of inheritance, for example,
*/

class ProtectedChild : protected Parent {};

/** 
    whereby public members become protected (privates remain private). Recall 
    protected means private, but retained by sub classes (unlike private 
    variables). To implement an abstract class (interface), public inheritance 
    is required.
*/


/** POLYMORPHISM

    One of the key polymorphism features of C++ is that pointers to a derived 
    class are "type-compatible" with pointers to its base class. Polymorphism 
    in C++ manifests with function overriding and virtual functions.
  
    A class is made abstract by declaring at least one of its methods (purely?) 
    virtual.
*/

class AbstractClass {
public:
    virtual void virtual_function() = 0;
};

class ConcreteClass : public AbstractClass {
public:
    virtual void virtual_function() {;}
};

void polymorphic_function(AbstractClass* p_abstract_object) {
    p_abstract_object->virtual_function();
}

// Remember in C and C++, a function must defined before it's used
void test_polymorphic_function() {
    ConcreteClass* p_concrete_object;
    polymorphic_function(p_concrete_object);
}


/** ENCAPSULATION
            
    Encapsulation is provided by access-specifiers: public, private, protected. 
    These control what is visible to other classes. This encourages decoupling.
    protected is another access modifier (along with private and public). 
    Private member variables and functions are not inherited! protected allows 
    otherwise private members to be inherited.
*/

class ParentClass {
private:
    int _private_member; 
public:
    // private members need a getter
    int get_private_member() {
        return this->_private_member;
    }
protected:
    int _protected_member;
};

class ChildClass : ParentClass {
private:
    int _private_member;
public:
    int get_private_member() {
        return this->_private_member;
    }
    int get_protected_member() {
        // protected member known from super class
        return this->_protected_member;
    }
};


/** OPEN RECURSION
    
    objects methods can call their own methods, typically using the keyword, 
    'this', a self-referential pointer to the object itself.
*/


/** OVERLOADING AND OVERRIDING

    Functions are overloaded if the same name has multiple signatures. A 
    function is overriden if it is redefined (with the same signature) in a 
    derived class.
*/


/** C VS. C++

    C++, invented by Bjarne Stroustrup in the late 70s and early 80s, was 
    motivated by bringing objects, classes, and others features from the 
    (Norwegian) Simula language (which is often used for discrete event 
    simulation) to the fast, general-purpose, and widely-used C programming 
    language (Dennis Ritchie, 1972). The initial project was indeed called 
    "C with classes". C++14 (2014 standard is the latest), prior to which 
    C++11 and C++98. The exit status/return code statement "return 0;" is 
    added automatically in C++, whereas it is required in C. C has smaller 
    libraries, and lacks, for example, a native Boolean type. The programmer 
    must implement,
*/

enum BOOL {FALSE, TRUE};


/** COMPILERS

    At a certain level, compilers are conceptually quite similar with 
    preprocessing, and lexical and semantic analysis performed. But they may 
    differ in all sorts of ways, for example, C++ is compiled to machine code, 
    the Java compiler, javac, compiles to Java byte code to be run on the Java 
    Virtual Machine (JVM). On a high level, a C++ compiler performs 
    preprocessing steps, resolving macros #define etc., compiles source code 
    into object .o files (these are binary files which aren't usually 
    independently executable), and the linker part of the compiler links these 
    binaries together.
*/


/** .h VS. .hpp FILES

    This is mainly to help the compiler/linker, we can use #include header.h to 
    "copy in" compiled source code from other files, without having to 
    recompile the object files. That is, the .cpp source can be compiled in 
    advance into .o object files, and the header file gives the compiler enough 
    information to proceed, without having recompile the binaries. The header 
    acts as a "promise" to the compiler that the code will be there. .hpp is 
    sometimes used to distinguish from C headers. It also facilitates a 
    separation of design and implementation. This is logically not the primary 
    purpose, since private member variables are part of the header file, 
    without having anything to do with the design. Note you do not have to use 
    headers. Classes can be defined and implemented at the same time, or at 
    least, in the same file.
*/


/** PREPROCESSOR DIRECTIVE
    
    Preprocessor directives are sort of meta code. They come in various forms.
*/

/** 
    The #include directive tells the compiler to include the contents of the 
    source file specified by <path name>, otherwise by <standard library>. A 
    .cpp file must include its header file.
*/
#include <iostream>

/** 
    The #define and #undef directives are macro directives. They allow to 
    substitute text directly, such as
*/
#define QUEEN 6

// There are predefined macros such as 
void predefined_macro() {
    std::cout << __TIME__ << std::endl;
}

/** 
    Conditional inclusions (#ifdef, #ifndef, #if, #endif, #else and #elif). 
    These directives allow to include or discard part of the code of a program 
    if a certain condition is met.
*/
#ifdef TABLE_SIZE
int table[TABLE_SIZE];
#endif

// There are other directives, line control, error directives, etc.


/** NAMESPACES

    Using namespaces allows the programmer to do away with scope resolution 
    operators and module names before functions and variables. Using namespace 
    std is very common, as the standard library is very widely used.
*/

using namespace std;

// A namespace can be created with,
namespace constants {
    double pi = 3.14159265358979323;
}

// Then accessed with constants::pi;. :: is the scope resolution operator.
void accessNamespace() {
    cout << constants::pi << endl;
}


/** SYMBOL TABLES

    A symbol table in C++ is part of a compiled object file. It is a lookup 
    table that relates the items in the file to names the linker can understand.
*/


/** BINDING
    
    Early and late binding refer to the two ways a variable may be exercised. 
    When a variable's type is known at compile time, it is bound early. In the 
    second case, a variable type is unknown until run time. A language 
    supporting this is said to be dynamically typed. This is achieved through 
    a variety of means including introspection (recall Java), but also by 
    virtual functions by extension of dynamic dispatch.

    Static/dynamic typing is about when the type is determined

    Strong/weak typing is about how strictly the types are distinguised. e.g. 
    variables have assigned types in C; in Python, a variables type is changed 
    if it is reassigned to another type.
*/


/** DISPATCH
    
    Functions may be statically or dynamically dispatched. In the former case, 
    the exact function signature is known unambiguously at compile time. In 
    the latter, the function is determined by context at runtime. There are 
    even two varieties of this. In single dynamic dispatch, the function is 
    determined dynamically by the (dynamic) type of the instance. In multiple 
    dynamic dispatch, the function signature (parameters) is also used to 
    determine the function. This is achieved through things like function 
    overriding, abstract functions, and virtual functions.
*/


/** OTHER KEYWORDS

    volatile is a qualifier (like const), which protects a variable from being 
    optimised away.
    
    auto keyword asserts that a variable's type should be deduced by its 
    initialisation, for example, auto a = 1 + 2;

    note also that "access modifier" and Æaccess specifier" are interchangeable.

    The friend keyword allows private and protected members to be accessible 
    from inside an external class or function. It suffices to declare this 
    external as a friend within the definiton of the class.
*/

class FriendlyClass {
private:
    string name;
public:
    FriendlyClass(string name) {
        this->name = name;
    }
    friend void friendly_function();
};

void friendly_function() {
    FriendlyClass s("Bradley");
    cout << s.name << endl;
}


/** SHARED LIBRARIES
    
    Shared libraries are compiled code to be used by other applications, 
    without "being copied by a linker when it creates a single monolithic 
    executable file for the program." Instead, shared libraries are usually 
    looked up at load or execution time. This is what's called late binding or 
    dynamic linking (as opposed to static linking). On Windows, shared 
    libraries are DLLs (dynamic link libraries). Shared libraries make 
    compilation more resistant to version conflicts.
*/


/** COMPILING CODE

    g++ is the C++ frontend to the GCC compiler. gcc is the C frontend. GCC 
    is the GNU Compiler Collection.

    g++ -o main main.cpp

    or simply
    
    g++ main.cpp
*/


/** MAKE, CMAKE

    make is a build automation tool. A makefile automates compiling a C or C++ 
    project by specifying a hierarchy of dependencies between object files.

    cmake is software for automating the creation of make files, and other 
    built automation input files for other languages. It can, for example, 
    turn source files into an XCode or VS project.
*/


/** DESTRUCTORS AND BUILT-IN FUNCTIONS

    Default constructor, destructor, copy and move contructors and operators. 
    There is a nice shorthand for initialising member variables with a 
    constructor:
*/

class Human {
    Human(int height, int weight) : _height(height), _weight(weight) {};
    // A destructor is defined in the following way
    ~Human() {};

    int _height;
    int _weight;
};


/** STRUCTS VS. CLASSES
    
    In C++, there is almost no difference between the two; structs can inherit 
    and be inherited from, can have abstract member functions etc. The only 
    differences are class member variables are private by default (meaning if 
    the access specified is not specified) and public for structs; 
    access-specifier for inherited members defaults to private for class and 
    public for struct (regardless of the access-specifier in the parent). As 
    amazing as that sounds, apparently that IS the only difference.
*/

struct IAmAStruct {
    int member_variable;
};

class IAmAClass {
    int member_variable;
public:
    // need getter--members private by default
    int get_member_variable() {
        return this->member_variable;
    }
};


/** STATIC VARIABLES AND FUNCTIONS

    A static variable is initialised a single time over the program life time, 
    no matter how many times the function containing it is called. It may 
    however have local scope rather than global scope. This is not to be 
    confused with a const variable, which is read-only. This is useful when 
    you have a lot of objects that you want to enforce some consensus on.

    Static member variables are independent of objects. They must be 
    initialised outside of the object definition: 

    "non-const static data member must be initialized out of line" 
    -- error message

    The compiler also complains if a static member variable isn't instantiated 
    at all.
    
    A static method is independent of objects. It may be used as a function, 
    and without initialising any objects. It can be used by an object as well, 
    so it isn't so clear what the point of it is.

    It is important to note, static variables can exist outside of classes. For 
    example,
*/

void function() {
    static int test = 0;
    cout << test << endl;
    test++;
}


/** INITIALISING OBJECTS

    An object can be initialised in two ways: dynamic allocation, which creates 
    an object on the heap and returns a pointer; and static allocation, which 
    creates an object with automatically allocated memory on the stack.
*/

class Something {
public:
    int member;
};

void initialising_objects() {
    // creates an integer pointer with no allocation i.e. null pointer
    Something * pointer;
    // creates the integer 3 in memory and returns the pointer
    pointer = new Something();
    // access public member variables and methods using -> operator
    pointer->member = 10;
    // or, alternatively, dereference to access object directly
    (*pointer).member = 10;
    // Statically
    Something obj;
    // We can then create a pointer after the fact with,
    Something* obj_pointer = &obj;
}

/**
    This runs the risk of creating memory leaks unless the delete directive is 
    used. Dynamically allocated memory is justified mainly for variables 
    requiring large memory.
*/


/** REFERENCES VS. POINTERS

    Everyone knows what a pointer is. A reference is somehow misunderstood, 
    but can easily be understood as an ALIAS. Then it is obvious why it can't 
    be insantiated alone--it's just another symbol for the same memory address. 
    Pointers, on the other hand, have their own memory allocated on the stack. 
    The & operator is confusing because it's also used to acquire the memory 
    address of a variable (as well as in logical operations).
*/
void references_vs_pointers() {
    // string& rs;          // error! References must
                        // be initialized
    string s("xyzzy");
    string& rs = s;         // okay, rs refers to s

    //Pointers are subject to no such restriction:

    string *ps;             // uninitialized pointer:
                            // valid but risky

    /**
        A pointer can be reassigned... a reference is almost like a const pointer, 
        but that can be misleading. A pointer has its own memory address on the 
        stack, an address shares its address with its variable. A pointer to a 4B 
        (in x86) pointer is therefore possible,
    */

    int* p;
    int** pp = &p;
}

/**
    Pointers are 8 bytes on a 64-bit machine.

    An array can be treated as a pointer, so p_array[10] = *(p_array + 10)

    However, an array is not exactly a pointer. After all, the sizeof()
    function has knowledge of the array contents.
*/


/** STACK VS. HEAP

    The stack is like a scratch pad of memory with a block set aside for each 
    function and its local variables etc. (presumably the compiler can work out 
    how much stack memory is needed for each function in advance). It works as 
    a LIFO (last in first out) queue.

    The heap is memory set aside for dynamic allocation. There is no such 
    queuing pattern for the heap. Each thread gets a stack, but usually they 
    share a heap. The OS allocates the stack for each thread when created. A 
    process is granted heap memory by the OS at runtime, which is freed at 
    process termination.

    The stack is faster because stack memory has a simpler access pattern, will 
    tend to be cached by the processor, and because heap memory must be made 
    thread-safe.
*/


/** METHOD VS. FUNCTION VS. PROCEDURE

    Method belongs to a class, function returns a value, procedure does not.
*/


/** EXCEPTIONS AND ASSERTIONS

    Exceptions can be used by including the appropriate header, 
*/

#include <stdexcept>

/** 
    then throw invalid_argument("Number not found");. Likewise, assertions with 
    #include <assert.h>, and assert(true == false);. A false assertion raises an 
    exception.
*/


/** TEMPLATES
    
    A template is a C++ feature allowing the specification of CONTAINERS! 
    (which includes abstract data types, but also classes) to contain objects 
    of other types, but without having to specify the object type in advance. 
    This is a useful polymorphic feature. Templates can be suprisingly 
    temperamental, without some jiggery pokery, implementing member functions 
    of a template class in a separate source file (.cpp) will invoke errors, 
    therefore implementations should be contained in header files. Templates 
    are what you use to define containers.
*/

template <class T>
class TContainer {
    T member;
};


/** ITERATORS

    An iterator is an object facilitating traversal of a container, 
    particularly lists. Thus, the iterator object is able to provide the next 
    element in a container on demand.
*/


/** GARBAGE COLLECTION
    
    A garbage collector ideally frees memory no longer used by the program. C++ 
    does not have garbage collection. Smart pointers are a potential remedy, 
    they are an abstract type simulating pointer behaviour, while adding 
    features such as automatic memory management.
*/


/** THREADS VS. PROCESSES

    Threads are for small tasks, processes for big tasks. Processes have their 
    own memory/address space allocated by the (loader part of the) OS, and 
    threads of the process share this space. Threads are spawned from a 
    process' primary thread.

    Using threads in C++ requires #include <thread>, then to create a thread 
    object, supplying it with a function to thread, along with that function 
    parameters,
*/

#include <thread>

void thread_example() {
    thread t(accessNamespace);
    // and executing 
    t.join();
}
    
/**
    A piece of code is thread-safe if it manipulates shared data structures 
    only in a manner that guarantees safe execution by multiple threads at the 
    same time i.e. free of race conditions i.e. events which change the result 
    of the program output.
*/


/** MVC

    Model-view-controller (MVC) is an architectural design pattern for user 
    interfaces. The three components are interconnected as an internal 
    representation (model), a view (manifestation), and controller (supplying 
    user interaction). It is very popular in web programming (see Ruby on Rails 
    and Django for server-side, AngularJS for client-side).
*/


/** SOFTWARE DESIGN PATTERNS

    Design patterns come in various categories: creational, behavioural, structural, and concurrency.

    A creational example is the singleton (ensure only one object of a class exists at a time).

    A structural example is a proxy i.e. essentially to write a wrapper class.

    A behavioural example is an iterator.

    A concurrency example is join. 
*/


/** DATA STRUCTURES

    At the most basic level, primitive types themselves are data structures--
    boolean, character, integer, float (32-bit real), double (64-bit real), and 
    enumerated type (categorical).

    Arrays and tuples are considered to be composite data types. There is no 
    meta-information involved in structuring them, they are just contiguous 
    groups. It isn't, however, a container.

    Abstract data types come in several categories: lists, trees, graphs, sets, 
    queues, associative arrays; with dozens of variants. An associative array 
    is similar to a hash table, but has some other features.

    Some notable examples of the above are:

    Linked list: this benefits mainly for space efficiency--N elements are 
    stored in N containers. Insertion is also straightforward. However, 
    searching must be linear.

    Binary trees have several variants including binary search trees and 
    (self-balancing binary) red-black trees. A simple binary search tree (BST) 
    adds elements to the left if they are less than a root or interior node, 
    and to the right if greater than. This makes search efficient logN time.

    A B-tree is a generalisatoin of a BST in which a node can have multiple 
    children. Some parameter determines the maximum number of children. There 
    are some other features such as splitting nodes to improve load balancing. 
    There also exists such a thing as B+-tree where keys are stored at nodes. 
    Search times are again logarithmic.

    A trie (or radix tree) is another tree structure where words (or numbers) 
    are stored by prefix, starting with the null prefix, ø.

    A FIFO queue is known as a queue. A LIFO queue is known as a stack. These 
    are considered linear structures, because they are conceptually similar to 
    an array with special insertion rules.

    Then there are general trees and trees with special relations between nodes 
    like heaps.
*/


/** SEARCH, SORTING, ALGORITHMS AND COMPLEXITY

    Searching algorithms depend on the chosen data structure involved, and may 
    be much faster when the data has some order. Indeed, effort may be expended 
    on insertion operations, such as in a binary tree, such that when it comes 
    time to search, the cost is minimised.
    
    When dealing with an array, searching algorithms don't leave much to the 
    imagination. If the array is not sorted, then only one deterministic 
    algorithm exists--linear search, whereby all elements must be checked until 
    the sought element is found, costing O(N/2) operations on average (1 in the 
    best case, N in the worst). If the array is sorted, a binary search can be 
    completed in at most O(log N) time.

    Special data structures give no better search performance than an ordered 
    array, unless an extra space cost is incurred. For example, a hash table 
    supports O(1) search time, but the data structure must be much larger than 
    the state space of keys.

    Sorting algorithms are more interesting. These only make sense in the 
    context of an unsorted array. The simplest/most naive algorithm is 
    insertion sort. This moves along the array element-wise, and swaps an 
    element backwards until it is locally sorted. Then the first part of the 
    array is in order. Continuing assures the whole array is sorted. The 
    algorithm runs in O(N^2) time on average, and at least O(N) (in the case 
    the array is already sorted). Clearly, there are at most 1 + 2 + 3 + ... + 
    N - 1 ~ N^2/2 swaps to make, in the even the array is sorted backwards.

    A much better (and highly popular) sorting algorithm is quicksort. In this 
    algorithm, a pivot element is chosen (say, the final element) and the other 
    elements are shuffled/swapped such that all elements less than the pivot 
    are to the left of the pivot, and those greater are on the right. The 
    shuffling operation is O(N). The algorithm continues recursively, repeating 
    this operation for the two unsorted halves, and so on, logN times, until 
    the array is sorted. The algorithm runs on average in O(NlogN) time. The 
    assumption is that the array is randomly sorted, so the pivot element has 
    even chances of being the true median element. In the worst case, the 
    algorithm runs in O(N^2) time. Heap sort is therefore theoretically 
    superior, as it never performs worse than O(NlogN).

    The radix sort algorithm, an inspired method, sorts elements in O(N) time, 
    incurring a small memory overhead. This works by considering the digits (or 
    characters) of elements in ascending order. Elements are funnelled to a 
    series of bins based on this digit. Now the numbers are ordered with 
    respect to the LSD. The may be return to the list. The operation is 
    repeated for the second LSD. Now the numbers are ordered with respect to 
    the second LSD, and wherever the same, ordered with respect to the first 
    LSD to "break the tie", by virtue of the first round of sorting. This is 
    repeated until MSD is sorted.

        55 107 1 54 1000
    =>  1000 1 54 55 107 ... position after funneling to buckets and returning 
        to list.
    =>  1000 01 107  54 55 ... note how 54 and 55, original inverted, retain 
        the correct order after the first iteration
    =>  1000 001 054 055 107  ... missing digits are treated as zeros
    =>  0001 0054 0055 0107 1000 ... and sorting is complete

    We thus require O(N) memory for the array, and O(kN) memory for the bins, 
    which are recycled, where k is the maximum number of digits. The time 
    complexity is O(kN).
*/

/** VON NEUMANN ARCHITECTURE

    The von Neumann architecture is a conceptual design for a computer 
    architecture by John von Neumann in 1945. It consists of input and output 
    to a computer consisting of a CPU and memory. The CPU further consists of 
    a control unit and arithmetic/logic unit.
*/


/** WHAT IS A BUS/BUSS?

    A system bus is hardware providing a communication channel between hardware 
    components.
*/


/** WHAT IS x86?

    x86 refers to a family (hence the 'x') of 32-bit processors by Intel. x64 
    is the family of 64-bit processors, which can for example directly 
    reference memory addresses of size 2^64.
*/


/** WHAT IS A BOOTSTRAP?

    This describes the self-sustaining process of booting a computer from 
    simple to complex. It also refers to an early piece of fundamental software 
    hand-written directly to machine code to allow other software compilers to 
    be written, to allow other software to be written, in which, paradoxically, 
    better compilers and bootstraps could be written.
*/


/** BOOTING

    Booting is essentially putting the computer into a state where it is 
    interactive to humans, by climbing layers of abstraction.

    The basic input output system (BIOS) is firmware for a particular 
    motherboard model that initialises i/o hardware at boot time. It is the 
    first event during booting. It loads a boot loader.

    A boot loader is a small piece of software that puts an OS into memory.

    An operating system is system software that manages computer hardware and 
    software resources and provides common services for computer programs.
*/


/** WHAT IS A KERNEL, A SHELL, POSIX?

    A kernel is a fundamental part of an operating system. It is the first 
    piece of software loaded at boot (by the bootloader) and has complete 
    control of the system, managing use of hardware (memory, CPU) by 
    applications. The kernel provides program execution, memory management, 
    the file system, device drivers, and more.

    A shell is a user interface. It can be either a command line interface 
    (CLI) or graphical user interface (GUI). Bash (Bourne Again Shell) is a CLI 
    and command language (bash script) written for the GNU (GNU's Not Unix!
    --Richard Stallman) project as a replacement for the Bourne Shell (sh) 
    written for proprietary Unix systems. It is the default shell on Linux and 
    OS X, and is coming to Windows 11. It is a POSIX shell.

    POSIX (portable operating system interface) is a standard defining an API 
    for interoperability with Unix operating systems.
*/


/** FILE SYSTEMS

    File systems provide the data structures and rules of compilation and 
    access for files stored in memory. This is not to be confused with a 
    directory structure, which is an abstraction over a file system. Famous 
    examples are FAT32 (File Allocation Table), which has limitations on 4GB 
    file sizes, and NTFS (New Technology File System). Another example is 
    Hadoop Distributed File System (HDFS).
*/


/** VERSION CONTROL SOFTWARE

    git, CVS (Concurrent Versions System), SVN (subversion)
*/


/** Package manager

    A package manager is software automating the installation of software. 
    Examples are apt-get for Linux operating systems and 3rd party Homebrew for 
    OS X. easy_install and pip are a related idea for installing Python 
    libraries.
*/

/** SECONDARY MEMORY

    Solid-state drive (SSD) vs. Hard Disk Drive (HDD)

    Like a memory stick, there are no moving parts to an SSD. Rather, 
    information is stored in microchips. Conversely, a hard disk drive uses a 
    mechanical arm with a read/write head to move around and read information 
    from the right location on a storage platter. This difference is what makes 
    SSD so much faster.
*/

int main () {}
