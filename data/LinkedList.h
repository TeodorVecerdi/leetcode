#pragma once
#include <vector>

template<typename T>
struct LinkedList {
    T val;
    LinkedList* next;

    LinkedList()
        : val(), next(nullptr) {
    }

    explicit LinkedList(T val)
        : val(val), next(nullptr) {
    }

    LinkedList(T val, LinkedList* next)
        : val(val), next(next) {
    }

    static LinkedList* from_vector(const std::vector<T>& nums) {
        LinkedList dummy(0);
        LinkedList* current = &dummy;
        for (const int num: nums) {
            current->next = new LinkedList(num);
            current = current->next;
        }
        return dummy.next;
    }

    static std::vector<T> to_vector(const LinkedList* head) {
        std::vector<T> nums;

        while (head != nullptr) {
            nums.push_back(head->val);
            head = head->next;
        }

        return nums;
    }

    static void free(const LinkedList* head) {
        while (head != nullptr) {
            LinkedList* next = head->next;
            delete head;
            head = next;
        }
    }
};
