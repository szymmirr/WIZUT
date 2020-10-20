<h2>&emsp; Najlepszy formularz</h2>

<?php

$wal_c=0;
$w_im=1;
$kryteria="";

if (isset($_GET["szukaj"]))
{
    $kryteria=$_GET["kryteria"];
    
    if(empty($kryteria))
        $w_im=0;
    
    else
        $w_im=1;

    
    if(($w_im==1))
        $wal_c=1;
    
    if($wal_c==1)
    {
        $_SESSION['prac'][]=array('kryteria'=>$kryteria);
        $pol=mysql_connect('127.0.0.1','szymmirr','haslo');
        if($pol)
        {
            $baza=mysql_select_db('szymmirr');
            if($baza)
            {
                $zap=mysql_query("SELECT * from baza;");
                if($zap)
                {
                    
                    $linki=' '; 
                                
                    $wybierz = "SELECT id, kryteria, nazwisko, plec, naz2, email, kod FROM baza"; 
                    $id_zap = mysql_query($wybierz);  
                    
                    
                    $zapytanie="SELECT count(*) FROM baza"; 
                    $pomoc=mysql_query ($zapytanie); 
                    $liczba_wyn=mysql_result($pomoc, 0); 
                     
                    $liczba_na_str=10;  
                    $liczba_str=$liczba_wyn/$liczba_na_str; 
                    $liczba_str=ceil($liczba_str); 
                     
                    if (isset($_GET['str']))   $str=$_GET['str'];  
                    else $str=1;  
                    $pomin=($str-1)*$liczba_na_str; 
                    
                    
                    $zapytanie=  "SELECT id, kryteria, nazwisko, plec, naz2, email, kod FROM baza
                    
                    LIMIT $pomin, $liczba_na_str"; 
                    
                    $query = "SELECT * FROM tabela"; 
                    $szukaj = $_GET['kryteria']; 
                    $where ='';
                    
                    $tablica_slow=explode(' ',$szukaj); 
                    
                    $where =  " nazwisko LIKE '%$szukaj%'";
                    
                    $lista_kryteriow[0]=" nazwisko LIKE '%$tablica_slow[0]%'"; 
                    $lista_kryteriow[1]=" nazwisko LIKE '%$tablica_slow[1]%'"; 
                    
                    $slowo1=$tablica_slow[0];
                    $slowo2=$tablica_slow[1];
                    $slowo3=$tablica_slow[2];
                    
                    $where=implode(' OR ', $lista_kryteriow); 
                    
                    
                    
                    $zapytanie="SELECT count(*) FROM baza WHERE $where"; 
                    $pomoc=mysql_query ($zapytanie); 
                    $liczba_wyn=mysql_result($pomoc, 0); 
                    
                    $liczba_na_str=10;  
                    $liczba_str=$liczba_wyn/$liczba_na_str; 
                    $liczba_str=ceil($liczba_str); 
                     
                    if (isset($_GET['str']))   $str=$_GET['str'];  
                    else $str=1;  
                    $pomin=($str-1)*$liczba_na_str; 
                    
                    $where = "SELECT id, kryteria, nazwisko, plec, naz2, email, kod FROM baza
                    WHERE $where
                    LIMIT $pomin, $liczba_na_str"; 
                    
                    
                    
                     
                    if (!empty($where)) 
                    {    $query = $query . " WHERE $szukaj"; } 
                    
                    $wyniki=mysql_query($where); 
                    echo "tabelka";
                    echo '<table border=1>';
                    echo '<tr><td><b>id</b></td><td><b>kryteria</b></td><td><b>nazwisko</b></td><td><b>plec</b></td><td><b>naz. pan.</b></td><td><b>email</b></td><td><b>kod</b></td>';
                    while ($wiersz=mysql_fetch_array($wyniki)) 
                    {  
                         echo '<tr><td>'. $wiersz['id'] . 
                                '</td><td>'. $wiersz['kryteria'] . 
                                '</td><td>'. $wiersz['nazwisko'] . 
                                '</td><td>'. $wiersz['plec'] . 
                                '</td><td>'. $wiersz['naz2'] . 
                                '</td><td>'. $wiersz['email'] . 
                                '</td><td>'. $wiersz['kod'] . 
                              '</td></tr>';  
                    }
                    echo '</table>';
                     if ($str>1) { 
                       $linki=$linki. '<a href="'.$_SERVER['PHP_SELF']. 
                            '?szukaj='.$szukaj. '&str='.($str-1).'"><-</a>';  } 
                    else  { $linki=$linki. '<-';  } 
                     
                    for($i=1; $i<=$liczba_str; $i++) { 
                       if ($str==$i) { $linki=$linki.' '.$i;  } 
                       else {  
                          $linki=$linki. '<a href="'.$_SERVER['PHP_SELF']. 
                                '?szukaj='.$szukaj. '&str='.$i.'">'.$i.'</a>';  }} 
                     
                    if ($str<$liczba_str) { 
                       $linki=$linki. '<a href="'.$_SERVER['PHP_SELF']. 
                            '?szukaj='.$szukaj. '&str='.($str+1).'">-></a>';  } 
                            else  { $linki=$linki. '->';  } 
                    echo $linki; 

                }
                else
                {
                    echo "BLAD - ".mysql_error();
                }
            }
            mysql_close();
        }
        else
        {
            echo "BLAD";
        }
        echo " ROLF ";
        echo "&emsp; kryteria: <b>$kryteria</b></br>";

    }
}
if((!isset($_GET["szukaj"])) or ($wal_c==0))
{
    ?>
    <?php
    echo '<form method="get" action="">';
    ?>
    <div>
        <label>kryteria:</label>
        <input type="text" id="1" name="kryteria"/>
    </div>
    <div id="button">
    <?php
    ?>
    <input type='submit' name="szukaj" value='Wyslij' id="8">
    <?php
    ?>
    </div>
</form>
<?php
}

?>