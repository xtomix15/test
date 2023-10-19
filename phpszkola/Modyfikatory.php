<?php
class Fruit {
    public $name;
    protected $color;
    private $weight;
}

$mango = new Fruit();
$mango->name = "Manog"; // OK
$mango->color = "Yellow"; // ERROR
$mango->weight = "300"; // ERROR
?>