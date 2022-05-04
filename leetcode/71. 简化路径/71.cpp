class Solution {
public:
    string simplifyPath(string path) {
        string s = "";
        int sz = path.size();
        int index = 0;
        while (index < sz)
        {
            while (index < sz && path[index] == '/')
            {
                index++;
            }
            string tmp = "/";
            while (index < sz && path[index] != '/')
            {
                tmp += path[index];
                index++;
            }
            if (tmp.compare("/") == 0 || tmp.compare("/.") == 0)
                tmp = "";
            else if (tmp.compare("/..") == 0)
            {
                //»ØÍË
                tmp = "";
                int _sz = s.size();
                while (_sz > 1 && s[_sz - 1] != '/')
                {
                    _sz--;
                }
                if (_sz)
                    _sz--;
                s.resize(_sz);
            }
            s += tmp;
        }
        if (s.size() == 0)
            return "/";
        return s;
    }
};