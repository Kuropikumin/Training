function validate( form )
{
    fail = ''
    fail += validateForename( form.forename.value )
    fail += validateSurname(  form.surname.value )
    fail += validateUsername( form.username.value )
    fail += validatePassword( form.password.value )
    fail += validateAge(      form.age.value )
    fail += validateEmail(    form.email.value )

    if( fail == '' ) return true
    else {
        alert( fail )
        return false
    }

    function validateForename( field )
    {
        if( field == "" ) return "Forenameが入力されていません。\n"
        return ""
    }

    function validateSurname( field )
    {
        if( field == "" ) return "Surnameが入力されていません。\n"
        return ""
    }

    function validateUsername( field )
    {
        if( field == "" ) return "Usernameが入力されていません。\n"
        else if( field.length < 5 ) return "Usernameは5文字以上必要です\n"
        else if( /[^a-zA-Z0-9_-]/.test( field ) ) return "Username で利用できる文字は半角英数字及び _, - のみです。\n"
        return ""
    }

    function validatePassword( field )
    {
        if( field == "" ) return "Passwordが入力されていません。\n"
        else if( field.length < 6 ) return "Passwordは5文字以上必要です\n"
        else if( !/[a-z]/.test( field ) &&
                 !/[A-Z]/.test( field ) &&
                 !/[0-9]/.test( field )
               ) return "Passwordには、半角英小文字、半角英大文字、半角数字がそれぞれ1文字以上必要です。\n"
        return ""
    }

    function validateAge( field )
    {
        if( field == "" ) return "Forenameが入力されていません。\n"
        else if( /[^\d]/.test( field ) )     return "半角数字を入力して下さい\n"
        else if( field < 18 || 110 < field ) return "本サイトを利用できる年齢は、18歳以上110歳以下です\n"

        console.log( field )
        return ""
    }

    function validateEmail( field )
    {
        if( field == "" ) return "Emailが入力されていません。\n"
        else if( !( ( field.indexOf( "." ) > 0 ) &&
                    ( field.indexOf( "@" ) > 0 ) ) || 
                 /[^a-zA-Z0-9@._-]/.test( field ) ) return "無効なメールアドレスです\n"
        return ""
    }
}
