/***************************************************************************
 * 
 * Copyright (c) 2014 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file Anagram.cpp
 * @author super(com@baidu.com)
 * @date 2014/07/25 13:40:55
 * @brief 
 *  
 **/

#include <iostream>
#include <map>
#include <string.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int len = s.size();
        if (len & 1) {
            cout << -1 << endl;
            continue;
        }
        string a = s.substr(0, len/2);
        string b = s.substr(len/2, len/2);
        int ca[200], cb[200];
        memset(ca, 0, sizeof(ca));
        memset(cb, 0, sizeof(cb));
        for (int i=0; i<len/2; ++i){ ++ca[a[i]]; ++cb[b[i]]; }
        int cnt = 0;
        for (int i=0; i<200; ++i) {
            cnt += max(cb[i] - ca[i], 0);
        }
        cout << cnt << endl;
    }
    return 0;
}


/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
