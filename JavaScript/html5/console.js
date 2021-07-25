console.log( "output1", "output2" );

var arr1 = [0, 1, 2];
console.log( arr1 );

var arr2 = ["a", "b", "c"];
console.log( arr2 );

var obj = { nm: "soldier", hp: 100 };
console.log( obj );


var obj2 = { prm: null };
for( var i = 0; i < 3; i++ ) {
    obj2.prm = { i: i };
    console.log( obj2 );
}
