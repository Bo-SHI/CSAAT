// 查看左移右移的值

#include <iostream>

const int timer_near_shift = 8;
const int timer_near = 1 << timer_near_shift;
const int timer_level_shift = 6;
const int timer_level = 1 << timer_level_shift;
const int timer_near_mask = timer_near - 1;
const int timer_level_mask = timer_level - 1;

int main() {
    std::cout << "timer_near: " << timer_near << std::endl;
    std::cout << "timer_near_mask: " << timer_near_mask << std::endl;

    std::cout << "timer_level: " << timer_level << std::endl;
    std::cout << "timer_level_mask: " << timer_level_mask << std::endl;
    return 0;
}
