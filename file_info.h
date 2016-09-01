//
// Created by fatih on 9/1/16.
//

#ifndef LIBRARYSELECTIONTOOL_FILE_INFO_H
#define LIBRARYSELECTIONTOOL_FILE_INFO_H

#include <string>
#include <vector>
#include <iostream>

class file_info {
public:
    file_info(const std::string& _path);
    file_info(const std::string& _path, const std::string& _fname, const std::string& _ext, size_t _size);

    std::string get_path() const;
    std::string get_name() const;
    std::string get_ext() const;


    enum class size_format {
        bytes, kbytes, mbytes
    };

    size_t get_size(size_format fmt = size_format::bytes) const;

    static std::vector<file_info> from_directory(const std::string& s);

    bool operator <(const file_info& other);


private:
    std::string m_path;
    std::string m_filename;
    std::string m_extension;
    size_t m_size_in_bytes;
};


#endif //LIBRARYSELECTIONTOOL_FILE_INFO_H
