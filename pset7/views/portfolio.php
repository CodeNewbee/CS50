<table style="width:100%" class="table-style">
    <tr>
        <th>Stock symbol</ th>
        <th>Stock Name</ th>
        <th>Amount of shares</ th>
        <th>Current price</ th>
        <th>Total value</ th>
    </tr>
    <tr>
        <td>CASH</td>
        <td></td>
        <td></td>
        <td></td>
        <td><?= $cash ?></td>
    </tr>
<?php foreach ($positions as $position): ?>
    <tr>
        <td><?= $position["symbol"] ?></ td>
        <td><?= $position["name"] ?></ td>
        <td><?= $position["shares"] ?></ td>
        <td><?= $position["price"] ?></ td>
        <td><?= $position["value"] ?></ td>
    </tr>
<?php endforeach ?>
</table>