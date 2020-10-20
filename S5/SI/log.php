<?
php session_start(); 
if (!isset($_SESSION['licznik'])) 
$_SESSION['licznik'] = 0;
else 
$_SESSION['licznik']++;
?>
<html><body><?php
echo "Liczba wizyt na stronie: ";
echo "<b>".$_SESSION['licznik']."</b>";
?></body></html>


<?php
session_start();
if (isset($_SESSION['klient']))
{
$_SESSION=array();
if (isset($_COOKIE[session_name()]))
{
setcookie(session_name(),'',time()-3600);  
}
session_destroy();
}  
?>