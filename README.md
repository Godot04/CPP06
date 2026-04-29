# C++ - Module 06: C++ Casts

![42 school](https://img.shields.io/badge/42-School-000000?style=flat-square&logo=42&logoColor=white)
![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=flat-square&logo=c%2B%2B&logoColor=white)
![Standard](https://img.shields.io/badge/Standard-C%2B%2B98-blue?style=flat-square)

## About

This repository contains exercises for Module 06, focusing on type casting mechanisms in C++ (C++98 style). Each exercise explores different casting operators and their appropriate use cases, helping you understand when and why to use each cast type in real-world scenarios.

## Project Goals

- Understand the four main C++ cast operators: `static_cast`, `dynamic_cast`, `reinterpret_cast`, and `const_cast`
- Learn proper type conversion handling for scalar types with error checking
- Practice pointer/integer conversions and their implications
- Implement polymorphic type identification using `dynamic_cast` without `typeid`
- Develop awareness of casting safety and runtime behavior

## Exercise Overview

The repository contains the following exercise directories:

- `ex00/` - **Conversion of scalar types**
  - Implements a `ScalarConverter` class that detects and converts between `char`, `int`, `float`, and `double` types from string representations.
  - Demonstrates `static_cast` for safe, implicit conversions between related types.
  - Handles edge cases: non-displayable characters, special float/double values (NaN, ±infinity), and overflow detection.
  - Learning concepts: type detection, safe type conversion, numeric limits, special floating-point values.

- `ex01/` - **Serialization**
  - Implements a `Serializer` class with `serialize()` and `deserialize()` methods for pointer-to-integer conversions.
  - Uses `reinterpret_cast` to convert between pointers and unsigned integers (`uintptr_t`).
  - Demonstrates pointer aliasing and the relationship between pointer addresses and integral values.
  - Learning concepts: `reinterpret_cast`, pointer arithmetic as integers, address preservation through conversion.

- `ex02/` - **Identify real type**
  - Builds a class hierarchy with a `Base` class and three derived classes (`A`, `B`, `C`).
  - Implements type identification functions using `dynamic_cast` without relying on `std::typeinfo`.
  - Distinguishes between pointer-based and reference-based polymorphic type checking.
  - Learning concepts: `dynamic_cast`, runtime polymorphism, virtual destructors, type-safe downcasting.

Each exercise is self-contained and builds understanding progressively from basic conversions to advanced polymorphic behavior.

## Compilation

Each exercise has its own `Makefile` and can be built independently.

### Build an Exercise

```bash
cd ex00
make
```

Replace `ex00` with any other exercise directory as needed.

### Available Targets

- `make` - Compile the exercise
- `make clean` - Remove object files
- `make fclean` - Remove object files and the executable
- `make re` - Rebuild everything from scratch

### Compilation Flags

- Compiler: `c++`
- Standard: `-std=c++98`
- Warnings: `-Wall -Wextra -Werror`

## Technical Notes

- The codebase strictly adheres to the C++98 standard as required for these exercises.
- Type casting must be explicit and justified — your choice of cast operator will be reviewed during evaluation.
- No use of `std::typeinfo` or `typeid` in `ex02` — `dynamic_cast` provides safe downcasting without RTTI.
- All classes follow the Orthodox Canonical Form where applicable (ex00 and ex01 have non-instantiable classes).
- Proper error handling is essential: invalid conversions must be detected and reported, not silently fail.

## Testing

- **ex00**: Test scalar conversions with various inputs (integers, floats, special values like NaN). Verify overflow detection and character displayability checks.
  ```bash
  ./convert 0
  ./convert nan
  ./convert 42.0f
  ```

- **ex01**: Serialize a Data object to an integer, then deserialize it back. Verify the final pointer equals the original.
  ```bash
  ./serialization
  ```

- **ex02**: Generate random derived objects through a base pointer, then identify their actual type using both pointer and reference functions.
  ```bash
  ./identify
  ```

## Author

**opopov** - 42 School Student
