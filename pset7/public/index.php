<?php

    // configuration
    require("../includes/config.php"); 

    $positions = [];
    
    //get users symbol and shares
    $rows = CS50::query("SELECT symbol, shares FROM stocks WHERE user_id = ?", $_SESSION["id"]);
    $money = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
    
    //store in positions stock name, current price, amount of shares user has, stock symbol, and value in cash of the stocks user has
    foreach($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if($stock !== false)
        {
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "shares" => $row["shares"],
                "symbol" => $row["symbol"],
                "value" => $stock["price"] * $row["shares"],
                ];
        }
    }
    
    render("portfolio.php", ["positions" => $positions, "cash" => $money[0]["cash"], "title" => "Portfolio"]);

?>
