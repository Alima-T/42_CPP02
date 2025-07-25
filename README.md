# The Orthodox Canonical Form in C++

## 🛠️ Rule of Three (pre-C++11)

Before C++11 introduced move semantics, C++ developers followed the **Rule of Three** when working with classes that manage resources manually (like dynamic memory, file handles, or raw pointers).

The rule states:

> If your class needs any one of the following:
> - A **destructor**,
> - A **copy constructor**,
> - A **copy assignment operator**,
> 
> Then you most likely need to implement all **three**.

This rule helps ensure **deep copying** and **safe cleanup** of resources to prevent memory leaks, double-deletes, or shallow copies.
Если необходим хотя бы один из методов 1,2 или 3, то нужно реализовать все три для корректного копирования объектов и освобождения ресурсов, чтобы избежать **утечек памяти**, **двойного удаления** или **поверхностного копирования**.
## ❌ Что будет, если игнорировать это правило?
Если вы реализуете только один метод (например, деструктор), но не реализуете конструктор копирования и оператор присваивания, то:
- При копировании объекта оба экземпляра будут указывать на одну и ту же область памяти.
- При удалении возникнет двойное освобождение памяти (double delete).
- Это приведёт к неопределённому поведению, сбоям или повреждению памяти.
---

### 🧪 Classic Example

```cpp
class MyClass {
private:
    int* data;

public:
    // 1. Constructor
    MyClass() : data(new int(0)) {}

    // 2. Copy Constructor
    MyClass(const MyClass& other) : data(new int(*other.data)) {}

    // 3. Copy Assignment Operator  - Оператор присваивания копированием
    MyClass& operator=(const MyClass& other) {
        if (this != &other) {
            delete data;
            data = new int(*other.data);
        }
        return *this;
    }

    // 4. Destructor
    ~MyClass() {
        delete data;
    }
};
---
```
## ✋ Правило Пяти (C++11 и новее)
### Что такое Правило Пяти?
## 💡 Why is it Important?
If a class allocates memory or handles other resources (like file handles), it must:
- Allocate them correctly,
- Copy or move them correctly,
- And release them correctly.
> Если вашему классу требуется управлять ресурсами (например, динамической памятью), и вы реализуете хотя бы один из следующих методов:
It includes the following:

1. **Default Constructor**  
2. **Copy Constructor - конструктор копирования**  
3. **Copy Assignment Operator - оператор присваивания копированием**  
4. **Destructor**  
5. **Move Constructor - конструктор перемещения** (C++11)  
6. **Move Assignment Operator - оператор присваивания перемещением** (C++11)  

## 💡 Когда это нужно?
Если ваш класс управляет ресурсами напрямую (например, через new/delete), он должен корректно обрабатывать как копирование, так и перемещение объектов. Это важно при:
Возврате объектов из функций по значению,
Передаче временных объектов,
Использовании STL-контейнеров, которые перемещают элементы для оптимизации.

**Rule of Five (C++11 and newer)**
Failing to define these functions can cause **shallow copies**, **memory leaks**, or **undefined behavior**.

## 🧪 Example

```cpp
class MyClass {
private:
    int* data;

public:
    // Default constructor
    MyClass() : data(new int(0)) {}

    // Copy constructor Оператор присваивания копированием
    MyClass(const MyClass& other) : data(new int(*other.data)) {}

    // Copy assignment operator Конструктор перемещения
    MyClass& operator=(const MyClass& other) {
        if (this != &other) {
            delete data;
            data = new int(*other.data);
        }
        return *this;
    }

    // Destructor
    ~MyClass() {
        delete data;
    }

    // Move constructor   // 5. Оператор присваивания перемещением
    MyClass(MyClass&& other) noexcept : data(other.data) {
        other.data = nullptr;
    }

    // Move assignment operator
    MyClass& operator=(MyClass&& other) noexcept {
        if (this != &other) {
            delete data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }
};

```
## 🚀 Best Practice
Whenever possible, prefer RAII (Resource Acquisition Is Initialization) and standard containers or smart pointers like std::vector, std::unique_ptr, etc. With those, the Rule of Zero applies—you don't need to write any of the five functions manually.


## ✅ Альтернатива — Правило Нуля
Современный C++ предлагает безопасные альтернативы ручному управлению памятью:
std::unique_ptr — для уникального владения ресурсом.
std::shared_ptr — для совместного владения.
std::vector, std::string, std::map и другие стандартные контейнеры — уже управляют ресурсами.
Если вы используете их, компилятор сгенерирует корректные версии всех пяти методов сам. Это называется Правило Нуля (Rule of Zero) — вы не пишете ни одного из специальных методов вручную.