// 解析行内元素
const parseInline = function (line) {
    let count = 0;
    // 处理 _ EM
    for (ch of line) {
        if (ch == '_') {
            count++;
            if (count % 2) line = line.replace('_', '<em>');
            else line = line.replace('_', '</em>')
        }
    }
    // 处理 a标签
    let start = line.indexOf('[');
    let mid = line.indexOf('](');
    let end = line.indexOf(')');
    if (start != -1 && mid != -1 && end != -1) {
        let href = line.slice(start + 1, mid);
        let text = line.slice(mid + 2, end);
        let newStr = `<a href="${href}">${text}</a>`;
        let repalceStr = line.slice(start, end + 1);
        line = line.replace(repalceStr, newStr);
    }
    return line;
}
// 解析md数组
const parseMd = function (lines) {
    let result = '';
    let lastIsLi = false;
    for (line of lines) {
        line = parseInline(line);
        if (line[0] === '<') {
            if (lastIsLi) { lastIsLi = false; result += '</ul>\n'; }
            result += `<p>${line}</p>`;
        }
        else if (line[0] != '#' && line[0] != '*') {
            if (lastIsLi) { lastIsLi = false; result += '</ul>\n'; }
            result += `<p>${line}</p>`;
        }
        else {
            for (i in line) {
                i = parseInt(i);
                if (line[i] == ' ') {

                    if (line[i - 1] == '#') {
                        if (lastIsLi) { lastIsLi = false; result += '</ul>\n'; }
                        result += `<h${i}>${line.slice(i + 1)}</h${i}>`;
                    } else {
                        if (!lastIsLi)
                            result += `<ul>\n`;
                        result += `<li>${line.slice(i + 1)}</li>`;
                        lastIsLi = true;
                    }
                    break;
                }
            }
        }
        result += '\n';
    }
    return result;
}
// 将字符串分离成数组
const seperateStr = function (mdStr) {
    mdStr = mdStr.replace(/\n\*/gi, '\n\n*');
    mdStr = mdStr.split('\n\n').filter(item => item);
    return mdStr.map(item => item.replace('\n', ''));
}
// class mdParser {
//     constructor(mdContent) {
//         this.mdContent = mdContent;
//     }
//     parse() {
//         const lines = seperateStr(this.mdContent);
//         const htmlContent = parseMd(lines);
//         return htmlContent;
//     }
// }
const parse = function(mdContent) {
    const lines = seperateStr(mdContent);
    const htmlContent = parseMd(lines);
    return htmlContent;
}
module.exports.mdParser = parse;