const Login = pwd => {
    return pwd === 'admin' ? 
    Promise.resolve('success'):
    Promise.reject('fail');
}
const pwd = 'admin';
const result = Login(pwd).then(msg => {
    console.log('leve 1');
    return Promise.resolve(2);
}).then(msg => {
    console.log('leve 2');
    return Promise.resolve(3);
}).then(msg => {
    console.log('leve 3');
    return Promise.resolve(4);
})
console.log(result);
result.then(msg => {
    console.log(msg);
    console.log(result);
})

