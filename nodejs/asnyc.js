// 异步
const Login = function(password) {
  console.log('Login activited!');
  return new Promise((resolve, reject) => {
    if(password === 'admin') {
      resolve('success!');
    } else {
      reject('failed!');
    }
  })
}
// 入队列1，执行
console.log('a');
// 入队列2，执行
var password = 'admin';
// 语句入队列3，，执行Login，因为是异步，所以console.log还没有入队列
Login(password).then(msg => {
  console.log(msg);
}).catch(msg => {
  console.log(msg);
})
// 入队列4，执行
console.log('b');
// 最后promise.then入队列，console执行