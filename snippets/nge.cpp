vl NGE(vl &a) {
    lli n = a.size();
    vl ans(n, -1);
    stack<lli> st;
    for (lli i = 0; i < n; i++) {
        while (!st.empty() && a[i] > a[st.top()]) {
            ans[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
