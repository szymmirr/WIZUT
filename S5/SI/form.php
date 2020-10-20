<h2>&emsp; Najlepszy formularz</h2>

<?php

$wal_c=0;
$w_im=1;
$imie="";
$w_naz=1;
$naz="";
$w_plec=1;
$plec="";
$w_naz2=1;
$naz2="";
$w_email=1;
$w_email2=1;
$email="";
$w_kod=1;
$w_kod2=1;
$kod="";
if (isset($_POST["wyslij"]))
{
    $imie=$_POST["imie"];
    
    if(empty($imie))
        $w_im=0;
    
    else
        $w_im=1;
        
    
    $naz=$_POST["nazwisko"];
    
    if(empty($naz))
        $w_naz=0;
    
    else
        $w_naz=1;
        
    $plec=$_POST["plec"];
    
    if(empty($plec))
        $w_plec=0;
    
    else
        $w_plec=1;
        
    $naz2=$_POST["panienskie"];
    
    if(empty($naz2))
        $w_naz2=0;
    
    else
        $w_naz2=1;
        
    $email=$_POST["email"];
        
    if(empty($email))
        $w_email=0;
    
    else
        $w_email=1;
        
    if(!eregi("^[_.0-9a-z-]+@([0-9a-z][0-9a-z-]+.)+[a-z]{2,4}$" , $email))
    {
        $email="";
        $w_email2=0;
    }
          
    else
        $w_email2=1;
        
    $kod=$_POST["kod"];
        
    if(empty($kod))
        $w_kod=0;
    
    else
        $w_kod=1;
        
    if(preg_match("/^([0-9]{2})(-[0-9]{3})?$/i",$kod))
    {
        $w_kod2=1;
    }
    else
    {
        $kod="";
        $w_kod2=0;
    }
        
        
        
        
    
    if(($w_im==1) and ($w_naz==1) and ($w_plec==1) and ($w_email==1) and ($w_kod==1) and ($w_kod2==1) and ($w_email2==1))
        $wal_c=1;
    
    if($wal_c==1)
    {
        $_SESSION['prac'][]=array('imie'=>$imie,'nazwisko'=>$naz,'plec'=>$plec,'panienskie'=>$naz2,'email'=>$email,'kod'=>$kod);
        $pol=mysql_connect('127.0.0.1','szymmirr','haslo');
        if($pol)
        {
            $baza=mysql_select_db('szymmirr');
            if($baza and $st==2)
            {
                $zap=mysql_query("INSERT INTO baza (imie,nazwisko,plec,naz2,email,kod) VALUES ('$imie','$naz','$plec','$naz2','$email','$kod');");
            }
            else
            {
                $zap=mysql_query("INSERT INTO baza (imie,nazwisko,plec,naz2,email,kod) VALUES ('$imie','$naz','$plec','$naz2','$email','$kod');");
            }
            mysql_close();
        }
        else
        {
            echo "BLAD";
        }
        echo " ROLF ";
        echo "&emsp; Imie: <b>$imie</b></br>";
        echo "&emsp; Nazwisko: <b>$naz</b></br>";
        if($plec == 'k')
        {
            echo "&emsp; Plec: <b>kobieta</b></br>";
        }
        else
        {
            echo "&emsp; Plec: <b>mezczyzna</b></br>";
        }
        echo "&emsp; Nazwisko panienskie: <b>$naz2</b></br>";
        echo "&emsp; Email: <b>$email</b></br>";
        echo "&emsp; Kod pocztowy: <b>$kod</b></br>";

    }
}
if((!isset($_POST["wyslij"])) or ($wal_c==0))
{
    ?>
    <?php
    if ($st==2) echo '<form method="POST" action="index.php?strona=2">';
    if ($st==5) echo '<form method="POST" action="index.php?strona=5">';
    ?>
    <div>
        <label>Imie:</label>
        <input type="text" id="1" name="imie" value="<?php
        if($w_im==1)
        echo "$imie";
        ?>">
        <?php if($w_im==0)
        echo "podaj imie";
        ?>
    </div>
    <div>
        <label>Nazwisko:</label>
        <input type="text" id="2" name="nazwisko" value="<?php
        if($w_naz==1)
        echo "$naz";
        ?>">
        <?php if($w_naz==0)
        echo "podaj nazwisko";
        ?>
    </div>
    </br>
    <div>
        <label>Plec:</label>
        <?php
        if ($st==2) echo '<div id="plec">';
        else echo '<div id="plecedit">';
        ?>
        <input type="radio" name="plec" id="3" value="k"
        <?php if($plec=='k')
        echo "checked";
        ?>> Kobieta </br>
        <input type="radio" name="plec" value="m" id="4"
        <?php if($plec=='m')
        echo "checked";
        ?>> Mezczyzna </br>
        </div>
        <?php if($w_plec==0)
        echo "&emsp; &emsp; &emsp; 
        &emsp;&emsp;&emsp; &emsp; &emsp;podaj plec";
        ?>
    </div>
    </br>
    <div>
        <label>Nazwisko panienskie:</label>
        <input type="text" id="5" name="panienskie" value="<?php
        if($w_naz2==1)
        echo "$naz2";
        ?>">
    </div>
    <div>
        <label>Email:</label>
        <input type="text" id="6" name="email" value="<?php
        if($w_email==1)
        echo "$email";
        ?>">
        <?php if($w_email==0)
        echo "podaj email";
        if($w_email2==0)
        {
            echo "podaj prawidlowy email";
        }
        
        ?>
    </div>
    <div>
        <label>Kod pocztowy:</label>
        <input type="text" id="7" name="kod" value="<?php
        if($w_kod==1)
        echo "$kod";
        ?>">
        <?php if($w_kod==0)
        echo "podaj kod pocztowy";
        if($w_kod2==0)
        echo "podaj prawidlowy kod pocztowy";
        ?>

    </div>
    <div id="button">
    <?php
    if ($st==5) echo 'EDYTUJ';
    if ($st==2) echo 'FORMULARZ';
    ?>
    <input type='submit' name="wyslij" value='Wyslij' id="8">
    <?php
    if ($st==5) echo '<input type="submit" name="odrzuc" value="Odrzuc" id="9">';
    ?>
    </div>
</form>
<?php
}

?>