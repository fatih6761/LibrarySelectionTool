//
// Created by fatih on 9/1/16.
//


#include "file_info.h"

#include <boost/filesystem.hpp>

using namespace boost::filesystem;

file_info::file_info(const std::string &path) {

}

std::string file_info::get_path() const {
    return std::__cxx11::string();
}

std::string file_info::get_name() const {
    return std::__cxx11::string();
}

size_t file_info::get_size(file_info::size_format fmt) const {
    return 0;
}
