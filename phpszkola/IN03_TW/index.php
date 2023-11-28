

<!DOCTYPE html>
<html lang="pl">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Sklep dla uczniów</title>
        <link rel="stylesheet" href="styl.css"> 
    </head>
    <?php 
        $servername = "localhost";
        $user = "root";
        $password = "";
        $db = "sklep";

        $conn = mysqli_connect($servername, $user, $password, $db);
    ?>
    <body>
        <header>
            <h1>Dzisiejsze promocje naszego sklepu</h1>
        </header>
        <main>
            <div class="left">
                <h2>Taniej o 30%</h2>
                <ol>
                    <?php 
                        $sql = "SELECT nazwa FROM `towary` WHERE promocja = 1;";

                        $result = mysqli_query($conn, $sql);

                        if(mysqli_num_rows($result)>0) {
                            while($row = mysqli_fetch_assoc($result)) {
                                echo "<li>" . $row['nazwa'] . "</li></br>";
                            }
                        }
                    ?>
                </ol>
            </div>
            <div class="center">
                <h2>Sprawdź cenę</h2>
                <form method="post" action="index.php">
                    <select name="taskOption">
                        <option value="Gumka do mazania" >Gumka do mazania</option>
                        <option value="Cienkopis" >Cienkopis</option>
                        <option value="Pisaki 60 szt." >Pisaki 60 szt.</option>
                        <option value="Markery 4 szt." >Markery 4 szt.</option>
                    </select>
                    <input type="submit" value="Sprawdź"></br>
                </form>
                <div class="php2">
                    <?php 
                    
                        $selectOption = $_POST['taskOption'];

                        if(isset($_POST['taskOption'])) {
                            $sql = "SELECT cena FROM `towary` WHERE nazwa LIKE '$selectOption';";
                            
                            $result = mysqli_query($conn, $sql);

                            if(mysqli_num_rows($result)>0) {
                                while($row = mysqli_fetch_assoc($result)) {
                                    echo "cena regularna: " . $row['cena'] . "</br>
                                    cena w promocji 30%: " . ($row['cena']-($row['cena']*0.3));
                                }
                            }
                        } else {
                            echo "Kod nie działa";
                        }
                    
                    ?>
                </div>
            </div>
            <div class="right">
                <h2>Kontakt</h2>
                <p>e-mail: <a href="bok@sklep.pl">bok@sklep.pl</a></p>
                <img src="promocja.png" alt="promocja">
            </div>
        </main>
        <footer>
            <h4>Autor strony: Tomasz Woźny</h4>
        </footer>
        <?php
            mysqli_close($conn);
        ?>
    </body>
</html>