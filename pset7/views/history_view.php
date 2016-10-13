<table style="width:100%", class="table-style">
    <tr>
        <th>Transaction</th>
        <th>Date</th>
        <th>Symbol</th>
        <th>Shares</th>
        <th>Price</th>
    </tr>
<?php foreach ($data as $row): ?>
    <tr>
        <td><?= $row["trans_type"] ?></ td>
        <td><?= $row["time"] ?></ td>
        <td><?= $row["symbol"] ?></ td>
        <td><?= $row["amount"] ?></ td>
        <td><?= $row["price"] ?></ td>
    </tr>
<?php endforeach ?>
</table>