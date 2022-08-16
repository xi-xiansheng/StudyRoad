class OrderedStream {
public:
    OrderedStream(int n) {
        v.resize(n + 1);
        index = 1;
    }

    vector<string> insert(int idKey, string value) {
        vector<string> ans;
        v[idKey].swap(value);
        if (idKey == index)
        {
            int sz = v.size();
            while (index < sz && v[index] != "")
            {
                ans.push_back(v[index++]);
            }
        }
        return ans;
    }
private:
    vector<string> v;
    int index;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */