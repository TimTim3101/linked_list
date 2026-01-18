#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int _val) : val(_val), next(nullptr) {}
    ListNode(int _val, ListNode *_next) : val(_val), next(_next) {}
};

class linked_list {
  private:
    int elementCount;
    ListNode *head;

  public:
    linked_list() : head(nullptr), elementCount(0) {}
    ~linked_list() {
        while (!isEmpty())
            pop_front();
    }
    void push_front(int val);
    void pop_front();
    void print_list();
    ListNode *remove_duplicate(ListNode *head);
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2);
    ListNode *reverseList(ListNode *head);
    int size() const;
    bool isEmpty() const;
};

void linked_list::push_front(int val) {
    head = new ListNode(val, head);
    elementCount++;
}

void linked_list::pop_front() {
    ListNode *temp = head->next;
    delete head;
    head = temp;
    elementCount--;
}

// removes duplicates in a sorted list
ListNode *linked_list::remove_duplicate(ListNode *head) {
    if (head == nullptr)
        return nullptr;
    if (head->next == nullptr)
        return head;
    ListNode *current = head;
    while (head->next && head) {
        if (current->val == current->next->val)
            current->next = current->next->next;
        else
            current = current->next;
    }
    return head;
}

// merges two linked lists to a sorted linked list
ListNode *linked_list::mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (!list1)
        return list2;
    if (!list2)
        return list1;
    if (!list1 && !list2)
        return nullptr;

    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    if (list1->val <= list2->val) {
        head = tail = list1;
        list1 = list1->next;
    } else {
        head = tail = list2;
        list2 = list2->next;
    }

    while (list1 && list2) {
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    tail->next = list1 ? list1 : list2;
    return head;
}

ListNode *reverseList(ListNode *head) {
    if (!head)
        return nullptr;
    if (!head->next)
        return head;
    ListNode *prev = nullptr;
    ListNode *cur = head;
    while (cur) {
        ListNode *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

// chat GPT task
int sumallvalues(ListNode *head) {
    if (!head)
        return 0;
    int sum = 0;
    ListNode *cur = head;
    while (cur) {
        sum += cur->val;
        cur = cur->next;
    }
    return sum;
}

bool isPalindrome(ListNode *head) {
    if (head && !head->next)
        return true;
    // TODO
}

ListNode *removeElements(ListNode *head, int val) {
    ListNode dummy(0);
    dummy.next = head;

    ListNode *prev = &dummy;
    ListNode *cur = head;
    while (cur) {
        if (cur->val == val) {
            prev->next = cur->next;
            delete cur;
            cur = prev->next;
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
    return dummy.next;
}

int linked_list::size() const {
    return elementCount;
}
bool linked_list::isEmpty() const {
    return elementCount == 0;
}

void linked_list::print_list() {
    ListNode *cur = head;
    while (cur) {
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
}

void print_reversed_list(linked_list &list) {
}

int main() {
    linked_list list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(4);
    list.print_list();
    print_reversed_list(list);

    return 0;
}
