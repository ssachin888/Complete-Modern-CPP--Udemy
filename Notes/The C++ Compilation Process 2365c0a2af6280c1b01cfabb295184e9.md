# The C++ Compilation Process

### 🛠️ **0. Your C++ Code (Source File)**

You write a file like:

```cpp
cpp
CopyEdi
// hello.cpp
#include <iostream>

int main() {
    std::cout << "Hello, Sachin!" << std::endl;
    return 0;
}

```

Now you run:

```bash
g++ hello.cpp -o hello
```

But what **really** happens inside?

---

## ⚙️ 1. Preprocessing (`hello.i`) – The Preprocessor

📌 **Command:** `g++ -E hello.cpp -o hello.i`

- Expands all `#include`, `#define`, `#ifdef`, etc.
- Adds full content of header files (like `iostream`) into your code.
- Removes comments, expands macros, handles conditional compilation.

✅ Output: A huge flat file `hello.i` with pure C++ code.

---

## 🧾 2. Compilation (`hello.s`) – The Compiler

📌 **Command:** `g++ -S hello.i -o hello.s`

- Takes the preprocessed C++ and **translates** it to **Assembly**.
- All syntax checking and type checking happens here.
- Templates are instantiated here.
- Converts your code to architecture-specific **Assembly instructions**.

✅ Output: `hello.s` — assembly code file readable by humans.

---

## 🧱 3. Assembling (`hello.o`) – The Assembler

📌 **Command:** `g++ -c hello.s -o hello.o`

- Converts Assembly into **machine code** (binary form) — object file.
- Still not an executable. It's just a **partially compiled module**.
- Multiple `.o` files may be generated if your project has multiple `.cpp` files.

✅ Output: `hello.o` — an object file.

---

## 🔗 4. Linking – The Linker

📌 **Command:** `g++ hello.o -o hello`

- Resolves all **symbol references**:
    - Where is `std::cout` defined?
    - What’s the actual memory address of `main`?
- Links in **external libraries** like the C++ standard library (`libstdc++.so`) and system startup code.
- Produces a **final binary** with everything in place.

✅ Output: `hello` — final executable!

---

### 🧠 Advanced Tip: Compilation = Frontend + Backend

- **Frontend**: Handles parsing, syntax checking, generating intermediate code.
- **Backend**: Optimizes and turns IR into machine code.

---

## 🧰 Tools to View Internals

| Tool | Purpose |
| --- | --- |
| `g++ -E` | See preprocessed code |
| `g++ -S` | See assembly code |
| `g++ -c` | Create object files |
| `objdump` | Disassemble object/executable |
| `nm` | View symbols in object files |
| `ldd` | Show dynamic libraries used |

---

### 📦 Bonus: Compilation Pipeline Diagram

```scss

Your Code (.cpp)
     ↓
[Preprocessor]
     ↓
Expanded Code (.i)
     ↓
[Compiler]
     ↓
Assembly (.s)
     ↓
[Assembler]
     ↓
Object File (.o)
     ↓
[Linker]
     ↓
Executable (a.out / hello)
```

---

### 🔍 Real-World Understanding Helps With:

- Reducing compile time (e.g., using precompiled headers)
- Understanding `undefined reference` vs. `syntax error`
- Using `Makefile` or `CMake`
- Debugging symbols and symbol resolution
- Optimization flags (`O2`, `O3`, `g`, `Wall`, `std=c++17`)

🧰 Summary: All Stages with Commands

| Stage | Command | Output |
| --- | --- | --- |
| Preprocessing | `g++ -E hello.cpp -o hello.i` | `.i` file |
| Compilation | `g++ -S hello.i -o hello.s` | `.s` file |
| Assembling | `g++ -c hello.s -o hello.o` | `.o` file |
| Linking | `g++ hello.o -o hello` | Executable |

---

Note:

> “You're giving me a .i file (C-style preprocessed output), but you’re in C++ mode. I’ll assume this .i file is preprocessed C++, not C, but this auto-detection is deprecated.”
> 

### 🔧 Why This Happens

The `.i` file is expected to be from C, while preprocessed **C++** files should end with `.ii`.

So Clang gets confused when you give a `.i` file while using `clang++`.

> GCC tolerates this, but Clang++ is stricter about file extensions and mode assumptions.
> 

## 🚦 TL;DR

| Extension | Language | Meaning |
| --- | --- | --- |
| `.i` | C | Preprocessed C code |
| `.ii` | C++ | Preprocessed C++ code |

So when working with **C++**, use `.ii` instead of `.i`.