/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Yu Jing <yu@argcv.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 **/
#include <cstdio>
#include <cstdlib>

#include <string>
#include <iostream>
#include <vector>

#include "argcv/random/random.hh"
#include "argcv/string/string.hh"
#include "argcv/wrapper/leveldb_wr.hh"

using namespace argcv::random;
using namespace argcv::string;
using namespace argcv::wrapper::leveldb;

std::string fileread(const char* name) {
    FILE* fp = fopen(name, "rb");
    size_t sz;
    char* buff;
    fseek(fp, 0, SEEK_END);
    sz = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    buff = (char*)malloc(sizeof(char) * (sz + 1));
    buff[sz] = '\0';
    fread(buff, sz, 1, fp);
    std::string rtstr(buff, sz);
    free(buff);
    fclose(fp);
    return rtstr;
}

int main(int argc, char* argv[]) {
    const char* names_file_path = "names.txt";
    const char* ddir = "exists_names.data";
    ldb_wr lw(ddir, 0, true);
    lw.conn();
    std::vector<std::string> names = split(fileread(names_file_path), "\n");
    size_t sz_names = names.size();
    std::string name;
    std::string mail;
    int idx = -1;
    // printf("load names: %lu\n", sz_names);
    // printf("guess name: %zu (%s)\n", off_name, names[off_name].c_str());
    do {
        idx++;
        size_t off_name = random_int() % sz_names;
        name = names[off_name];
        mail = name + ".lee" + (idx > 0 ? std::to_string(idx).c_str() : "") + "@argcv.com";
    } while (lw.exist(mail));
    lw[mail] = "got";
    printf("name  : %s Lee\nemail : %s\n", name.c_str(), mail.c_str());
    lw.close();
    return 0;
}