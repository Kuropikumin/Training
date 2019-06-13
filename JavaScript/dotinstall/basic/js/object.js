var user = 
    {
        email: "hoge@aa.bb.cc",
        score: 90,
        greet: function(name) {
            console.log("Hello, " + name + " from " + this.email);
        }
    };

console.log(user["email"]);
console.log(user.score);
user.score = 100;
console.log(user.score);
user.greet("Tom");

