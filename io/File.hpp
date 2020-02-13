#pragma once

#include <iostream>
#include <fstream>
#include <string>

/**
 * Класс для работы с файлами
 * Данный класс реализует паттерн проектирования RAII
 **/
class File
{
private:
    /**
     * Текущий файл
     **/
    std::fstream file;
    /**
     * Путь до файла
     **/
    std::string pathToFile;
public:
    File(std::string pathToFile);
    ~File();

    bool isOpen();
    size_t getSize();
    std::string read(u_int64_t start, u_int64_t end);
    void rewrite(u_int64_t start, u_int64_t end, const std::string& content);
    void append(const std::string& content);
    void rename(std::string newName);
};