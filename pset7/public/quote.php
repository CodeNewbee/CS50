<?php

    //configuration
    require("../includes/config.php");
    
    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("quote_form.php", ["title" => "Quote"]);
    }
    
    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        
        $stock_info = lookup($_POST["symbol"]);
        
        if($stock_info)
        {
            render("quote_display.php", $stock_info);
        }
        else
        {
            apologize("Requested stock symbol could not be found. Check spelling and try again.");
        }
    }