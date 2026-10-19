/*
修复说明：
1. 数字判断原来传入数值 0 和 9，改为数字字符 '0' 和 '9'。
2. 长度条件原来是 <= 10，改为 >= 10，表示至少 10 个字符。
3. 字符范围原来使用严格小于号，遗漏了边界字符；
   改为 lower <= ch && ch <= upper，包含范围两端。
4. 删除未使用的变量 checked，消除编译警告。

自设计测试：
输入：Chen Lin Az00000000
预期输出：VALID
说明：密码恰好 10 个字符，包含大写 A、小写 z 和数字 0，
且不包含 Chen 或 Lin，同时检查长度与字符范围边界。
*/
#include <iostream>
#include <string>

bool contains_between(const std::string& text, char lower, char upper) {
    for (char ch : text) {
        if (lower <= ch && ch <= upper) {
            return true;
        }
    }
    return false;
}

bool check_password(const std::string& first_name,
                    const std::string& last_name,
                    const std::string& password) {
    bool length_ok = password.size() >= 10;
    bool upper_ok = contains_between(password, 'A', 'Z');
    bool lower_ok = contains_between(password, 'a', 'z');
    bool digit_ok = contains_between(password, '0', '9');
    bool name_ok = password.find(first_name) == std::string::npos &&
                   password.find(last_name) == std::string::npos;
                
   return length_ok && upper_ok && lower_ok && digit_ok && name_ok;
}

int main() {
    std::string first_name, last_name, password;
    if (!(std::cin >> first_name >> last_name >> password)) {
        std::cerr << "请输入：名 姓 密码\n";
        return 1;
    }
    std::cout << (check_password(first_name, last_name, password)
                      ? "VALID" : "INVALID") << '\n';
    return 0;
}
