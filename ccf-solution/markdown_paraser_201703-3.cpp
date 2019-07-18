// markdown to html

#include <bits/stdc++.h>
using namespace std;

void parse_content(string &content)
{
    auto em = make_pair("<em>", "</em>");
    int count = 1;
    // 处理 _ em
    for (unsigned int i = 0; i < content.size(); ++i)
    {
        if (content[i] == '_')
        {
            if (count % 2)
                content.replace(i, 1, em.first);
            else
                content.replace(i, 1, em.second);
            ++count;
        }
    }
    // 处理link
    auto start = content.find("[");
    auto mid = content.find("](");
    auto end = content.find(")");
    if (start != content.npos && mid != content.npos && end != content.npos)
    {
        string href = "<a href=\"" + content.substr(mid + 2, end - mid - 2) + "\">";
        string text = content.substr(start + 1, mid - start - 1) + "</a>";
        content.erase(content.begin() + start, content.begin() + end + 1);
        content.insert(start, href + text);
    }
}
string parse(string md)
{
    parse_content(md);
    map<string, pair<string, string>> tags;
    tags["#"] = make_pair("<h1>", "</h1>");
    tags["##"] = make_pair("<h2>", "</h2>");
    tags["###"] = make_pair("<h3>", "</h3>");
    tags["####"] = make_pair("<h4>", "</h4>");
    tags["#####"] = make_pair("<h5>", "</h5>");
    tags["######"] = make_pair("<h6>", "</h6>");
    string flag, content;
    unsigned int i;
    // 无标记则为段落p
    if (isalpha(md[0]))
    {
        return "<p>" + md + "</p>";
    }
    for (i = 0; i < md.size(); ++i)
    {
        if (md[i] == ' ')
        {
            flag = md.substr(0, i);
            content = md.substr(i + 1, md.size());
            break;
        }
    }
    return tags[flag].first + content + tags[flag].second;
}
int main()
{

    string line;
    vector<string> lines;
    bool li_flag = false;
    bool line_flag = true;
    while (getline(cin, line))
    {
        if (line.empty())
        {
            line_flag = true;
            continue;
        }
        else
        {
            if (line_flag || line[0] =='*') {
                lines.push_back(line);
                line_flag = false;
            }
            else
                lines[lines.size() - 1] += "\n"+line;
        }
    }
    for (auto l : lines)
    {
        if (!li_flag && l[0] == '*')
        {
            li_flag = true;
            cout << "<ul>" << endl;
        }
        if (li_flag && l[0] != '*')
        {
            cout << "</ul>" << endl;
            li_flag = false;
        }
        cout << parse(l) << endl;
    }
    // li是最后结尾的
    if (li_flag)
        cout << "</ul>" << endl;
    return 0;
}