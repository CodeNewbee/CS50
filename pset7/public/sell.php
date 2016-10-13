<?php

    //configuration
    require("../includes/config.php");
    
    //if user reached page via GET, render sell html form
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        //get users owned stock symbols
        $rows = CS50::query("SELECT symbol FROM stocks WHERE user_id = ?", $_SESSION["id"]);
        
        //if user doesn't have any stocks
        if(empty($rows))
        {
            apologize("You do not own any stocks to sell :(");
        }
        
        $symbols = [];
        
        foreach($rows as $row)
        {
            $symbols[] = ["symbol" => $row["symbol"]];
        }
            
        render("sell_form.php", ["symbols" => $symbols, "title" => "Sell"]);
    }
    
    //else if user reached via POST
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        //get stock information
        $stock = lookup($_POST["symbol"]);
        
        //how many shares does user own
        $shares = CS50::query("SELECT shares FROM stocks WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
        $shares = $shares[0]["shares"];
        
        //calculate how much money user gains from seling his shares
        $money_gained = $stock["price"] * $shares;
        
        //remove users shares
        CS50::query("DELETE FROM stocks WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
        
        //update users cash balance
        CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $money_gained, $_SESSION["id"]);
        
        //store data in history about the transaction.
        CS50::query("INSERT INTO history (user_id, trans_type, amount, symbol, time, price) VALUES(?, 'sell', ?, ?, NOW(), ?)", $_SESSION["id"], $shares, $_POST["symbol"], $money_gained);
        
        //redirect user to index page
        redirect("/");
    }
?>