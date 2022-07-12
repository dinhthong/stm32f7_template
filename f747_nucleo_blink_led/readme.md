# Intro
- ROS serial (on USART3) + CubeMX HAL + Cube IDE 
- Remember to add `./Drivers` folder to this repo before compiling
# STM32F7 rosserial full project
- First I tried implementing rosserial on STM32F4 Discovery Board -> succeeded, and understand the concepts and ideas...
- Similarly, I ported to STM32F7 by previous experience on STM32F4
- Results: rosserial is running my nucleo-f746zg board (publishing chatter message), with LED blinking periodically
# Preferences
- https://github.com/fdila/rosserial_stm32f7
- https://github.com/xav-jann1/rosserial_stm32f4
- https://github.com/yoneken/rosserial_stm32
- https://www.youtube.com/watch?v=cq0HmKrIOt8
