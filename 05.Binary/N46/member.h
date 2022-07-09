#pragma once

class member {
  protected:
    string _name = "membername";
    int _birth[3] = {1, 1, 2000};
    float _age = 18.0;
    string _hometown = "Tokyo";
    char _gen = '0';
    bool _graduated = 0;

  public:
    void memberp(); //在一行中格式化输出
    member(const vector<string> &vetstr);
    member(const string &str);
    member(const string &str, bool hand);
    bool graduate(bool hand);
    bool graduate();
    bool whethergraduated();
    int birthyear();
    string memberoff();
    void ageupdate(int d, int m, int y);
    float age();
    string name();
};

//成员函数的实现

void member::memberp() {
    cout << "| ";
    cout << left << setw(16) << _name;
    cout << "| ";
    cout << setfill('0') << right << setw(2) << _birth[0];
    cout << "-";
    cout << setw(2) << _birth[1];
    cout << "-";
    cout << setw(4) << _birth[2];
    cout << " | " << (int)_age << " | ";
    cout << setfill(' ') << left << setw(10) << _hometown;
    cout << "|  " << _gen << "  |";
    if (_graduated == 1)
        cout << " Graduated |\n";
    else
        cout << " Working   |\n";
}

member::member(const vector<string> &vetstr) {
    _name = vetstr[0];
    _birth[0] = stoi(vetstr[1]);
    _birth[1] = stoi(vetstr[2]);
    _birth[2] = stoi(vetstr[3]);
    _age = stof(vetstr[4]);
    _hometown = vetstr[5];
    const char *p = vetstr[6].data();
    _gen = *p;
}

member::member(const string &str) {
    vector<string> vetstr = splitWithStl(str, "\t");
    _name = vetstr[0];
    _birth[0] = stoi(vetstr[1]);
    _birth[1] = stoi(vetstr[2]);
    _birth[2] = stoi(vetstr[3]);
    _age = stof(vetstr[4]);
    _hometown = vetstr[5];
    const char *p = vetstr[6].data();
    _gen = *p;
};

member::member(const string &str, bool hand) {
    vector<string> vetstr = splitWithStl(str, "-");
    _name = vetstr[0];
    _birth[0] = stoi(vetstr[1]);
    _birth[1] = stoi(vetstr[2]);
    _birth[2] = stoi(vetstr[3]);
    _hometown = vetstr[4];
    const char *p = vetstr[5].data();
    _gen = *p;
    _age = 18.0;
    _graduated = 0;
}

bool member::graduate(bool hand) {
    if (hand == 1)
        _graduated = 1;
    else
        _graduated = 0;
    return _graduated;
}

bool member::graduate() {
    _graduated = 1;
    return _graduated;
}

bool member::whethergraduated() { return _graduated; }

int member::birthyear() { return _birth[2]; }

string member::memberoff() {
    string temp;
    temp += _name;
    temp += "\t";
    temp += to_string(_birth[0]);
    temp += "\t";
    temp += to_string(_birth[1]);
    temp += "\t";
    temp += to_string(_birth[2]);
    temp += "\t";
    temp += to_string((int)_age);
    temp += "\t";
    temp += _hometown;
    temp += "\t";
    temp += _gen;
    temp += "\n";
    return temp;
}

void member::ageupdate(int d, int m, int y) {
    _age = (float)(m - _birth[0]) * 0.083333333 +
           (float)(d - _birth[1]) * 0.002778 + (float)(y - _birth[2]);
}

float member::age() { return _age; }

string member::name() { return _name; }

//非成员函数

bool cmpage(member &a, member &b) { return a.age() > b.age(); }