class Spreadsheet
{
public:
    vector<vector<int>> ans;
    Spreadsheet(int rows)
    {
        ans.resize(rows, vector<int>(26, 0));
    }

    void setCell(string cell, int value)
    {
        char a = cell[0];
        string r(cell.begin() + 1, cell.end());
        int j = stoi(r);
        ans[j - 1][a - 'A'] = value;
    }

    void resetCell(string cell)
    {
        char a = cell[0];
        string r(cell.begin() + 1, cell.end());
        int j = stoi(r);
        ans[j - 1][a - 'A'] = 0;
    }

    int getValue(string formula)
    {
        string s(formula.begin() + 1, formula.end());
        string s1;
        int i = 0;
        while (s[i] != '+')
        {
            s1 += s[i++];
        }
        i++;
        string s2;
        while (i != s.size())
        {
            s2 += s[i++];
        }
        int sum = 0;
        if (isalpha(s1[0]))
        {
            char a = s1[0];
            string r(s1.begin() + 1, s1.end());
            int j = stoi(r);
            sum += ans[j - 1][a - 'A'];
        }
        else
        {
            sum += stoi(s1);
        }
        if (isalpha(s2[0]))
        {
            char a = s2[0];
            string r(s2.begin() + 1, s2.end());
            int j = stoi(r);
            sum += ans[j - 1][a - 'A'];
        }
        else
        {
            sum += stoi(s2);
        }
        return sum;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */