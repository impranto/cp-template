vl computeLPS(const string &s) {
    lli n = s.size();
    vl lps(n, 0);
    lli len = 0, i = 1;
    while (i < n) {
        if (s[i] == s[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vl KMP(const string &text, const string &pattern) {
    string s = pattern + "#" + text;
    vl lps = computeLPS(s);
    vl occurrences;
    lli m = pattern.size();
    for (lli i = m + 1; i < lps.size(); i++) {
        if (lps[i] == m) occurrences.push_back(i - 2 * m);
    }
    return occurrences;
}
