function User( forename, username, password )
{
    this.forename = forename
    this.username = username
    this.password = password

    this.showUser = function()
    {
        var s = ""
        s += "Forename: " + this.forename + "<br />"
        s += "Usrename: " + this.username + "<br />"
        s += "Password: " + this.password + "<br />"
        return s
    }
}
