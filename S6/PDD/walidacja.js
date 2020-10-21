function walidacja_nazwy(){
	var x=document.getElementById("nazwa");
	var val=x.value;
	
	
	
	if(val==""){
		document.getElementById("blad_name").innerHTML="Pole obowiazkowe";
		x.classList.remove("is-valid");
		x.classList.add("is-invalid");
		return false;
	}else if(val.length>10){
		document.getElementById("blad_name").innerHTML="Max 10 znakow";
		x.classList.remove("is-valid");
		x.classList.add("is-invalid");
		return false;
	}else if(val.search(/^[a-zA-Z]+$/)){
		document.getElementById("blad_name").innerHTML="Tylko litery";
		x.classList.remove("is-valid");
		x.classList.add("is-invalid");
		x.classList.tooltip;
		return false;
	}else{
		var data = document.getElementById("table");
        var unique_data_Array = [];
        for (var i = 0; i < data.rows.length; i++) {
            unique_data_Array.push(data.rows[i])
        }

	var istnieje = 0;
		
        for (var j = 0; j < data.rows.length; j++) {
           if ( data.rows[j].cells[0].textContent.indexOf(val) >= 0) 
		   {
			   //alert("Element istnieje " + (j + 1));
			   document.getElementById("blad_name").innerHTML="Element istnieje";
				x.classList.remove("is-valid");
				x.classList.add("is-invalid");
				istnieje=1;
				return false;
		   }   
        }
		if(istnieje==0)
		{
			x.classList.remove("is-invalid");
			x.classList.add("is-valid");
			return true;
		}
	}
}

function walidacja_kodu(){
	var x=document.getElementById("kod");
	var val=x.value;
	
	if(val==""){
		document.getElementById("blad_name2").innerHTML="Pole obowiazkowe";
		x.classList.remove("is-valid");
		x.classList.add("is-invalid");
		return false;
	}	
	else if (val.search(/^[0-9a-zA-Z]{2}-[0-9a-zA-Z]{2}$/)) {
        document.getElementById("blad_name2").innerHTML="Wprowadz kod w formacie XX-XX, dozwolone tylko litery i cyfry";
		x.classList.remove("is-valid");
		x.classList.add("is-invalid");
		return false;
    }else{
		x.classList.remove("is-invalid");
		x.classList.add("is-valid");
		return true;
	}
}

function walidacja_netto(){
	var x=document.getElementById("netto");
	var val=x.value;
	//x.value = val.toFixed(2);
	
	if(val==""){
		document.getElementById("blad_name3").innerHTML="Pole obowiazkowe";
		x.classList.remove("is-valid");
		x.classList.add("is-invalid");
		return false;
	}	
	else if (val.search(/^[0-9]/)) {
        document.getElementById("blad_name3").innerHTML="Podaj cene";
		x.classList.remove("is-valid");
		x.classList.add("is-invalid");
		return false;
    }else{
		x.classList.remove("is-invalid");
		x.classList.add("is-valid");
		
		x.value= Number(x.value).toFixed(2);
		return true;
	}
}

function walidacja_vat(){
	var x=document.getElementById("vat");
	var val=x.value;
	
	if(val==""){
		document.getElementById("blad_name4").innerHTML="Pole obowiazkowe";
		x.classList.remove("is-valid");
		x.classList.add("is-invalid");
		return false;
	}	
	else if (val.search(/^[0-9]+$/)) {
        document.getElementById("blad_name4").innerHTML="Podaj tylko cyfry";
		x.classList.remove("is-valid");
		x.classList.add("is-invalid");
		return false;
    }else{
		x.classList.remove("is-invalid");
		x.classList.add("is-valid");
		return true;
	}
}

function walidacja_brutto(){
	var x=document.getElementById("brutto");
	var val=x.value;
	var netto=document.getElementById("netto");
	var nettoval=netto.value;
	var vat=document.getElementById("vat");
	var vatval=vat.value;
	//x.value=+nettoval+ +vatval;
	//x.value = +nettoval + ((nettoval / vatval) * 100)
	x.value = +nettoval+(nettoval*vatval*0.01);
}

function walidacja_kategoria(){
	var x=document.getElementById("kategoria");
	var val=x.value;
	if(val==0){
		document.getElementById("blad_name6").innerHTML="Pole obowiazkowe";
		x.classList.remove("is-valid");
		x.classList.add("is-invalid");
		return false;
	}
	else{
		x.classList.remove("is-invalid");
		x.classList.add("is-valid");
		return true;
	}
}

function walidacja_opcje(){
	var x=document.getElementById("opcje");
	var val=x.value;
  for (var i=0; i<x.length; i++) {
    if (!x[i].checked) {
	document.getElementById("blad_name7").innerHTML="Pole obowiazkowe";
      x.classList.remove("is-valid");
		x.classList.add("is-invalid");
		return false;
    } 
  }
}

function walidacja_ocena(){
	var x=document.getElementById("inlineRadioOptions");
	var val=x.value;
	document.getElementById("blad_name8").innerHTML="Pole obowiazkowe";
    if (!x[1].checked&&!x[2].checked&&!x[3].checked&&!x[4].checked) {
	document.getElementById("blad_name8").innerHTML="Pole obowiazkowe";
      x.classList.remove("is-valid");
		x.classList.add("is-invalid");
		return false;
	}
}

function check(){
   var table = document.getElementById("table");
for (var i = 0, cell; cell = table.cells[i]; i++) {
     //iterate through cells
     //cells would be accessed using the "cell" variable assigned in the for loop
	 alert(cell);
}
}

function walidacja_istnieje(){
	var data = document.getElementById("table");
        var unique_data_Array = [];
        for (var i = 0; i < data.rows.length; i++) {
            unique_data_Array.push(data.rows[i])
        }

		var x=document.getElementById("nazwa");
	var val=x.value;
	var istnieje = 0;
		
        for (var j = 0; j < data.rows.length; j++) {
           if ( data.rows[j].cells[0].innerHTML.indexOf(val) >= 0) 
		   {
			   alert("Element istnieje " + (j + 1));
			   document.getElementById("blad_name").innerHTML="Element istnieje";
				x.classList.remove("is-valid");
				x.classList.add("is-invalid");
				istnieje=1;
				return false;
		   }
               
			   
        }
		if(istnieje==0)
		{
			x.classList.remove("is-invalid");
			x.classList.add("is-valid");
			return true;
		}
}

function walidacja_all(){
	walidacja_nazwy();
	walidacja_kodu();
	walidacja_netto();
	walidacja_vat();
	walidacja_kategoria();
	walidacja_istnieje();
}

function remove(){
	var x = document.getElementsByName("towar");
		var i;
		for (i = 0; i < x.length; i++) {
			if (x[i].checked == true) {
				//alert(x[i].value);
				//document.getElementById("table").deleteRow(x[i].value);
				var row = document.getElementById(x[i].value);
				row.parentNode.removeChild(row);
			}
		}
}

function add(){
//alert('beka');
	var x = document.getElementsByName("towar");
		var i;
		for (i = 0; i < x.length; i++) {
			if (x[i].checked == true) {
				//alert('hmmm');
				//alert(x[i].value);
				//document.getElementById("table").deleteRow(x[i].value);
				
				var row = document.getElementById(x[i].value);
				
				//var control_id = 2;
				//var type_id_name = "Praveen";
				//$("#tableID tr#value_"+ control_id+" :nth-child(2)").html(type_id_name);
				//$("#tableID tr#value_"+ control_id+" td:nth-child(2)").html(type_id_name);
				
				//alert($("#space_bet3").prev("#space_bet2").attr("id"))
				//alert($('row').prev('td id="name"').innerHTML);
				var j=i+1;
				var nazwa = 'name' + j;
				
				
				var ciacho2=document.cookie;
				  var koszyk = 'koszyk=';
				  if(getCookie('koszyk')!='')
				  {
					
					koszyk = '';
				  }
	  var produkt=document.getElementById(nazwa).innerHTML;
	  //var rowwithvarname=tabelka+row;
	  ciacho2=ciacho2+koszyk+produkt+', '+';';
	  //alert(ciacho2);
    document.cookie=ciacho2;
	
	var kosz=getCookie('koszyk');
	//alert(kosz);
				
				//alert(i);
				//alert(document.getElementById(nazwa).innerHTML);
				//row.parentNode.removeChild(row);
			}
		}
}

function edit(){
	
/*	var $row = $(this).closest("tr"),       // Finds the closest row <tr> 
    $tds = $row.find("td");             // Finds all children <td> elements

$.each($tds, function() {               // Visits every single <td> element
    console.log($(this).text());        // Prints out the text within the <td>
});*/
	
	var x = document.getElementsByName("towar");
		var i;
		for (i = 0; i < x.length; i++) {
			if (x[i].checked == true) {
				var kol1 = document.getElementById("1").value = row.cells[1].innerHTML;
				 alert(kol1);
				//alert(x[i].value);
				//document.getElementById("table").deleteRow(x[i].value);
				var currentRow = document.getElementById(x[i].value);
				var col1=currentRow.find("td:eq(0)").text(); // get current row 1st TD value
				 var col2=currentRow.find("td:eq(1)").text(); // get current row 2nd TD
				 var col3=currentRow.find("td:eq(2)").text(); // get current row 3rd TD
				 var data=col1+"\n"+col2+"\n"+col3;
				 
				 var kol1 = document.getElementById("").value = row.cells[1].innerHTML;
				 alert(kol1);
                document.getElementById("").value = row.cells[2].innerHTML;
                document.getElementById("").value = row.cells[3].innerHTML;
                document.getElementById("").value = row.cells[4].innerHTML;
				 
				 alert(data);
				//row.parentNode.removeChild(row);
			}
		}
}
//https://codepedia.info/jquery-get-table-cell-td-value-div/

function dodaj(){
	var x = document.getElementsByName("towar");
		var i;
		for (i = 0; i < x.length; i++) {
			if (x[i].checked == true) {
				//alert(x[i].value);
				//document.getElementById("table").deleteRow(x[i].value);
				var row = document.getElementById(x[i].value);
				row.parentNode.removeChild(row);
			}
		}
}

function getCookie(cname) {
    var name = cname + "=";
    var ca = document.cookie.split(';');
    for(var i = 0; i < ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0) == ' ') {
            c = c.substring(1);
        }
        if (c.indexOf(name) == 0) {
            return c.substring(name.length, c.length);
        }
    }
    return "";
}
