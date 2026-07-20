#include <iostream>

class stack
{
private:
    int size;
    int *stk;
    int TOS;
    static int stkCount;

public:
    stack()
    {
        size = 10;
        stk = new int[size];
        TOS = -1;
        stkCount++;
    }
    stack(int size)
    {
        this->size = size;
        stk = new int[size];
        TOS = -1;
        stkCount++;
    }

    stack(const stack &other)
    {
        this->size = other.size;
        this->TOS = other.TOS;
        stk = new int[this->size];
        for (int i = 0; i < (this->size); i++)
        {
            stk[i] = other.stk[i];
        }
        stkCount++;
    }

    stack &operator=(const stack &other)
    {
        if (this != &other)
        {
            delete[] stk;

            size = other.size;
            TOS = other.TOS;

            stk = new int[size];

            for (int i = 0; i <= TOS; i++)
            {
                stk[i] = other.stk[i];
            }
        }

        return *this;
    }

    int pop()
    {
        if (TOS >= 0)
        {
            return stk[TOS--];
        }

        std::cout << "Stack is empty\n";
        return -1;
    }
    void push(int item)
    {
        if (TOS < size - 1)
        {
            stk[++TOS] = item;
        }
        else
        {
            std::cout << "stack is full\n";
        }
    }

    static int getCount()
    {
        return stkCount;
    }
    int getTOS()
    {
        return TOS;
    }
    int getSize()
    {
        return size;
    }
    void setSize(int newSize)
    {
        int *newStack = new int[newSize];

        int limit = (TOS + 1 < newSize) ? TOS + 1 : newSize;

        for (int i = 0; i < limit; i++)
        {
            newStack[i] = stk[i];
        }

        delete[] stk;

        stk = newStack;
        size = newSize;

        if (TOS >= newSize)
            TOS = newSize - 1;
    }

    void printStack()
    {
        if (TOS == -1)
        {
            std::cout << "stack is empty\n";
        }
        std::cout << "stack elements: ";
        for (int i = 0; i <= TOS; i++)
        {
            std::cout << stk[i] << " ";
        }
        std::cout << std::endl;
    }

    ~stack()
    {
        delete[] stk;
        stk = nullptr;
        stkCount--;
    }
};
int stack::stkCount = 0;

int main()
{
    stack s1;

    s1.push(10);
    s1.push(20);
    s1.push(30);

    s1.printStack();

    stack s2 = s1; 

    std::cout << "Copied stack:\n";
    s2.printStack();

    stack s3;

    s3.push(100);
    s3.push(200);

    std::cout << "Before assignment:\n";
    s3.printStack();

    s3 = s1; 

    std::cout << "After assignment:\n";
    s3.printStack();

    s1.pop();

    std::cout << "Original stack after pop:\n";
    s1.printStack();

    std::cout << "Copied stack should stay unchanged:\n";
    s2.printStack();

    std::cout << "Resize copied stack to 2\n";

    s2.setSize(2);

    s2.printStack();

    std::cout << "Number of stack objects = "
              << stack::getCount() << std::endl;
}