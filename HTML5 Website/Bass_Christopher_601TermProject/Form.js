function lettersOnly(txt)
{
	var letters = /^[A-Za-z]+$/; //got the alpha expression /^[A-Za-z]+$/ from http://www.w3resource.com/javascript/form/letters-numbers-field.php
	
	if(txt.value.match(letters))
	{
		document.getElementById("firstName").innerHTML ="Valid!";
	}
	else
	{
		document.getElementById("firstName").innerHTML ="First Name must contain only letters and must be filled out!";
	}
}

function minChar()
{
	var latname = document.forms["form1"]["lastName"].value;
	
	if (latname.length < 3)
	{
		document.getElementById("lastName").innerHTML ="Last name must be greater than 3 characters and must be filled out!";
	}
	else
	{
		document.getElementById("lastName").innerHTML ="Valid";
	}	
}


function emailFunction(txt2)
{
	
	var emailForm= /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/; //Got /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/ expression from http://www.w3resource.com/javascript/form/email-validation.php
			
	if(txt2.value.match(emailForm))
	{
		document.getElementById("emailID").innerHTML ="Valid!";
	}
	else
	{
		document.getElementById("emailID").innerHTML ="Invalid Email";
	}

	
}

function minCharFac()
{

	var facilname = document.forms["form1"]["Gamer Tag"].value;
	
	if (facilname.length < 3)
	{
		document.getElementById("GamerTag").innerHTML ="Gamer Tag must be greater than 3 characters and must be filled out!";
	}
	else
	{
		document.getElementById("GamerTag").innerHTML ="Valid";
	}	

}


function allValidation()
{
	
	if(document.getElementById("emailID").innerHTML !="Valid!" || document.getElementById("lastName").innerHTML !="Valid" 
	|| document.getElementById("firstName").innerHTML !="Valid!" || document.getElementById("GamerTag").innerHTML !="Valid")
	{
	return false;
	}
	else
	{
	return true;
	}

}

function Success()
{
	
	alert("Form Submitted Successfully You will be returned to page.");
	//document.getElementById("Success").innerHTML ="Form Submitted Successfully!";

}

function Success2()
{
	if (allValidation()==true)
	{
	alert("Form Submitted Successfully You will be returned to page.");
	//document.getElementById("Success").innerHTML ="Form Submitted Successfully!";
	}
}
