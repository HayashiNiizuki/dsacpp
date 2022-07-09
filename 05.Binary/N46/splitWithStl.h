#pragma once

vector<string> splitWithStl(const string &str,const string &pattern)
{
    vector<string> resVec;

	if ("" == str)
    {
        return resVec;
    }
    //方便截取最后一段数据
    string strs = str + pattern;

    size_t pos = strs.find(pattern);

    while (pos != string::npos)
    {
        string x = strs.substr(0,pos);
        resVec.push_back(x);
        strs = strs.substr(pos+1);
        pos = strs.find(pattern);
    }

    return resVec;
}