/**
 * @return {Function}
 */
var createHelloWorld = function(args) {
    
    return function(...args) {
        return "Hello World";
    }
};


/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */

//MY SOLUTION


//  function createHelloWorld(){
//     function f(){
//         return "Hello World";
//     }
//     return f;
//  }


 function createHelloWorld(){
   return function f(){
        return "Hello World";
    } 
 }