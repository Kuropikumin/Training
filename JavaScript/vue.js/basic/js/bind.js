Vue.createApp({
    data: function() {
        return {
            url: 'https://wings.msn.to/'
        };
    }
}).mount( '#app' );

Vue.createApp({
    data: function() {
        return {
            flag: false
        };
    }
}).mount( '#app2' );

