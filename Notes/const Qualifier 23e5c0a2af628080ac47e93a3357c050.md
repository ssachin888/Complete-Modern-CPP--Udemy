# const Qualifier

- Creates a variable that is constant.
- Values cannot be modified. Attempt to modify will cause compilation error.
- Qualified to a declaration, but always need an initializer, otherwise compilation error.
- Replaces C macros.
    
    Macros largely used in C for constants.
    
    But constants have disadvantages. They are not type safe and dont have scope. Scope is global. const dont have these problems. Macros don’t appear in debugger (like GDB) as real functions or variables. So hard to debug. ✅ Alternative: Use `const`, `inline`, or `constexpr`
    
- commonly used with references.
    
    const <type> <variable> {intializer}
    
    const float PI {3.141};
    
    ![image.png](const%20Qualifier%2023e5c0a2af628080ac47e93a3357c050/image.png)
    

Its a good practice to use constant declaration with Uppercase letter just to denote that the value is this variable will be fixed at compile time and cannot be modified letter.

- constant always need an initializer.

```cpp
void print(const int &ref){
	cout << ref << endl;
}
int main(){
	int x = 5;
	print(x);
	print(1); // this is allowed only when there is const. if we remove const from            // function call, it will give an error. Because reference is bound 
	           //to literal and  that is not allowed.
	return 0;
}
```

Note:
`const int &ref = a;` — makes `ref` read-only, **but `a` itself is still mutable**. we can modify a directly.

### 🧠 Key Concept:

> In C++, const T& can bind to temporaries, and the lifetime of the temporary is extended to match the reference.
> 

```cpp
#include <iostream>
using namespace std;

int getValue() {
    return 42;
}

int main() {
    const int &ref = getValue();
    cout << ref << endl;
    return 0;
}
Output : 42
```

### 🧠 Key Rule:

- `const int *ptr` → “**pointer to const int**” (value can't change, pointer can)
- Read right to left: `ptr` is a pointer to `const int`

### 🧠 Key takeaway:

> int *const ptr = &x; → "ptr is a constant pointer to an int"
> 
> 
> Value can change (`*ptr = ...`) but address can't (`ptr = ...`)
> 

### ✅ **Pointer + const Combinations Cheat Sheet**

| Declaration | Is pointer const? | Is value const? | Can change value (`*ptr = ...`)? | Can change address (`ptr = ...`)? |
| --- | --- | --- | --- | --- |
| `int *ptr;` | ❌ No | ❌ No | ✅ Yes | ✅ Yes |
| `const int *ptr;` or `int const *ptr;` | ❌ No | ✅ Yes | ❌ No | ✅ Yes |
| `int *const ptr = &x;` | ✅ Yes | ❌ No | ✅ Yes | ❌ No |
| `const int *const ptr = &x;` | ✅ Yes | ✅ Yes | ❌ No | ❌ No |

## 🧠 Conclusion:

- 🔸 **Const rules control the compiler syntax**
- 🔸 But **string literals** add a **runtime memory safety layer** — they're placed in **read-only memory**
- 🔥 So even if syntax allows it, **you can't safely modify string literals**

1. Differnces in below. State which are modifyable, the address or string.
    
    1) char *p = "Quick Heal"
    
    2) const char *q = "Quick Heal"
    
    3) char const *r = "Quick Heal"
    
    4) char* const s = "Quick Heal"
    
    5) const char* const t = "Quick Heal"
    

### 📊 Summary Table

| Declaration | Pointer Modifiable | String Modifiable | Notes |
| --- | --- | --- | --- |
| `char *p = "Quick Heal";` | ✅ Yes | 🚫 No (UB) | Technically allowed, but **unsafe** |
| `const char *q = "Quick Heal";` | ✅ Yes | ❌ No | Safe and correct |
| `char const *r = "Quick Heal";` | ✅ Yes | ❌ No | Same as above |
| `char* const s = "Quick Heal";` | ❌ No | 🚫 No (UB) | Pointer fixed, but string is still literal |
| `const char* const t = ...` | ❌ No | ❌ No | Fully const → safest, immutable setup |

```cpp
//Try to modify x1 & x2 and see the compilation output
int x = 5 ;
const int MAX = 12 ;
int &ref_x1 = x ;
const int &ref_x2 = x ;
 
//Try to modify the pointer (e.g. ptr1) and the pointee value (e.g. *ptr1)
const int *ptr1 = &x ;
int *const ptr2 = &x ;
const int * const ptr3 = &x ;
 
//Find which declarations are valid. If invalid, correct the declaration
const int *ptr3 = &MAX ;
int *ptr4 = &MAX ;
 
const int &r1 = ref_x1 ;
int &r2 = ref_x2 ;
 
int *&p_ref1 = ptr1 ;
const int*&p_ref2 = ptr2 ;
```

### ✅ Summary Table:

| Expression | Valid? | Why / What happens |
| --- | --- | --- |
| `ref_x1 = 10;` | ✅ Yes | `ref_x1` is a non-const reference to `x` |
| `ref_x2 = 20;` | ❌ No | `ref_x2` is a const reference — cannot modify |

| Declaration | Pointer Modifiable? | Value Modifiable? |
| --- | --- | --- |
| `const int *ptr1` | ✅ Yes | ❌ No |
| `int *const ptr2` | ❌ No | ✅ Yes |
| `const int *const ptr3` | ❌ No | ❌ No |

| Declaration | Valid? | Notes / Correction |
| --- | --- | --- |
| `const int *ptr3 = &MAX;` | ✅ Yes | OK |
| `int *ptr4 = &MAX;` | ❌ No | ❗️ Cannot assign `const int*` to `int*` |
| `const int &r1 = ref_x1;` | ✅ Yes | OK |
| `int &r2 = ref_x2;` | ❌ No | ❗️ Cannot bind non-const reference to const value |
| `int *&p_ref1 = ptr1;` | ❌ No | ❗️ Type mismatch — should be `const int*&` |
| `const int *&p_ref2 = ptr2;` | ✅ Yes | OK |