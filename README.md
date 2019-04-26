# Binary arithmetic

### 开发环境

- 编辑器：vim
- 编译器：gcc
- 调试器：gdb
- 开发平台：CentOS 7.4

### 运行环境

Linux

### 设计思路

先将输入的两个二进制数转换成十进制，然后再进行相应的运算，最后将结果转换成二进制的形式打印。

### 部分实现思路

- 二进制转换为十进制

  遍历当前二进制数的每一位（这里用字符串接收二进制数，所以遍历的是字符串），将每一位乘以2的对应次方（调用程序内实现的_my_pow函数），由于程序内用字符串接收输入的二进制数，所以首先要将字符‘1’和‘0’转换为对应的数字，然后将每一位的结果累加起来即转换后的结果。

- 十进制转换为二进制

  定义一个字符数组来接收转换后的结果。

  如果当前十进制数为正数，将十进制数模2，如果得到的结果为1，则将字符串当前位赋值为‘1’，否则赋值为‘0’，然后字符串当前位向后走一位，将十进制数右移一位，重复这个过程。当十进制数为0的时候，说明已经转换完成，退出循环。

  如果当前十进制数为负数，先将十进制数变成它的相反数，然后获取十进制数的补码（对十进制数进行取反加一），用移位操作从高到低获取补码的每一位和1相与，如果结果是1，则将字符串对应元素赋值为‘1’，否则赋值为‘0’。当遍历完补码的每一位后，字符数组中从前往后存储的就是补码从高到低的数值。

