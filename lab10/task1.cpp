#include <iostream>
#include <vector>

class IntArray {
public:
    std::vector<int> data;

    IntArray() = default;

    explicit IntArray(size_t size, int init_val = 0) : data(size, init_val) {}

    IntArray(const std::vector<int>& vec) : data(vec) {}

    IntArray(const IntArray& other) = default;

    int max() const {
        if (data.empty()) {
            throw "Помилка: пошук максимуму в порожньому масиві.";
        }
        int max_val = data[0];
        for (size_t i = 1; i < data.size(); ++i) {
            if (data[i] > max_val) {
                max_val = data[i];
            }
        }
        return max_val;
    }

    int min() const {
        if (data.empty()) {
            throw "Помилка: пошук мінімуму в порожньому масиві.";
        }
        int min_val = data[0];
        for (size_t i = 1; i < data.size(); ++i) {
            if (data[i] < min_val) {
                min_val = data[i];
            }
        }
        return min_val;
    }

    long long sum() const {
        long long total = 0;
        for (int x : data) {
            total += x;
        }
        return total;
    }

    void sort() {
        for (size_t i = 0; i < data.size(); ++i) {
            size_t min_idx = i;
            for (size_t j = i + 1; j < data.size(); ++j) {
                if (data[j] < data[min_idx]) {
                    min_idx = j;
                }
            }
            if (min_idx != i) {
                int temp = data[i];
                data[i] = data[min_idx];
                data[min_idx] = temp;
            }
        }
    }

    IntArray operator+(const IntArray& rhs) const {
        if (data.size() != rhs.data.size()) {
            throw "Помилка: додавання масивів різної довжини.";
        }
        IntArray result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] + rhs.data[i];
        }
        return result;
    }

    IntArray operator*(int scalar) const {
        IntArray result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] * scalar;
        }
        return result;
    }

    int& operator[](size_t index) {
        if (index >= data.size()) {
            throw "Помилка: індекс виходить за межі масиву.";
        }
        return data[index];
    }

    const int& operator[](size_t index) const {
        if (index >= data.size()) {
            throw "Помилка: індекс виходить за межі const-масиву.";
        }
        return data[index];
    }
};

IntArray operator*(int scalar, const IntArray& arr) {
    return arr * scalar;
}

std::ostream& operator<<(std::ostream& os, const IntArray& arr) {
    os << "[";
    for (size_t i = 0; i < arr.data.size(); ++i) {
        os << arr.data[i] << (i + 1 < arr.data.size() ? ", " : "");
    }
    os << "]";
    return os;
}

std::istream& operator>>(std::istream& is, IntArray& arr) {
    for (size_t i = 0; i < arr.data.size(); ++i) {
        if (!(is >> arr.data[i])) {
            break;
        }
    }
    return is;
}

// =========================================================================
//                               FRIEND
// =========================================================================

class IntArrayFriend {
private:
    std::vector<int> data;

public:
    explicit IntArrayFriend(size_t size, int init_val = 0) : data(size, init_val) {}
    IntArrayFriend(const std::vector<int>& vec) : data(vec) {}

    friend IntArrayFriend operator+(const IntArrayFriend& lhs, const IntArrayFriend& rhs);
    friend std::ostream& operator<<(std::ostream& os, const IntArrayFriend& arr);
};

IntArrayFriend operator+(const IntArrayFriend& lhs, const IntArrayFriend& rhs) {
    if (lhs.data.size() != rhs.data.size()) {
        throw "Помилка: масиви мають різну довжину.";
    }
    IntArrayFriend result(lhs.data.size());
    for (size_t i = 0; i < lhs.data.size(); ++i) {
        result.data[i] = lhs.data[i] + rhs.data[i];
    }
    return result;
}

std::ostream& operator<<(std::ostream& os, const IntArrayFriend& arr) {
    os << "[";
    for (size_t i = 0; i < arr.data.size(); ++i) {
        os << arr.data[i] << (i + 1 < arr.data.size() ? ", " : "");
    }
    os << "]";
    return os;
}

int main() {
    std::cout << "=== Звичайні дані та базові операції ===\n";
    IntArray a(std::vector<int>{10, -5, 20, 3});
    IntArray b(std::vector<int>{1, 5, -10, 7});

    std::cout << "Масив a: " << a << "\n";
    std::cout << "Масив b: " << b << "\n";
    std::cout << "Сума a + b: " << (a + b) << "\n";
    std::cout << "Множення a * 3: " << (a * 3) << "\n";
    std::cout << "Множення 2 * b: " << (2 * b) << "\n";
    std::cout << "Макс(a) = " << a.max() << ", Мін(a) = " << a.min() << ", Сума(a) = " << a.sum() << "\n";

    a.sort();
    std::cout << "Відсортований a: " << a << "\n\n";

    std::cout << "=== Копіювання та доступ [] ===\n";
    IntArray copy_a = a;
    copy_a[0] = 999;
    const IntArray const_arr(std::vector<int>{7, 8, 9});
    std::cout << "Оригінал a (не змінився): " << a << "\n";
    std::cout << "Змінена копія: " << copy_a << "\n";
    std::cout << "Читання з const_arr[1]: " << const_arr[1] << "\n\n";

    std::cout << "=== 3. Граничні дані ===\n";
    IntArray empty_arr;
    IntArray single_arr(1, 42);
    std::cout << "Порожній масив: " << empty_arr << ", сума = " << empty_arr.sum() << "\n";
    std::cout << "Один елемент: " << single_arr << ", макс = " << single_arr.max() << ", мін = " << single_arr.min() << "\n\n";

    std::cout << "=== Перевірка альтернативної реалізації через friend ===\n";
    IntArrayFriend f1(std::vector<int>{2, 4, 6});
    IntArrayFriend f2(std::vector<int>{1, 3, 5});
    std::cout << "Friend сума f1 + f2: " << (f1 + f2) << "\n\n";

    std::cout << "=== Некоректні операції ===\n";
    try {
        IntArray bad_sum = a + single_arr;
    } catch (const char* msg) {
        std::cout << "Виняток (+): " << msg << "\n";
    }

    try {
        int val = a[10];
        (void)val;
    } catch (const char* msg) {
        std::cout << "Виняток ([]): " << msg << "\n";
    }

    try {
        int m = empty_arr.max();
        (void)m;
    } catch (const char* msg) {
        std::cout << "Виняток (max): " << msg << "\n";
    }

    return 0;
}