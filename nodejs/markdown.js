const { mdParser } = require('./md');

const htmlContent = mdParser(`
# hello

* asd
* adsad

[hello](http://this.com)
`)

console.log(htmlContent);