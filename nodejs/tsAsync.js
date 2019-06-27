var Login = function (pwd) {
    return new Promise(function (reslove, reject) {
        pwd === 'admin' ? reslove('success!') : reject('failed!');
    });
};
Login('123').then(function (msg) {
    console.log("had " + msg);
})["catch"](function (msg) {
    console.log("fuck it, " + msg);
});
