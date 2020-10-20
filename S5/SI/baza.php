<div id="prawo">
<ul id="prawolinki" type="square" style="color: blue" style="list-style-type:square"> 
<form method="get" action="wyniki.php"> 
       <input type="text" name="kryteria"/>  
       <input type="submit" name="szukaj" value="Szukaj"/> 
       </form> 
</div>

<?php
$_SESSION['prac'][]=array('imie'=>$imie,'nazwisko'=>$naz,'plec'=>$plec,'panienskie'=>$naz2,'email'=>$email,'kod'=>$kod);
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
                                
                    $wybierz = "SELECT id, imie, nazwisko, plec, naz2, email, kod FROM baza"; 
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
                    
                    
                    $zapytanie=  "SELECT id, imie, nazwisko, plec, naz2, email, kod FROM baza
                    
                    LIMIT $pomin, $liczba_na_str"; 
                    $wyniki=mysql_query($zapytanie); 
                     
                    echo 'tabelka';
                    
                    if (!isset($_GET['id']) or ((isset($_POST['NIE'])) and $_POST['NIE']=="NIE"));
                    {
                        echo '<table border=1>';
                        echo '<tr>';
                        if ($st==5) echo '<td><b>Edycja</b></td>';
                        if ($st==6) echo '<td><b>Usun</b></td>';
                        echo '<td><b>id</b></td><td><b>imie</b></td><td><b>nazwisko</b></td><td><b>plec</b></td><td><b>naz. pan.</b></td><td><b>email</b></td><td><b>kod</b></td>';
                        while ($wiersz=mysql_fetch_array($wyniki)) 
                        {  
                            echo '<tr>';
                            if ($st==5) echo '<td><a href="index.php?strona=5&id=' .$wiersz['id']. '">Edycja</a></td>';
                            if ($st==6) echo '<td><a href="index.php?strona=6&id=' .$wiersz['id']. '">Usun</a></td>';
                            
                             echo '<td>'. $wiersz['id'] . 
                                    '</td><td>'. $wiersz['imie'] . 
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
                                '?strona=6'.$strona. '&str='.($str-1).'"><-</a>';  } 
                        else  { $linki=$linki. '<-';  } 
                         
                        for($i=1; $i<=$liczba_str; $i++) { 
                           if ($str==$i) { $linki=$linki.' '.$i;  } 
                           else {  
                              $linki=$linki. '<a href="'.$_SERVER['PHP_SELF']. 
                                    '?strona=6'.$strona. '&str='.$i.'">'.$i.'</a>';  }} 
                         
                        if ($str<$liczba_str) { 
                           $linki=$linki. '<a href="'.$_SERVER['PHP_SELF']. 
                                '?strona=6'.$strona. '&str='.($str+1).'">-></a>';  } 
                                else  { $linki=$linki. '->';  } 
                        echo $linki; 

                        
                        
                    }
                    if($st==6)
                    {
                        if (!isset($_POST['TAK']) and (isset($_GET['id'])))
                        {
                            $ajdi = $_GET['id'];
                            echo '<form action="index.php?str=6&id=' .$wiersz['id']. '" method="post">';
                            echo 'Usunac uzytkownika o id ' .$_GET['id']. '?';
                            echo '<input type="submit" name="TAK" value="TAK" method="post">';
                            echo '<input type="submit" name="NIE" value="NIE" method="post">';
                            $zapytanie=  "DELETE FROM baza WHERE id = $ajdi"; 
                            $wyniki=mysql_query($zapytanie);
                            echo 'espost ' .$_POST['TAK']. ' ';
                        }
                        else
                        {
                            
                        }
                        
                        if (isset($_POST['TAK']) and $_POST['TAK']=='TAK')
                        {
                            $ajdi = $_GET['id'];
                            echo 'usuwam usera o id ' .$_GET['id']. ' ';
                            $zapytanie=  "DELETE FROM baza WHERE id = $ajdi"; 
                            $wyniki=mysql_query($zapytanie);
                            echo 'usuwam usera o id ' .$_GET['id']. ' ';
                            include("baza.php");
                        }
                        else
                        {
                            
                        }
                    }
                    
                    
                    if($st==5)
                    {
                        if ((isset($_GET['id'])))
                        {
                            $ajdi = $_GET['id'];
                            echo '<form action="index.php?str=6&id=' .$wiersz['id']. '" method="post">';
                            echo 'Edytowac uzytkownika o id ' .$_GET['id']. '?';
                            include("form.php");
                        }
                        else
                        {
                            
                        }
                        if($_GET['str']==5)
                        {
                            include("form.php");
                        }
                        
                    }
                
                    

                }
                else
                {
                    echo "BLAD - ".mysql_error();
                }
            }
            else
            {
                echo "BLAD - ".mysql_error();
            }
            mysql_close();
        }
        else
        {
            echo "BLAD - ".mysql_error();
        }
?>



