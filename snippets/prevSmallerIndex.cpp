vl prevSmallerIndex(vl &a){
    lli n = a.size();
    vl pse(n);
    stack<int> st;

    for(int i=0; i<n; i++){
        while(!st.empty() and a[st.top()] >= a[i]){
            st.pop();
        }

        if(st.empty()) pse[i] = -1;
        else pse[i] = st.top();
        st.push(i);
    }

    return pse;
}