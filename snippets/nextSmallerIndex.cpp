vl nextSmallerIndex(vl &a){
    lli n = a.size();
    vl nse(n);
    stack<int> st;

    for(int i=n-1; i>=0; i--){
        while(!st.empty() and a[st.top()]>=a[i]){
            st.pop();
        }

        if(st.empty()) nse[i] = n;
        else nse[i] = st.top();

        st.push(i);
    }
}