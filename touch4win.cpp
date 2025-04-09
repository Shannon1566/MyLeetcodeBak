#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <utime.h>
#include <ctime>

void touch(const std::string &filename) {
    struct stat buffer;
    if (stat(filename.c_str(), &buffer) != 0) {
        // 文件不存在，创建空文件
        std::ofstream file(filename);
        if (!file) {
            std::cerr << "Error creating file!" << std::endl;
            return;
        }
        file.close();
    } else {
        // 文件存在，更新文件的访问时间和修改时间
        struct utimbuf new_times;
        new_times.actime = time(NULL);  // 更新访问时间
        new_times.modtime = time(NULL); // 更新修改时间
        if (utime(filename.c_str(), &new_times) != 0) {
            std::cerr << "Error updating file times!" << std::endl;
            return;
        }
    }

    // std::cout << "File \"" << filename << "\" has been touched." << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    touch(filename);
    return 0;
}
