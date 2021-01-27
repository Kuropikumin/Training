function User2( forename, username, password )
{
    this.forename = forename
    this.username = username
    this.password = password
    this.showUser = showUser
}

function showUser()
{
    var s = ""
    s += "Forename: " + this.forename + "<br />"
    s += "Uorename: " + this.username + "<br />"
    s += "Password: " + this.password + "<br />"
    return s
}
