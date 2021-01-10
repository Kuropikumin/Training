function ajaxRequest()
{
    try
    {
        console.log( "First try >>> \n")
        var request = new XMLHttpRequest()
    }
    catch( e1 )
    {
        console.log( "e1 : \n" + e1 )
        try
        {
            console.log( "Second try >>> \n")
            request = new ActiveXObject( "Msxml2.XMLHTTP" )
        }
        catch( e2 )
        {
            console.log( "e2 : \n" + e2 )
            try
            {
                console.log( "Third try >>> \n")
                request = new ActiveXObject( "Microsoft.XMLHTTP" )
            }
            catch( e3 )
            {
                console.log( "e3 : \n" + e3 )
                request = false
            }
        }
    }
    return request
}
