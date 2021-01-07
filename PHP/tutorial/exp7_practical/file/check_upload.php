<?php
    echo <<<_END
<html><head><title>PHP Form Upload</title></head><body><form method='post' action='check_upload.php' enctype='multipart/form-data'>Select JPG, GIF or PNG File: <input type='file' name='filename' size='10' /><input type='submit' value='Upload' /></form>
_END;

    if( $_FILES ) {
        print_r( $_FILES['filename'] );
        extract($_FILES['filename']);
        echo $name . " : " . $tmp_name . " : " . $type . "<br>\n";
        switch( $type ) {
            case 'image/jpeg' : $ext = 'jpg'; break;
            case 'image/png'  : $ext = 'png'; break;
            case 'image/gif'  : $ext = 'gif'; break;
            case 'image/tiff' : $ext = 'tif'; break;
            default            : $ext = '';
        }

        if( $ext ) {
            $n = "image.$ext";
            move_uploaded_file( $tmp_name, $n );
            echo "Uploaded image '$name' as '$n' <br><img src='$n' />";
        }
        else {
            echo "'$name' is not an accepted image file!<br>\n";
        }
    }
    else {
        echo "No image has been uploaded!<br>\n";
    }

    echo "</body></html>";
?>
