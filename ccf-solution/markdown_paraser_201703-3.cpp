// markdown to html

#include <bits/stdc++.h>
using namespace std;

void parse_content(string &content)
{
    auto em = make_pair("<em>", "</em>");
    int count = 1;
    // 处理 _ em, 注意可能开头就是_
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
        // cout<<"content: "<<content<<endl;
        content.replace(start, end-start+1, href + text);
        // cout<<"after content: "<<content<<endl;
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
    tags["*"] = make_pair("<li>", "</li>");
    string flag, content;
    unsigned int i;
    // 无标记则为段落p，解析行内标签
    if (md[0] != '#' && md[0] != '*')
    {
        return "<p>" + md + "</p>";
    }
    // 解析完成最上级就是行内标签，肯定就没有段标签了。比如<a href>, <em>
    if (md[0] == '<')
    {
        return "<p>" + md + "</p>";
        // return md;
    }
    // 正常标记解析
    else
    {
        for (i = 0; i < md.size(); ++i)
        {
            if (md[i] == ' ')
            {
                flag = md.substr(0, i);
                content = md.substr(i + 1, md.size());
                md = tags[flag].first + content + tags[flag].second;
                break;
            }
        }
        return md;
    }
}
int main()
{

    string line;
    // line = "[SB](http://tenss.cn)";
    // parse_content(line);
    // cout << line << endl;
    // return 0;
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
            if (line_flag || line[0] == '*')
            {
                lines.push_back(line);
                line_flag = false;
            }
            else
                lines[lines.size() - 1] += "\n" + line;
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