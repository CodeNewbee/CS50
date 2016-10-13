<?php 

    //configuration
    require("../includes/config.php");

    $data = CS50::query("SELECT trans_type, time, symbol, amount, price FROM history WHERE user_id = ?", $_SESSION["id"]);
    //dump($data);    
    
    //render history view, pass data associative array.
    render("history_view.php", ["data" => $data, "title" => "History"]);
?>