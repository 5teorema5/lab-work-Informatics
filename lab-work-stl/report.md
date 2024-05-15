<h2>Лаба по контенерам</h2>
<details>
  <summary><h3>1. Пример с лекции</h3></summary>
  
  Будем последовательно добавлять элементы в `std::vector`, следить за изменением размерности вектора - `capacity` и `size`. Эти значения записываем в файл, после чего построим график зависимомти размерностей вектора от количества итераций(числа добавляемых элементов).

<details>
  <summary>"task0.cpp"</summary>

  ```C++
  #include <iostream>
  #include <fstream>
  #include <vector>
  
  int main() {
      std::vector<int> v;
      std::ofstream of("../0.csv", std::ios::out);
      for (int i = 0; i < 4096; i++) {
          v.push_back(i);
          if (i % 100 == 0) {
              of << v.capacity() << ' ' << v.size() << '\n';
          }
      }
      return 0;
  }
  ```
  
</details>

![capacity_size](./img/image0.png)

Видим, что значение `size` изменяется линейно в соответствии с добавляемыми элементами, а вот значение `capacity` - скачкообразно, сответствуют степеняв двойки (1, 2, 4, 8, 16, 32, 64,..). Так происходит из-за того, что `size` - занимаемое место в векторе, соответственно, если мы добавили 1 элемент, то этот параметр увеличился на единицу. А вот `capacity` - это место, которое впринципе выделено под вектор, соотвественно, при достижении верхней границы этого места этот параметр автоматически увеличивается. А поскольку трудоёмко каждый раз увеличивать место на единицу, то этот параметр увеличивается с запасом.
  
</details>

<details>
  <summary><h3>2. Среднее время вставки элемента в произвольное место вектора</h3></summary>

Напишем свой `subvector`, помимо прочих методов, реализуем нужный нам метод `insert` - добавление элемента на конкретную позицию.

```C++
void Subvector::insert(int pos, int value) {
    if (this->top > this->capacity) {
        this->resize(this->top * 2 + 1);
    }
    for (unsigned int i = this->top - 1; i > pos; i--) {
        this->mas[i + 1] = this->mas[i];
    }
    this->mas[pos + 1] = this->mas[pos];
    this->top++;
    this->mas[pos] = value;
}
```

Будем тестировать наш метод `insert` для нашего `subvector`, а так же стандартный `insert` для `std::vector`. Для этого будем добавлять элемент, стая его на первое (нулевое) место, а так же будем засекать время работы этих методов, а потом строить график зависимости времени выполнения от размера вектора/сабвектора.

<details>
  <summary>"task1.cpp"</summary>

```C++
#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <chrono>
#include "subvector.h"

double get_time() {
    return std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::steady_clock::now().time_since_epoch()).count() / 1e6;
}

int rand_uns(int min, int max) {
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    static std::default_random_engine e(seed);
    std::uniform_int_distribution<int> d(min, max);
    return d(e);
}

int main() {
    std::ofstream f1("../1_1.csv", std::ios::out);
    std::ofstream f2("../1_2.csv", std::ios::out);

    Subvector subv;
    std::vector<int> v;
    for (int i = 0; i < 1048576; i++) {
        int value = rand_uns(0, 100);
        subv.push_back(value);
        v.push_back(value);
        if (i % 1000 == 0) {
            int new_value = rand_uns(0, 100);
            //int new_pos = rand_uns(0, subv.getTop());
            int new_pos = 0;
            auto start = get_time();
            subv.insert(new_pos, new_value);
            auto finish = get_time();
            auto time = finish - start;
            f1 << subv.getTop() << " " << time << "\n";

            start = get_time();
            v.insert(v.begin() + new_pos, new_value);
            finish = get_time();
            time = finish - start;
            f2 << v.size()<< " " << time << "\n";
        }
    }

    std::cout << subv.getCapacity() << '\n';

    return 0;
}
```
</details>

Итак, график для `subvector`:

![capacity_size](./img/image1.png)

Можем точно сказать, что ассимптотика нашего метода `insert` равна **O(N)**. Это и очевидно, поскольку для того, чтобы добавить элемент, нам нужно передвинуть весь сабвектор на одну позицию.

И график для `std::vector`:

![capacity_size](./img/image2.png)

Здесь так же ассимптотика составляет **O(N)**. Мы так же можем наблюдать некоторый излом - это происходит из-за больших данных. В общей картине - ничего не меняется.
  
</details>


<details>
  <summary><h3>3. Среднее время удаления одного элемента из произвольного места вектора</h3></summary>

Дополним предыдущий вектор, реализовав нужный нам метод `erase` - удаление элемента из конкретной позиции.

```C++
void Subvector::erase(int pos) {
    for (unsigned int i = pos; i < this->getTop() - 1; i++) {
        this->mas[i] = this->mas[i+1];
    }
    this->top--;
}
```

Будем тестировать наш метод `erase` для нашего `subvector`, а так же стандартный `erase` для `std::vector`. Для этого сначала заполним наши контейнера набором одинаковых чисел, а затем будем постепенно удалять первый (нулевой) элемент. Во время использования метода будем засекать время, а затем построим график зависимости времени выполнения от размера вектора/сабвектора.

<details>
  <summary>"task1.cpp"</summary>

```C++
#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <chrono>
#include "subvector.h"

double get_time() {
    return std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::steady_clock::now().time_since_epoch()).count() / 1e6;
}

int rand_uns(int min, int max) {
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    static std::default_random_engine e(seed);
    std::uniform_int_distribution<int> d(min, max);
    return d(e);
}

int main() {
    std::ofstream f1("../2_1.csv", std::ios::out);
    std::ofstream f2("../2_2.csv", std::ios::out);

    Subvector subv;
    std::vector<int> v;
    for (int i = 0; i < 262144; i++) {
        int value = rand_uns(0, 100);
        subv.push_back(value);
        v.push_back(value);
    }
    for (int i = 0; i < 262144; i++) {
        std::cout << i << '\n';
        if (i % 1000 != 0) {
            subv.erase(0);
            v.erase(v.begin());
        }
        else if (i % 1000 == 0) {
            auto start = get_time();
            subv.erase(0);
            auto finish = get_time();
            auto time = finish - start;
            f1 << subv.getTop() << " " << time << "\n";

            start = get_time();
            v.erase(v.begin());
            finish = get_time();
            time = finish - start;
            f2 << v.size()<< " " << time << "\n";
        }
    }

    return 0;
}
```
</details>

Итак, график для `subvector`:

![capacity_size](./img/image3.png)

Можем точно сказать, что ассимптотика нашего метода `erase` равна **O(N)**. Это и очевидно, поскольку для того, чтобы удалить элемент, нам нужно передвинуть весь сабвектор на одну позицию.

И график для `std::vector`:

![capacity_size](./img/image4.png)

Здесь так же ассимптотика составляет **O(N)**. Мы так же можем наблюдать некоторый излом - это происходит из-за больших данных. В общей картине - опять же ничего не меняется.
  
</details>
