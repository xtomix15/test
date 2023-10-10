<?php
    $wzorzec = '/[-\w.]+@([-A-z0-9]+\.)+[A-z]/';
    $tekst = "email: john@poczta.eu";
    if(preg_match($wzorzec, $tekst))
        echo "znaleziono email";
    else
        echo "nie znaleziono email";
?>