﻿# uni2-oop-lab-1
(Грищенко Юрій)


## Build process

This project uses [CMake](https://cmake.org/) as its build toolchain. This means that this is a cross-platform project that you can develop on any OS.

### Using an IDE

Visual Studio 2019 and CLion both have native support for CMake projects. Other IDEs might require addons or plugins to get them to work.

### Running on GNU/Linux

1. Install git, CMake and any C++ compiler (GCC is recommended) from your distro's reposiotry.
2. Clone the repository and run `cmake .` in the project's directory. This will set up the build environment for the project.
3. Run `make`. The output should appear in the `bin/` subdirectory. 

## Doxygen

If you want to generate documentation pages, install Doxygen, open a command propmt and enter `doxygen`. The generated documents should appear in the `docs/` subdirectory.

## Task

5. (***) Черга з пріоритетом на основі списку (реалізації на основі
зв’язного списку та масивів змінної довжини) та дерева. Додавання
елементу, забирання елементу (за правилами черги), подивитись
наступний елемент, не забираючи його.
  - +* за реалізацію на основі heap
  
.

7. (**) Адреси IPv4 (a1.a2.a3.a4, 0&lt;=ai&lt;=255) та IPv6
(b1:b2:b3:b4:b5:b6:b7:b8, кожна з bi – набір від 1 до 4 шістнадцяткових
цифр 0..9a..f). Адреси підмереж у форматі CIDR: address/subnet_bits, де
address – адреса в одному з форматів, subnet_bits – кількість бітів маски
підмережі. Перевірка належності адреси до підмережі.

  - +* за підтримку інших варіантів запису IPv6 адрес, наприклад
скорочень :: та IPv4 адрес в нотації IPv6;

  - +* за побудову адрес з текстового подання (parsing);

  - +* за додаткову підтримку MAC адрес та побудову IPv6 адреси
на основі MAC адреси.
