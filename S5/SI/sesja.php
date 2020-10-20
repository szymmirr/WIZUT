<?php
echo '<table border="1">';
echo sprintf('<tr>');
       echo sprintf('<td><b>imie</b></td><td><b>nazwisko</b></td><td><b>plec</b></td><td><b>naz. pan.</b></td><td><b>email</b></td><td><b>kod</b></td>');

    echo sprintf('</tr>');

foreach ($_SESSION["prac"] as $rek => $war)
{    
    echo sprintf('<tr>');
    foreach($_SESSION['prac'][$rek] as $klucz=>$war)
    {
       
       echo sprintf('<td>%s</td>', $war);

    }
    echo sprintf('</tr>');
}
echo '</table>';
?>
