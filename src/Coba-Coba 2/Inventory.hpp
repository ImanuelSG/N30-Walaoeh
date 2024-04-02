#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <vector>
#include <memory>
#include "Entitas.hpp"

using namespace std;

template <typename T>
class Inventory {
private:
    vector<shared_ptr<T>> items;

public:
    void TambahItem(const shared_ptr<T>& item) {
        items.push_back(item);
    }

    void HapusItem(size_t index) {
        if (index < items.size()) {
            items.erase(items.begin() + index);
        }
    }
};

#endif
