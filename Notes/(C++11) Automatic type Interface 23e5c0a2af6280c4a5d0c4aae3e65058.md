# (C++11) Automatic type Interface

auto keyword:-

Indicates storage class of a variable in C and pre C++11.

Meaning changed in C++11.

The compiler automatically takes the type from the initializer. The initializer is important.

      **auto <identifier> = <initializer>**

auto x; —> not allowed

auto x = 5 —> allowed

Ex1 : auto sum = i + 4.3f (i —> int )

the type of sum will be going to be largest type i.e. float in this case.

Ex2 : auto res= sum(a,b); (return type of sum is int)

Ex3 : static auto y =2;

Ex4: const int x = 10;

 auto var = x;  —> here the qualifier of x is discarded, var is not a const int here

 const auto var = x;  → now var becomes const.

auto &var1 = x; → if we use reference, the qualifier will not be discarded. var1 is a       const reference here.

auto ptr = &x; → if we use pointer, the qualifiers are not discarded. ptr is a pointer to const int. Here we should not write like auto *ptr = &x to avoid confusion. We should avoid auto when intializing references or pointers.

**Initializer list:**

auto list = {1, 2, 3, 4, 5} ; → this works fine  and this an initializer list.

auto list{1,2,3,4,5} ; → this is wrong we cant write like this. Although we can write as below.

auto list{1} ; → the type of list is int.