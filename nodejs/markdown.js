const { mdParser } = require('./mdParser');

const htmlContent = mdParser(`
# Heading

## Sub-heading

paragraphs are separated
by a blank line.

Text attributes _italic_.

Bullet list:


* apples
* oranges
* pears

A [Link](http://example.com).

## [SB](http://tenss.cn)

[Link](http://example.com)

Text_shabi_[TEST](http://tenss.cn)dfkgjkldfg


parahares [TEST](http://test.cn)_string_
parafsdkfjdfsd

# heading

_qiangdiao_

_[TEST](HTTP://tenss.cn)_
`)

console.log(htmlContent);