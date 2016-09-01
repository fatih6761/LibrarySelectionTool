//
// Created by fatih on 9/1/16.
//

#include "ListFileHelper.h"

#include <fstream>
#include <boost/algorithm/string.hpp>

vector<file_info> ListFileHelper::load_list(const string &ifile) {
    vector<file_info> files;
    std::ifstream infile(ifile);
    string line;

    for (string line; getline(infile, line); ) {
        if (! boost::starts_with(line, "#")) {
            files.emplace_back(line);
        }
    }

    return files;
}

void ListFileHelper::save_list(const vector<file_info>& files, const string& ofile) {
    std::ofstream outfile(ofile);
    outfile << "# List of selected files:\n";
    for (const auto& x : files)
        outfile << x.get_path() << "\n";
    outfile << "# End\n";
}
