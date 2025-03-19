#include <iostream>

#define STACK_SIZE 8

struct stack { //posso cambiare struct con class
    int     data[STACK_SIZE];
    int     top;
// public:
            stack();
            stack(const stack& other);
    void    push(int value);
    int     pop();
    bool    empty();
    bool    full();
};

stack::stack() {
    top = 0;
}

stack::stack(const stack& other) {
    for (int i = 0; i < STACK_SIZE; i++)
        data[i] = other.data[i];
}

void stack::push(int value) {
    if (top < STACK_SIZE)
        data[top++] = value;
}

int stack::pop() {
    if (top > 0)
        return data[--top];

    return 0;
}

bool stack::empty() {
    return (top == 0);
}

bool stack::full() {
    return (top == STACK_SIZE);
}

int main(void)
{
    stack s;
    std::cout << "Is empty: " << std::boolalpha << s.empty() << "\n";
    std::cout << "Pushing 10 and 20\n";
    s.push(10);
    s.push(20);
    std::cout << s.pop() << "\n";
    std::cout << "Is empty: " << std::boolalpha << s.empty() << "\n";
    std::cout << s.pop() << "\n";
    std::cout << "Is empty: " << std::boolalpha << s.empty() << "\n";
	stack s2; // ne posso creare altri
	s2.top = -1; // segmentation fault- tentativo di accedere a memoria non valida
	// se creo class mi da errore quando cerco di cambiare top
	s2.push(5);
	std::cout <<s.empty() << " " << s2.empty()<< std::endl;

    return 0;
}

