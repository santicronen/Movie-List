    
    
    
    let prog1 = document.getElementById('factorial');
    let prog2 = document.getElementById('fibonacci');
    let prog3 = document.getElementById('mcd');

    function programa1(){
        prog1.classList.add("show");
        prog2.classList.remove("show");
        prog3.classList.remove("show");
    }
    function programa2(){
        prog2.classList.add("show");
        prog1.classList.remove("show");
        prog3.classList.remove("show");
    }
    function programa3(){
        prog3.classList.add("show");
        prog2.classList.remove("show");
        prog1.classList.remove("show");
    }





  