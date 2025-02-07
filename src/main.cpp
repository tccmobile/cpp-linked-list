#include <iostream>
#include <string>
#include <stdexcept>

// Node class for the double-linked list
template <typename T>
class Node {
public:
    T data;
    Node* prev;
    Node* next;
    
    Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};

// Double-linked list class implementation
template <typename T>
class DoubleLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    size_t size;

public:
    // Constructor
    DoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    
    // Destructor to clean up memory
    ~DoubleLinkedList() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Add element to the front of the list
    void pushFront(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    // Add element to the back of the list
    void pushBack(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    // Remove element from the front
    T popFront() {
        if (isEmpty()) {
            throw std::runtime_error("List is empty");
        }
        
        T value = head->data;
        Node<T>* temp = head;
        
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        
        delete temp;
        size--;
        return value;
    }

    // Remove element from the back
    T popBack() {
        if (isEmpty()) {
            throw std::runtime_error("List is empty");
        }
        
        T value = tail->data;
        Node<T>* temp = tail;
        
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        
        delete temp;
        size--;
        return value;
    }

    // Insert element at specific position
    void insertAt(size_t position, const T& value) {
        if (position > size) {
            throw std::out_of_range("Position out of range");
        }
        
        if (position == 0) {
            pushFront(value);
            return;
        }
        
        if (position == size) {
            pushBack(value);
            return;
        }

        Node<T>* current = head;
        for (size_t i = 0; i < position - 1; i++) {
            current = current->next;
        }

        Node<T>* newNode = new Node<T>(value);
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
        size++;
    }

    // Check if list is empty
    bool isEmpty() const {
        return size == 0;
    }

    // Get current size of list
    size_t getSize() const {
        return size;
    }

    // Print list forward
    void printForward() const {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data;
            if (current->next != nullptr) std::cout << " <-> ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Print list backward
    void printBackward() const {
        Node<T>* current = tail;
        while (current != nullptr) {
            std::cout << current->data;
            if (current->prev != nullptr) std::cout << " <-> ";
            current = current->prev;
        }
        std::cout << std::endl;
    }
};

// Task class for a real-world example
class Task {
private:
    std::string description;
    int priority;

public:
    Task(const std::string& desc = "", int prio = 0) 
        : description(desc), priority(prio) {}

    friend std::ostream& operator<<(std::ostream& os, const Task& task) {
        os << "[Priority: " << task.priority << "] " << task.description;
        return os;
    }
};

int main() {
    // Create a task list using our double-linked list
    DoubleLinkedList<Task> taskList;

    std::cout << "Task Management System using Double-Linked List\n";
    std::cout << "=============================================\n\n";

    // Add some tasks
    taskList.pushBack(Task("Complete project documentation", 3));
    taskList.pushBack(Task("Review pull requests", 2));
    taskList.pushFront(Task("Fix critical bug", 1));
    taskList.insertAt(2, Task("Team meeting", 2));

    // Display tasks in forward order
    std::cout << "Tasks (forward order):\n";
    taskList.printForward();
    std::cout << "\n";

    // Display tasks in reverse order
    std::cout << "Tasks (reverse order):\n";
    taskList.printBackward();
    std::cout << "\n";

    // Remove highest priority task
    std::cout << "Completing highest priority task:\n";
    Task completedTask = taskList.popFront();
    std::cout << "Completed: " << completedTask << "\n\n";

    // Show remaining tasks
    std::cout << "Remaining tasks:\n";
    taskList.printForward();
    std::cout << "\nNumber of remaining tasks: " << taskList.getSize() << "\n";

    return 0;
} 