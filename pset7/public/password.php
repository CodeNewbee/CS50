<?php

    //configuration
    require("../includes/config.php");
    
    //If page reached via GET, render form
    if($_SERVER["REQUEST_METHOD"] == "GET")
    {
        render("password_form.php", ["title" => "Change password"]);
    }
    
    //If site reached via POST handle the information from the form
    else if($_SERVER["REQUEST_METHOD"] == "POST")
    {
        //validate submision
        if (empty($_POST["password"]))
        {
            apologize("You did not provide a new password.");
        }
    
    	//update users password
    	CS50::query("UPDATE users SET hash = ? WHERE id = ?", password_hash($_POST["password"], PASSWORD_DEFAULT), $_SESSION["id"]);
    
    	redirect("/");
    }

?>
