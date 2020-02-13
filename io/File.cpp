#include "File.hpp"

File::File(std::string pathToFile)
{
    this->file.open(pathToFile, std::ios_base::in | std::ios_base::out | std::ios_base::binary);
    this->pathToFile = pathToFile;
}

File::~File()
{
    this->file.close();
}

bool File::isOpen()
{
    return this->file.is_open();
}

size_t File::getSize()
{
    u_int32_t cursor = this->file.tellg();
    this->file.seekg(0, std::ios_base::end);
    u_int32_t size = this->file.tellg();

    this->file.seekg(cursor, std::ios_base::beg);

    return size;
}

std::string File::read(u_int64_t start, u_int64_t end)
{
    std::string content;
    char symbol;
    this->file.seekg(start, std::ios_base::beg);

    u_int64_t counter = end - start + 1;
    while(!this->file.eof() && counter-- > 0)
    {
        this->file >> symbol;
        content += symbol;
    }

    return content;
}

void File::rewrite(u_int64_t start, u_int64_t end, const std::string& content)
{
    if(end - start + 1 != content.length()) return;

    this->file.seekg(start, std::ios_base::beg);
    this->file << content;
}

void File::append(const std::string& content)
{
    this->file.seekg(0, std::ios_base::end);
    this->file << content;
}

void File::rename(std::string newName)
{
    std::rename(this->pathToFile.c_str(), newName.c_str());
}