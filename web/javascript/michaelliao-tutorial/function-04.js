'use strict';

function string2int(s) {
    console.log(s.split(""));
    s = s.split("");
    var arr = s.map(function (x) {
        return x - '0';
    });
    console.log(arr);
    // console.log(arr.reduce(function (x, y) { return 10 * x + y }));
    return arr.reduce(function (x, y) {
        return 10 * x + y;
    });
}

string2int('123');

// 测试:
if (string2int('0') === 0 && string2int('12345') === 12345 && string2int('12300') === 12300) {
    if (string2int.toString().indexOf('parseInt') !== -1) {
        console.log('请勿使用parseInt()!');
    } else if (string2int.toString().indexOf('Number') !== -1) {
        console.log('请勿使用Number()!');
    } else {
        console.log('测试通过!');
    }
}
else {
    console.log('测试失败!');
}