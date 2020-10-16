

//Funcion factorial

function validar(value){
    if(value%1==0){
        return true;
    }else{
        return false;
    }
}

function factorial(){
    let element = document.getElementById('element').value;
    if(validar(element)){
        let resultado = factor(element);
        document.getElementById('respuestaFactorial').value=resultado;
    }else{
        document.getElementById('respuestaFactorial').value="Err-Ingrese solo numeros enteros"; 
    }

}

function factor(n){
    if(n<=1){
        return 1;
    }
    return n*factor(n-1);
}

function fibonacci(){
    let posicion = document.getElementById('posicion').value;
    if(validar(posicion)){
        let elementList=fibo(posicion);
        document.getElementById('respuestaFibonacci').value = elementList;
    }else{
        document.getElementById('respuestaFibonacci').value="Err-Ingrese solo numeros enteros"; 
    }
    
}

function fibo(e){
    if (e===1){
      return [0, 1];
    } 
      let s = fibo(e - 1);
      s.push(s[s.length - 1] + s[s.length - 2]);
        return s;
}

function Mcd(){
    let num1 = document.getElementById('num1').value;
    let num2 = document.getElementById('num2').value;
    if(validar(num1)&&validar(num2)){
        let respuesta = mcd(num1,num2);
        document.getElementById('respuestaMcd').value = respuesta;
    }else{
        document.getElementById('respuestaMcd').value = "Err-Ingrese solo numeros enteros"; 
    }
}

function mcd(a,b){
    if(b==0){
		return a;
	    }else if(a>b){
		    return mcd(b,a%b);
	        }else{
		        return mcd(a,b%a);	
	        }
}