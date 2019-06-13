'use strict';

{
    class Player {
        constructor(name, score) {
            this.name  = name;
            this.score = score;
        }

        showInfo() {
            console.log(`name: ${this.name} score: ${this.score}`);
        }

        static showVersion() {
            console.log("hogehoge");
        }
    }

    class SoccerPlayer extends Player {
        constructor(name, score, number) {
            super(name, score);
            this.number = number;
        }
        kick() {
            console.log('Goal!');
        }
    }

    const taguchi = new Player('taguchi', 32);
    taguchi.showInfo();
    Player.showVersion();

    const test = new SoccerPlayer('test', 35, 10);
    test.kick();
}


