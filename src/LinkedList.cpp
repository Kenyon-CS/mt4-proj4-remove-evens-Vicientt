#include "LinkedList.hpp"
#include <sstream>

LinkedList::LinkedList() : head_(nullptr) {}
LinkedList::~LinkedList() {
    Node* p = head_;
    while (p) { Node* n = p->next; delete p; p = n; }
}
void LinkedList::push_front(int v) { head_ = new Node(v, head_); }
void LinkedList::remove_evens() {
    // TODO: implement
    while (head_ != nullptr && head_->value % 2 == 0) {
        Node* node_to_delete = head_;
        head_ = head_->next;
        delete node_to_delete;
    }

    if (head_ == nullptr) {
        return;
    }

    Node* prev = head_;
    Node* current = head_->next;

    while (current != nullptr) {
        if (current->value % 2 == 0) {
            prev->next = current->next; 
            delete current;             
            current = prev->next;       
        } else {
            prev = current;
            current = current->next;
        }
    }
}
std::string LinkedList::to_string() const {
    std::ostringstream oss;
    oss << "[";
    Node* p = head_;
    bool first = true;
    while (p) {
        if (!first) oss << ", ";
        first = false;
        oss << p->value;
        p = p->next;
    }
    oss << "]";
    return oss.str();
}
