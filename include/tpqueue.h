// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <list>

template<typename T>
class TPQueue {
 private:
    std::list<T> items;

 public:
    void push(const T& element) {
       auto it = items.front();
       while (it != items.end() && it->prior >= element.prior) {
          ++it;
       }
       items.insert(it, element);
    }
    T pop() {
       T frontElement = items.front();
       items.pop_front();
       return frontElement;
    }
    bool isEmpty() const {
       return items.empty();
    }
    const T& front() const {
       return items.front();
    }
    size_t size() const {
       return items.size();
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
