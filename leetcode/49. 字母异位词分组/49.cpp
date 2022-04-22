class Solution {
public:
    /*vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> vvs;
        map<map<char, int>, int> mmap;
        int pos = 0;
        for(auto str : strs)
        {
            map<char, int> tmp;
            for(auto ch : str)
            {
                tmp[ch] += 1;
            }
            if(mmap.find(tmp) == mmap.end())
            {
                vvs.resize(vvs.size() + 1);
                int _pos = pos;
                mmap[tmp] = pos++;
                vvs[_pos].push_back(str);
            }
            else
            {
                vvs[mmap[tmp]].push_back(str);
            }
        }
        return vvs;
    }*/
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> vvs;
        unordered_map<string, int> umap;
        int pos = 0;
        for (auto str : strs)
        {
            string tmp = str;
            std::sort(tmp.begin(), tmp.end());
            int _pos = 0;
            if (umap.find(tmp) == umap.end())
            {
                _pos = pos;
                umap[tmp] = pos++;
                vvs.resize(vvs.size() + 1);
            }
            else
            {
                _pos = umap[tmp];
            }
            vvs[_pos].push_back(str);
        }
        return vvs;
    }
};