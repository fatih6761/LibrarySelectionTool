//
// Created by fatih on 9/1/16.
//

#ifndef LIBRARYSELECTIONTOOL_FILE_INFO_H
#define LIBRARYSELECTIONTOOL_FILE_INFO_H

#include <string>

using std::string;

class file_info {
public:
    file_info(const string& path);

    string get_path() const;
    string get_name() const;

    enum class size_format {
        bytes, kbytes, mbytes
    };

    size_t get_size(size_format fmt = size_format::bytes) const;

private:
    string path;
    string filename;
    size_t size_in_bytes;
};


#endif //LIBRARYSELECTIONTOOL_FILE_INFO_H
