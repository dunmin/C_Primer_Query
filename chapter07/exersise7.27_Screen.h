#ifndef SCREEN_H
#define SCREEN_H
#include <string>

class Screen
{
    public:
        Screen() = default;
        Screen(std::string init):
                contents(init){}
        Screen &mov(int);
        Screen &set(char);
        const Screen &display() const;
    protected:
    private:
        int cursor = 0;
        int height = 0,width = 0;
        std::string contents;
};

#endif // SCREEN_H
