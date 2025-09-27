#include <iostream>
#include <memory>

struct Test {
    Test(const std::string& name) : name(name) { 
        std::cout << name << " Created\n"; 
    }
    ~Test() { 
        std::cout << name << " Destroyed\n"; 
    }
    void hello() { 
        std::cout << "Hello from " << name << "\n"; 
    }
    std::string name;
};

int main() {
    // 1. unique_ptr (exclusive ownership)
    std::unique_ptr<Test> u1 = std::make_unique<Test>("Unique");
    // std::unique_ptr<Test> u2 = u1;          // ❌ Not allowed
    std::unique_ptr<Test> u2 = std::move(u1);   // ✅ Transfer ownership
    if (!u1) std::cout << "u1 is empty after move\n";
    u2->hello();

    // 2. shared_ptr (shared ownership, ref counting)
    std::shared_ptr<Test> s1 = std::make_shared<Test>("Shared");
    std::shared_ptr<Test> s2 = s1;  // another owner
    std::cout << "Shared count: " << s1.use_count() << "\n"; // 2
    s2->hello();

    // 3. weak_ptr (non-owning observer)
    std::weak_ptr<Test> w1 = s1; // does not increase count
    std::cout << "Shared count (with weak): " << s1.use_count() << "\n"; // still 2

    if (auto sp = w1.lock()) {  // lock() gives shared_ptr if alive
        sp->hello();
    }

    s1.reset(); // one shared_ptr released
    s2.reset(); // last shared_ptr released -> object destroyed

    if (w1.expired()) {
        std::cout << "Weak pointer expired\n";
    }
}
