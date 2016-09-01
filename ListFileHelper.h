//
// Created by fatih on 9/1/16.
//

#ifndef LIBRARYSELECTIONTOOL_LISTFILEHELPER_H
#define LIBRARYSELECTIONTOOL_LISTFILEHELPER_H

#include <string>
#include <vector>

#include "file_info.h"

using std::string;
using std::vector;

class ListFileHelper {
private:
    ListFileHelper() {};

public:
    static vector<file_info> load_list(const string& path);
    static void save_list(const vector<file_info>& files, const string& ofile);
};


#endif //LIBRARYSELECTIONTOOL_LISTFILEHELPER_H
