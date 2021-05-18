'use strict'

function* next_id() {
    for (var i = 1; i < 100; i++) {
        yield i;
    }
}


var
    x,
    pass = true,
    g = next_id();
for (x = 1; x < 100; x++) {
    if (g.next().value !== x) {
        pass = false;
        console.log('测试失败!');
        break;
    }
}
if (pass) {
    console.log('测试通过!');
}