# Data Types

<climits> or <limits.h>

![Screenshot 2025-07-23 at 12.16.04 AM.png](Data%20Types%202385c0a2af6280ce9bcad2a38596517b/Screenshot_2025-07-23_at_12.16.04_AM.png)

<cfloat> or <float.h>

![image.png](Data%20Types%202385c0a2af6280ce9bcad2a38596517b/image.png)

---

bool flag =0 ;

if flag == 0 —> its false

if flag == any non-zero number —> its true

---

Uniform initialization in modern c++ using curly brances.

int a {0}

int a[5]{1,2,3,4,5}

---

Console I/O

**iostream Library and std —> namespace**

std::basic_ostream & std::basic_istream

std::ostream & std::istream (class)

std:cout & std:cin (object)

<< (insertion operator)

>> (extraction operator)

endl is a manipulator which changes to new line and fluses buffer.

—> to take line as input

getline(cin,name);

cin.getline(name, 64, ‘/n’)

---

We cannot run a program without main function as it is the entry point of any program 

main function always have a return type unlike c language where we have void main

main can have arguments—> two arguments which are used for command line arguments

int main(int argc, char *argv)

—> argc stand for argument count, it is a integer that stores number of command line argument passed to the main function, it also includes the count for the name of the program.

—>argv stand for argument vector, it is an array of C-style strings like (char*) where every elements points to a command line argument. It does not store the actual argument, but the pointer to the argument. The argv[0] always contain the name of the program.