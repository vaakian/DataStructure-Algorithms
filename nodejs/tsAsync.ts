const Login: Function = (pwd: String) => {
    return new Promise<String>((reslove, reject) => {
        pwd === 'admin' ? reslove('success!'): reject('failed!');
    })
}

Login('123').then((msg: String) => {
    console.log(`had ${msg}`);
}).catch((msg: String) => {
    console.log(`fuck it, ${msg}`);
})