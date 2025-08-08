# Range-Based for loop

int a[ ] = {1, 2, 3, 4, 5};

for(int x : a){ cout << x ;}. —> ensures we dont go beyond the size.

for(auto x : a){ cout << x ;}. —> we can also write like this but it create a new copy of x everytime.

for(auto &x : a){ cout << x ;}.  —> Instead we write like this to avoid creation of copy of x everytime.

**With Reference:**

```cpp
Also we can wrtie like this, we can modify the value of x,

for(auto &x : a){
        x= 3;
        cout << x <<ends;
    }
O/P:- 3 3 3 3 3 

🔍 What’s Happening:
for (int &x : a)
Then x = 3; would modify the actual array, and a would become {3, 3, 3, 3, 3}.

Note dont assume x as a counter. It is the actual element. You're **not looping on the value of x**. You're looping on the **elements of a**, which is **always 5 elements**, no matter what their values are.
```

**Without reference:**

```cpp

for(int x : a){
        x= 3;
        cout << x <<ends;
    }
    
O/P: 3 3 3 3 3

🔍 What’s Happening:
for (int x : a) → this means x is a copy of each element in a.

So, changing x = 3; only changes the copy, not the array.

You're just printing the modified copy (x = 3) each time.
But the original array a[] remains unchanged:
After this loop, a is still: {1, 2, 3, 4, 5}
```

> Note: If we dont want that x should be modifed, then we have to declare that variable as const reference.
> 

```cpp
for(const auto &x : a){
        // x= 3;  --> Now this line will give error
        cout << x <<ends;
    }
```

The range based for loop can also iterate over an initializer list. An initializer list is also a range.

```cpp
for(auto x: {1,2,3,4,5}){
	cout << x;
}
```

Differences b/w for and Range-Based loops

![temp_image_1753904572894.jpg](Range-Based%20for%20loop%202405c0a2af62801d947ae66a45b94208/d7cb1ab6-ac2f-483e-8d5d-98e37edd6692.png)

### **Internal working of Range-Based For Loop:**

```cpp
First step:

int a[]= {1, 2, 3, 4, 5};
int *beg = &a[0]; // or a
int *end = &a[5];
while(beg != end){
	cout << *beg;
	++beg;
}

Second step:
Now, instead of manually getting the value of beg and end we can use some function introduced in c++11. --> begin() and end() // automatically returns the address of a.

int *beg = begin(a);
int *end = end(a);

Now, Lets take 
auto range = a;  // Here range is a pointer type pointing to a ; 
									//It means int* range = a;
									
auto begin = begin(a); // Here we are using a in begin and end because range
auto end = end(a);		 // will not work inside begin and end as it holds
												// and integer and range is a pointer.
												
for(;begin != end; ++begin){
	auto v = *begin;
}
```

```cpp
So, range based loop below
			for(auto x : a){
				cout<<a;
			}
			
is expanded to :

auto range = a;  	
auto begin = begin(a); 
auto end = end(a);										
for(;begin != end; ++begin){
	auto v = *begin;
}
```

> So, for each loop works on where the object supports ! = and begin and end.
> 

begin and end should be of same type. But in some ranges it will not be same. For example:

char array begin is char and end is a null character.

In this scenario, range based for loop will not work.

**There was one changes in C++17:**

begin and end need not be of same type. begin and end can be of different type. But they must provide comparision operator ( ! = ) so that range based for loop can compare them.

Also the change in expansion is :

```cpp
auto &&range = a; // this forward referencing && allows us to use l-value and                           r-value in range based for loop.
										// Ex:	for(auto x : {1,2,3,4}) --> rvalue as a range
										//      for(auto x : a) --> lvalue as a range   
										
// Now, after forwarding reference, the type of range becomes type of a; So we can use it int the place of array a;
auto begin = begin(range); 
auto end = end(range);										
for(;begin != end; ++begin){
	auto v = *begin;
}
```

<aside>
💡

Important Point: 

If we want our class to work with range based for loop then we have to provide iterator for that class.

</aside>

### More things to know

So, we already studied that

```cpp
auto ptr = a; // a is an array here

	means

int* ptr = a;
```

- `ptr` is now a pointer to the **first element** of the array `a`.
- You can do things like:

```cpp
cout << ptr[0];  // prints 1
cout << *(ptr + 2); // prints 3
```

## ⚠️ Key Things to Know

1. `auto ptr = a;` → `ptr` becomes `int*`, **not** `int[5]`
2. If you really want to preserve the **array type**, you must use:
    
    ```cpp
    auto& arrRef = a;  // arrRef is of type int (&)[5]
    ```
    

## 🎯 Comparison

| Expression | Deduces `auto` as | Notes |
| --- | --- | --- |
| `auto ptr = a;` | `int*` | Array decays to pointer |
| `auto& ref = a;` | `int (&)[5]` | Reference to array, not decayed |
| `decltype(a)` | `int[5]` | Full array type preserved |

## 🧪 Bonus: Why `decltype(a)` is Powerful

You can create exact-type clones:

```cpp
decltype(a) b = {1, 2, 3};  // b is int[3]
```

Whereas:

```cpp
int* b = a;  // b is just a pointer, not an array
```

## 🎯 Goal-Based Decision Guide

| Use Case | Best Choice | Why |
| --- | --- | --- |
| Iterate over elements and **modify** them | `auto& x : a` | Gets a reference, avoids copy, updates original array |
| Just want to **read** values | `auto x : a` | Cleaner, faster for small types like `int`, avoids accidental changes |
| Need to **preserve array size/type exactly** | `decltype(a)` or `auto&` | Retains array size and type (e.g., `int[5]`, not `int*`) |
| Pass array to a function **without decay** | `int (&arr)[N]` or `template<size_t N>` | Prevents decay, keeps array bounds available |
| Want to create a **clone with same type** | `decltype(a) b = {...}` | Ensures type, size match |
| Want to get **just a pointer** | `auto ptr = a` | Explicitly means “I want a pointer” |

## ✅ Summary: What to Use When

| Intent | Code Example |
| --- | --- |
| Modify elements | `for (auto& x : a)` |
| Read-only access | `for (auto x : a)` |
| Clone full array type | `decltype(a) b = {...}` |
| Prevent array decay in func | `int (&arr)[N]` or template style |
| Just get pointer | `auto ptr = a` |

## 🧠 What is "Array Decay"?

> Array decay means: an array automatically converts into a pointer to its first element in most expressions.
> 

That means:

```cpp
int a[] = {10, 20, 30};
```

Even though `a` is technically of type `int[3]`, in most places, it is **treated as**:

```cpp
int* a = &a[0];  // pointer to first element
```

So **`a` becomes a pointer** — this is called *decay*.

### ✅ Happens in:

```cpp
auto ptr = a;          // a decays to int*
int* p = a;            // same as &a[0]
sizeof(a + 0);         // decays before doing pointer math
```

---

### ❌ Doesn’t Happen in:

```cpp
sizeof(a);             // stays as int[3], so result = 3 * 4 = 12
decltype(a);           // gives int[3]
template<int (&arr)[3]> // array type preserved
```

---

## ✅ Summary

| Concept | Explanation |
| --- | --- |
| Array decay | Array turns into a pointer to its first element |
| Why it happens | Because C++ treats arrays as pointers in expressions |
| Problem it causes | You lose array size/type info |
| How to avoid it | Use reference (`int (&a)[N]`) or `decltype(a)` |
| Function workaround | Use templates to deduce size without decay |

---