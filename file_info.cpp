//
// Created by fatih on 9/1/16.
//


#include "file_info.h"

#include <iostream>
#include <boost/filesystem.hpp>

using namespace boost::filesystem;

file_info::file_info(const std::string &s) {
    path p(s);

    try {
        if (exists(p)) {
            if (is_regular_file(p)) {
                m_path = p.string();
                m_filename = p.filename().string();
                m_size_in_bytes = file_size(p);
            } else {
                std::cerr << "FileInfo: " << p << " is not a regular file." << std::endl;
            }
        } else {
            std::cerr << "FileInfo: " << p << " does not exist." << std::endl;
        }
    } catch (const filesystem_error& ex) {
        std::cerr << ex.what() << std::endl;
    }
}

file_info::file_info(const string &_path, const string &_fname, size_t _size)
        : m_path(_path), m_filename(_fname), m_size_in_bytes(_size) {
    //
}

std::string file_info::get_path() const {
    return m_path;
}

std::string file_info::get_name() const {
    return m_filename;
}

size_t file_info::get_size(file_info::size_format fmt) const {
    size_t r;
    switch(fmt) {
        case size_format::bytes:
            r = m_size_in_bytes;
            break;
        case size_format::kbytes:
            r = m_size_in_bytes / 1024;
            break;
        case size_format::mbytes:
            r = m_size_in_bytes / (1024 * 1024);
            break;
    }
    return r;
}

vector<file_info> file_info::from_directory(const std::string &s) {
    vector<file_info> files;
    path p(s);

    try {
        if (exists(p)) {
            if (is_directory(p)) {
                for (directory_entry& x : directory_iterator(p)) {
                    auto y = x.path();
                    if (is_regular_file(y)) {
                        files.emplace_back(y.string(), y.filename().string(), file_size(y));
                    }
                }
            } else {
                std::cerr << "FileInfo: " << p << " is not a directory." << std::endl;
            }
        } else {
            std::cerr << "FileInfo: " << p << " does not exist." << std::endl;
        }
    } catch (const filesystem_error& ex) {
        std::cerr << ex.what() << std::endl;
    }

    return files;
}

bool file_info::operator<(const file_info &other) {
    return (m_filename < other.m_filename);
}
