<?php
    // utworzenie nowego pliku i zapis tekstu do niego

    $myfile = fopen("newfile.txt","w")
                or die("Unable to open file");
    $tekst = "John już to nie mieszka";
    fwrite( $myfile, $tekst );
    fclose( $myfile );
?>