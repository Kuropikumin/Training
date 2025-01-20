Vue.createApp({
    data() {
        return {
            message: 'ようこそ、Vue.jsへ'
        };
    },

    mounted() {
        this.message = '初めまして、私はVue.jsです';
        // console.log( this.$el.textContent.includes( this.message ) ); $elがthis.message変数を持っていないという結果になる
        this.$nextTick( () => {
            console.log( this.$el.textContent.includes( this.message ) );
        });
    }
}).mount('#app');