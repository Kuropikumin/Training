var a = new Array(100, 500, 300);
console.log(a.length);
a.push(700);
console.log(a);

a.unshift(50);
console.log(a);

a.splice(1, 2);
console.log(a);

a.splice(1, 2, 800, 1000);
console.log(a);
