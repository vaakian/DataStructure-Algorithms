var obj = new Proxy({}, {
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
console.log(obj);