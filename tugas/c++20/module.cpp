export module math_operations; 

export int add(int a, int b)
    return a + b;
}

import math_operations; // import modul

#include <iostream>

int main() {
    int result = add(10, 5); // Memanggil fungsi dari modul
    std::cout << "Hasil penjumlahan: " << result << std::endl;
    return 0;
}

📁 project/
├── math.ixx        ← interface module
├── math.cpp        ← implementasi
└── main.cpp        ← program utama