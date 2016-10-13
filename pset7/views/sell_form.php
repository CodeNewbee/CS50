<form action="sell.php" method="post">
    <fieldset>
        
        <div class ="form-group">
            <select name="symbol">
                <?php foreach($symbols as $symbol): ?>
                  <option <?=$symbol["symbol"]?>> <?=$symbol["symbol"]?> </option>
                <?php endforeach ?>
            </select>
        </div>
        
        <div class="form-group">
            <button class="btn btn-default" type="submit">
                <span aria-hidden="true" class="glyphicon glyphicon-ok"></span>
                Sell
            </button>
        </div>
        
    </fieldset>
</form>
