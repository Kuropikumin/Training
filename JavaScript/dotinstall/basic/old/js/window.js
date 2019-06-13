console.dir(window);
console.log(window.outerHeight);
// window.location.href = 'http://dotinstall.com';
//
var e = document.getElementById('msg');
e.txtContext = "hogehoge";
e.style.color = 'red';

var greet = document.createElement('p');
var text  = document.createTextNode('hello world');
document.body.appendChild(greet).appendChild(text);

document.getElementById('add').addEventListener('click', function(){
var greet = document.createElement('p');
var text  = document.createTextNode('hello world');
document.body.appendChild(greet).appendChild(text);
});
