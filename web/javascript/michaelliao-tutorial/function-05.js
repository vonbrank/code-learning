'use strict'

function normalize(arr) {
    function f(s) {
        s = s.split("");
        if (!(s[0] >= 'A' && s[0] <= 'Z')) s[0] = s[0] - 'a' + 'A';
        for (var i = 1; i < s.length; i++) {
            if (!(s[i] >= 'a' && s[i] <= 'z')) s[i] = s[i] - 'A' + 'a';
        }
        return s.toString();
    }
    console.log(f(arr[0]));
    return arr.map();
}

console.log(normalize(['adam', 'LISA', 'barT']).toString());

// 测试:
if (normalize(['adam', 'LISA', 'barT']).toString() === ['Adam', 'Lisa', 'Bart'].toString()) {
    console.log('测试通过!');
}
else {
    console.log('测试失败!');
}