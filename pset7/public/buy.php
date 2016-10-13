<?php 

    //configuration
    require("../includes/config.php");
    
    //if user reached page via GET
    if($_SERVER["REQUEST_METHOD"] == "GET")
    {
        render("buy_form.php", ["title" => "Buy"]);
    }
    
    //if user reached page via POST
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        //fetch stock symbol and amount of shares from the form
        $symbol = strtoupper($_POST["symbol"]);
        $amount = $_POST["amount"];
        
        //fetch stock info
        $stock = lookup($symbol);
        
        //dump($stock);
        
        //check if stock exsists
        if(!$stock)
        {
            apologize("Stock symbol does not exsist. Check spelling and try again.");
        }
        
        //users money left after purchase 
        $money_left = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
        $money_left = $money_left[0]["cash"] - $stock["price"] * $amount;
        
        //if user can't afford the purchase
        if($money_left < 0)
        {
            apologize("Insufficient funds.");
        }
        
        //if user tries to buy non positive or non integer amount of stocks
        if(!preg_match("/^\d+$/", $amount) or $amount == 0)
        {
            apologize("Amount of shares must be whole, positive integers.");
        }
        
        //update users cash balance
        CS50::query("UPDATE users SET cash = ? WHERE id = ?", $money_left, $_SESSION["id"]);
        
        //update users stocks
        CS50::query("INSERT INTO stocks (user_id, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", $_SESSION["id"], $symbol, $amount);

        //store data in history about the transaction.
        CS50::query("INSERT INTO history (user_id, trans_type, amount, symbol, time, price) VALUES(?, 'buy', ?, ?, NOW(), ?)", $_SESSION["id"], $amount, $symbol, $stock["price"] * $amount);
        
        redirect("/");
    }
?>