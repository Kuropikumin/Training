Vue.createApp({
    data: function() {
        return {
            email: 'Y-Suzuki@example.com'
        };
    },

    computed: {
        localEmail: function() {
            return this.email.split('@')[0].toLowerCase();
        }
    }

    // 関数を呼び出すやり方でもOK
    // ,
    // methods: {
    //     localEmail: function() {
    //         return this.email.split('@')[0].toLowerCase();
    //     }
    // }
}).mount('#app');