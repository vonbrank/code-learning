'use strict';

function product(arr) {
    function f(x, y) {
        return x * y;
    }
    return arr.reduce(f);
}

// 测试:
if (product([1, 2, 3, 4]) === 24 && product([0, 1, 2]) === 0 && product([99, 88, 77, 66]) === 44274384) {
    console.log('测试通过!');
}
else {
    console.log('测试失败!');
}