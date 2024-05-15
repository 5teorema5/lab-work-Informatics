<h2>Лаба по контенерам</h2>
<details>
  <summary><h3>Пример с лекции</h3></summary>
  
  Будем последовательно добавлять элементы в `std::vector`, следить за изменением размерности вектора - `capacity` и `size`. Эти значения записываем в файл, после чего построим график зависимомти размерностей вектора от количества итераций(числа добавляемых элементов).

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

![capacity_size]()
  
</details>
