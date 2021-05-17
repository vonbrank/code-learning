'use strict'
function area_of_circle(r, pi) {
    if (arguments.length == 1) {
        pi = 3.14;
    }
    return pi * r * r;
}

// console.log(area_of_circle(2));

// 测试:
if (area_of_circle(2) === 12.56 && area_of_circle(2, 3.1416) === 12.5664) {
    console.log('测试通过');
} else {
    console.log('测试失败');
}