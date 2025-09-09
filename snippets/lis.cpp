lli LIS(vl &a) {
    vl tail;
    for (auto x : a) {
        auto it = lower_bound(tail.begin(), tail.end(), x);
        if (it == tail.end())
            tail.push_back(x);
        else
            *it = x;
    }
    return tail.size();
}