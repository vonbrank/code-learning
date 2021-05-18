'use strict';

function get_primes(arr) {
    return arr.filter(function (x) {
        return arr.filter(function (x) {
            if (x == 1) return false;
            if (x == 2) return true;
            for (var i = 2; i < x; i++) {
                if (x % i == 0) return false;
            }
            return true;
        });
    }

// 测试:
var
        x,
        r,
        arr = [];
    for (x = 1; x < 100; x++) {
        arr.push(x);
    }
    r = get_primes(arr);
    if (r.toString() === [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97].toString()) {
        console.log('测试通过!');
    } else {
        console.log('测试失败: ' + r.toString());
    }