<?php
    $servername = "localhost";
    $username = "root"; // root
    $password = ""; // ""


    // create connections
    $conn = mysqli_connect($servername, $username, $password);


    // check connection
    if (!$conn) {
        die("Connection failed: " . mysqli_connect_error());
    }
    echo "Connect successfully!";

    $database="5ina28";


    //Create database
    $sql = "CREATE DATABASE $database";
    if (mysqli_query($conn, $sql)) {
        echo "Database created succesfully<br>";
    } else {
       echo "Error creating database: <br>" . mysqli_error($conn);
    }


    // Connect to database
    if(mysqli_select_db($conn, $database)) {
        echo "Database $database selected<br>";
    } else {
        echo "Error select database: <br>" . mysqli_error($conn);
    }

    $sql = "CREATE TABLE MyGuests (
                                id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
                                firstname VARCHAR(30) NOT NULL,
                                lastname VARCHAR(30) NOT NULL,
                                email VARCHAR(50),
                                reg_date TIMESTAMP DEFAULT
                                        CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
                                )";
    if (mysqli_query($conn, $sql)) {
        echo "Table Myguests created successfully<br>";
    } else {
        echo "Error creating table:<br> " . mysqli_error($conn);
    }
    // insert data
    // $sql = "INSERT INTO MyGuests (firstname, lastname, email)
    // VALUES ('Arthur', 'Ben', 'Apt@example.com');";
    // $sql .="INSERT INTO MyGuests (firstname, lastname, email)
    // VALUES ('Michael', 'Moke', 'Mok@example.com');";
    // $sql .="INSERT INTO MyGuests (firstname, lastname, email)
    // VALUES ('Simeon', 'Got', 'gok@example.com');";

    // if (mysqli_multi_query($conn, $sql)) {
    //     echo "New record created successfully";
    // } else {
    //     echo "Error: " . $sql . "<br>" . mysqli_error($conn);
    // }

    // select data
    $sql = "SELECT id, firstname, lastname FROM MyGuests";
    $result = mysqli_query($conn, $sql);
    echo "<br>";
    if (mysqli_num_rows($result) > 0){
        //output data of each row
        while($row = mysqli_fetch_assoc($result)){
            echo "id: " . $row["id"]. " - Name: " . $row["firstname"]. " " . $row["lastname"]. "<br>";
        }
    } else{
        echo "0 results";
    }

    //delete data
    $sql = "DELETE FROM MyGuests WHERE id=3";

    if(mysqli_query($conn, $sql)){
        echo "Record deleted successfully<br>";
    } else {
        echo "Error deleting record: " . mysqli_error($conn);
    }

    //update data

    $sql = "UPDATE MyGuests SET lastname='Doe' WHERE id=2";

    if (mysqli_query($conn, $sql)) {
        echo "Record updated successfully <br>";
    } else {
        echo "Error updating record: " . mysqli_error($conn);
    }

    //  select data - ver.2
    $sql = "SELECT id, firstname, lastname FROM MyGuests";
    $result = mysqli_query($conn, $sql);

    if (mysqli_num_rows($result) > 0){
        // output data of each row
        while($row = mysqli_fetch_row($result)){
            echo "id: ". $row[0]. " - Name: ". $row[1]. " ". $row[2]. "<br>";
        }
    } else {
        echo "0 results";
    }

    // select data - generowanie tabeli
    $sql = "SELECT id, firstname, lastname FROM MyGuests";
    $result = mysqli_query($conn, $sql);

    if (mysqli_num_rows($result) >0){
        echo "<table>";
        while($row = mysqli_fetch_row($result)){
            echo "<tr><td>" . $row[0]. "</td><td>" . $row[1]. "</td><td>" . $row[2]. "</td></tr>";
        }
        echo "</table>";
    } else {
        echo "0 results";
    }
    
    // select data - generowanie listy
    $sql = "SELECT id, firstname, lastname FROM MyGuests";
    $result = mysqli_query($conn, $sql);

    if(mysqli_num_rows($result) >0 ){
        echo "<ul>";
        while($row = mysqli_fetch_row($result)){
            echo "<li>" . $row[0]. " " . $row[1]. " " . $row[2]. "</li>";
        }
        echo "</ul>";
    } else {
        echo "0 results";
    }

    
?>