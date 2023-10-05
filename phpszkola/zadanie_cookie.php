<?php
    $cookie_name ="promocja";
    $cookie_value ="wycieczka";
    
    setcookie($cookie_name, $cookie_value, 
                time() + (2*24*60*60) ); // 1 day

        $cookie_name = "promocja";
    if(!isset($_COOKIE[$cookie_name])) {
        echo "Cookie named '" . $cookie_name . "' is not set!";
   
    } else {
        echo "Cookie '" .$cookie_name . "' is set! <br>";
        echo "Value is: ".$_COOKIE[$cookie_name];
    }

    setcookie("promocja","",time() + 10); 
?>