/**
 * @return {Function}
 */
// var createHelloWorld = function(args) {
    
//     return function(...args) {
        
//     }
// };


/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */

 function createHelloWorld(){
    function f(){
        return "Hello World";
    }
    return f;
 }