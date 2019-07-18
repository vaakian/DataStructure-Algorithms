// call apply bind都是改变this指向

const obj = {
    name: 'allen',
    Show: function () {
        console.log(`I'm ${this.name}`);
    }
}
obj.Show();

const newObj = {
    name: 'Cindy'
}
// 将obj的this指向newObj
obj.Show.call(newObj);

// 返回函数，不立即执行
const show = obj.Show.bind({ name: 15 })
// show();

const a = {
    name: "Cherry",
    func1: function () {
        console.log(this.name)
    },
    func2: function () {
        setTimeout(function () {
            this.func1()
        }.bind(a), 100); // this指向a，否则指向了func2
    }

};
a.func2();

/*
fn.call(obj, arg1, arg2, ...) 
fn.apply(obj, [arg1, arg2, ...])
fn.bind(obj, arg1, arg2, ...) 不立即执行
*/