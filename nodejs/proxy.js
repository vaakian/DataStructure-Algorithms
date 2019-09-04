/*var obj = new Proxy({}, {
    get: function (target, key, receiver) {
        console.log({ target, key });
        return Reflect.get(...arguments);
    },
    set: function (target, key, value, receiver) {
        console.log(`setting ${key}!`);
        return Reflect.set(...arguments);
    }
});
obj.count = 5; 
console.log(obj);*/
const target = {
    name: 5
}
const handler = {
    get: function(target, key, receiver) {
        console.log(`get ${key}`);
        return Reflect.get(...arguments);
    }
}
let object = { proxy: new Proxy(target, handler) };
console.log(object);