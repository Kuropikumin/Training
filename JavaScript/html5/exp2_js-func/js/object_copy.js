var obj1 = { name: "hoge", hp: 10 };
var obj2 = obj1;

console.log( obj1 );
obj1["name"] = "fuga";
console.log( obj2 );

var obj3 = test( obj1 );
console.log( obj3 );
console.log( obj1 );

function test( arg ) {
    var keys = [ "name", "mp" ];
    var obj = {
        [keys[0]]: "fuga",
        [keys[1]]: 100
    };
    return $.extend( true, obj, arg );
}
