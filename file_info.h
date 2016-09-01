//
// Created by fatih on 9/1/16.
//

#ifndef LIBRARYSELECTIONTOOL_FILE_INFO_H
#define LIBRARYSELECTIONTOOL_FILE_INFO_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class file_info {
public:
    file_info(const string& _path);
    file_info(const string& _path, const string& _fname, const string& _ext, size_t _size);

    string get_path() const;
    string get_name() const;
    string get_ext() const;


    enum class size_format {
        bytes, kbytes, mbytes
    };

    size_t get_size(size_format fmt = size_format::bytes) const;

    static vector<file_info> from_directory(const std::string& s);

    bool operator <(const file_info& other);

private:
    string m_path;
    string m_filename;
    string m_extension;
    size_t m_size_in_bytes;
};


#endif //LIBRARYSELECTIONTOOL_FILE_INFO_H
